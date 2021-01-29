@@ -18,9 +18,11 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
-#include "derivation.h"
+
 #include "system.h"
 
+#include "derivation.h"
+
 static derivation d_dot = { -1, NULL };
 
 const derivation *
@@ -68,21 +70,24 @@ derivation_print (const derivation *deriv, FILE *f)
 {
   if (deriv == &d_dot)
     {
-      fputs (" • ", f);
+      fputs (" •", f);
       return;
     }
   symbol *sym = symbols[deriv->sym];
   if (!deriv->children)
     {
-      fprintf (f, " %s ", sym->tag);
+      fprintf (f, " %s", sym->tag);
       return;
     }
   gl_list_iterator_t it = gl_list_iterator (deriv->children);
   derivation *child;
   fprintf (f, " %s ::=[", sym->tag);
   while (gl_list_iterator_next (&it, (const void **) &child, NULL))
-    derivation_print (child, f);
-  fputs ("] ", f);
+    {
+      derivation_print (child, f);
+      fputs (" ", f);
+    }
+  fputs ("]", f);
 }
 
 void
@@ -90,18 +95,23 @@ derivation_print_leaves (const derivation *deriv, FILE *f)
 {
   if (deriv == &d_dot)
     {
-      fputs (" • ", f);
+      fputs ("•", f);
       return;
     }
   if (!deriv->children)
     {
       symbol *sym = symbols[deriv->sym];
-      fprintf (f, " %s ", sym->tag);
+      fprintf (f, "%s", sym->tag);
       return;
     }
 
   gl_list_iterator_t it = gl_list_iterator (deriv->children);
+  const char *sep = "";
   derivation *child;
   while (gl_list_iterator_next (&it, (const void **) &child, NULL))
-    derivation_print_leaves (child, f);
+    {
+      fputs (sep, f);
+      sep = "  ";
+      derivation_print_leaves (child, f);
+    }
 }
