@@ -124,7 +124,6 @@ set_firsts (void)
   for (i = ntokens; i < nsyms; i++)
     {
       FIRSTS (i) = bitset_create (nvars, BITSET_FIXED);
-      bitset_zero (FIRSTS (i));
       for (j = 0; derives[i][j] >= 0; ++j)
 	{
 	  int symbol = ritem[rules[derives[i][j]].rhs];
@@ -157,10 +156,7 @@ set_fderives (void)
   fderives = XCALLOC (bitset, nvars);
   bitset_stats_init ();
   for (i = 0 ; i < nvars; ++i)
-    {
-      fderives[i] = bitset_create (nrules + 1, BITSET_FIXED);
-      bitset_zero (fderives[i]);
-    }
+    fderives[i] = bitset_create (nrules + 1, BITSET_FIXED);
 
   set_firsts ();
 
@@ -185,7 +181,6 @@ new_closure (int n)
   itemset = XCALLOC (short, n);
 
   ruleset = bitset_create (nrules + 1, BITSET_FIXED);
-  bitset_zero (ruleset);
 
   set_fderives ();
 }
