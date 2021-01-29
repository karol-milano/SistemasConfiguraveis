@@ -376,7 +376,7 @@ generate_states (void)
       closure (s->items, s->nitems);
       /* Record the reductions allowed out of this state.  */
       save_reductions (s);
-      /* Find the itemsets of the states that shifts can reach.  */
+      /* Find the itemsets of the states that shifts/gotos can reach.  */
       new_itemsets (s);
       /* Find or create the core structures for those states.  */
       append_states (s);
