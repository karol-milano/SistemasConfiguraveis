@@ -34,7 +34,7 @@ typedef struct parse_state
   struct si_chunk
   {
     // elements newly added in this chunk
-    gl_list_t contents;
+    state_item_list contents;
     // properties of the linked list this chunk represents
     const state_item *head_elt;
     const state_item *tail_elt;
@@ -252,7 +252,7 @@ parse_state_completed_steps (const parse_state *ps, int *shifts, int *production
   while (root_ps->parent)
     root_ps = root_ps->parent;
 
-  gl_list_t sis = root_ps->state_items.contents;
+  state_item_list sis = root_ps->state_items.contents;
   int count = 0;
 
   state_item *last = NULL;
@@ -337,19 +337,17 @@ parser_pop (parse_state *ps, int deriv_index,
   for (int i = 0; i < 4; ++i)
     chunks[i] = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   for (parse_state *pn = ps; pn != NULL; pn = pn->parent)
-    {
-      if (pn->prepend)
-        {
-          gl_list_add_last (chunks[0], pn->state_items.contents);
-          gl_list_add_last (chunks[2], pn->derivs.contents);
-        }
-      else
-        {
-          gl_list_add_first (chunks[1], pn->state_items.contents);
-          gl_list_add_first (chunks[3], pn->derivs.contents);
-        }
-    }
-  gl_list_t popped_derivs = derivation_list_new ();
+    if (pn->prepend)
+      {
+        gl_list_add_last (chunks[0], pn->state_items.contents);
+        gl_list_add_last (chunks[2], pn->derivs.contents);
+      }
+    else
+      {
+        gl_list_add_first (chunks[1], pn->state_items.contents);
+        gl_list_add_first (chunks[3], pn->derivs.contents);
+      }
+  derivation_list popped_derivs = derivation_list_new ();
   gl_list_t ret_chunks[4] = { ret->state_items.contents, NULL,
     ret->derivs.contents, popped_derivs
   };
@@ -390,7 +388,7 @@ parser_pop (parse_state *ps, int deriv_index,
 }
 
 void
-parse_state_lists (parse_state *ps, gl_list_t *sitems,
+parse_state_lists (parse_state *ps, state_item_list *sitems,
                    derivation_list *derivs)
 {
   parse_state *temp = empty_parse_state ();
@@ -431,14 +429,14 @@ nullable_closure (parse_state *ps, state_item *si, parse_state_list state_list)
     }
 }
 
-gl_list_t
+parse_state_list
 simulate_transition (parse_state *ps)
 {
   const state_item *si = ps->state_items.tail_elt;
   symbol_number sym = item_number_as_symbol_number (*si->item);
   // Transition on the same next symbol, taking nullable
   // symbols into account.
-  gl_list_t result = parse_state_list_new ();
+  parse_state_list result = parse_state_list_new ();
   state_item_number si_next = si->trans;
   // check for disabled transition, shouldn't happen
   // as any state_items that lead to these should be
@@ -473,10 +471,10 @@ compatible (symbol_number sym1, symbol_number sym2)
     return false;
 }
 
-gl_list_t
+parse_state_list
 simulate_production (parse_state *ps, symbol_number compat_sym)
 {
-  gl_list_t result = parse_state_list_new ();
+  parse_state_list result = parse_state_list_new ();
   const state_item *si = parse_state_tail (ps);
   if (si->prods)
     {
@@ -504,10 +502,10 @@ simulate_production (parse_state *ps, symbol_number compat_sym)
 // simulates a reduction on the given parse state, conflict_item is the
 // item associated with ps's conflict. symbol_set is a lookahead set this
 // reduction must be compatible with
-gl_list_t
+parse_state_list
 simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
 {
-  gl_list_t result = parse_state_list_new ();
+  parse_state_list result = parse_state_list_new ();
 
   int s_size = ps->state_items.total_size;
   int d_size = ps->derivs.total_size;
@@ -537,7 +535,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
       // The head state_item is a production item, so we need to prepend
       // with possible source state-items.
       const state_item *head = ps->state_items.head_elt;
-      gl_list_t prev = lssi_reverse_production (head, symbol_set);
+      state_item_list prev = lssi_reverse_production (head, symbol_set);
       // TODO: better understand what causes this case.
       if (gl_list_size (prev) == 0)
         {
@@ -570,10 +568,10 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
   return result;
 }
 
-gl_list_t
+parse_state_list
 parser_prepend (parse_state *ps)
 {
-  gl_list_t res = parse_state_list_new ();
+  parse_state_list res = parse_state_list_new ();
   const state_item *head = ps->state_items.head_elt;
   symbol_number prepend_sym =
     item_number_as_symbol_number (*(head->item - 1));
