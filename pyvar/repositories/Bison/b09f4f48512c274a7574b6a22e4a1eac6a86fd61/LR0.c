@@ -183,8 +183,8 @@ new_itemsets (state *s)
 
   nshifts = 0;
 
-  for (i = 0; i < nritemset; ++i)
-    if (ritem[itemset[i]] >= 0)
+  for (i = 0; i < nitemset; ++i)
+    if (item_number_is_symbol_number (ritem[itemset[i]]))
       {
 	symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
 	if (!kernel_size[sym])
@@ -272,7 +272,7 @@ save_reductions (state *s)
   size_t i;
 
   /* Find and count the active items that represent ends of rules. */
-  for (i = 0; i < nritemset; ++i)
+  for (i = 0; i < nitemset; ++i)
     {
       item_number item = ritem[itemset[i]];
       if (item_number_is_rule_number (item))
