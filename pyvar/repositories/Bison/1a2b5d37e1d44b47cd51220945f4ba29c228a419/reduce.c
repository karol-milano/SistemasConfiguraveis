@@ -108,7 +108,7 @@ useful_production (int i, BSet N0)
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
 
-  for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+  for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
     if (ISVAR (n = *r))
       if (!BITISSET (N0, n - ntokens))
 	return FALSE;
@@ -157,7 +157,7 @@ useless_nonterminals (void)
 	    {
 	      if (useful_production (i, N))
 		{
-		  SETBIT (Np, rule_table[i].lhs - ntokens);
+		  SETBIT (Np, rules[i].lhs - ntokens);
 		  SETBIT (P, i);
 		}
 	    }
@@ -220,9 +220,9 @@ inaccessable_symbols (void)
 	    {
 	      if (!BITISSET (Pp, i)
 		  && BITISSET (P, i)
-		  && BITISSET (V, rule_table[i].lhs))
+		  && BITISSET (V, rules[i].lhs))
 		{
-		  for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+		  for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
 		    if (ISTOKEN (t = *r) || BITISSET (N, t - ntokens))
 		      SETBIT (Vp, t);
 		  SETBIT (Pp, i);
@@ -258,8 +258,8 @@ inaccessable_symbols (void)
 
   /* A token that was used in %prec should not be warned about.  */
   for (i = 1; i < nrules; i++)
-    if (rule_table[i].precsym != 0)
-      SETBIT (V1, rule_table[i].precsym);
+    if (rules[i].precsym != 0)
+      SETBIT (V1, rules[i].precsym);
 }
 
 static void
@@ -289,15 +289,15 @@ reduce_grammar_tables (void)
 	      np++;
 	      if (pn != np)
 		{
-		  rule_table[np].lhs   = rule_table[pn].lhs;
-		  rule_table[np].line  = rule_table[pn].line;
-		  rule_table[np].prec  = rule_table[pn].prec;
-		  rule_table[np].assoc = rule_table[pn].assoc;
-		  rule_table[np].rhs   = rule_table[pn].rhs;
-		  if (rule_table[np].rhs != ni)
+		  rules[np].lhs   = rules[pn].lhs;
+		  rules[np].line  = rules[pn].line;
+		  rules[np].prec  = rules[pn].prec;
+		  rules[np].assoc = rules[pn].assoc;
+		  rules[np].rhs   = rules[pn].rhs;
+		  if (rules[np].rhs != ni)
 		    {
-		      pi = rule_table[np].rhs;
-		      rule_table[np].rhs = ni;
+		      pi = rules[np].rhs;
+		      rules[np].rhs = ni;
 		      while (ritem[pi] >= 0)
 			ritem[ni++] = ritem[pi++];
 		      ritem[ni++] = -np;
@@ -324,7 +324,7 @@ reduce_grammar_tables (void)
     {
       int pn;
       for (pn = 1; pn <= nrules; pn++)
-	rule_table[pn].useful = BITISSET (P, pn);
+	rules[pn].useful = BITISSET (P, pn);
     }
 }
 
@@ -367,10 +367,10 @@ nonterminals_reduce (void)
 
   for (i = 1; i <= nrules; i++)
     {
-      rule_table[i].lhs = nontermmap[rule_table[i].lhs];
-      if (ISVAR (rule_table[i].precsym))
+      rules[i].lhs = nontermmap[rules[i].lhs];
+      if (ISVAR (rules[i].precsym))
 	/* Can this happen?  */
-	rule_table[i].precsym = nontermmap[rule_table[i].precsym];
+	rules[i].precsym = nontermmap[rules[i].precsym];
     }
 
   for (i = 0; i < nritems; ++i)
@@ -422,12 +422,12 @@ reduce_output (FILE *out)
       int i;
       fprintf (out, "%s\n\n", _("Useless rules:"));
       for (i = 1; i <= nrules; i++)
-	if (!rule_table[i].useful)
+	if (!rules[i].useful)
 	  {
 	    rule r;
 	    fprintf (out, "#%-4d  ", i - 1);
-	    fprintf (out, "%s:", symbols[rule_table[i].lhs]->tag);
-	    for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+	    fprintf (out, "%s:", symbols[rules[i].lhs]->tag);
+	    for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
 	      fprintf (out, " %s", symbols[*r]->tag);
 	    fputs (";\n", out);
 	  }
@@ -458,15 +458,15 @@ dump_grammar (FILE *out)
     {
       int rhs_count = 0;
       /* Find the last RHS index in ritems. */
-      for (r = &ritem[rule_table[i].rhs]; *r >= 0; ++r)
+      for (r = &ritem[rules[i].rhs]; *r >= 0; ++r)
 	++rhs_count;
       fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
 	       i - 1,
-	       rule_table[i].prec, rule_table[i].assoc, rule_table[i].useful,
-	       rule_table[i].rhs, rule_table[i].rhs + rhs_count - 1,
-	       rule_table[i].lhs);
+	       rules[i].prec, rules[i].assoc, rules[i].useful,
+	       rules[i].rhs, rules[i].rhs + rhs_count - 1,
+	       rules[i].lhs);
       /* Dumped the RHS. */
-      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+      for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
 	fprintf (out, "%3d", *r);
       fprintf (out, "  [%d]\n", -(*r) - 1);
     }
@@ -474,8 +474,8 @@ dump_grammar (FILE *out)
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   for (i = 1; i <= nrules; i++)
     {
-      fprintf (out, "%-5d  %s :", i, symbols[rule_table[i].lhs]->tag);
-      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+      fprintf (out, "%-5d  %s :", i, symbols[rules[i].lhs]->tag);
+      for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
 	fprintf (out, " %s", symbols[*r]->tag);
       fputc ('\n', out);
     }
