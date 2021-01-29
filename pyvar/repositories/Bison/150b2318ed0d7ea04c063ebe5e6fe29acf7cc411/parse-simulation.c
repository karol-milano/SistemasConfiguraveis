@@ -199,7 +199,8 @@ void
 free_parse_state (parse_state *original_ps)
 {
   bool free_contents = true;
-  for (parse_state *ps = original_ps; ps && free_contents; ps = ps->parent)
+  parse_state *parent_ps = NULL;
+  for (parse_state *ps = original_ps; ps && free_contents; ps = parent_ps)
     {
       --ps->reference_count;
       free_contents = (ps->reference_count == 1 && ps->free_contents_early)
@@ -213,11 +214,11 @@ free_parse_state (parse_state *original_ps)
           if (ps->derivs.contents)
             derivation_list_free (ps->derivs.contents);
         }
+      parent_ps = ps->parent;
       if (ps->reference_count <= 0)
         {
           free (ps);
           ++frees;
-          break;
         }
     }
 }
@@ -303,7 +304,7 @@ list_flatten_and_split (gl_list_t *list, gl_list_t *rets, int split, int n,
     }
 }
 
-static gl_list_t
+static parse_state_list
 parse_state_list_new (void)
 {
   return gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
@@ -311,6 +312,12 @@ parse_state_list_new (void)
                                true);
 }
 
+void parse_state_list_append (parse_state_list pl, parse_state *ps)
+{
+  parse_state_retain (ps);
+  gl_list_add_last (pl, ps);
+}
+
 // Emulates a reduction on a parse state by popping some amount of
 // derivations and state_items off of the parse_state and returning
 // the result in ret. Returns the derivation of what's popped.
@@ -397,7 +404,7 @@ parse_state_lists (parse_state *ps, gl_list_t *sitems,
  * nullable symbols whenever possible from the given state_item.
  */
 void
-nullable_closure (parse_state *ps, state_item *si, gl_list_t state_list)
+nullable_closure (parse_state *ps, state_item *si, parse_state_list state_list)
 {
   parse_state *current_ps = ps;
   state_item_number prev_sin = si - state_items;
@@ -413,8 +420,7 @@ nullable_closure (parse_state *ps, state_item *si, gl_list_t state_list)
       current_ps = copy_parse_state (false, current_ps);
       ps_si_append (current_ps, nsi);
       ps_derivs_append (current_ps, derivation_new_leaf (sp));
-      parse_state_retain (current_ps);
-      gl_list_add_last (state_list, current_ps);
+      parse_state_list_append (state_list, current_ps);
     }
 }
 
@@ -435,8 +441,7 @@ simulate_transition (parse_state *ps)
   parse_state *next_ps = copy_parse_state (false, ps);
   ps_si_append (next_ps, state_items + si_next);
   ps_derivs_append (next_ps, derivation_new_leaf (sym));
-  parse_state_retain (next_ps);
-  gl_list_add_last (result, next_ps);
+  parse_state_list_append (result, next_ps);
 
   nullable_closure (next_ps, state_items + si_next, result);
   return result;
@@ -481,8 +486,7 @@ simulate_production (parse_state *ps, symbol_number compat_sym)
             continue;
           parse_state *next_ps = copy_parse_state (false, ps);
           ps_si_append (next_ps, next);
-          parse_state_retain (next_ps);
-          gl_list_add_last (result, next_ps);
+          parse_state_list_append (result, next_ps);
           if (next_ps->depth >= 0)
             ++next_ps->depth;
           nullable_closure (next_ps, next, result);
@@ -520,8 +524,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
     {
       state_item *tail = (state_item *) new_root->state_items.tail_elt;
       ps_si_append (new_root, state_items + si_trans[tail - state_items]);
-      parse_state_retain (new_root);
-      gl_list_add_last (result, new_root);
+      parse_state_list_append (result, new_root);
     }
   else
     {
@@ -529,22 +532,31 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
       // with possible source state-items.
       const state_item *head = ps->state_items.head_elt;
       gl_list_t prev = lssi_reverse_production (head, symbol_set);
-      gl_list_iterator_t it = gl_list_iterator (prev);
-      state_item *psis;
-      while (gl_list_iterator_next (&it, (const void **) &psis, NULL))
+      // TODO: better understand what causes this case.
+      if (gl_list_size (prev) == 0)
+        {
+          // new_root needs to have an RC of 1 to be freed correctly here.
+          parse_state_retain (new_root);
+          free_parse_state (new_root);
+        }
+      else
         {
-          //Prepend the result from the reverse production
-          parse_state *copy = copy_parse_state (true, new_root);
-          ps_si_prepend (copy, psis);
-
-          // Append the left hand side to the end of the parser state
-          copy = copy_parse_state (false, copy);
-          struct si_chunk *sis = &copy->state_items;
-          const state_item *tail = sis->tail_elt;
-          ps_si_append (copy, state_items + si_trans[tail - state_items]);
-          parse_state_retain (copy);
-          gl_list_add_last (result, copy);
-          nullable_closure (copy, (state_item *) sis->tail_elt, result);
+          gl_list_iterator_t it = gl_list_iterator (prev);
+          state_item *psis;
+          while (gl_list_iterator_next (&it, (const void **) &psis, NULL))
+            {
+              //Prepend the result from the reverse production
+              parse_state *copy = copy_parse_state (true, new_root);
+              ps_si_prepend (copy, psis);
+
+              // Append the left hand side to the end of the parser state
+              copy = copy_parse_state (false, copy);
+              struct si_chunk *sis = &copy->state_items;
+              const state_item *tail = sis->tail_elt;
+              ps_si_append (copy, state_items + si_trans[tail - state_items]);
+              parse_state_list_append (result, copy);
+              nullable_closure (copy, (state_item *) sis->tail_elt, result);
+            }
         }
       gl_list_free (prev);
     }
@@ -564,11 +576,10 @@ parser_prepend (parse_state *ps)
   BITSET_FOR_EACH (biter, prev, sin, 0)
   {
     parse_state *copy = copy_parse_state (true, ps);
-    parse_state_retain (copy);
     ps_si_prepend (copy, state_items + sin);
     if (SI_TRANSITION (head))
       ps_derivs_prepend (copy, derivation_new_leaf (prepend_sym));
-    gl_list_add_last (result, copy);
+    parse_state_list_append (result, copy);
   }
   return result;
 }
