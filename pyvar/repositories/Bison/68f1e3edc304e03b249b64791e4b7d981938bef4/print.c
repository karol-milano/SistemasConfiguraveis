@@ -216,7 +216,7 @@ print_grammar (FILE *out)
   fprintf (out, "  %s\n", _("Number, Line, Rule"));
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
-    if (rule_table[i].lhs >= 0)
+    if (rule_table[i].useful)
       {
 	fprintf (out, _("  %3d %3d %s ->"),
 		 i, rule_table[i].line, tags[rule_table[i].lhs]);
