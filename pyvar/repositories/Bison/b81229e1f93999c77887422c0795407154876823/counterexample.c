@@ -116,9 +116,9 @@ static void
 print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
 {
   const bool flat = getenv ("YYFLAT");
-  fprintf (out, "  %s%-20s ",
+  fprintf (out, flat ? "  %s%-20s " : "  %s%s: ",
            prefix, cex->unifying ? _("Example") : _("First example"));
-  derivation_print_leaves (cex->d1, out, prefix);
+  derivation_print_leaves (cex->d1, out);
   fprintf (out, flat ? "  %s%-20s " : "  %s%s",
            prefix, cex->shift_reduce ? _("Shift derivation") : _("First derivation"));
   derivation_print (cex->d1, out, prefix);
@@ -128,9 +128,9 @@ print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
   // to see the differences.
   if (!cex->unifying || is_styled (stderr))
     {
-      fprintf (out, "  %s%-20s ",
+      fprintf (out, flat ? "  %s%-20s " : "  %s%s: ",
                prefix, cex->unifying ? _("Example") : _("Second example"));
-      derivation_print_leaves (cex->d2, out, prefix);
+      derivation_print_leaves (cex->d2, out);
     }
   fprintf (out, flat ? "  %s%-20s " : "  %s%s",
            prefix, cex->shift_reduce ? _("Reduce derivation") : _("Second derivation"));
