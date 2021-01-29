@@ -77,12 +77,11 @@ AnnotationList__isContributionAlways (AnnotationList const *self,
  *   - Otherwise, \c list now contains the node \c self, \c result is true, and
  *     \c list assumes responsibility for the memory of \c self.
  *   - The sort in \c list is:
- *     - Sort in reverse order on memory address of the associated inadequacy
- *       node.  Because memory is usually allocated in ascending order (FIXME:
- *       Is this true enough?  Should we keep some sort of global index to
- *       guarantee it?), this should mean that the insertion position within an
- *       annotation list is usually near the beginning with other annotations
- *       associated with the same inadequacy.
+ *     - Sort in reverse order on the unique ID of the associated
+ *       inadequacy node.  Because these IDs are assigned in ascending
+ *       order, this should mean that the insertion position within an
+ *       annotation list is usually near the beginning with other
+ *       annotations associated with the same inadequacy.
  *     - Next, sort on the first contribution that is different as follows:
  *       - Sort an always-contribution before a never-contribution before a
  *         potential-contribution.
@@ -104,9 +103,9 @@ AnnotationList__insertInto (AnnotationList *self, AnnotationList **list,
     {
       int cmp = 0;
       ContributionIndex ci;
-      if (self->inadequacyNode < (*node)->inadequacyNode)
+      if (self->inadequacyNode->id < (*node)->inadequacyNode->id)
         cmp = 1;
-      else if ((*node)->inadequacyNode < self->inadequacyNode)
+      else if ((*node)->inadequacyNode->id < self->inadequacyNode->id)
         cmp = -1;
       else
         for (ci = 0;
@@ -408,18 +407,14 @@ AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
 }
 
 void
-AnnotationList__compute_from_inadequacies (state *s,
-                                           bitsetv follow_kernel_items,
-                                           bitsetv always_follows,
-                                           state ***predecessors,
-                                           bitset **item_lookahead_sets,
-                                           InadequacyList **inadequacy_lists,
-                                           AnnotationList **annotation_lists,
-                                           AnnotationIndex *annotation_counts,
-                                           ContributionIndex
-                                             *max_contributionsp,
-                                           struct obstack
-                                             *annotations_obstackp)
+AnnotationList__compute_from_inadequacies (
+  state *s, bitsetv follow_kernel_items, bitsetv always_follows,
+  state ***predecessors, bitset **item_lookahead_sets,
+  InadequacyList **inadequacy_lists, AnnotationList **annotation_lists,
+  AnnotationIndex *annotation_counts,
+  ContributionIndex *max_contributionsp,
+  struct obstack *annotations_obstackp,
+  InadequacyListNodeCount *inadequacy_list_node_count)
 {
   bitsetv all_lookaheads;
   bitset shift_tokens;
@@ -530,8 +525,9 @@ AnnotationList__compute_from_inadequacies (state *s,
             }
           {
             InadequacyList *conflict_node =
-              InadequacyList__new_conflict (s, symbols[conflicted_token],
-                                            actions);
+              InadequacyList__new_conflict (
+                s, symbols[conflicted_token], actions,
+                inadequacy_list_node_count);
             actions = NULL;
             annotation_node->inadequacyNode = conflict_node;
             if (ContributionIndex__none
