@@ -113,11 +113,6 @@ free_counterexample (counterexample *cex)
   free (cex);
 }
 
-static int max (int a, int b)
-{
-  return a < b ? b : a;
-}
-
 static void
 counterexample_print (const counterexample *cex, FILE *out, const char *prefix)
 {
@@ -131,8 +126,8 @@ counterexample_print (const counterexample *cex, FILE *out, const char *prefix)
   const char *deriv2_label
     = cex->shift_reduce ? _("Reduce derivation") : _("Second reduce derivation");
   const int width =
-    max (max (mbswidth (example1_label, 0), mbswidth (example2_label, 0)),
-         max (mbswidth (deriv1_label, 0),   mbswidth (deriv2_label, 0)));
+    max_int (max_int (mbswidth (example1_label, 0), mbswidth (example2_label, 0)),
+             max_int (mbswidth (deriv1_label, 0),   mbswidth (deriv2_label, 0)));
   if (flat)
     fprintf (out, "  %s%s%*s ", prefix,
              example1_label, width - mbswidth (example1_label, 0), "");
