@@ -125,9 +125,9 @@ set_firsts (void)
   firsts = bitsetv_create (nvars, nvars, BITSET_FIXED);
 
   for (i = ntokens; i < nsyms; i++)
-    for (j = 0; derives[i][j] >= 0; ++j)
+    for (j = 0; derives[i][j]; ++j)
       {
-	int symbol = rules[derives[i][j]].rhs[0];
+	int symbol = derives[i][j]->rhs[0];
 	if (ISVAR (symbol))
 	  bitset_set (FIRSTS (i), symbol - ntokens);
       }
@@ -165,8 +165,8 @@ set_fderives (void)
   for (i = ntokens; i < nsyms; ++i)
     for (j = ntokens; j < nsyms; ++j)
       if (bitset_test (FIRSTS (i), j - ntokens))
-	for (k = 0; derives[j][k] >= 0; ++k)
-	  bitset_set (FDERIVES (i), derives[j][k]);
+	for (k = 0; derives[j][k]; ++k)
+	  bitset_set (FDERIVES (i), derives[j][k]->number);
 
   if (trace_flag & trace_sets)
     print_fderives ();
