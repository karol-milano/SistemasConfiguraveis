@@ -101,16 +101,14 @@ ielr_compute_internal_follow_edges (bitset ritem_sees_lookahead_set,
   *edge_countsp = xnmalloc (ngotos, sizeof **edge_countsp);
   {
     bitset sources = bitset_create (ngotos, BITSET_FIXED);
-    goto_number i;
-    for (i = 0; i < ngotos; ++i)
+    for (goto_number i = 0; i < ngotos; ++i)
       (*edge_countsp)[i] = 0;
-    for (i = 0; i < ngotos; ++i)
+    for (goto_number i = 0; i < ngotos; ++i)
       {
         int nsources = 0;
         {
-          rule **rulep;
-          for (rulep = derives[states[to_state[i]]->accessing_symbol
-                               - ntokens];
+          for (rule **rulep = derives[states[to_state[i]]->accessing_symbol
+                                      - ntokens];
                *rulep;
                ++rulep)
             {
@@ -198,30 +196,26 @@ ielr_compute_follow_kernel_items (bitset ritem_sees_lookahead_set,
 {
   {
     size_t max_nitems = 0;
-    state_number i;
-    for (i = 0; i < nstates; ++i)
+    for (state_number i = 0; i < nstates; ++i)
       if (states[i]->nitems > max_nitems)
         max_nitems = states[i]->nitems;
     *follow_kernel_itemsp = bitsetv_create (ngotos, max_nitems, BITSET_FIXED);
   }
-  {
-    goto_number i;
-    for (i = 0; i < ngotos; ++i)
-      {
-        size_t nitems = states[from_state[i]]->nitems;
-        item_number *items = states[from_state[i]]->items;
-        size_t j;
-        for (j = 0; j < nitems; ++j)
-          /* If this item has this goto and if all subsequent symbols in this
-             RHS (if any) are nullable nonterminals, then record this item as
-             one whose lookahead set is included in this goto's follows.  */
-          if (item_number_is_symbol_number (ritem[items[j]])
-              && item_number_as_symbol_number (ritem[items[j]])
-                == states[to_state[i]]->accessing_symbol
-              && bitset_test (ritem_sees_lookahead_set, items[j]))
-            bitset_set ((*follow_kernel_itemsp)[i], j);
-      }
-  }
+  for (goto_number i = 0; i < ngotos; ++i)
+    {
+      size_t nitems = states[from_state[i]]->nitems;
+      item_number *items = states[from_state[i]]->items;
+      size_t j;
+      for (j = 0; j < nitems; ++j)
+        /* If this item has this goto and if all subsequent symbols in this
+           RHS (if any) are nullable nonterminals, then record this item as
+           one whose lookahead set is included in this goto's follows.  */
+        if (item_number_is_symbol_number (ritem[items[j]])
+            && item_number_as_symbol_number (ritem[items[j]])
+            == states[to_state[i]]->accessing_symbol
+            && bitset_test (ritem_sees_lookahead_set, items[j]))
+          bitset_set ((*follow_kernel_itemsp)[i], j);
+    }
   relation_digraph (internal_follow_edges, ngotos, follow_kernel_itemsp);
 
   if (trace_flag & trace_ielr)
@@ -252,8 +246,7 @@ ielr_compute_always_follows (goto_number ***edgesp,
   *always_followsp = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
   {
     goto_number *edge_array = xnmalloc (ngotos, sizeof *edge_array);
-    goto_number i;
-    for (i = 0; i < ngotos; ++i)
+    for (goto_number i = 0; i < ngotos; ++i)
       {
         goto_number nedges = edge_counts[i];
         {
@@ -300,32 +293,28 @@ ielr_compute_always_follows (goto_number ***edgesp,
 static state ***
 ielr_compute_predecessors (void)
 {
-  state_number i;
   int *predecessor_counts = xnmalloc (nstates, sizeof *predecessor_counts);
   state ***result = xnmalloc (nstates, sizeof *result);
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     predecessor_counts[i] = 0;
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     {
       int j;
       for (j = 0; j < states[i]->transitions->num; ++j)
         ++predecessor_counts[states[i]->transitions->states[j]->number];
     }
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     {
       result[i] = xnmalloc (predecessor_counts[i]+1, sizeof *result[i]);
       result[i][predecessor_counts[i]] = NULL;
       predecessor_counts[i] = 0;
     }
-  for (i = 0; i < nstates; ++i)
-    {
-      int j;
-      for (j = 0; j < states[i]->transitions->num; ++j)
-        {
-          state_number k = states[i]->transitions->states[j]->number;
-          result[k][predecessor_counts[k]++] = states[i];
-        }
-    }
+  for (state_number i = 0; i < nstates; ++i)
+    for (int j = 0; j < states[i]->transitions->num; ++j)
+      {
+        state_number k = states[i]->transitions->states[j]->number;
+        result[k][predecessor_counts[k]++] = states[i];
+      }
   free (predecessor_counts);
   return result;
 }
@@ -354,11 +343,8 @@ ielr_compute_auxiliary_tables (bitsetv *follow_kernel_itemsp,
     bitset_free (ritem_sees_lookahead_set);
   }
   ielr_compute_always_follows (&edges, edge_counts, always_followsp);
-  {
-    int i;
-    for (i = 0; i < ngotos; ++i)
-      free (edges[i]);
-  }
+  for (int i = 0; i < ngotos; ++i)
+    free (edges[i]);
   free (edges);
   free (edge_counts);
   if (predecessorsp)
@@ -381,10 +367,9 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
 {
   if (!item_lookahead_sets[s->number])
     {
-      size_t i;
       item_lookahead_sets[s->number] =
         xnmalloc (s->nitems, sizeof item_lookahead_sets[s->number][0]);
-      for (i = 0; i < s->nitems; ++i)
+      for (size_t i = 0; i < s->nitems; ++i)
         item_lookahead_sets[s->number][i] = NULL;
     }
   if (!item_lookahead_sets[s->number][item])
@@ -416,16 +401,15 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
               for (i = s->items[item];
                    !item_number_is_rule_number (ritem[i]);
                    ++i)
-                ;
+                continue;
               lhs = rules[item_number_as_rule_number (ritem[i])].lhs->number;
             }
           /* If this kernel item is next to the beginning of the RHS, then
              check all predecessors' goto follows for the LHS.  */
           if (item_number_is_rule_number (ritem[s->items[item] - 2]))
             {
-              state **predecessor;
               aver (lhs != accept->content->number);
-              for (predecessor = predecessors[s->number];
+              for (state **predecessor = predecessors[s->number];
                    *predecessor;
                    ++predecessor)
                 bitset_or (item_lookahead_sets[s->number][item],
@@ -437,8 +421,7 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
              predecessor items' lookahead sets.  */
           else
             {
-              state **predecessor;
-              for (predecessor = predecessors[s->number];
+              for (state **predecessor = predecessors[s->number];
                    *predecessor;
                    ++predecessor)
                 {
@@ -493,11 +476,10 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
     xnmalloc (nstates, sizeof *annotation_counts);
   ContributionIndex max_contributions = 0;
   unsigned int total_annotations = 0;
-  state_number i;
 
   *inadequacy_listsp = xnmalloc (nstates, sizeof **inadequacy_listsp);
   *annotation_listsp = xnmalloc (nstates, sizeof **annotation_listsp);
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     {
       item_lookahead_sets[i] = NULL;
       (*inadequacy_listsp)[i] = NULL;
@@ -506,7 +488,7 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
     }
   {
     InadequacyListNodeCount inadequacy_list_node_count = 0;
-    for (i = 0; i < nstates; ++i)
+    for (state_number i = 0; i < nstates; ++i)
       AnnotationList__compute_from_inadequacies (
         states[i], follow_kernel_items, always_follows, predecessors,
         item_lookahead_sets, *inadequacy_listsp, *annotation_listsp,
@@ -514,7 +496,7 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
         &inadequacy_list_node_count);
   }
   *max_annotationsp = 0;
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     {
       if (annotation_counts[i] > *max_annotationsp)
         *max_annotationsp = annotation_counts[i];
@@ -522,7 +504,7 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
     }
   if (trace_flag & trace_ielr)
     {
-      for (i = 0; i < nstates; ++i)
+      for (state_number i = 0; i < nstates; ++i)
         {
           fprintf (stderr, "Inadequacy annotations for state %d:\n", i);
           AnnotationList__debug ((*annotation_listsp)[i],
@@ -536,11 +518,10 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
       fprintf (stderr, "Max number of contributions per annotation: %d\n",
                max_contributions);
     }
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     if (item_lookahead_sets[i])
       {
-        size_t j;
-        for (j = 0; j < states[i]->nitems; ++j)
+        for (size_t j = 0; j < states[i]->nitems; ++j)
           if (item_lookahead_sets[i][j])
             bitset_free (item_lookahead_sets[i][j]);
         free (item_lookahead_sets[i]);
@@ -615,9 +596,8 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
                          bitsetv lookaheads)
 {
   size_t s_item = 0;
-  size_t t_item;
   bitsetv_zero (lookaheads);
-  for (t_item = 0; t_item < t->nitems; ++t_item)
+  for (size_t t_item = 0; t_item < t->nitems; ++t_item)
     {
       /* If this kernel item is the beginning of a RHS, it must be the
          kernel item in the start state, but t is supposed to be a successor
@@ -771,15 +751,12 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
   }
 
   has_lookaheads = false;
-  {
-    size_t i;
-    for (i = 0; i < lr0_isocore->state->nitems; ++i)
-      if (!bitset_empty_p (lookaheads[i]))
-        {
-          has_lookaheads = true;
-          break;
-        }
-  }
+  for (size_t i = 0; i < lr0_isocore->state->nitems; ++i)
+    if (!bitset_empty_p (lookaheads[i]))
+      {
+        has_lookaheads = true;
+        break;
+      }
 
   /* Merge with an existing isocore.  */
   if (this_isocorep == &t->state_list || *this_isocorep != t->state_list)
@@ -822,11 +799,10 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
         (*this_isocorep)->recomputedAsSuccessor = true;
       else if (new_lookaheads)
         {
-          int i;
           /* When merging demands identical lookahead sets, it is impossible to
              merge new lookaheads.  */
           aver (annotation_lists);
-          for (i = 0; i < (*tp)->transitions->num; ++i)
+          for (int i = 0; i < (*tp)->transitions->num; ++i)
             {
               state *t2 = (*tp)->transitions->states[i];
               /* At any time, there's at most one state for which we have so
@@ -969,9 +945,8 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
   /* Set up state list and some reusable bitsets.  */
   {
     size_t max_nitems = 0;
-    state_number i;
     state_list **nodep = &first_state;
-    for (i = 0; i < nstates; ++i)
+    for (state_number i = 0; i < nstates; ++i)
       {
         *nodep = states[i]->state_list = last_state = xmalloc (sizeof **nodep);
         (*nodep)->state = states[i];
@@ -993,12 +968,12 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
   /* Recompute states.  */
   {
     ContributionIndex *work = xnmalloc (max_annotations, sizeof *work);
-    state_list *this_state;
-    for (this_state = first_state; this_state; this_state = this_state->next)
+    for (state_list *this_state = first_state;
+         this_state;
+         this_state = this_state->next)
       {
         state *s = this_state->state;
-        int i;
-        for (i = 0; i < s->transitions->num; ++i)
+        for (int i = 0; i < s->transitions->num; ++i)
           {
             state *t = s->transitions->states[i];
             if (annotation_lists)
@@ -1022,11 +997,8 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
 
   /* Store states back in the states array.  */
   states = xnrealloc (states, nstates, sizeof *states);
-  {
-    state_list *node;
-    for (node = first_state; node; node = node->next)
-      states[node->state->number] = node->state;
-  }
+  for (state_list *node = first_state; node; node = node->next)
+    states[node->state->number] = node->state;
 
   /* In the case of canonical LR(1), copy item lookahead sets to reduction
      lookahead sets.  */
@@ -1034,14 +1006,12 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
     {
       timevar_push (TV_IELR_PHASE4);
       initialize_LA ();
-      state_list *node;
-      for (node = first_state; node; node = node->next)
+      for (state_list *node = first_state; node; node = node->next)
         if (!node->state->consistent)
           {
             size_t i = 0;
             item_number *itemset = node->state->items;
-            size_t r;
-            for (r = 0; r < node->state->reductions->num; ++r)
+            for (size_t r = 0; r < node->state->reductions->num; ++r)
               {
                 rule *this_rule = node->state->reductions->rules[r];
                 bitset lookahead_set =
@@ -1149,11 +1119,8 @@ ielr (void)
                                          predecessors, &max_annotations,
                                          &inadequacy_lists, &annotation_lists,
                                          &annotations_obstack);
-          {
-            state_number i;
-            for (i = 0; i < nstates; ++i)
-              free (predecessors[i]);
-          }
+          for (state_number i = 0; i < nstates; ++i)
+            free (predecessors[i]);
           free (predecessors);
           bitsetv_free (goto_follows);
           lalr_free ();
@@ -1168,11 +1135,8 @@ ielr (void)
       ielr_split_states (follow_kernel_items, always_follows,
                          annotation_lists, max_annotations);
       if (inadequacy_lists)
-        {
-          state_number i;
-          for (i = 0; i < nstates_lr0; ++i)
-            InadequacyList__delete (inadequacy_lists[i]);
-        }
+        for (state_number i = 0; i < nstates_lr0; ++i)
+          InadequacyList__delete (inadequacy_lists[i]);
     }
     free (inadequacy_lists);
     if (annotation_lists)
