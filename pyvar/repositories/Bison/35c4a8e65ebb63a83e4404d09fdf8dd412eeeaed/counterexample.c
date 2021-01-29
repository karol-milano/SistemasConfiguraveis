@@ -169,7 +169,7 @@ si_bfs_free (si_bfs_node *n)
  *
  * this returns the derivation of the productions that lead to conflict_sym
  */
-static inline gl_list_t
+static inline derivation_list
 expand_to_conflict (state_item_number start, symbol_number conflict_sym)
 {
   si_bfs_node *init = si_bfs_new (start, NULL);
@@ -216,11 +216,9 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
       exit (1);
     }
 
-  derivation *dinit = derivation_new (conflict_sym, NULL);
-  gl_list_t result =
-    gl_list_create (GL_LINKED_LIST, NULL, NULL,
-                    (gl_listelement_dispose_fn) derivation_free,
-                    true, 1, (const void **) &dinit);
+  derivation *dinit = derivation_new_leaf (conflict_sym);
+  derivation_list result = derivation_list_new ();
+  derivation_list_append (result, dinit);
   // iterate backwards through the generated path to create a derivation
   // of the conflict symbol containing derivations of each production step.
 
@@ -232,23 +230,22 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
         {
           item_number *i = NULL;
           for (i = pos + 1; !item_number_is_rule_number (*i); ++i)
-            gl_list_add_last (result, derivation_new (*i, NULL));
+            derivation_list_append (result, derivation_new_leaf (*i));
           symbol_number lhs =
             rules[item_number_as_rule_number (*i)].lhs->number;
           derivation *deriv = derivation_new (lhs, result);
-          result =
-            gl_list_create (GL_LINKED_LIST, NULL, NULL,
-                            (gl_listelement_dispose_fn) derivation_free,
-                            true, 1, (const void **) &deriv);
+          result = derivation_list_new ();
+          derivation_list_append (result, deriv);
         }
       else
         {
           symbol_number sym = item_number_as_symbol_number (*(pos - 1));
-          derivation *deriv = derivation_new (sym, NULL);
-          gl_list_add_first (result, deriv);
+          derivation *deriv = derivation_new_leaf (sym);
+          derivation_list_prepend (result, deriv);
         }
     }
   gl_list_free (queue);
+  derivation_free ((derivation*)gl_list_get_at (result, 0));
   gl_list_remove_at (result, 0);
   return result;
 }
@@ -263,16 +260,15 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
  */
 static derivation *
 complete_diverging_example (symbol_number conflict_sym,
-                            gl_list_t path, gl_list_t derivs)
+                            gl_list_t path, derivation_list derivs)
 {
   // The idea is to transfer each pending symbol on the productions
   // associated with the given StateItems to the resulting derivation.
-  gl_list_t result =
-    gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
+  derivation_list result = derivation_list_new ();
   bool lookahead_required = false;
   if (!derivs)
     {
-      derivs = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
+      derivs = derivation_list_new ();
       gl_list_add_last (result, derivation_dot ());
       lookahead_required = true;
     }
@@ -295,9 +291,8 @@ complete_diverging_example (symbol_number conflict_sym,
       if (gl_list_size (result) == 1 && !item_number_is_rule_number (pos)
           && gl_list_get_at (result, 0) == derivation_dot() )
         {
-          gl_list_add_last (result,
-                            derivation_new (item_number_as_symbol_number
-                                            (pos), NULL));
+          derivation_list_append (result,
+            derivation_new_leaf (item_number_as_symbol_number (pos)));
           lookahead_required = false;
         }
       item_number *i = item;
@@ -313,7 +308,7 @@ complete_diverging_example (symbol_number conflict_sym,
           symbol_number sym = item_number_as_symbol_number (*i);
           if (!lookahead_required || sym == conflict_sym)
             {
-              gl_list_add_last (result, derivation_new (sym, NULL));
+              derivation_list_append (result, derivation_new_leaf (sym));
               lookahead_required = false;
               continue;
             }
@@ -330,25 +325,19 @@ complete_diverging_example (symbol_number conflict_sym,
           if (bitset_test (FIRSTS (sym), conflict_sym))
             {
               lookahead_required = false;
-              gl_list_t next_derivs = expand_to_conflict (nsi,
-                                                          conflict_sym);
+              derivation_list next_derivs =
+                expand_to_conflict (nsi, conflict_sym);
               gl_list_iterator_t it = gl_list_iterator (next_derivs);
               derivation *d = NULL;
               while (gl_list_iterator_next (&it, (const void **) &d, NULL))
-                gl_list_add_last (result, d);
+                derivation_list_append (result, d);
               i += gl_list_size (next_derivs) - 1;
-              // next_derivs is leaked to prevent the copied derivations from
-              // being freed. It is somewhat difficult to for expand_to_conflict
-              // to decide which derivation list will be the final one that is
-              // returned, so each list frees its derivations when freed.
+              derivation_list_free (next_derivs);
             }
           else if (nullable[sym - ntokens])
             {
-              derivation *d = derivation_new (sym,
-                                              gl_list_create_empty
-                                              (GL_LINKED_LIST, NULL,
-                                               NULL, NULL, 1));
-              gl_list_add_last (result, d);
+              derivation *d = derivation_new_leaf (sym);
+              derivation_list_append (result, d);
             }
           else
             {
@@ -356,7 +345,7 @@ complete_diverging_example (symbol_number conflict_sym,
               // having the conflict symbol in its lookahead, no example
               // containing the symbol after the conflict item
               // can be found.
-              gl_list_add_last (result, derivation_new (1, NULL));
+              derivation_list_append (result, derivation_new_leaf (1));
               lookahead_required = false;
             }
         }
@@ -371,19 +360,20 @@ complete_diverging_example (symbol_number conflict_sym,
             {
               const void *tmp_deriv = gl_list_node_value (derivs, deriv);
               deriv = gl_list_previous_node (derivs, deriv);
-              gl_list_add_first (result, tmp_deriv);
+              derivation_list_prepend (result, (derivation*)tmp_deriv);
             }
           else
-            gl_list_add_first (result, derivation_new (*i, NULL));
+            derivation_list_prepend (result, derivation_new_leaf (*i));
         }
       // completing the derivation
       derivation *new_deriv = derivation_new (rules[r].lhs->number, result);
-      result =
-        gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
-                        (const void **) &new_deriv);
+      result = derivation_list_new ();
+      derivation_list_append (result, new_deriv);
     }
   derivation *res = (derivation *) gl_list_get_at (result, 0);
-  gl_list_free (result);
+  derivation_retain (res);
+  derivation_list_free (result);
+  derivation_list_free (derivs);
   return res;
 }
 
@@ -567,13 +557,6 @@ search_state_free (search_state *ss)
   free (ss);
 }
 
-static inline void
-search_state_retain_derivs (search_state *ss)
-{
-  parse_state_retain_deriv (ss->states[0]);
-  parse_state_retain_deriv (ss->states[1]);
-}
-
 static void
 search_state_print (search_state *ss)
 {
@@ -608,9 +591,11 @@ complete_diverging_examples(search_state *ss,
   derivation *new_derivs[2];
   for (int i = 0; i < 2; ++i)
     {
-      gl_list_t sitems, derivs;
+      gl_list_t sitems;
+      derivation_list derivs;
       parse_state_lists (ss->states[i], &sitems, &derivs);
       new_derivs[i] = complete_diverging_example (next_sym, sitems, derivs);
+      gl_list_free (sitems);
     }
   return new_counterexample (new_derivs[0], new_derivs[1], false, true);
 }
@@ -778,6 +763,8 @@ reduction_step (search_state *ss, const item_number *conflict_item,
       gl_list_add_last (result, copy);
     }
   gl_list_free (reduced);
+  if (symbol_set != si->lookahead)
+    bitset_free (symbol_set);
   return result;
 }
 
@@ -1068,17 +1055,16 @@ unifying_example (state_item_number itm1,
                   && has_common_prefix (si1src->item, si2src->item))
                 {
                   // Stage 4: both paths share a prefix
-                  const derivation *d1 = parse_state_derivation (ps1);
-                  const derivation *d2 = parse_state_derivation (ps2);
+                  derivation *d1 = parse_state_derivation (ps1);
+                  derivation *d2 = parse_state_derivation (ps2);
                   if (parse_state_derivation_completed (ps1)
-                      && parse_state_derivation_completed (ps2)
-                      && d1->sym == d2->sym)
+                      && parse_state_derivation_completed (ps2))
                     {
                       // Once we have two derivations for the same symbol,
                       // we've found a unifying counterexample.
                       cex = new_counterexample (d1, d2, true, false);
-                      // prevent d1/d2 from being freed.
-                      search_state_retain_derivs (ss);
+                      derivation_retain (d1);
+                      derivation_retain (d2);
                       goto cex_search_end;
                     }
                   if (!stage3result)
@@ -1116,7 +1102,6 @@ cex_search_end:;
       if (stage3result)
         {
           cex = complete_diverging_examples (stage3result, next_sym);
-          search_state_retain_derivs (stage3result);
           search_state_free (stage3result);
         }
       // Otherwise, construct a nonunifying counterexample that
