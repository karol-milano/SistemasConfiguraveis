@@ -255,8 +255,8 @@ end_iteration:
 
   /* A token that was used in %prec should not be warned about.  */
   for (i = 1; i < nrules; i++)
-    if (rprecsym[i] != 0)
-      SETBIT (V1, rprecsym[i]);
+    if (rule_table[i].precsym != 0)
+      SETBIT (V1, rule_table[i].precsym);
 }
 
 static void
@@ -281,8 +281,8 @@ reduce_grammar_tables (void)
 		{
 		  rule_table[np].lhs = rule_table[pn].lhs;
 		  rline[np] = rline[pn];
-		  rprec[np] = rprec[pn];
-		  rassoc[np] = rassoc[pn];
+		  rule_table[np].prec = rule_table[pn].prec;
+		  rule_table[np].assoc = rule_table[pn].assoc;
 		  rule_table[np].rhs = rule_table[pn].rhs;
 		  if (rule_table[np].rhs != ni)
 		    {
@@ -370,9 +370,9 @@ reduce_grammar_tables (void)
 	  /* Ignore the rules disabled above.  */
 	  if (rule_table[i].lhs >= 0)
 	    rule_table[i].lhs = nontermmap[rule_table[i].lhs];
-	  if (ISVAR (rprecsym[i]))
+	  if (ISVAR (rule_table[i].precsym))
 	    /* Can this happen?  */
-	    rprecsym[i] = nontermmap[rprecsym[i]];
+	    rule_table[i].precsym = nontermmap[rule_table[i].precsym];
 	}
 
       for (r = ritem; *r; r++)
@@ -464,7 +464,11 @@ dump_grammar (FILE *out)
   for (i = 1; i <= nrules; i++)
     {
       fprintf (out, "%-5d(%5d%5d)%5d : (@%-5d)",
-	       i, rprec[i], rassoc[i], rule_table[i].lhs, rule_table[i].rhs);
+	       i,
+	       rule_table[i].prec,
+	       rule_table[i].assoc,
+	       rule_table[i].lhs,
+	       rule_table[i].rhs);
       for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
 	fprintf (out, "%5d", *r);
       fprintf (out, " [%d]\n", -(*r));
