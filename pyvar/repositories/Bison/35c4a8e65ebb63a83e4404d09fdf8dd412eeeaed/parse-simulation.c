@@ -27,22 +27,26 @@
 #include "nullable.h"
 #include "parse-simulation.h"
 
-typedef struct
-{
-  // elements newly added in this chunk
-  gl_list_t contents;
-  // properties of the linked list this chunk represents
-  const void *head_elt;
-  const void *tail_elt;
-  size_t total_size;
-} ps_chunk;
-
 typedef struct parse_state
 {
   // path of state-items the parser has traversed
-  ps_chunk state_items;
+  struct si_chunk
+  {
+    // elements newly added in this chunk
+    gl_list_t contents;
+    // properties of the linked list this chunk represents
+    const state_item *head_elt;
+    const state_item *tail_elt;
+    size_t total_size;
+  } state_items;
   // list of derivations of the symbols
-  ps_chunk derivs;
+  struct deriv_chunk
+  {
+    derivation_list contents;
+    const derivation *head_elt;
+    const derivation *tail_elt;
+    size_t total_size;
+  } derivs;
   struct parse_state *parent;
   int reference_count;
   // incremented during productions,
@@ -60,23 +64,47 @@ typedef struct parse_state
 
 
 static void
-ps_chunk_prepend (ps_chunk *chunk, const void *element)
+ps_si_prepend (parse_state *ps, const state_item *si)
+{
+  struct si_chunk *sic = &ps->state_items;
+  gl_list_add_first (sic->contents, si);
+  sic->head_elt = si;
+  ++sic->total_size;
+  if (!sic->tail_elt)
+    sic->tail_elt = si;
+}
+
+static void
+ps_si_append (parse_state *ps, const state_item *si)
+{
+  struct si_chunk *sic = &ps->state_items;
+  gl_list_add_last (sic->contents, si);
+  sic->tail_elt = si;
+  ++sic->total_size;
+  if (!sic->head_elt)
+    sic->head_elt = si;
+}
+
+static void
+ps_derivs_prepend (parse_state *ps, derivation *d)
 {
-  gl_list_add_first (chunk->contents, element);
-  chunk->head_elt = element;
-  ++chunk->total_size;
-  if (!chunk->tail_elt)
-    chunk->tail_elt = element;
+  struct deriv_chunk *dc = &ps->derivs;
+  derivation_list_prepend (dc->contents, d);
+  dc->head_elt = d;
+  ++dc->total_size;
+  if (!dc->tail_elt)
+    dc->tail_elt = d;
 }
 
 static void
-ps_chunk_append (ps_chunk *chunk, const void *element)
+ps_derivs_append (parse_state *ps, derivation *d)
 {
-  gl_list_add_last (chunk->contents, element);
-  chunk->tail_elt = element;
-  ++chunk->total_size;
-  if (!chunk->head_elt)
-    chunk->head_elt = element;
+  struct deriv_chunk *dc = &ps->derivs;
+  derivation_list_append (dc->contents, d);
+  dc->tail_elt = d;
+  ++dc->total_size;
+  if (!dc->head_elt)
+    dc->head_elt = d;
 }
 
 static int allocs = 0;
@@ -88,8 +116,7 @@ empty_parse_state (void)
   parse_state *res = xcalloc (1, sizeof *res);
   res->state_items.contents
     = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
-  res->derivs.contents
-    = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
+  res->derivs.contents = derivation_list_new ();
   ++allocs;
   return res;
 }
@@ -98,8 +125,8 @@ parse_state *
 new_parse_state (const state_item *si)
 {
   parse_state *res = empty_parse_state ();
-  ps_chunk_append (&res->state_items, si);
-  ps_chunk_append (&res->derivs, derivation_dot ());
+  ps_si_append (res, si);
+  ps_derivs_append (res, derivation_dot ());
   return res;
 }
 
@@ -110,8 +137,7 @@ copy_parse_state (bool prepend, parse_state *parent)
   memcpy (res, parent, sizeof *res);
   res->state_items.contents
     = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
-  res->derivs.contents
-    = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
+  res->derivs.contents = derivation_list_new ();
   res->parent = parent;
   res->prepend = prepend;
   res->reference_count = 0;
@@ -127,10 +153,10 @@ parse_state_derivation_completed (const parse_state *ps)
   return ps->derivs.total_size == 1;
 }
 
-const derivation *
+derivation *
 parse_state_derivation (const parse_state *ps)
 {
-  return ps->derivs.head_elt;
+  return (derivation *)ps->derivs.head_elt;
 }
 
 const state_item *
@@ -169,12 +195,6 @@ parse_state_free_contents_early (parse_state *ps)
   ps->free_contents_early = true;
 }
 
-void
-parse_state_retain_deriv (parse_state *ps)
-{
-  ps->derivs.contents = NULL;
-}
-
 void
 free_parse_state (parse_state *original_ps)
 {
@@ -191,7 +211,7 @@ free_parse_state (parse_state *original_ps)
           if (ps->state_items.contents)
             gl_list_free (ps->state_items.contents);
           if (ps->derivs.contents)
-            gl_list_free (ps->derivs.contents);
+            derivation_list_free (ps->derivs.contents);
         }
       if (ps->reference_count <= 0)
         {
@@ -205,7 +225,7 @@ free_parse_state (parse_state *original_ps)
 size_t
 parse_state_hasher (const parse_state *ps, size_t max)
 {
-  const ps_chunk *sis = &ps->state_items;
+  const struct si_chunk *sis = &ps->state_items;
   return ((state_item *) sis->head_elt - state_items +
           (state_item *) sis->tail_elt - state_items + sis->total_size) % max;
 }
@@ -213,8 +233,8 @@ parse_state_hasher (const parse_state *ps, size_t max)
 bool
 parse_state_comparator (const parse_state *ps1, const parse_state *ps2)
 {
-  const ps_chunk *sis1 = &ps1->state_items;
-  const ps_chunk *sis2 = &ps2->state_items;
+  const struct si_chunk *sis1 = &ps1->state_items;
+  const struct si_chunk *sis2 = &ps2->state_items;
   return sis1->head_elt == sis2->head_elt
     && sis1->tail_elt == sis2->tail_elt
     && sis1->total_size == sis2->total_size;
@@ -245,10 +265,20 @@ parse_state_completed_steps (const parse_state *ps, int *shifts, int *production
   *shifts = root_ps->state_items.total_size - count;
 }
 
+typedef void (*chunk_append_fn) (gl_list_t, const void *);
+
+// A version of gl_list_add_last which has the chunk_append_fn
+// signature.
+void list_add_last (gl_list_t list, const void *elt)
+{
+  gl_list_add_last (list, elt);
+}
+
 // takes an array of n gl_lists and flattens them into two list
 // based off of the index split
 static void
-list_flatten_and_split (gl_list_t *list, gl_list_t *rets, int split, int n)
+list_flatten_and_split (gl_list_t *list, gl_list_t *rets, int split, int n,
+                        chunk_append_fn append_fn)
 {
   int ret_index = 0;
   int ret_array = 0;
@@ -267,7 +297,7 @@ list_flatten_and_split (gl_list_t *list, gl_list_t *rets, int split, int n)
               if (ret_index++ == split)
                 ++ret_array;
               if (rets[ret_array])
-                gl_list_add_last (rets[ret_array], si);
+                append_fn (rets[ret_array], si);
             }
         }
     }
@@ -284,7 +314,7 @@ parse_state_list_new (void)
 // Emulates a reduction on a parse state by popping some amount of
 // derivations and state_items off of the parse_state and returning
 // the result in ret. Returns the derivation of what's popped.
-static gl_list_t
+static derivation_list
 parser_pop (parse_state *ps, int deriv_index,
             int si_index, parse_state *ret)
 {
@@ -305,13 +335,14 @@ parser_pop (parse_state *ps, int deriv_index,
           gl_list_add_first (chunks[3], pn->derivs.contents);
         }
     }
-  gl_list_t popped_derivs =
-    gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
+  gl_list_t popped_derivs = derivation_list_new ();
   gl_list_t ret_chunks[4] = { ret->state_items.contents, NULL,
     ret->derivs.contents, popped_derivs
   };
-  list_flatten_and_split (chunks, ret_chunks, si_index, 2);
-  list_flatten_and_split (chunks + 2, ret_chunks + 2, deriv_index, 2);
+  list_flatten_and_split (chunks, ret_chunks, si_index, 2,
+                          list_add_last);
+  list_flatten_and_split (chunks + 2, ret_chunks + 2, deriv_index, 2,
+                          (chunk_append_fn)derivation_list_append);
   size_t s_size = gl_list_size (ret->state_items.contents);
   ret->state_items.total_size = s_size;
   if (s_size > 0)
@@ -346,18 +377,19 @@ parser_pop (parse_state *ps, int deriv_index,
 
 void
 parse_state_lists (parse_state *ps, gl_list_t *sitems,
-                   gl_list_t *derivs)
+                   derivation_list *derivs)
 {
   parse_state *temp = empty_parse_state ();
   size_t si_size = ps->state_items.total_size;
   size_t deriv_size = ps->derivs.total_size;
-  parser_pop (ps, si_size, deriv_size, temp);
+  derivation_list dl = parser_pop (ps, si_size, deriv_size, temp);
   *sitems = temp->state_items.contents;
   *derivs = temp->derivs.contents;
   // prevent the return lists from being freed
   temp->state_items.contents = NULL;
   temp->derivs.contents = NULL;
   free_parse_state (temp);
+  derivation_list_free (dl);
 }
 
 /**
@@ -379,8 +411,8 @@ nullable_closure (parse_state *ps, state_item *si, gl_list_t state_list)
 
       state_item *nsi = state_items + sin;
       current_ps = copy_parse_state (false, current_ps);
-      ps_chunk_append (&current_ps->state_items, nsi);
-      ps_chunk_append (&current_ps->derivs, derivation_new (sp, NULL));
+      ps_si_append (current_ps, nsi);
+      ps_derivs_append (current_ps, derivation_new_leaf (sp));
       parse_state_retain (current_ps);
       gl_list_add_last (state_list, current_ps);
     }
@@ -401,8 +433,8 @@ simulate_transition (parse_state *ps)
   if (si_next < 0)
     return result;
   parse_state *next_ps = copy_parse_state (false, ps);
-  ps_chunk_append (&next_ps->state_items, state_items + si_next);
-  ps_chunk_append (&next_ps->derivs, derivation_new (sym, NULL));
+  ps_si_append (next_ps, state_items + si_next);
+  ps_derivs_append (next_ps, derivation_new_leaf (sym));
   parse_state_retain (next_ps);
   gl_list_add_last (result, next_ps);
 
@@ -448,7 +480,7 @@ simulate_production (parse_state *ps, symbol_number compat_sym)
           if (!compatible (*itm1, compat_sym) || !production_allowed (si, next))
             continue;
           parse_state *next_ps = copy_parse_state (false, ps);
-          ps_chunk_append (&next_ps->state_items, next);
+          ps_si_append (next_ps, next);
           parse_state_retain (next_ps);
           gl_list_add_last (result, next_ps);
           if (next_ps->depth >= 0)
@@ -472,9 +504,9 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
   if (ps->depth >= 0)
     d_size--;                   // account for dot
   parse_state *new_root = empty_parse_state ();
-  gl_list_t popped_derivs = parser_pop (ps, d_size - rule_len,
-                                        s_size - rule_len - 1,
-                                        new_root);
+  derivation_list popped_derivs =
+    parser_pop (ps, d_size - rule_len,
+                s_size - rule_len - 1, new_root);
 
   // update derivation
   state_item *si = (state_item *) ps->state_items.tail_elt;
@@ -482,13 +514,12 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
   symbol_number lhs = r->lhs->number;
   derivation *deriv = derivation_new (lhs, popped_derivs);
   --new_root->depth;
-  ps_chunk_append (&new_root->derivs, deriv);
+  ps_derivs_append (new_root, deriv);
 
   if (s_size != rule_len + 1)
     {
       state_item *tail = (state_item *) new_root->state_items.tail_elt;
-      ps_chunk_append (&new_root->state_items,
-                       state_items + si_trans[tail - state_items]);
+      ps_si_append (new_root, state_items + si_trans[tail - state_items]);
       parse_state_retain (new_root);
       gl_list_add_last (result, new_root);
     }
@@ -504,13 +535,13 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
         {
           //Prepend the result from the reverse production
           parse_state *copy = copy_parse_state (true, new_root);
-          ps_chunk_prepend (&copy->state_items, psis);
+          ps_si_prepend (copy, psis);
 
           // Append the left hand side to the end of the parser state
           copy = copy_parse_state (false, copy);
-          ps_chunk *sis = &copy->state_items;
+          struct si_chunk *sis = &copy->state_items;
           const state_item *tail = sis->tail_elt;
-          ps_chunk_append (sis, state_items + si_trans[tail - state_items]);
+          ps_si_append (copy, state_items + si_trans[tail - state_items]);
           parse_state_retain (copy);
           gl_list_add_last (result, copy);
           nullable_closure (copy, (state_item *) sis->tail_elt, result);
@@ -534,9 +565,9 @@ parser_prepend (parse_state *ps)
   {
     parse_state *copy = copy_parse_state (true, ps);
     parse_state_retain (copy);
-    ps_chunk_prepend (&copy->state_items, state_items + sin);
+    ps_si_prepend (copy, state_items + sin);
     if (SI_TRANSITION (head))
-      ps_chunk_prepend (&copy->derivs, derivation_new (prepend_sym, NULL));
+      ps_derivs_prepend (copy, derivation_new_leaf (prepend_sym));
     gl_list_add_last (result, copy);
   }
   return result;
