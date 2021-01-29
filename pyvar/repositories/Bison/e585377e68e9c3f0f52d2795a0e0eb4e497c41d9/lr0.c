@@ -57,14 +57,14 @@ static state *
 state_list_append (symbol_number sym, size_t core_size, item_number *core)
 {
   state_list *node = xmalloc (sizeof *node);
-  state *s = state_new (sym, core_size, core);
+  state *res = state_new (sym, core_size, core);
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
              nstates, sym, symbols[sym]->tag);
 
   node->next = NULL;
-  node->state = s;
+  node->state = res;
 
   if (!first_state)
     first_state = node;
@@ -72,13 +72,15 @@ state_list_append (symbol_number sym, size_t core_size, item_number *core)
     last_state->next = node;
   last_state = node;
 
-  return s;
+  return res;
 }
 
-static int nshifts;
-static symbol_number *shift_symbol;
+/* Symbols that can be "shifted" (including non terminals) from the
+   current state.  */
+bitset shift_symbol;
 
 static rule **redset;
+/* For the current state, the states that can be reached via a "shift".  */
 static state **shiftset;
 
 static item_number **kernel_base;
@@ -133,14 +135,14 @@ allocate_storage (void)
   shiftset = xnmalloc (nsyms, sizeof *shiftset);
   redset = xnmalloc (nrules, sizeof *redset);
   state_hash_new ();
-  shift_symbol = xnmalloc (nsyms, sizeof *shift_symbol);
+  shift_symbol = bitset_create (nsyms, BITSET_FIXED);
 }
 
 
 static void
 free_storage (void)
 {
-  free (shift_symbol);
+  bitset_free (shift_symbol);
   free (redset);
   free (shiftset);
   free (kernel_base);
@@ -152,20 +154,19 @@ free_storage (void)
 
 
 
-/*---------------------------------------------------------------.
-| Find which symbols can be shifted in S, and for each one       |
-| record which items would be active after that shift.  Uses the |
-| contents of itemset.                                           |
-|                                                                |
-| shift_symbol is set to a vector of the symbols that can be     |
-| shifted.  For each symbol in the grammar, kernel_base[symbol]  |
-| points to a vector of item numbers activated if that symbol is |
-| shifted, and kernel_size[symbol] is their numbers.             |
-|                                                                |
-| itemset is sorted on item index in ritem, which is sorted on   |
-| rule number.  Compute each kernel_base[symbol] with the same   |
-| sort.                                                          |
-`---------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| Find which symbols can be shifted in S, and for each one record    |
+| which items would be active after that shift.  Uses the contents   |
+| of itemset.                                                        |
+|                                                                    |
+| shift_symbol is a bitset of the symbols that can be shifted.  For  |
+| each symbol in the grammar, kernel_base[symbol] points to a vector |
+| of item numbers activated if that symbol is shifted, and           |
+| kernel_size[symbol] is their numbers.                              |
+|                                                                    |
+| itemset is sorted on item index in ritem, which is sorted on rule  |
+| number.  Compute each kernel_base[symbol] with the same sort.      |
+`-------------------------------------------------------------------*/
 
 static void
 new_itemsets (state *s)
@@ -175,17 +176,14 @@ new_itemsets (state *s)
 
   memset (kernel_size, 0, nsyms * sizeof *kernel_size);
 
-  nshifts = 0;
+  bitset_zero (shift_symbol);
 
   for (size_t i = 0; i < nitemset; ++i)
     if (item_number_is_symbol_number (ritem[itemset[i]]))
       {
         symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
         if (!kernel_size[sym])
-          {
-            shift_symbol[nshifts] = sym;
-            nshifts++;
-          }
+          bitset_set (shift_symbol, sym);
 
         kernel_base[sym][kernel_size[sym]] = itemset[i] + 1;
         kernel_size[sym]++;
@@ -230,21 +228,13 @@ append_states (state *s)
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering append_states, state = %d\n", s->number);
 
-  /* First sort shift_symbol into increasing order.  */
-
-  for (int i = 1; i < nshifts; i++)
-    {
-      const symbol_number sym = shift_symbol[i];
-      int j = i;
-      for (; 0 < j && sym < shift_symbol[j - 1]; j--)
-        shift_symbol[j] = shift_symbol[j - 1];
-      shift_symbol[j] = sym;
-    }
-
-  for (int i = 0; i < nshifts; i++)
+  bitset_iterator iter;
+  symbol_number sym;
+  int i = 0;
+  BITSET_FOR_EACH (iter, shift_symbol, sym, 0)
     {
-      const symbol_number sym = shift_symbol[i];
       shiftset[i] = get_state (sym, kernel_size[sym], kernel_base[sym]);
+      ++i;
     }
 }
 
@@ -351,7 +341,7 @@ generate_states (void)
 
       /* Create the shifts structures for the shifts to those states,
          now that the state numbers transitioning to are known.  */
-      state_transitions_set (s, nshifts, shiftset);
+      state_transitions_set (s, bitset_count (shift_symbol), shiftset);
     }
 
   /* discard various storage */
