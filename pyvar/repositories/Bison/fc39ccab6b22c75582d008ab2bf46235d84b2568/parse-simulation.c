@@ -37,7 +37,6 @@ typedef struct
   size_t total_size;
 } ps_chunk;
 
-struct parse_state;
 typedef struct parse_state
 {
   // path of state-items the parser has traversed
@@ -86,11 +85,11 @@ static int frees = 0;
 static parse_state *
 empty_parse_state (void)
 {
-  parse_state *res = xcalloc (1, sizeof (parse_state));
-  res->state_items.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
-                                                    NULL, NULL, true);
-  res->derivs.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
-                                               NULL, NULL, true);
+  parse_state *res = xcalloc (1, sizeof *res);
+  res->state_items.contents
+    = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
+  res->derivs.contents
+    = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   ++allocs;
   return res;
 }
@@ -109,10 +108,10 @@ copy_parse_state (bool prepend, parse_state *parent)
 {
   parse_state *res = xmalloc (sizeof *res);
   memcpy (res, parent, sizeof *res);
-  res->state_items.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
-                                                    NULL, NULL, true);
-  res->derivs.contents = gl_list_create_empty (GL_LINKED_LIST, NULL,
-                                               NULL, NULL, true);
+  res->state_items.contents
+    = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
+  res->derivs.contents
+    = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   res->parent = parent;
   res->prepend = prepend;
   res->reference_count = 0;
@@ -216,8 +215,9 @@ parse_state_comparator (const parse_state *ps1, const parse_state *ps2)
 {
   const ps_chunk *sis1 = &ps1->state_items;
   const ps_chunk *sis2 = &ps2->state_items;
-  return sis1->head_elt == sis2->head_elt &&
-    sis1->tail_elt == sis2->tail_elt && sis1->total_size == sis2->total_size;
+  return sis1->head_elt == sis2->head_elt
+    && sis1->tail_elt == sis2->tail_elt
+    && sis1->total_size == sis2->total_size;
 }
 
 
@@ -273,6 +273,14 @@ list_flatten_and_split (gl_list_t *list, gl_list_t *rets, int split, int n)
     }
 }
 
+static gl_list_t
+parse_state_list_new (void)
+{
+  return gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
+                               (gl_listelement_dispose_fn)free_parse_state,
+                               true);
+}
+
 // Emulates a reduction on a parse state by popping some amount of
 // derivations and state_items off of the parse_state and returning
 // the result in ret. Returns the derivation of what's popped.
@@ -283,7 +291,7 @@ parser_pop (parse_state *ps, int deriv_index,
   // prepend sis, append sis, prepend derivs, append derivs
   gl_list_t chunks[4];
   for (int i = 0; i < 4; ++i)
-    chunks[i] = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, 1);
+    chunks[i] = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   for (parse_state *pn = ps; pn != NULL; pn = pn->parent)
     {
       if (pn->prepend)
@@ -298,7 +306,7 @@ parser_pop (parse_state *ps, int deriv_index,
         }
     }
   gl_list_t popped_derivs =
-    gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, 1);
+    gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   gl_list_t ret_chunks[4] = { ret->state_items.contents, NULL,
     ret->derivs.contents, popped_derivs
   };
@@ -385,10 +393,7 @@ simulate_transition (parse_state *ps)
   symbol_number sym = item_number_as_symbol_number (*si->item);
   // Transition on the same next symbol, taking nullable
   // symbols into account.
-  gl_list_t result =
-    gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
-                          (gl_listelement_dispose_fn)free_parse_state,
-                          true);
+  gl_list_t result = parse_state_list_new ();
   state_item_number si_next = si_trans[si - state_items];
   // check for disabled transition, shouldn't happen
   // as any state_items that lead to these should be
@@ -427,10 +432,7 @@ compatible (symbol_number sym1, symbol_number sym2)
 gl_list_t
 simulate_production (parse_state *ps, symbol_number compat_sym)
 {
-  gl_list_t result =
-    gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
-                          (gl_listelement_dispose_fn)free_parse_state,
-                          true);
+  gl_list_t result = parse_state_list_new ();
   const state_item *si = parse_state_tail (ps);
   bitset prod = si_prods_lookup (si - state_items);
   if (prod)
@@ -463,10 +465,7 @@ simulate_production (parse_state *ps, symbol_number compat_sym)
 gl_list_t
 simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
 {
-  gl_list_t result =
-    gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
-                          (gl_listelement_dispose_fn)free_parse_state,
-                          true);
+  gl_list_t result = parse_state_list_new ();
 
   int s_size = ps->state_items.total_size;
   int d_size = ps->derivs.total_size;
@@ -524,10 +523,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
 gl_list_t
 parser_prepend (parse_state *ps)
 {
-  gl_list_t result = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
-                                           (gl_listelement_dispose_fn)
-                                           free_parse_state,
-                                           true);
+  gl_list_t result = parse_state_list_new ();
   const state_item *head = ps->state_items.head_elt;
   bitset prev = si_revs[head - state_items];
   symbol_number prepend_sym =
