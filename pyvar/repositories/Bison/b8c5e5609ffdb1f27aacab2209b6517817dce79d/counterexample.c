@@ -26,6 +26,7 @@
 #include <gl_linked_list.h>
 #include <gl_rbtreehash_list.h>
 #include <hash.h>
+#include <mbswidth.h>
 #include <stdlib.h>
 #include <textstyle.h>
 #include <time.h>
@@ -112,15 +113,37 @@ free_counterexample (counterexample *cex)
   free (cex);
 }
 
+static int max (int a, int b)
+{
+  return a < b ? b : a;
+}
+
 static void
 print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
 {
   const bool flat = getenv ("YYFLAT");
-  fprintf (out, flat ? "  %s%-20s " : "  %s%s: ",
-           prefix, cex->unifying ? _("Example") : _("First example"));
+  const char *example1_label
+    = cex->unifying ? _("Example") : _("First example");
+  const char *example2_label
+    = cex->unifying ? _("Example") : _("Second example");
+  const char *deriv1_label
+    = cex->shift_reduce ? _("Shift derivation") : _("First reduce derivation");
+  const char *deriv2_label
+    = cex->shift_reduce ? _("Reduce derivation") : _("Second reduce derivation");
+  const int width =
+    max (max (mbswidth (example1_label, 0), mbswidth (example2_label, 0)),
+         max (mbswidth (deriv1_label, 0),   mbswidth (deriv2_label, 0)));
+  if (flat)
+    fprintf (out, "  %s%s%*s ", prefix,
+             example1_label, width - mbswidth (example1_label, 0), "");
+  else
+    fprintf (out, "  %s%s: ", prefix, example1_label);
   derivation_print_leaves (cex->d1, out);
-  fprintf (out, flat ? "  %s%-20s " : "  %s%s",
-           prefix, cex->shift_reduce ? _("Shift derivation") : _("First derivation"));
+  if (flat)
+    fprintf (out, "  %s%s%*s ", prefix,
+             deriv1_label, width - mbswidth (deriv1_label, 0), "");
+  else
+    fprintf (out, "  %s%s", prefix, deriv1_label);
   derivation_print (cex->d1, out, prefix);
 
   // If we output to the terminal (via stderr) and we have color
@@ -128,12 +151,18 @@ print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
   // to see the differences.
   if (!cex->unifying || is_styled (stderr))
     {
-      fprintf (out, flat ? "  %s%-20s " : "  %s%s: ",
-               prefix, cex->unifying ? _("Example") : _("Second example"));
+      if (flat)
+        fprintf (out, "  %s%s%*s ", prefix,
+                 example2_label, width - mbswidth (example2_label, 0), "");
+      else
+        fprintf (out, "  %s%s: ", prefix, example2_label);
       derivation_print_leaves (cex->d2, out);
     }
-  fprintf (out, flat ? "  %s%-20s " : "  %s%s",
-           prefix, cex->shift_reduce ? _("Reduce derivation") : _("Second derivation"));
+  if (flat)
+    fprintf (out, "  %s%s%*s ", prefix,
+             deriv2_label, width - mbswidth (deriv2_label, 0), "");
+  else
+    fprintf (out, "  %s%s", prefix, deriv2_label);
   derivation_print (cex->d2, out, prefix);
 
   if (out != stderr)
