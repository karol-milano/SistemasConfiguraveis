@@ -18,37 +18,94 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+#include <gl_linked_list.h>
 
 #include "system.h"
 
 #include "derivation.h"
 
-static derivation d_dot = { -1, NULL };
+struct derivation
+{
+  symbol_number sym;
+  gl_list_t children;
+  int reference_count;
+};
+
+static derivation d_dot = { -1, NULL, -1 };
 
-const derivation *
+derivation *
 derivation_dot (void)
 {
   return &d_dot;
 }
 
+void
+derivation_list_append (derivation_list dl, derivation *d)
+{
+  derivation_retain (d);
+  gl_list_add_last (dl, d);
+}
+
+void
+derivation_list_prepend (derivation_list dl, derivation *d)
+{
+  derivation_retain (d);
+  gl_list_add_first (dl, d);
+}
+
+void derivation_list_free (derivation_list dl)
+{
+  gl_list_iterator_t it = gl_list_iterator (dl);
+  derivation *d;
+  while (gl_list_iterator_next (&it, (const void **) &d, NULL))
+    if (d != &d_dot)
+      derivation_free (d);
+  gl_list_free (dl);
+}
+
 derivation *
-derivation_new (symbol_number sym, gl_list_t children)
+derivation_new (symbol_number sym, derivation_list children)
 {
   derivation *deriv = xmalloc (sizeof (derivation));
   deriv->sym = sym;
   deriv->children = children;
+  deriv->reference_count = 0;
   return deriv;
 }
 
+void
+derivation_retain (derivation *d)
+{
+  ++d->reference_count;
+}
+
 void
 derivation_free (derivation *d)
 {
-  if (d && d != &d_dot)
+  if (!d)
+    return;
+  derivation_list free_queue =
+    gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true,
+                    1, (const void **)&d);
+  while (gl_list_size (free_queue) > 0)
     {
-      if (d->children)
-        gl_list_free (d->children);
-      free (d);
+      derivation *deriv = (derivation *) gl_list_get_at (free_queue, 0);
+      if (--deriv->reference_count == 0)
+        {
+          if (deriv->children)
+            {
+              gl_list_iterator_t it = gl_list_iterator (deriv->children);
+              derivation *child;
+              while (gl_list_iterator_next (&it, (const void **) &child, NULL))
+                if (child != &d_dot)
+                  gl_list_add_last (free_queue, child);
+              gl_list_free (deriv->children);
+            }
+          free (deriv);
+        }
+      gl_list_remove_at (free_queue, 0);
     }
+  gl_list_free (free_queue);
 }
 
 size_t
