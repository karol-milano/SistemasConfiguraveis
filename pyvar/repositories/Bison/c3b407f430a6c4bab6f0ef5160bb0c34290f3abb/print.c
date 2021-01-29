@@ -366,19 +366,17 @@ print_grammar (FILE *out)
   fprintf (out, "%s\n\n", _("Grammar"));
   fprintf (out, "  %s\n", _("Number, Line, Rule"));
   for (i = 1; i < nrules + 1; i++)
-    /* Don't print rules disabled in reduce_grammar_tables.  */
-    if (rules[i].useful)
-      {
-	fprintf (out, _("  %3d %3d %s ->"),
-		 i - 1, rules[i].line, escape (symbols[rules[i].lhs]->tag));
-	rule = rules[i].rhs;
-	if (*rule >= 0)
-	  while (*rule >= 0)
-	    fprintf (out, " %s", escape (symbols[*rule++]->tag));
-	else
-	  fprintf (out, " /* %s */", _("empty"));
-	fputc ('\n', out);
-      }
+    {
+      fprintf (out, _("  %3d %3d %s ->"),
+	       i - 1, rules[i].line, escape (symbols[rules[i].lhs]->tag));
+      rule = rules[i].rhs;
+      if (*rule >= 0)
+	while (*rule >= 0)
+	  fprintf (out, " %s", escape (symbols[*rule++]->tag));
+      else
+	fprintf (out, " /* %s */", _("empty"));
+      fputc ('\n', out);
+    }
   fputs ("\n\n", out);
 
 
