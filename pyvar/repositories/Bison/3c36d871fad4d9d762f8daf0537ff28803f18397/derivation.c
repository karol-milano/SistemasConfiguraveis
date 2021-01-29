@@ -25,6 +25,7 @@
 #include <c-ctype.h>
 #include <gl_linked_list.h>
 #include <mbswidth.h>
+#include <vasnprintf.h>
 
 #include "system.h"
 #include "complain.h"
@@ -34,13 +35,15 @@ struct derivation
   symbol_number sym;
   derivation_list children;
   int reference_count;
+  // The rule SYM -> CHILDREN.
+  const rule *rule;
   // Color assigned for styling.  Guarantees that the derivation is
   // always displayed with the same color, independently of the order
   // in which the derivations are traversed.
   int color;
 };
 
-static derivation d_dot = { -1, NULL, -1, -1 };
+static derivation d_dot = { -1, NULL, -1, NULL, -1 };
 
 derivation *
 derivation_dot (void)
@@ -74,12 +77,14 @@ void derivation_list_free (derivation_list dl)
 }
 
 derivation *
-derivation_new (symbol_number sym, derivation_list children)
+derivation_new (symbol_number sym, derivation_list children,
+                const rule *r)
 {
   derivation *res = xmalloc (sizeof *res);
   res->sym = sym;
   res->children = children;
   res->reference_count = 0;
+  res->rule = r;
   res->color = -1;
   return res;
 }
@@ -205,6 +210,23 @@ fputs_if (bool cond, FILE *out, int *padding, const char *s)
   return res;
 }
 
+static int
+fprintf_if (bool cond, FILE *out, int *padding, const char *fmt, ...)
+{
+  char buf[256];
+  size_t len = sizeof (buf);
+  va_list args;
+  va_start (args, fmt);
+  char *cp = vasnprintf (buf, &len, fmt, args);
+  va_end (args);
+  if (!cp)
+    xalloc_die ();
+  int res = fputs_if (cond, out, padding, cp);
+  if (cp != buf)
+    free (cp);
+  return res;
+}
+
 // The width taken to report this derivation recursively down to its
 // leaves.
 static int
@@ -217,6 +239,7 @@ derivation_width (const derivation *deriv)
 
       // Arrow and space.
       int children_width = down_arrow_width;
+      children_width += snprintf (NULL, 0, "%d: ", deriv->rule->number);
       if (gl_list_size (deriv->children) == 0)
         // Empty rhs.
         children_width += empty_width;
@@ -281,6 +304,7 @@ derivation_print_tree_impl (const derivation *deriv, FILE *out,
       else
         {
           res += fputs_if (depth == 1, out, padding, down_arrow);
+          res += fprintf_if (depth == 1, out, padding, "%d: ", deriv->rule->number);
           if (gl_list_size (deriv->children) == 0)
             // Empty rhs.
             res += fputs_if (depth == 1, out, padding, empty);
