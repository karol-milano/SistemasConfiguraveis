@@ -244,18 +244,11 @@ closure (short *core, int n)
   if (trace_flag)
     print_closure ("input", core, n);
 
-  if (n == 0)
-    {
-      bitset_copy (ruleset, FDERIVES (start_symbol));
-    }
-  else
-    {
-      bitset_zero (ruleset);
+  bitset_zero (ruleset);
 
-      for (c = 0; c < n; ++c)
-	if (ISVAR (ritem[core[c]]))
-	  bitset_or (ruleset, ruleset, FDERIVES (ritem[core[c]]));
-    }
+  for (c = 0; c < n; ++c)
+    if (ISVAR (ritem[core[c]]))
+      bitset_or (ruleset, ruleset, FDERIVES (ritem[core[c]]));
 
   nitemset = 0;
   c = 0;
