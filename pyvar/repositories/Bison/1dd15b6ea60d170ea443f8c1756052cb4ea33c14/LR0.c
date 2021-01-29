@@ -1,4 +1,4 @@
-/* Generate the nondeterministic finite state machine for bison,
+/* Generate the nondeterministic finite state machine for Bison.
 
    Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002 Free Software
    Foundation, Inc.
@@ -59,7 +59,7 @@ static state_list *last_state = NULL;
 static state *
 state_list_append (symbol_number sym, size_t core_size, item_number *core)
 {
-  state_list *node = XMALLOC (state_list, 1);
+  state_list *node = MALLOC (node, 1);
   state *s = state_new (sym, core_size, core);
 
   if (trace_flag & trace_automaton)
@@ -106,7 +106,7 @@ allocate_itemsets (void)
      browsed too, hence we need to allocate room for _all_ the
      symbols.  */
   int count = 0;
-  short *symbol_count = XCALLOC (short, nsyms + nuseless_nonterminals);
+  short *symbol_count = CALLOC (symbol_count, nsyms + nuseless_nonterminals);
 
   for (r = 0; r < nrules; ++r)
     for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
@@ -121,9 +121,9 @@ allocate_itemsets (void)
      appears as an item, which is SYMBOL_COUNT[S].
      We allocate that much space for each symbol.  */
 
-  kernel_base = XCALLOC (item_number *, nsyms);
+  CALLOC (kernel_base, nsyms);
   if (count)
-    kernel_items = XCALLOC (item_number, count);
+    CALLOC (kernel_items, count);
 
   count = 0;
   for (i = 0; i < nsyms; i++)
@@ -133,7 +133,7 @@ allocate_itemsets (void)
     }
 
   free (symbol_count);
-  kernel_size = XCALLOC (int, nsyms);
+  CALLOC (kernel_size, nsyms);
 }
 
 
@@ -142,10 +142,10 @@ allocate_storage (void)
 {
   allocate_itemsets ();
 
-  shiftset = XCALLOC (state *, nsyms);
-  redset = XCALLOC (rule *, nrules);
+  CALLOC (shiftset, nsyms);
+  CALLOC (redset, nrules);
   state_hash_new ();
-  shift_symbol = XCALLOC (symbol_number, nsyms);
+  CALLOC (shift_symbol, nsyms);
 }
 
 
@@ -157,7 +157,7 @@ free_storage (void)
   free (shiftset);
   free (kernel_base);
   free (kernel_size);
-  XFREE (kernel_items);
+  free (kernel_items);
   state_hash_free ();
 }
 
@@ -296,7 +296,7 @@ save_reductions (state *s)
 static void
 set_states (void)
 {
-  states = XCALLOC (state *, nstates);
+  CALLOC (states, nstates);
 
   while (first_state)
     {
