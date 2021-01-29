@@ -59,7 +59,7 @@ static state_list *last_state = NULL;
 static state *
 state_list_append (symbol_number sym, size_t core_size, item_number *core)
 {
-  state_list *node = MALLOC (node, 1);
+  state_list *node = xmalloc (sizeof *node);
   state *s = state_new (sym, core_size, core);
 
   if (trace_flag & trace_automaton)
@@ -84,14 +84,14 @@ state_list_append (symbol_number sym, size_t core_size, item_number *core)
 }
 
 static int nshifts;
-static symbol_number *shift_symbol = NULL;
+static symbol_number *shift_symbol;
 
-static rule **redset = NULL;
-static state **shiftset = NULL;
+static rule **redset;
+static state **shiftset;
 
-static item_number **kernel_base = NULL;
-static int *kernel_size = NULL;
-static item_number *kernel_items = NULL;
+static item_number **kernel_base;
+static int *kernel_size;
+static item_number *kernel_items;
 
 
 static void
@@ -106,8 +106,8 @@ allocate_itemsets (void)
      browsed too, hence we need to allocate room for _all_ the
      symbols.  */
   int count = 0;
-  short int *symbol_count = CALLOC (symbol_count,
-				    nsyms + nuseless_nonterminals);
+  short int *symbol_count = xcalloc (nsyms + nuseless_nonterminals,
+				     sizeof *symbol_count);
 
   for (r = 0; r < nrules; ++r)
     for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
@@ -122,9 +122,8 @@ allocate_itemsets (void)
      appears as an item, which is SYMBOL_COUNT[S].
      We allocate that much space for each symbol.  */
 
-  CALLOC (kernel_base, nsyms);
-  if (count)
-    CALLOC (kernel_items, count);
+  kernel_base = xnmalloc (nsyms, sizeof *kernel_base);
+  kernel_items = xnmalloc (count, sizeof *kernel_items);
 
   count = 0;
   for (i = 0; i < nsyms; i++)
@@ -134,7 +133,7 @@ allocate_itemsets (void)
     }
 
   free (symbol_count);
-  CALLOC (kernel_size, nsyms);
+  kernel_size = xnmalloc (nsyms, sizeof *kernel_size);
 }
 
 
@@ -143,10 +142,10 @@ allocate_storage (void)
 {
   allocate_itemsets ();
 
-  CALLOC (shiftset, nsyms);
-  CALLOC (redset, nrules);
+  shiftset = xnmalloc (nsyms, sizeof *shiftset);
+  redset = xnmalloc (nrules, sizeof *redset);
   state_hash_new ();
-  CALLOC (shift_symbol, nsyms);
+  shift_symbol = xnmalloc (nsyms, sizeof *shift_symbol);
 }
 
 
@@ -252,7 +251,7 @@ append_states (state *s)
     {
       symbol_number sym = shift_symbol[i];
       int j;
-      for (j = i; 0 < j && sym < shift_symbol [j - 1]; j--)
+      for (j = i; 0 < j && sym < shift_symbol[j - 1]; j--)
 	shift_symbol[j] = shift_symbol[j - 1];
       shift_symbol[j] = sym;
     }
@@ -297,7 +296,7 @@ save_reductions (state *s)
 static void
 set_states (void)
 {
-  CALLOC (states, nstates);
+  states = xcalloc (nstates, sizeof *states);
 
   while (first_state)
     {
@@ -331,15 +330,14 @@ set_states (void)
 void
 generate_states (void)
 {
+  item_number initial_core = 0;
   state_list *list = NULL;
   allocate_storage ();
   new_closure (nritems);
 
   /* Create the initial state.  The 0 at the lhs is the index of the
      item of this initial rule.  */
-  kernel_base[0][0] = 0;
-  kernel_size[0] = 1;
-  state_list_append (0, kernel_size[0], kernel_base[0]);
+  state_list_append (0, 1, &initial_core);
 
   list = first_state;
 
