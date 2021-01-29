@@ -114,7 +114,7 @@ useless_nonterminals (void)
   while (1)
     {
       bitset_copy (Np, N);
-      for (i = 1; i <= nrules; i++)
+      for (i = 1; i < nrules + 1; i++)
 	if (!bitset_test (P, i)
 	    && useful_production (i, N))
 	  {
@@ -174,7 +174,7 @@ inaccessable_symbols (void)
       while (1)
 	{
 	  bitset_copy (Vp, V);
-	  for (i = 1; i <= nrules; i++)
+	  for (i = 1; i < nrules + 1; i++)
 	    {
 	      if (!bitset_test (Pp, i)
 		  && bitset_test (P, i)
@@ -241,7 +241,7 @@ reduce_grammar_tables (void)
 
 	np = 0;
 	ni = 0;
-	for (pn = 1; pn <= nrules; pn++)
+	for (pn = 1; pn < nrules + 1; pn++)
 	  if (bitset_test (P, pn))
 	    {
 	      np++;
@@ -281,7 +281,7 @@ reduce_grammar_tables (void)
   if (nuseless_productions > 0)
     {
       int pn;
-      for (pn = 1; pn <= nrules; pn++)
+      for (pn = 1; pn < nrules + 1; pn++)
 	rules[pn].useful = bitset_test (P, pn);
     }
 }
@@ -322,7 +322,7 @@ nonterminals_reduce (void)
 
   /* Replace all symbol numbers in valid data structures.  */
 
-  for (i = 1; i <= nrules; i++)
+  for (i = 1; i < nrules + 1; i++)
     {
       rules[i].lhs = nontermmap[rules[i].lhs];
       if (ISVAR (rules[i].precsym))
@@ -378,7 +378,7 @@ reduce_output (FILE *out)
     {
       int i;
       fprintf (out, "%s\n\n", _("Useless rules:"));
-      for (i = 1; i <= nrules; i++)
+      for (i = 1; i < nrules + 1; i++)
 	if (!rules[i].useful)
 	  {
 	    rule r;
@@ -411,7 +411,7 @@ dump_grammar (FILE *out)
   fprintf (out, "\n\n");
   fprintf (out, "Rules\n-----\n\n");
   fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
-  for (i = 1; i <= nrules; i++)
+  for (i = 1; i < nrules + 1; i++)
     {
       int rhs_count = 0;
       /* Find the last RHS index in ritems. */
@@ -429,7 +429,7 @@ dump_grammar (FILE *out)
     }
   fprintf (out, "\n\n");
   fprintf (out, "Rules interpreted\n-----------------\n\n");
-  for (i = 1; i <= nrules; i++)
+  for (i = 1; i < nrules + 1; i++)
     {
       fprintf (out, "%-5d  %s :", i, symbols[rules[i].lhs]->tag);
       for (r = rules[i].rhs; *r >= 0; r++)
