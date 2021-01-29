@@ -177,9 +177,9 @@ si_bfs_free (si_bfs_node *n)
 
 /**
  * start is a state_item such that conflict_sym is an element of FIRSTS of the
- * non-terminal after the dot in start. Because of this, we should be able to
+ * nonterminal after the dot in start. Because of this, we should be able to
  * find a production item starting with conflict_sym by only searching productions
- * of the non-terminal and shifting over nullable non-terminals
+ * of the nonterminal and shifting over nullable nonterminals
  *
  * this returns the derivation of the productions that lead to conflict_sym
  */
@@ -292,7 +292,7 @@ complete_diverging_example (symbol_number conflict_sym,
   // We go backwards through the path to create the derivation tree bottom-up.
   // Effectively this loops through each production once, and generates a
   // derivation of the left hand side by appending all of the rhs symbols.
-  // this becomes the derivation of the non-terminal after the dot in the
+  // this becomes the derivation of the nonterminal after the dot in the
   // next production, and all of the other symbols of the rule are added as normal.
   for (gl_list_node_t state_node = list_get_end (path);
        state_node != NULL;
@@ -334,8 +334,8 @@ complete_diverging_example (symbol_number conflict_sym,
           // Since reductions have the dot at the end of the item,
           // this loop will be first executed on the last item in the path
           // that's not a reduction. When that happens,
-          // the symbol after the dot should be a non-terminal,
-          // and we can look through successive nullable non-terminals
+          // the symbol after the dot should be a nonterminal,
+          // and we can look through successive nullable nonterminals
           // for one with the conflict symbol in its first set.
           if (bitset_test (FIRSTS (sym), conflict_sym))
             {
