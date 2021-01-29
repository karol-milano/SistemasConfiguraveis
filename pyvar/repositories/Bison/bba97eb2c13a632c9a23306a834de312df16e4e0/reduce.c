@@ -118,7 +118,7 @@ useless_nonterminals (void)
 	if (!bitset_test (P, i)
 	    && useful_production (i, N))
 	  {
-	    bitset_set (Np, rules[i].lhs - ntokens);
+	    bitset_set (Np, rules[i].lhs->number - ntokens);
 	    bitset_set (P, i);
 	  }
       if (bitset_equal_p (N, Np))
@@ -178,7 +178,7 @@ inaccessable_symbols (void)
 	    {
 	      if (!bitset_test (Pp, i)
 		  && bitset_test (P, i)
-		  && bitset_test (V, rules[i].lhs))
+		  && bitset_test (V, rules[i].lhs->number))
 		{
 		  for (r = rules[i].rhs; *r >= 0; r++)
 		    if (ISTOKEN (t = *r) || bitset_test (N, t - ntokens))
@@ -307,6 +307,8 @@ nonterminals_reduce (void)
   {
     bucket **symbols_sorted = XMALLOC (bucket *, nvars) - ntokens;
 
+    for (i = ntokens; i < nsyms; i++)
+      symbols[i]->number = nontermmap[i];
     for (i = ntokens; i < nsyms; i++)
       symbols_sorted[nontermmap[i]] = symbols[i];
     for (i = ntokens; i < nsyms; i++)
@@ -318,7 +320,6 @@ nonterminals_reduce (void)
 
   for (i = 1; i < nrules + 1; i++)
     {
-      rules[i].lhs = nontermmap[rules[i].lhs];
       if (ISVAR (rules[i].precsym))
 	/* Can this happen?  */
 	rules[i].precsym = nontermmap[rules[i].precsym];
@@ -376,7 +377,7 @@ reduce_output (FILE *out)
 	{
 	  rule r;
 	  fprintf (out, "#%-4d  ", rules[i].number - 1);
-	  fprintf (out, "%s:", symbols[rules[i].lhs]->tag);
+	  fprintf (out, "%s:", rules[i].lhs->tag);
 	  for (r = rules[i].rhs; *r >= 0; r++)
 	    fprintf (out, " %s", symbols[*r]->tag);
 	  fputs (";\n", out);
@@ -414,7 +415,7 @@ dump_grammar (FILE *out)
 	       i - 1,
 	       rules[i].prec, rules[i].assoc, rules[i].useful,
 	       rules[i].rhs - ritem, rules[i].rhs - ritem + rhs_count - 1,
-	       rules[i].lhs);
+	       rules[i].lhs->number);
       /* Dumped the RHS. */
       for (r = rules[i].rhs; *r >= 0; r++)
 	fprintf (out, "%3d", *r);
@@ -424,7 +425,7 @@ dump_grammar (FILE *out)
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   for (i = 1; i < nrules + nuseless_productions + 1; i++)
     {
-      fprintf (out, "%-5d  %s :", i, symbols[rules[i].lhs]->tag);
+      fprintf (out, "%-5d  %s :", i, rules[i].lhs->tag);
       for (r = rules[i].rhs; *r >= 0; r++)
 	fprintf (out, " %s", symbols[*r]->tag);
       fputc ('\n', out);
