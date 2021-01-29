@@ -62,7 +62,7 @@ state_list_append (symbol_number sym, size_t core_size, item_number *core)
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
-	     nstates, sym, symbols[sym]->tag);
+             nstates, sym, symbols[sym]->tag);
 
   node->next = NULL;
   node->state = s;
@@ -100,13 +100,13 @@ allocate_itemsets (void)
      symbols.  */
   size_t count = 0;
   size_t *symbol_count = xcalloc (nsyms + nuseless_nonterminals,
-				  sizeof *symbol_count);
+                                  sizeof *symbol_count);
 
   for (r = 0; r < nrules; ++r)
     for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
       {
-	count++;
-	symbol_count[*rhsp]++;
+        count++;
+        symbol_count[*rhsp]++;
       }
 
   /* See comments before new_itemsets.  All the vectors of items
@@ -187,15 +187,15 @@ new_itemsets (state *s)
   for (i = 0; i < nitemset; ++i)
     if (item_number_is_symbol_number (ritem[itemset[i]]))
       {
-	symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
-	if (!kernel_size[sym])
-	  {
-	    shift_symbol[nshifts] = sym;
-	    nshifts++;
-	  }
-
-	kernel_base[sym][kernel_size[sym]] = itemset[i] + 1;
-	kernel_size[sym]++;
+        symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
+        if (!kernel_size[sym])
+          {
+            shift_symbol[nshifts] = sym;
+            nshifts++;
+          }
+
+        kernel_base[sym][kernel_size[sym]] = itemset[i] + 1;
+        kernel_size[sym]++;
       }
 }
 
@@ -214,7 +214,7 @@ get_state (symbol_number sym, size_t core_size, item_number *core)
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
-	     sym, symbols[sym]->tag);
+             sym, symbols[sym]->tag);
 
   s = state_hash_lookup (core_size, core);
   if (!s)
@@ -228,7 +228,7 @@ get_state (symbol_number sym, size_t core_size, item_number *core)
 
 /*---------------------------------------------------------------.
 | Use the information computed by new_itemsets to find the state |
-| numbers reached by each shift transition from S.		 |
+| numbers reached by each shift transition from S.               |
 |                                                                |
 | SHIFTSET is set up as a vector of those states.                |
 `---------------------------------------------------------------*/
@@ -248,7 +248,7 @@ append_states (state *s)
       symbol_number sym = shift_symbol[i];
       int j;
       for (j = i; 0 < j && sym < shift_symbol[j - 1]; j--)
-	shift_symbol[j] = shift_symbol[j - 1];
+        shift_symbol[j] = shift_symbol[j - 1];
       shift_symbol[j] = sym;
     }
 
@@ -277,16 +277,16 @@ save_reductions (state *s)
     {
       item_number item = ritem[itemset[i]];
       if (item_number_is_rule_number (item))
-	{
-	  rule_number r = item_number_as_rule_number (item);
-	  redset[count++] = &rules[r];
-	  if (r == 0)
-	    {
-	      /* This is "reduce 0", i.e., accept. */
-	      aver (!final_state);
-	      final_state = s;
-	    }
-	}
+        {
+          rule_number r = item_number_as_rule_number (item);
+          redset[count++] = &rules[r];
+          if (r == 0)
+            {
+              /* This is "reduce 0", i.e., accept. */
+              aver (!final_state);
+              final_state = s;
+            }
+        }
     }
 
   /* Make a reductions structure and copy the data into it.  */
@@ -308,14 +308,14 @@ set_states (void)
       state_list *this = first_state;
 
       /* Pessimization, but simplification of the code: make sure all
-	 the states have valid transitions and reductions members,
-	 even if reduced to 0.  It is too soon for errs, which are
-	 computed later, but set_conflicts.  */
+         the states have valid transitions and reductions members,
+         even if reduced to 0.  It is too soon for errs, which are
+         computed later, but set_conflicts.  */
       state *s = this->state;
       if (!s->transitions)
-	state_transitions_set (s, 0, 0);
+        state_transitions_set (s, 0, 0);
       if (!s->reductions)
-	state_reductions_set (s, 0, 0);
+        state_reductions_set (s, 0, 0);
 
       states[s->number] = s;
 
@@ -349,9 +349,9 @@ generate_states (void)
     {
       state *s = list->state;
       if (trace_flag & trace_automaton)
-	fprintf (stderr, "Processing state %d (reached by %s)\n",
-		 s->number,
-		 symbols[s->accessing_symbol]->tag);
+        fprintf (stderr, "Processing state %d (reached by %s)\n",
+                 s->number,
+                 symbols[s->accessing_symbol]->tag);
       /* Set up itemset for the transitions out of this state.  itemset gets a
          vector of all the items that could be accepted next.  */
       closure (s->items, s->nitems);
@@ -363,7 +363,7 @@ generate_states (void)
       append_states (s);
 
       /* Create the shifts structures for the shifts to those states,
-	 now that the state numbers transitioning to are known.  */
+         now that the state numbers transitioning to are known.  */
       state_transitions_set (s, nshifts, shiftset);
     }
 
