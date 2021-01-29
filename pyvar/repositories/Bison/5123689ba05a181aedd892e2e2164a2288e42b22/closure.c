@@ -31,7 +31,7 @@
 
 /* NITEMSET is the size of the array ITEMSET.  */
 short *itemset;
-int nitemset;
+int nritemset;
 
 static bitset ruleset;
 
@@ -258,7 +258,7 @@ closure (short *core, int n)
     if (ISVAR (ritem[core[c]]))
       bitset_or (ruleset, ruleset, FDERIVES (ritem[core[c]]));
 
-  nitemset = 0;
+  nritemset = 0;
   c = 0;
   for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
     if (bitset_test (ruleset, ruleno))
@@ -266,23 +266,23 @@ closure (short *core, int n)
 	int itemno = rules[ruleno].rhs - ritem;
 	while (c < n && core[c] < itemno)
 	  {
-	    itemset[nitemset] = core[c];
-	    nitemset++;
+	    itemset[nritemset] = core[c];
+	    nritemset++;
 	    c++;
 	  }
-	itemset[nitemset] = itemno;
-	nitemset++;
+	itemset[nritemset] = itemno;
+	nritemset++;
       }
 
   while (c < n)
     {
-      itemset[nitemset] = core[c];
-      nitemset++;
+      itemset[nritemset] = core[c];
+      nritemset++;
       c++;
     }
 
   if (trace_flag)
-    print_closure ("output", itemset, nitemset);
+    print_closure ("output", itemset, nritemset);
 }
 
 
