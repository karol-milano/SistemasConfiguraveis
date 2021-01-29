@@ -20,6 +20,7 @@
 #include <config.h>
 
 #include "derivation.h"
+#include "glyphs.h"
 
 #include <gl_linked_list.h>
 
@@ -145,9 +146,7 @@ derivation_print_impl (const derivation *deriv, FILE *out,
         {
           fputs (prefix, out);
           begin_use_class ("cex-step", out);
-          fprintf (out, "%s ", sym->tag);
-          print_arrow (out);
-          fprintf (out, " [ ");
+          fprintf (out, "%s %s [ ", sym->tag, arrow);
           end_use_class ("cex-step", out);
           prefix = "";
         }
@@ -181,7 +180,7 @@ derivation_print_impl (const derivation *deriv, FILE *out,
     {
       fputs (prefix, out);
       begin_use_class ("cex-dot", out);
-      print_dot (out);
+      fputs (dot, out);
       end_use_class ("cex-dot", out);
     }
   else // leaf.
