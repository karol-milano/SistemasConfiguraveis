@@ -89,10 +89,6 @@ static item_number *kernel_items;
 static void
 allocate_itemsets (void)
 {
-  symbol_number i;
-  rule_number r;
-  item_number *rhsp;
-
   /* Count the number of occurrences of all the symbols in RITEMS.
      Note that useless productions (hence useless nonterminals) are
      browsed too, hence we need to allocate room for _all_ the
@@ -101,8 +97,8 @@ allocate_itemsets (void)
   size_t *symbol_count = xcalloc (nsyms + nuseless_nonterminals,
                                   sizeof *symbol_count);
 
-  for (r = 0; r < nrules; ++r)
-    for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+  for (rule_number r = 0; r < nrules; ++r)
+    for (item_number *rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
       {
         count++;
         symbol_count[*rhsp]++;
@@ -118,7 +114,7 @@ allocate_itemsets (void)
   kernel_items = xnmalloc (count, sizeof *kernel_items);
 
   count = 0;
-  for (i = 0; i < nsyms; i++)
+  for (symbol_number i = 0; i < nsyms; i++)
     {
       kernel_base[i] = kernel_items + count;
       count += symbol_count[i];
@@ -174,8 +170,6 @@ free_storage (void)
 static void
 new_itemsets (state *s)
 {
-  size_t i;
-
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering new_itemsets, state = %d\n", s->number);
 
@@ -183,7 +177,7 @@ new_itemsets (state *s)
 
   nshifts = 0;
 
-  for (i = 0; i < nitemset; ++i)
+  for (size_t i = 0; i < nitemset; ++i)
     if (item_number_is_symbol_number (ritem[itemset[i]]))
       {
         symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
@@ -209,13 +203,11 @@ new_itemsets (state *s)
 static state *
 get_state (symbol_number sym, size_t core_size, item_number *core)
 {
-  state *s;
-
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
              sym, symbols[sym]->tag);
 
-  s = state_hash_lookup (core_size, core);
+  state *s = state_hash_lookup (core_size, core);
   if (!s)
     s = state_list_append (sym, core_size, core);
 
@@ -235,25 +227,23 @@ get_state (symbol_number sym, size_t core_size, item_number *core)
 static void
 append_states (state *s)
 {
-  int i;
-
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering append_states, state = %d\n", s->number);
 
   /* First sort shift_symbol into increasing order.  */
 
-  for (i = 1; i < nshifts; i++)
+  for (int i = 1; i < nshifts; i++)
     {
-      symbol_number sym = shift_symbol[i];
-      int j;
-      for (j = i; 0 < j && sym < shift_symbol[j - 1]; j--)
+      const symbol_number sym = shift_symbol[i];
+      int j = i;
+      for (; 0 < j && sym < shift_symbol[j - 1]; j--)
         shift_symbol[j] = shift_symbol[j - 1];
       shift_symbol[j] = sym;
     }
 
-  for (i = 0; i < nshifts; i++)
+  for (int i = 0; i < nshifts; i++)
     {
-      symbol_number sym = shift_symbol[i];
+      const symbol_number sym = shift_symbol[i];
       shiftset[i] = get_state (sym, kernel_size[sym], kernel_base[sym]);
     }
 }
@@ -269,10 +259,9 @@ static void
 save_reductions (state *s)
 {
   int count = 0;
-  size_t i;
 
   /* Find and count the active items that represent ends of rules. */
-  for (i = 0; i < nitemset; ++i)
+  for (size_t i = 0; i < nitemset; ++i)
     {
       item_number item = ritem[itemset[i]];
       if (item_number_is_rule_number (item))
@@ -334,17 +323,16 @@ set_states (void)
 void
 generate_states (void)
 {
-  item_number initial_core = 0;
-  state_list *list = NULL;
   allocate_storage ();
   new_closure (nritems);
 
   /* Create the initial state.  The 0 at the lhs is the index of the
      item of this initial rule.  */
+  item_number initial_core = 0;
   state_list_append (0, 1, &initial_core);
 
   /* States are queued when they are created; process them all.  */
-  for (list = first_state; list; list = list->next)
+  for (state_list *list = first_state; list; list = list->next)
     {
       state *s = list->state;
       if (trace_flag & trace_automaton)
