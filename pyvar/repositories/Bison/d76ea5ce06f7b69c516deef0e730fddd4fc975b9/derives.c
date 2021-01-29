@@ -40,11 +40,9 @@ rule ***derives;
 static void
 print_derives (void)
 {
-  int i;
-
   fputs ("DERIVES\n", stderr);
 
-  for (i = ntokens; i < nsyms; i++)
+  for (symbol_number i = ntokens; i < nsyms; ++i)
     {
       fprintf (stderr, "  %s derives\n", symbols[i]->tag);
       for (rule **rp = derives[i - ntokens]; *rp; ++rp)
@@ -88,7 +86,7 @@ derives_compute (void)
   /* Q is the storage for DERIVES[...] (DERIVES[0] = q).  */
   rule **q = xnmalloc (nvars + nrules, sizeof *q);
 
-  for (symbol_number i = ntokens; i < nsyms; i++)
+  for (symbol_number i = ntokens; i < nsyms; ++i)
     {
       rule_list *p = dset[i - ntokens];
       derives[i - ntokens] = q;
