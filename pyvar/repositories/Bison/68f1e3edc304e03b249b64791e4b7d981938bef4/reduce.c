@@ -310,20 +310,12 @@ reduce_grammar_tables (void)
 
     }
 #endif /* 0 */
-  /* Disable useless productions,
-     since they may contain useless nonterms
-     that would get mapped below to -1 and confuse everyone.  */
+  /* Disable useless productions. */
   if (nuseless_productions > 0)
     {
       int pn;
-
       for (pn = 1; pn <= nrules; pn++)
-	{
-	  if (!BITISSET (P, pn))
-	    {
-	      rule_table[pn].lhs = -1;
-	    }
-	}
+	rule_table[pn].useful = BITISSET (P, pn);
     }
 }
 
@@ -338,8 +330,8 @@ nonterminals_reduce (void)
   int i, n;
   rule r;
 
-  /* Create a map of nonterminal number to new nonterminal number. -1
-     in the map means it was useless and is being eliminated.  */
+  /* Map the nonterminals to their new index: useful first, useless
+     afterwards.  Kept for later report.  */
 
   short *nontermmap = XCALLOC (short, nvars) - ntokens;
   n = ntokens;
@@ -379,9 +371,7 @@ nonterminals_reduce (void)
 
   for (i = 1; i <= nrules; i++)
     {
-      /* Ignore the rules disabled above.  */
-      if (rule_table[i].lhs >= 0)
-	rule_table[i].lhs = nontermmap[rule_table[i].lhs];
+      rule_table[i].lhs = nontermmap[rule_table[i].lhs];
       if (ISVAR (rule_table[i].precsym))
 	/* Can this happen?  */
 	rule_table[i].precsym = nontermmap[rule_table[i].precsym];
@@ -396,7 +386,7 @@ nonterminals_reduce (void)
   nsyms -= nuseless_nonterminals;
   nvars -= nuseless_nonterminals;
 
-  free (&nontermmap[ntokens]);
+  free (nontermmap + ntokens);
 }
 
 
@@ -436,11 +426,11 @@ reduce_output (FILE *out)
       int i;
       fprintf (out, "%s\n\n", _("Useless rules:"));
       for (i = 1; i <= nrules; i++)
-	if (!BITISSET (P, i))
+	if (!rule_table[i].useful)
 	  {
 	    rule r;
 	    fprintf (out, "#%-4d  ", i);
-	    fprintf (out, "%s :\t", tags[rule_table[i].lhs]);
+	    fprintf (out, "%s:", tags[rule_table[i].lhs]);
 	    for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
 	      fprintf (out, " %s", tags[*r]);
 	    fputs (";\n", out);
