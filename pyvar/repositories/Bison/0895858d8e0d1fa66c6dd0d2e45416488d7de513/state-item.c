@@ -336,7 +336,7 @@ bitsetv firsts = NULL;
 static void
 init_firsts (void)
 {
-  firsts = bitsetv_create (nvars, nsyms, BITSET_FIXED);
+  firsts = bitsetv_create (nnterms, nsyms, BITSET_FIXED);
   for (rule_number i = 0; i < nrules; ++i)
     {
       rule *r = rules + i;
