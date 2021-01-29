@@ -150,7 +150,7 @@ new_itemsets (void)
 
   shiftcount = 0;
 
-  for (i = 0; i < itemsetend - itemset; ++i)
+  for (i = 0; i < itemsetsize; ++i)
     {
       int symbol = ritem[itemset[i]];
       if (symbol > 0)
@@ -544,19 +544,15 @@ augment_automaton (void)
 static void
 save_reductions (void)
 {
-  short *isp;
-  int item;
   int count;
-  reductions *p;
-
-  short *rend;
+  int i;
 
   /* Find and count the active items that represent ends of rules. */
 
   count = 0;
-  for (isp = itemset; isp < itemsetend; isp++)
+  for (i = 0; i < itemsetsize; ++i)
     {
-      item = ritem[*isp];
+      int item = ritem[itemset[i]];
       if (item < 0)
 	redset[count++] = -item;
     }
@@ -565,7 +561,7 @@ save_reductions (void)
 
   if (count)
     {
-      p = REDUCTIONS_ALLOC (count);
+      reductions *p = REDUCTIONS_ALLOC (count);
 
       p->number = this_state->number;
       p->nreds = count;
