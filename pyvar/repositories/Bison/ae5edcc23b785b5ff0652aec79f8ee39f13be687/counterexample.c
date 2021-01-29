@@ -103,21 +103,18 @@ static void
 print_counterexample (counterexample *cex)
 {
   FILE *out = stderr;
-  if (cex->unifying)
-    fprintf (out, "Example  ");
-  else
-    fprintf (out, "First  Example ");
+
+  fprintf (out, "%-20s ", cex->unifying ? _("Example") : _("First example"));
   derivation_print_leaves (cex->d1, out);
-  fprintf (out, "\nFirst  derivation ");
+  fprintf (out, "%-20s ", _("First derivation"));
   derivation_print (cex->d1, out);
-  if (!cex->unifying)
-    {
-      fprintf (out, "\nSecond Example ");
-      derivation_print_leaves (cex->d2, out);
-    }
-  fprintf (out, "\nSecond derivation ");
+
+  fprintf (out, "%-20s ", cex->unifying ? _("Example") : _("Second example"));
+  derivation_print_leaves (cex->d2, out);
+  fprintf (out, "%-20s ", _("Second derivation"));
   derivation_print (cex->d2, out);
-  fputs ("\n\n", out);
+
+  fputc ('\n', out);
 }
 
 /*
