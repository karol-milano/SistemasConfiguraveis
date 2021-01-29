@@ -399,8 +399,9 @@ print_grammar (FILE *out)
   fprintf (out, "  %s\n", _("Number, Line, Rule"));
   for (j = 1; j < nrules + 1; j++)
     {
-      fprintf (out, _("  %3d %3d %s ->"),
-	       j - 1, rules[j].line, escape (rules[j].lhs->tag));
+      fprintf (out, "  %3d %3d %s ->",
+	       j - 1, rules[j].location.first_line,
+	       escape (rules[j].lhs->tag));
       rule = rules[j].rhs;
       if (*rule >= 0)
 	while (*rule >= 0)
