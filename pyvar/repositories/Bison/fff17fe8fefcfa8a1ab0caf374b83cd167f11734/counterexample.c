@@ -115,10 +115,11 @@ free_counterexample (counterexample *cex)
 static void
 print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
 {
+  const bool flat = getenv ("YYFLAT");
   fprintf (out, "  %s%-20s ",
            prefix, cex->unifying ? _("Example") : _("First example"));
   derivation_print_leaves (cex->d1, out, prefix);
-  fprintf (out, "  %s%-20s ",
+  fprintf (out, flat ? "  %s%-20s " : "  %s%s",
            prefix, cex->shift_reduce ? _("Shift derivation") : _("First derivation"));
   derivation_print (cex->d1, out, prefix);
 
@@ -131,7 +132,7 @@ print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
                prefix, cex->unifying ? _("Example") : _("Second example"));
       derivation_print_leaves (cex->d2, out, prefix);
     }
-  fprintf (out, "  %s%-20s ",
+  fprintf (out, flat ? "  %s%-20s " : "  %s%s",
            prefix, cex->shift_reduce ? _("Reduce derivation") : _("Second derivation"));
   derivation_print (cex->d2, out, prefix);
 
