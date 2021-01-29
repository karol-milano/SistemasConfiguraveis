@@ -56,9 +56,9 @@ static short *shift_symbol = NULL;
 static short *redset = NULL;
 static short *shiftset = NULL;
 
-static short **kernel_base = NULL;
+static item_number_t **kernel_base = NULL;
 static int *kernel_size = NULL;
-static short *kernel_items = NULL;
+static item_number_t *kernel_items = NULL;
 
 /* hash table for states, to recognize equivalent ones.  */
 
@@ -70,7 +70,7 @@ static void
 allocate_itemsets (void)
 {
   int i, r;
-  short *rhsp;
+  item_number_t *rhsp;
 
   /* Count the number of occurrences of all the symbols in RITEMS.
      Note that useless productions (hence useless nonterminals) are
@@ -92,9 +92,9 @@ allocate_itemsets (void)
      appears as an item, which is symbol_count[symbol].
      We allocate that much space for each symbol.  */
 
-  kernel_base = XCALLOC (short *, nsyms);
+  kernel_base = XCALLOC (item_number_t *, nsyms);
   if (count)
-    kernel_items = XCALLOC (short, count);
+    kernel_items = XCALLOC (item_number_t, count);
 
   count = 0;
   for (i = 0; i < nsyms; i++)
@@ -194,15 +194,16 @@ new_state (int symbol)
 	     nstates, symbol, quotearg_style (escape_quoting_style,
 					      symbols[symbol]->tag));
 
-  if (nstates >= MAXSHORT)
-    fatal (_("too many states (max %d)"), MAXSHORT);
+  if (nstates >= SHRT_MAX)
+    fatal (_("too many states (max %d)"), SHRT_MAX);
 
   p = STATE_ALLOC (kernel_size[symbol]);
   p->accessing_symbol = symbol;
   p->number = nstates;
   p->nitems = kernel_size[symbol];
 
-  shortcpy (p->items, kernel_base[symbol], kernel_size[symbol]);
+  memcpy (p->items, kernel_base[symbol],
+	  kernel_size[symbol] * sizeof (kernel_base[symbol][0]));
 
   /* If this is the eoftoken, and this is not the initial state, then
      this is the final state.  */
@@ -340,7 +341,7 @@ static void
 save_shifts (void)
 {
   shifts *p = shifts_new (nshifts);
-  shortcpy (p->shifts, shiftset, nshifts);
+  memcpy (p->shifts, shiftset, nshifts * sizeof (shiftset[0]));
   this_state->shifts = p;
 }
 
@@ -372,7 +373,7 @@ save_reductions (void)
 
   /* Make a reductions structure and copy the data into it.  */
   this_state->reductions = reductions_new (count);
-  shortcpy (this_state->reductions->rules, redset, count);
+  memcpy (this_state->reductions->rules, redset, count * sizeof (redset[0]));
 }
 
 
