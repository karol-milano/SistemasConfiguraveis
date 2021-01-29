@@ -158,14 +158,14 @@ set_fderives (void)
   symbol_number_t i, j;
   rule_number_t k;
 
-  fderives = bitsetv_create (nvars, nrules + 1, BITSET_FIXED);
+  fderives = bitsetv_create (nvars, nrules, BITSET_FIXED);
 
   set_firsts ();
 
   for (i = ntokens; i < nsyms; ++i)
     for (j = ntokens; j < nsyms; ++j)
       if (bitset_test (FIRSTS (i), j - ntokens))
-	for (k = 0; derives[j][k] > 0; ++k)
+	for (k = 0; derives[j][k] >= 0; ++k)
 	  bitset_set (FDERIVES (i), derives[j][k]);
 
   if (trace_flag)
@@ -181,7 +181,7 @@ new_closure (int n)
 {
   itemset = XCALLOC (item_number_t, n);
 
-  ruleset = bitset_create (nrules + 1, BITSET_FIXED);
+  ruleset = bitset_create (nrules, BITSET_FIXED);
 
   set_fderives ();
 }
