@@ -37,7 +37,7 @@
 
 /* NITEMSET is the size of the array ITEMSET.  */
 item_number *itemset;
-size_t nritemset;
+size_t nitemset;
 
 static bitset ruleset;
 
@@ -213,30 +213,30 @@ closure (item_number *core, size_t n)
     if (ISVAR (ritem[core[c]]))
       bitset_or (ruleset, ruleset, FDERIVES (ritem[core[c]]));
 
-  nritemset = 0;
+  nitemset = 0;
   c = 0;
   BITSET_FOR_EACH (iter, ruleset, ruleno, 0)
     {
       item_number itemno = rules[ruleno].rhs - ritem;
       while (c < n && core[c] < itemno)
 	{
-	  itemset[nritemset] = core[c];
-	  nritemset++;
+	  itemset[nitemset] = core[c];
+	  nitemset++;
 	  c++;
 	}
-      itemset[nritemset] = itemno;
-      nritemset++;
+      itemset[nitemset] = itemno;
+      nitemset++;
     };
 
   while (c < n)
     {
-      itemset[nritemset] = core[c];
-      nritemset++;
+      itemset[nitemset] = core[c];
+      nitemset++;
       c++;
     }
 
   if (trace_flag & trace_sets)
-    print_closure ("output", itemset, nritemset);
+    print_closure ("output", itemset, nitemset);
 }
 
 
