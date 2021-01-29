@@ -102,14 +102,14 @@ free_counterexample (counterexample *cex)
 static void
 print_counterexample (counterexample *cex, FILE *out)
 {
-  fprintf (out, "%-20s ", cex->unifying ? _("Example") : _("First example"));
+  fprintf (out, "  %-20s ", cex->unifying ? _("Example") : _("First example"));
   derivation_print_leaves (cex->d1, out);
-  fprintf (out, "%-20s ", _("First derivation"));
+  fprintf (out, "  %-20s ", _("First derivation"));
   derivation_print (cex->d1, out);
 
-  fprintf (out, "%-20s ", cex->unifying ? _("Example") : _("Second example"));
+  fprintf (out, "  %-20s ", cex->unifying ? _("Example") : _("Second example"));
   derivation_print_leaves (cex->d2, out);
-  fprintf (out, "%-20s ", _("Second derivation"));
+  fprintf (out, "  %-20s ", _("Second derivation"));
   derivation_print (cex->d2, out);
 
   fputc ('\n', out);
