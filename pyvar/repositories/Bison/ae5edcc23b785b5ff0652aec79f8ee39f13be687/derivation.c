@@ -18,11 +18,13 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+
+#include "derivation.h"
+
 #include <gl_linked_list.h>
 
 #include "system.h"
-
-#include "derivation.h"
+#include "complain.h"
 
 struct derivation
 {
@@ -124,57 +126,72 @@ derivation_size (const derivation *deriv)
   return size;
 }
 
-// these are used rarely enough that I don't think they should be interned.
-void
-derivation_print (const derivation *deriv, FILE *f)
+/* Print DERIV, colored according to COUNTER.  */
+static void
+derivation_print_impl (const derivation *deriv, FILE *f,
+                       bool leaves_only,
+                       int *counter)
 {
-  if (deriv == &d_dot)
+  if (deriv->children)
     {
-      fputs (" •", f);
-      return;
+      const symbol *sym = symbols[deriv->sym];
+      char style[20];
+      snprintf (style, 20, "cex-%d", *counter);
+      ++*counter;
+      begin_use_class (style, f);
+
+      if (!leaves_only)
+        {
+          begin_use_class ("cex-step", f);
+          fprintf (f, "%s ::=[ ", sym->tag);
+          end_use_class ("cex-step", f);
+        }
+      const char *sep = "";
+      derivation *child;
+      for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+           derivation_list_next (&it, &child);
+           )
+        {
+          fputs (sep, f);
+          sep = " ";
+          derivation_print_impl (child, f, leaves_only, counter);
+        }
+      if (!leaves_only)
+        {
+          begin_use_class ("cex-step", f);
+          fputs (" ]", f);
+          end_use_class ("cex-step", f);
+        }
+      end_use_class (style, f);
     }
-  symbol *sym = symbols[deriv->sym];
-  if (!deriv->children)
+  else if (deriv == &d_dot)
     {
-      fprintf (f, " %s", sym->tag);
-      return;
+      begin_use_class ("cex-dot", f);
+      fputs ("•", f);
+      end_use_class ("cex-dot", f);
     }
-
-  fprintf (f, " %s ::=[", sym->tag);
-  derivation *child;
-  for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
-       derivation_list_next (&it, &child);
-       )
+  else // leaf.
     {
-      derivation_print (child, f);
-      fputs (" ", f);
+      const symbol *sym = symbols[deriv->sym];
+      begin_use_class ("cex-leaf", f);
+      fprintf (f, "%s", sym->tag);
+      end_use_class ("cex-leaf", f);
     }
-  fputs ("]", f);
 }
 
 void
-derivation_print_leaves (const derivation *deriv, FILE *f)
+derivation_print (const derivation *deriv, FILE *f)
 {
-  if (deriv == &d_dot)
-    {
-      fputs ("•", f);
-      return;
-    }
-  if (!deriv->children)
-    {
-      symbol *sym = symbols[deriv->sym];
-      fprintf (f, "%s", sym->tag);
-      return;
-    }
+  int counter = 0;
+  derivation_print_impl (deriv, f, false, &counter);
+  fputc ('\n', f);
+}
 
-  const char *sep = "";
-  derivation *child;
-  for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
-       derivation_list_next (&it, &child);
-       )
-    {
-      fputs (sep, f);
-      sep = "  ";
-      derivation_print_leaves (child, f);
-    }
+
+void
+derivation_print_leaves (const derivation *deriv, FILE *f)
+{
+  int counter = 0;
+  derivation_print_impl (deriv, f, true, &counter);
+  fputc ('\n', f);
 }
