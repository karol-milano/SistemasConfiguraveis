@@ -78,7 +78,7 @@ static bitset
 ielr_compute_ritem_sees_lookahead_set (void)
 {
   bitset result = bitset_create (nritems, BITSET_FIXED);
-  unsigned i = nritems-1;
+  int i = nritems-1;
   while (0 < i)
     {
       --i;
@@ -418,7 +418,7 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
              top-level invocation), go get it.  */
           if (!lhs)
             {
-              unsigned i;
+              int i;
               for (i = s->items[item];
                    !item_number_is_rule_number (ritem[i]);
                    ++i)
@@ -496,7 +496,7 @@ ielr_compute_annotation_lists (bitsetv follow_kernel_items,
   AnnotationIndex *annotation_counts =
     xnmalloc (nstates, sizeof *annotation_counts);
   ContributionIndex max_contributions = 0;
-  unsigned total_annotations = 0;
+  int total_annotations = 0;
 
   *inadequacy_listsp = xnmalloc (nstates, sizeof **inadequacy_listsp);
   *annotation_listsp = xnmalloc (nstates, sizeof **annotation_listsp);
@@ -633,7 +633,7 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
         {
           if (item_number_is_rule_number (ritem[t->items[t_item] - 2]))
             {
-              unsigned rule_item;
+              int rule_item;
               for (rule_item = t->items[t_item];
                    !item_number_is_rule_number (ritem[rule_item]);
                    ++rule_item)
