@@ -100,7 +100,7 @@ useful_production (int i, BSet N0)
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
 
-  for (r = &ritem[rrhs[i]]; *r > 0; r++)
+  for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
     if (ISVAR (n = *r))
       if (!BITISSET (N0, n - ntokens))
 	return FALSE;
@@ -149,7 +149,7 @@ useless_nonterminals (void)
 	    {
 	      if (useful_production (i, N))
 		{
-		  SETBIT (Np, rlhs[i] - ntokens);
+		  SETBIT (Np, rule_table[i].lhs - ntokens);
 		  SETBIT (P, i);
 		}
 	    }
@@ -211,9 +211,9 @@ inaccessable_symbols (void)
 	Vp[i] = V[i];
       for (i = 1; i <= nrules; i++)
 	{
-	  if (!BITISSET (Pp, i) && BITISSET (P, i) && BITISSET (V, rlhs[i]))
+	  if (!BITISSET (Pp, i) && BITISSET (P, i) && BITISSET (V, rule_table[i].lhs))
 	    {
-	      for (r = &ritem[rrhs[i]]; *r >= 0; r++)
+	      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
 		{
 		  if (ISTOKEN (t = *r) || BITISSET (N, t - ntokens))
 		    {
@@ -279,15 +279,15 @@ reduce_grammar_tables (void)
 	      np++;
 	      if (pn != np)
 		{
-		  rlhs[np] = rlhs[pn];
+		  rule_table[np].lhs = rule_table[pn].lhs;
 		  rline[np] = rline[pn];
 		  rprec[np] = rprec[pn];
 		  rassoc[np] = rassoc[pn];
-		  rrhs[np] = rrhs[pn];
-		  if (rrhs[np] != ni)
+		  rule_table[np].rhs = rule_table[pn].rhs;
+		  if (rule_table[np].rhs != ni)
 		    {
-		      pi = rrhs[np];
-		      rrhs[np] = ni;
+		      pi = rule_table[np].rhs;
+		      rule_table[np].rhs = ni;
 		      while (ritem[pi] >= 0)
 			ritem[ni++] = ritem[pi++];
 		      ritem[ni++] = -np;
@@ -319,7 +319,7 @@ reduce_grammar_tables (void)
 	{
 	  if (!BITISSET (P, pn))
 	    {
-	      rlhs[pn] = -1;
+	      rule_table[pn].lhs = -1;
 	    }
 	}
     }
@@ -368,8 +368,8 @@ reduce_grammar_tables (void)
       for (i = 1; i <= nrules; i++)
 	{
 	  /* Ignore the rules disabled above.  */
-	  if (rlhs[i] >= 0)
-	    rlhs[i] = nontermmap[rlhs[i]];
+	  if (rule_table[i].lhs >= 0)
+	    rule_table[i].lhs = nontermmap[rule_table[i].lhs];
 	  if (ISVAR (rprecsym[i]))
 	    /* Can this happen?  */
 	    rprecsym[i] = nontermmap[rprecsym[i]];
@@ -434,8 +434,8 @@ reduce_output (FILE *out)
 	  if (!BITISSET (P, i))
 	    {
 	      fprintf (out, "#%-4d  ", i);
-	      fprintf (out, "%s :\t", tags[rlhs[i]]);
-	      for (r = &ritem[rrhs[i]]; *r >= 0; r++)
+	      fprintf (out, "%s :\t", tags[rule_table[i].lhs]);
+	      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
 		fprintf (out, " %s", tags[*r]);
 	      fprintf (out, ";\n");
 	    }
@@ -464,8 +464,8 @@ dump_grammar (FILE *out)
   for (i = 1; i <= nrules; i++)
     {
       fprintf (out, "%-5d(%5d%5d)%5d : (@%-5d)",
-	       i, rprec[i], rassoc[i], rlhs[i], rrhs[i]);
-      for (r = &ritem[rrhs[i]]; *r > 0; r++)
+	       i, rprec[i], rassoc[i], rule_table[i].lhs, rule_table[i].rhs);
+      for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
 	fprintf (out, "%5d", *r);
       fprintf (out, " [%d]\n", -(*r));
     }
@@ -473,8 +473,8 @@ dump_grammar (FILE *out)
   fprintf (out, _("Rules interpreted\n-----------------\n\n"));
   for (i = 1; i <= nrules; i++)
     {
-      fprintf (out, "%-5d  %s :", i, tags[rlhs[i]]);
-      for (r = &ritem[rrhs[i]]; *r > 0; r++)
+      fprintf (out, "%-5d  %s :", i, tags[rule_table[i].lhs]);
+      for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
 	fprintf (out, " %s", tags[*r]);
       fputc ('\n', out);
     }
