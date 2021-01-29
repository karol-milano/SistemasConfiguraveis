@@ -128,9 +128,9 @@ set_firsts (void)
   firsts = bitsetv_create (nvars, nvars, BITSET_FIXED);
 
   for (i = ntokens; i < nsyms; i++)
-    for (j = 0; derives[i][j]; ++j)
+    for (j = 0; derives[i - ntokens][j]; ++j)
       {
-	item_number sym = derives[i][j]->rhs[0];
+	item_number sym = derives[i - ntokens][j]->rhs[0];
 	if (ISVAR (sym))
 	  bitset_set (FIRSTS (i), sym - ntokens);
       }
@@ -168,8 +168,8 @@ set_fderives (void)
   for (i = ntokens; i < nsyms; ++i)
     for (j = ntokens; j < nsyms; ++j)
       if (bitset_test (FIRSTS (i), j - ntokens))
-	for (k = 0; derives[j][k]; ++k)
-	  bitset_set (FDERIVES (i), derives[j][k]->number);
+	for (k = 0; derives[j - ntokens][k]; ++k)
+	  bitset_set (FDERIVES (i), derives[j - ntokens][k]->number);
 
   if (trace_flag & trace_sets)
     print_fderives ();
@@ -182,7 +182,7 @@ set_fderives (void)
 void
 new_closure (int n)
 {
-  itemset = XCALLOC (item_number, n);
+  CALLOC (itemset, n);
 
   ruleset = bitset_create (nrules, BITSET_FIXED);
 
@@ -241,7 +241,7 @@ closure (item_number *core, int n)
 void
 free_closure (void)
 {
-  XFREE (itemset);
+  free (itemset);
   bitset_free (ruleset);
   bitsetv_free (fderives);
 }
