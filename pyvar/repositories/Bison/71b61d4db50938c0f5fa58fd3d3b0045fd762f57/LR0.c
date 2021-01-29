@@ -169,6 +169,10 @@ free_storage (void)
 | shifted.  For each symbol in the grammar, kernel_base[symbol]  |
 | points to a vector of item numbers activated if that symbol is |
 | shifted, and kernel_size[symbol] is their numbers.             |
+|                                                                |
+| itemset is sorted on item number from ritem, which is sorted   |
+| on rule number.  Compute each kernel_base[symbol] with the     |
+| same sort.                                                     |
 `---------------------------------------------------------------*/
 
 static void
@@ -351,10 +355,8 @@ generate_states (void)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
 		 s->number,
 		 symbols[s->accessing_symbol]->tag);
-      /* Set up ruleset and itemset for the transitions out of this
-         state.  ruleset gets a 1 bit for each rule that could reduce
-         now.  itemset gets a vector of all the items that could be
-         accepted next.  */
+      /* Set up itemset for the transitions out of this state.  itemset gets a
+         vector of all the items that could be accepted next.  */
       closure (s->items, s->nitems);
       /* Record the reductions allowed out of this state.  */
       save_reductions (s);
