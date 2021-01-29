@@ -141,7 +141,6 @@ static void
 new_itemsets (void)
 {
   int i;
-  int shiftcount;
 
   if (trace_flag)
     fprintf (stderr, "Entering new_itemsets, state = %d\n",
@@ -151,25 +150,23 @@ new_itemsets (void)
     kernel_size[i] = 0;
 
   shift_symbol = XCALLOC (short, nsyms);
-  shiftcount = 0;
+  nshifts = 0;
 
-  for (i = 0; i < itemsetsize; ++i)
+  for (i = 0; i < nitemset; ++i)
     {
       int symbol = ritem[itemset[i]];
       if (symbol > 0)
 	{
 	  if (!kernel_size[symbol])
 	    {
-	      shift_symbol[shiftcount] = symbol;
-	      shiftcount++;
+	      shift_symbol[nshifts] = symbol;
+	      nshifts++;
 	    }
 
 	  kernel_base[symbol][kernel_size[symbol]] = itemset[i] + 1;
 	  kernel_size[symbol]++;
 	}
     }
-
-  nshifts = shiftcount;
 }
 
 
@@ -542,7 +539,7 @@ save_reductions (void)
   /* Find and count the active items that represent ends of rules. */
 
   count = 0;
-  for (i = 0; i < itemsetsize; ++i)
+  for (i = 0; i < nitemset; ++i)
     {
       int item = ritem[itemset[i]];
       if (item < 0)
