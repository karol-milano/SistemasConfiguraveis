@@ -455,18 +455,22 @@ dump_grammar (FILE *out)
     fprintf (out, "%5d  %5d   %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
   fprintf (out, "\n\n");
   fprintf (out, "Rules\n-----\n\n");
-  fprintf (out, "Num (Prec, Assoc) Lhs : (@Rhs) Ritems [Num?]\n");
+  fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
   for (i = 1; i <= nrules; i++)
     {
-      fprintf (out, "%-5d(%5d%5d)%5d : (@%-5d)",
+      int rhs_count = 0;
+      /* Find the last RHS index in ritems. */
+      for (r = &ritem[rule_table[i].rhs]; *r > 0; ++r)
+	++rhs_count;
+      fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
 	       i,
-	       rule_table[i].prec,
-	       rule_table[i].assoc,
-	       rule_table[i].lhs,
-	       rule_table[i].rhs);
+	       rule_table[i].prec, rule_table[i].assoc, rule_table[i].useful,
+	       rule_table[i].rhs, rule_table[i].rhs + rhs_count - 1,
+	       rule_table[i].lhs);
+      /* Dumped the RHS. */
       for (r = &ritem[rule_table[i].rhs]; *r > 0; r++)
-	fprintf (out, "%5d", *r);
-      fprintf (out, " [%d]\n", -(*r));
+	fprintf (out, "%3d", *r);
+      fprintf (out, "  [%d]\n", -(*r));
     }
   fprintf (out, "\n\n");
   fprintf (out, "Rules interpreted\n-----------------\n\n");
