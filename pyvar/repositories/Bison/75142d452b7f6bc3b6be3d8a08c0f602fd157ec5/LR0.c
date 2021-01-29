@@ -68,8 +68,8 @@ allocate_itemsets (void)
   int count = 0;
   short *symbol_count = XCALLOC (short, nsyms + nuseless_nonterminals);
 
-  for (i = 0; ritem[i]; ++i)
-    if (ritem[i] > 0)
+  for (i = 0; i < nritems; ++i)
+    if (ritem[i] >= 0)
       {
 	count++;
 	symbol_count[ritem[i]]++;
@@ -152,7 +152,7 @@ new_itemsets (void)
   for (i = 0; i < nitemset; ++i)
     {
       int symbol = ritem[itemset[i]];
-      if (symbol > 0)
+      if (symbol >= 0)
 	{
 	  if (!kernel_size[symbol])
 	    {
