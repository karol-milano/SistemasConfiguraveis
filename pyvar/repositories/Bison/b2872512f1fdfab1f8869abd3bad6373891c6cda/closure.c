@@ -26,9 +26,9 @@
 #include "derives.h"
 #include "warshall.h"
 
-/* ITEMSETSIZE is the size of the array ITEMSET.  */
+/* NITEMSET is the size of the array ITEMSET.  */
 short *itemset;
-int itemsetsize;
+int nitemset;
 
 static unsigned *ruleset;
 
@@ -218,7 +218,7 @@ closure (short *core, int n)
 	    ruleset[r] |= FDERIVES (ritem[core[c]])[r];
     }
 
-  itemsetsize = 0;
+  nitemset = 0;
   c = 0;
   for (ruleno = 0; ruleno < rulesetsize * BITS_PER_WORD; ++ruleno)
     if (BITISSET (ruleset, ruleno))
@@ -226,23 +226,23 @@ closure (short *core, int n)
 	int itemno = rule_table[ruleno].rhs;
 	while (c < n && core[c] < itemno)
 	  {
-	    itemset[itemsetsize] = core[c];
-	    itemsetsize++;
+	    itemset[nitemset] = core[c];
+	    nitemset++;
 	    c++;
 	  }
-	itemset[itemsetsize] = itemno;
-	itemsetsize++;
+	itemset[nitemset] = itemno;
+	nitemset++;
       }
 
   while (c < n)
     {
-      itemset[itemsetsize] = core[c];
-      itemsetsize++;
+      itemset[nitemset] = core[c];
+      nitemset++;
       c++;
     }
 
   if (trace_flag)
-    print_closure ("output", itemset, itemsetsize);
+    print_closure ("output", itemset, nitemset);
 }
 
 
