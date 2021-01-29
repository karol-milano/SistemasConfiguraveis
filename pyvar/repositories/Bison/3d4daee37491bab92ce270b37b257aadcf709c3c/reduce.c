@@ -107,7 +107,7 @@ useful_production (int i, BSet N0)
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
 
-  for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
+  for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
     if (ISVAR (n = *r))
       if (!BITISSET (N0, n - ntokens))
 	return FALSE;
@@ -304,13 +304,15 @@ reduce_grammar_tables (void)
 		}
 	      else
 		{
-		  while (ritem[ni++] >= 0);
+		  while (ritem[ni++] >= 0)
+		    /* Nothing. */;
 		}
 	    }
 
 	ritem[ni] = 0;
 	nrules -= nuseless_productions;
 	nitems = ni;
+	nritems = ni;
 
 	/* Is it worth it to reduce the amount of memory for the
 	   grammar? Probably not.  */
@@ -466,24 +468,24 @@ dump_grammar (FILE *out)
     {
       int rhs_count = 0;
       /* Find the last RHS index in ritems. */
-      for (r = &ritem[rule_table[i].rhs]; *r > 0; ++r)
+      for (r = &ritem[rule_table[i].rhs]; *r >= 0; ++r)
 	++rhs_count;
       fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
-	       i,
+	       i - 1,
 	       rule_table[i].prec, rule_table[i].assoc, rule_table[i].useful,
 	       rule_table[i].rhs, rule_table[i].rhs + rhs_count - 1,
 	       rule_table[i].lhs);
       /* Dumped the RHS. */
-      for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
+      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
 	fprintf (out, "%3d", *r);
-      fprintf (out, "  [%d]\n", -(*r));
+      fprintf (out, "  [%d]\n", -(*r) - 1);
     }
   fprintf (out, "\n\n");
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   for (i = 1; i <= nrules; i++)
     {
       fprintf (out, "%-5d  %s :", i, tags[rule_table[i].lhs]);
-      for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
+      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
 	fprintf (out, " %s", tags[*r]);
       fputc ('\n', out);
     }
