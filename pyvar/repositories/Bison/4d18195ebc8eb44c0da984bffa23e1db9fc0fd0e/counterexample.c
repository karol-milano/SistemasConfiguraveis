@@ -113,7 +113,7 @@ free_counterexample (counterexample *cex)
 }
 
 static void
-print_counterexample (counterexample *cex, FILE *out, const char *prefix)
+print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
 {
   fprintf (out, "  %s%-20s ",
            prefix, cex->unifying ? _("Example") : _("First example"));
