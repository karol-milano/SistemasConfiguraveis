@@ -105,7 +105,7 @@ allocate_itemsets (void)
   int count = 0;
   short *symbol_count = XCALLOC (short, nsyms + nuseless_nonterminals);
 
-  for (r = 1; r < nrules + 1; ++r)
+  for (r = 0; r < nrules; ++r)
     for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
       {
 	count++;
@@ -140,7 +140,7 @@ allocate_storage (void)
   allocate_itemsets ();
 
   shiftset = XCALLOC (state_number_t, nsyms);
-  redset = XCALLOC (short, nrules + 1);
+  redset = XCALLOC (short, nrules);
   state_hash_new ();
   shift_symbol = XCALLOC (symbol_number_t, nsyms);
 }
@@ -233,7 +233,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 | Use the information computed by new_itemsets to find the state    |
 | numbers reached by each shift transition from STATE.              |
 |                                                                   |
-| TRANSITIONSET is set up as a vector of state numbers of those states.  |
+| SHIFTSET is set up as a vector of state numbers of those states.  |
 `------------------------------------------------------------------*/
 
 static void
@@ -292,7 +292,7 @@ save_reductions (state_t *state)
     {
       int item = ritem[itemset[i]];
       if (item < 0)
-	redset[count++] = -item;
+	redset[count++] = item_number_as_rule_number (item);
     }
 
   /* Make a reductions structure and copy the data into it.  */
