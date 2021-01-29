@@ -26,8 +26,10 @@
 #include "derives.h"
 #include "warshall.h"
 
+/* ITEMSETSIZE is the size of the array ITEMSET.  */
 short *itemset;
-short *itemsetend;
+size_t itemsetsize;
+
 static unsigned *ruleset;
 
 /* internal data.  See comments before set_fderives and set_firsts.  */
@@ -51,11 +53,10 @@ static int varsetsize;
 static void
 print_closure (int n)
 {
-  short *isp;
-
+  int i;
   fprintf (stderr, "n = %d\n", n);
-  for (isp = itemset; isp < itemsetend; isp++)
-    fprintf (stderr, "   %d\n", *isp);
+  for (i = 0; i < itemsetsize; ++i)
+    fprintf (stderr, "   %d\n", itemset[i]);
   fprintf (stderr, "\n\n");
 }
 
@@ -265,9 +266,9 @@ closure (short *core, int n)
     }
 
   ruleno = 0;
-  itemsetend = itemset;
+  itemsetsize = 0;
   csp = core;
-  for (i= 0; i < rulesetsize; ++i)
+  for (i = 0; i < rulesetsize; ++i)
     {
       int word = ruleset[i];
       if (word == 0)
@@ -283,9 +284,9 @@ closure (short *core, int n)
 	      if (word & (1 << b))
 		{
 		  itemno = rule_table[ruleno].rhs;
-		  while (csp < (core + n ) && *csp < itemno)
-		    *itemsetend++ = *csp++;
-		  *itemsetend++ = itemno;
+		  while (csp < (core + n) && *csp < itemno)
+		    itemset[itemsetsize++] = *csp++;
+		  itemset[itemsetsize++] = itemno;
 		}
 
 	      ruleno++;
@@ -294,7 +295,7 @@ closure (short *core, int n)
     }
 
   while (csp < (core + n))
-    *itemsetend++ = *csp++;
+    itemset[itemsetsize++] = *csp++;
 
   if (trace_flag)
     print_closure (n);
