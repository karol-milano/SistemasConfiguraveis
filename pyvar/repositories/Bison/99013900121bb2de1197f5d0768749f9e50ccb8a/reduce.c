@@ -72,7 +72,7 @@ useful_production (int i, bitset N0)
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
 
-  for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
+  for (r = rules[i].rhs; *r >= 0; r++)
     if (ISVAR (n = *r) && !bitset_test (N0, n - ntokens))
       return FALSE;
   return TRUE;
@@ -180,7 +180,7 @@ inaccessable_symbols (void)
 		  && bitset_test (P, i)
 		  && bitset_test (V, rules[i].lhs))
 		{
-		  for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
+		  for (r = rules[i].rhs; *r >= 0; r++)
 		    if (ISTOKEN (t = *r) || bitset_test (N, t - ntokens))
 		      bitset_set (Vp, t);
 		  bitset_set (Pp, i);
@@ -252,10 +252,10 @@ reduce_grammar_tables (void)
 		  rules[np].prec  = rules[pn].prec;
 		  rules[np].assoc = rules[pn].assoc;
 		  rules[np].rhs   = rules[pn].rhs;
-		  if (rules[np].rhs != ni)
+		  if (rules[np].rhs - ritem != ni)
 		    {
-		      pi = rules[np].rhs;
-		      rules[np].rhs = ni;
+		      pi = rules[np].rhs - ritem;
+		      rules[np].rhs = ritem + ni;
 		      while (ritem[pi] >= 0)
 			ritem[ni++] = ritem[pi++];
 		      ritem[ni++] = -np;
@@ -384,7 +384,7 @@ reduce_output (FILE *out)
 	    rule r;
 	    fprintf (out, "#%-4d  ", i - 1);
 	    fprintf (out, "%s:", symbols[rules[i].lhs]->tag);
-	    for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
+	    for (r = rules[i].rhs; *r >= 0; r++)
 	      fprintf (out, " %s", symbols[*r]->tag);
 	    fputs (";\n", out);
 	  }
@@ -415,15 +415,15 @@ dump_grammar (FILE *out)
     {
       int rhs_count = 0;
       /* Find the last RHS index in ritems. */
-      for (r = &ritem[rules[i].rhs]; *r >= 0; ++r)
+      for (r = rules[i].rhs; *r >= 0; ++r)
 	++rhs_count;
       fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
 	       i - 1,
 	       rules[i].prec, rules[i].assoc, rules[i].useful,
-	       rules[i].rhs, rules[i].rhs + rhs_count - 1,
+	       rules[i].rhs - ritem, rules[i].rhs - ritem + rhs_count - 1,
 	       rules[i].lhs);
       /* Dumped the RHS. */
-      for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
+      for (r = rules[i].rhs; *r >= 0; r++)
 	fprintf (out, "%3d", *r);
       fprintf (out, "  [%d]\n", -(*r) - 1);
     }
@@ -432,7 +432,7 @@ dump_grammar (FILE *out)
   for (i = 1; i <= nrules; i++)
     {
       fprintf (out, "%-5d  %s :", i, symbols[rules[i].lhs]->tag);
-      for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
+      for (r = rules[i].rhs; *r >= 0; r++)
 	fprintf (out, " %s", symbols[*r]->tag);
       fputc ('\n', out);
     }
@@ -490,7 +490,6 @@ reduce_grammar (void)
   inaccessable_symbols ();
 
   reduced = (bool) (nuseless_nonterminals + nuseless_productions > 0);
-
   if (!reduced)
     return;
 
