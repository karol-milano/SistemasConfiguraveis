@@ -213,17 +213,19 @@ print_grammar (FILE *out)
 
   /* rule # : LHS -> RHS */
   fprintf (out, "\n%s\n\n", _("Grammar"));
+  fprintf (out, "  %s\n", _("Number, Line, Rule"));
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rule_table[i].lhs >= 0)
       {
-	fprintf (out, _("rule %-4d %s ->"), i, tags[rule_table[i].lhs]);
+	fprintf (out, _("  %3d %3d %s ->"),
+		 i, rule_table[i].line, tags[rule_table[i].lhs]);
 	rule = &ritem[rule_table[i].rhs];
 	if (*rule > 0)
 	  while (*rule > 0)
 	    fprintf (out, " %s", tags[*rule++]);
 	else
-	  fprintf (out, "		/* %s */", _("empty"));
+	  fprintf (out, " /* %s */", _("empty"));
 	fputc ('\n', out);
       }
 
