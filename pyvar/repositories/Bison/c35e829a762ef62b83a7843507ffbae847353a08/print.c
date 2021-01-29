@@ -356,7 +356,9 @@ print_state (FILE *out, const state *s)
       fputc ('\n', out);
       fputs (s->solved_conflicts, out);
     }
-  if (warning_is_enabled (Wcounterexamples) && has_conflicts (s))
+  if (has_conflicts (s)
+      && (report_flag & report_cex
+          || warning_is_enabled (Wcounterexamples)))
     {
       fputc ('\n', out);
       counterexample_report_state (s, out, "    ");
