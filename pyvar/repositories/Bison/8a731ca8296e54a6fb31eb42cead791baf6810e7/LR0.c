@@ -94,7 +94,7 @@ allocate_itemsets (void)
   /* See comments before new_itemsets.  All the vectors of items
      live inside KERNEL_ITEMS.  The number of active items after
      some symbol cannot be more than the number of times that symbol
-     appears as an item, which is symbol_count[symbol].
+     appears as an item, which is SYMBOL_COUNT[SYMBOL].
      We allocate that much space for each symbol.  */
 
   kernel_base = XCALLOC (item_number_t *, nsyms);
@@ -313,8 +313,7 @@ save_reductions (state_t *state)
     }
 
   /* Make a reductions structure and copy the data into it.  */
-  state->reductions = reductions_new (count);
-  memcpy (state->reductions->rules, redset, count * sizeof (redset[0]));
+  state_reductions_set (state, count, redset);
 }
 
 
@@ -340,7 +339,7 @@ set_states (void)
       if (!state->errs)
 	state->errs = errs_new (0);
       if (!state->reductions)
-	state->reductions = reductions_new (0);
+	state_reductions_set (state, 0, 0);
 
       states[state->number] = state;
 
