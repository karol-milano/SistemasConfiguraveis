@@ -219,7 +219,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
     {
       gl_list_free (queue);
       fputs ("Error expanding derivation\n", stderr);
-      exit (1);
+      abort ();
     }
 
   derivation *dinit = derivation_new_leaf (conflict_sym);
@@ -295,7 +295,7 @@ complete_diverging_example (symbol_number conflict_sym,
       item_number pos = *item;
       // symbols after dot
       if (gl_list_size (result) == 1 && !item_number_is_rule_number (pos)
-          && gl_list_get_at (result, 0) == derivation_dot() )
+          && gl_list_get_at (result, 0) == derivation_dot ())
         {
           derivation_list_append (result,
             derivation_new_leaf (item_number_as_symbol_number (pos)));
@@ -604,8 +604,8 @@ ss_set_parse_state (search_state *ss, int idx, parse_state *ps)
  * but not the end of the example.
  */
 static counterexample *
-complete_diverging_examples(search_state *ss,
-                            symbol_number next_sym)
+complete_diverging_examples (search_state *ss,
+                             symbol_number next_sym)
 {
   derivation *new_derivs[2];
   for (int i = 0; i < 2; ++i)
@@ -634,7 +634,7 @@ static void
 ssb_free (search_state_bundle *ssb)
 {
   gl_list_free (ssb->states);
-  free(ssb);
+  free (ssb);
 }
 
 static size_t
