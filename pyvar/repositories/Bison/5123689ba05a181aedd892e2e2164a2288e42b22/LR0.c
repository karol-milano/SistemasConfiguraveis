@@ -160,7 +160,7 @@ new_itemsets (void)
 
   nshifts = 0;
 
-  for (i = 0; i < nitemset; ++i)
+  for (i = 0; i < nritemset; ++i)
     {
       int symbol = ritem[itemset[i]];
       if (symbol >= 0)
@@ -363,7 +363,7 @@ save_reductions (void)
     return;
 
   /* Find and count the active items that represent ends of rules. */
-  for (i = 0; i < nitemset; ++i)
+  for (i = 0; i < nritemset; ++i)
     {
       int item = ritem[itemset[i]];
       if (item < 0)
