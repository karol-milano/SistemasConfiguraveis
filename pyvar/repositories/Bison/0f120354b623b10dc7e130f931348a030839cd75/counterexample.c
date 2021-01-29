@@ -27,6 +27,7 @@
 #include <gl_rbtreehash_list.h>
 #include <hash.h>
 #include <stdlib.h>
+#include <textstyle.h>
 #include <time.h>
 
 #include "closure.h"
@@ -109,9 +110,15 @@ print_counterexample (counterexample *cex, FILE *out, const char *prefix)
            prefix, _("First derivation"));
   derivation_print (cex->d1, out, prefix);
 
-  fprintf (out, "  %s%-20s ",
-           prefix, cex->unifying ? _("Example") : _("Second example"));
-  derivation_print_leaves (cex->d2, out, prefix);
+  // If we output to the terminal (via stderr) and we have color
+  // support, display unifying examples a second time, as color allows
+  // to see the differences.
+  if (!cex->unifying || is_styled (stderr))
+    {
+      fprintf (out, "  %s%-20s ",
+               prefix, cex->unifying ? _("Example") : _("Second example"));
+      derivation_print_leaves (cex->d2, out, prefix);
+    }
   fprintf (out, "  %s%-20s ",
            prefix, _("Second derivation"));
   derivation_print (cex->d2, out, prefix);
