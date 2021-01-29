@@ -50,7 +50,7 @@ ielr_compute_ritem_sees_lookahead_set (void)
 {
   bitset result = bitset_create (nritems, BITSET_FIXED);
   unsigned i = nritems-1;
-  while (i>0)
+  while (0 < i)
     {
       --i;
       while (!item_number_is_rule_number (ritem[i])
@@ -59,7 +59,7 @@ ielr_compute_ritem_sees_lookahead_set (void)
         bitset_set (result, i--);
       if (!item_number_is_rule_number (ritem[i]) && ISVAR (ritem[i]))
         bitset_set (result, i--);
-      while (!item_number_is_rule_number (ritem[i]) && i>0)
+      while (!item_number_is_rule_number (ritem[i]) && 0 < i)
         --i;
     }
   if (trace_flag & trace_ielr)
@@ -205,8 +205,7 @@ ielr_compute_follow_kernel_items (bitset ritem_sees_lookahead_set,
     {
       size_t nitems = states[from_state[i]]->nitems;
       item_number *items = states[from_state[i]]->items;
-      size_t j;
-      for (j = 0; j < nitems; ++j)
+      for (size_t j = 0; j < nitems; ++j)
         /* If this item has this goto and if all subsequent symbols in this
            RHS (if any) are nullable nonterminals, then record this item as
            one whose lookahead set is included in this goto's follows.  */
@@ -298,11 +297,8 @@ ielr_compute_predecessors (void)
   for (state_number i = 0; i < nstates; ++i)
     predecessor_counts[i] = 0;
   for (state_number i = 0; i < nstates; ++i)
-    {
-      int j;
-      for (j = 0; j < states[i]->transitions->num; ++j)
-        ++predecessor_counts[states[i]->transitions->states[j]->number];
-    }
+    for (int j = 0; j < states[i]->transitions->num; ++j)
+      ++predecessor_counts[states[i]->transitions->states[j]->number];
   for (state_number i = 0; i < nstates; ++i)
     {
       result[i] = xnmalloc (predecessor_counts[i]+1, sizeof *result[i]);
@@ -530,7 +526,8 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
   free (annotation_counts);
 }
 
-typedef struct state_list {
+typedef struct state_list
+{
   struct state_list *next;
   state *state;
   /** Has this state been recomputed as a successor of another state?  */
@@ -683,7 +680,6 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
 {
   state_list *lr0_isocore = t->state_list->lr0Isocore;
   state_list **this_isocorep;
-  bool has_lookaheads;
 
   /* Determine whether there's an isocore of t with which these lookaheads can
      be merged.  */
@@ -750,7 +746,7 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
       }
   }
 
-  has_lookaheads = false;
+  bool has_lookaheads = false;
   for (size_t i = 0; i < lr0_isocore->state->nitems; ++i)
     if (!bitset_empty_p (lookaheads[i]))
       {
@@ -894,10 +890,9 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
       (*last_statep)->lookaheads = NULL;
       if (has_lookaheads)
         {
-          size_t i;
           (*last_statep)->lookaheads =
             xnmalloc (t->nitems, sizeof (*last_statep)->lookaheads);
-          for (i = 0; i < t->nitems; ++i)
+          for (size_t i = 0; i < t->nitems; ++i)
             {
               if (bitset_empty_p (lookaheads[i]))
                 (*last_statep)->lookaheads[i] = NULL;
@@ -1046,8 +1041,7 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
       state_list *node = first_state;
       if (node->lookaheads)
         {
-          size_t i;
-          for (i = 0; i < node->state->nitems; ++i)
+          for (size_t i = 0; i < node->state->nitems; ++i)
             if (node->lookaheads[i])
               bitset_free (node->lookaheads[i]);
           free (node->lookaheads);
