@@ -49,7 +49,7 @@ static bitset
 ielr_compute_ritem_sees_lookahead_set (void)
 {
   bitset result = bitset_create (nritems, BITSET_FIXED);
-  unsigned int i = nritems-1;
+  unsigned i = nritems-1;
   while (i>0)
     {
       --i;
@@ -397,7 +397,7 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
              top-level invocation), go get it.  */
           if (!lhs)
             {
-              unsigned int i;
+              unsigned i;
               for (i = s->items[item];
                    !item_number_is_rule_number (ritem[i]);
                    ++i)
@@ -475,7 +475,7 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
   AnnotationIndex *annotation_counts =
     xnmalloc (nstates, sizeof *annotation_counts);
   ContributionIndex max_contributions = 0;
-  unsigned int total_annotations = 0;
+  unsigned total_annotations = 0;
 
   *inadequacy_listsp = xnmalloc (nstates, sizeof **inadequacy_listsp);
   *annotation_listsp = xnmalloc (nstates, sizeof **annotation_listsp);
@@ -611,7 +611,7 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
         {
           if (item_number_is_rule_number (ritem[t->items[t_item] - 2]))
             {
-              unsigned int rule_item;
+              unsigned rule_item;
               for (rule_item = t->items[t_item];
                    !item_number_is_rule_number (ritem[rule_item]);
                    ++rule_item)
