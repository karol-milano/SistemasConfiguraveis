@@ -22,7 +22,9 @@
 #include "derivation.h"
 #include "glyphs.h"
 
+#include <c-ctype.h>
 #include <gl_linked_list.h>
+#include <mbswidth.h>
 
 #include "system.h"
 #include "complain.h"
@@ -32,9 +34,13 @@ struct derivation
   symbol_number sym;
   derivation_list children;
   int reference_count;
+  // Color assigned for styling.  Guarantees that the derivation is
+  // always displayed with the same color, independently of the order
+  // in which the derivations are traversed.
+  int color;
 };
 
-static derivation d_dot = { -1, NULL, -1 };
+static derivation d_dot = { -1, NULL, -1, -1 };
 
 derivation *
 derivation_dot (void)
@@ -74,6 +80,7 @@ derivation_new (symbol_number sym, derivation_list children)
   deriv->sym = sym;
   deriv->children = children;
   deriv->reference_count = 0;
+  deriv->color = -1;
   return deriv;
 }
 
@@ -127,19 +134,235 @@ derivation_size (const derivation *deriv)
   return size;
 }
 
+
+static int
+max (int a, int b)
+{
+  return a < b ? b : a;
+}
+
+// Longest distance from root to leaf.
+static int
+derivation_depth (const derivation *deriv)
+{
+  if (deriv->children)
+    {
+      // Children's depth cannot be 0, even if there are no children
+      // (the case of a derivation with an empty RHS).
+      int res = 1;
+      derivation *child;
+      for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+           derivation_list_next (&it, &child);
+           )
+        res = max (res, derivation_depth (child));
+      return res + 1;
+    }
+  else
+    return 1;
+}
+
+static bool
+all_spaces (const char *s)
+{
+  while (c_isspace (*s))
+    s++;
+  return *s == '\0';
+}
+
+// Printing the derivation as trees without trailing spaces is
+// painful: we cannot simply pad one "column" before moving to the
+// next:
+//
+// exp
+// ↳ x1          e1  foo1                      x1
+//   ↳ x2        ↳ ε ↳ foo2                    ↳ x2
+//     ↳ x3            ↳ foo3                    ↳ x3
+//       ↳ "X" •         ↳ x1        foo4          ↳ "X"
+//                         ↳ x2      ↳ "quuux"
+//                           ↳ x3
+//                             ↳ "X"
+//
+// It's hard for a column to know that it's "last" to decide whether
+// to output the right-padding or not.  So when we need to pad on the
+// right to complete a column, we don't output the spaces, we
+// accumulate the width of padding in *PADDING.
+//
+// Each time we actually print something (non space), we flush that
+// padding.  When we _don't_ print something, its width is added to
+// the current padding.
+//
+// This function implements this.
+//
+// When COND is true, put S on OUT, preceeded by *PADDING white
+// spaces.  Otherwise add the width to *PADDING.  Return the width of
+// S.
+static int
+fputs_if (bool cond, FILE *out, int *padding, const char *s)
+{
+  int res = mbswidth (s, 0);
+  if (cond && !all_spaces (s))
+    {
+      fprintf (out, "%*s%s", *padding, "", s);
+      *padding = 0;
+    }
+  else
+    {
+      *padding += res;
+    }
+  return res;
+}
+
+// The width taken to report this derivation recursively down to its
+// leaves.
+static int
+derivation_width (const derivation *deriv)
+{
+  if (deriv->children)
+    {
+      const symbol *sym = symbols[deriv->sym];
+      int self_width = mbswidth (sym->tag, 0);
+
+      // Arrow and space.
+      int children_width = down_arrow_width;
+      if (gl_list_size (deriv->children) == 0)
+        // Empty rhs.
+        children_width += empty_width;
+      else
+        {
+          derivation *child;
+          for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+               derivation_list_next (&it, &child);
+               )
+            children_width
+              += derivation_separator_width + derivation_width (child);
+          // No separator at the beginning.
+          children_width -= derivation_separator_width;
+        }
+      return max (self_width, children_width);
+    }
+  else if (deriv == &d_dot)
+    {
+      return dot_width;
+    }
+  else // leaf.
+    {
+      const symbol *sym = symbols[deriv->sym];
+      return mbswidth (sym->tag, 0);
+    }
+}
+
+
+// Print DERIV for DEPTH.
+//
+// The tree is printed from top to bottom with DEPTH ranging from 0 to
+// the total depth of the tree.  DERIV should only printed when we
+// reach its depth, i.e., then DEPTH is 0.
+//
+// When DEPTH is 1 and we're on a subderivation, then we print the RHS
+// of the derivation (in DEPTH 0 we printed its LHS).
+//
+// Return the "logical printed" width.  We might have not have reached
+// that width, in which case the missing spaces are in *PADDING.
+static int
+derivation_print_tree_impl (const derivation *deriv, FILE *out,
+                            int depth, int *padding)
+{
+  const int width = derivation_width (deriv);
+
+  int res = 0;
+  if (deriv->children)
+    {
+      const symbol *sym = symbols[deriv->sym];
+      char style[20];
+      snprintf (style, 20, "cex-%d", deriv->color);
+
+      if (depth == 0 || depth == 1)
+        {
+          begin_use_class (style, out);
+          begin_use_class ("cex-step", out);
+        }
+      if (depth == 0)
+        {
+          res += fputs_if (true, out, padding, sym->tag);
+        }
+      else
+        {
+          res += fputs_if (depth == 1, out, padding, down_arrow);
+          if (gl_list_size (deriv->children) == 0)
+            // Empty rhs.
+            res += fputs_if (depth == 1, out, padding, empty);
+          else
+            {
+              bool first = true;
+              derivation *child;
+              for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+                   derivation_list_next (&it, &child);
+                   )
+                {
+                  if (!first)
+                    res += fputs_if (depth == 1, out, padding, derivation_separator);
+                  res += derivation_print_tree_impl (child, out, depth - 1, padding);
+                  first = false;
+                }
+            }
+        }
+      if (depth == 0 || depth == 1)
+        {
+          end_use_class ("cex-step", out);
+          end_use_class (style, out);
+        }
+      *padding += width - res;
+      res = width;
+    }
+  else if (deriv == &d_dot)
+    {
+      if (depth == 0)
+        begin_use_class ("cex-dot", out);
+      res += fputs_if (depth == 0, out, padding, dot);
+      if (depth == 0)
+        end_use_class ("cex-dot", out);
+    }
+  else // leaf.
+    {
+      const symbol *sym = symbols[deriv->sym];
+      if (depth == 0)
+        begin_use_class ("cex-leaf", out);
+      res += fputs_if (depth == 0, out, padding, sym->tag);
+      if (depth == 0)
+        end_use_class ("cex-leaf", out);
+    }
+  return res;
+}
+
+static void
+derivation_print_tree (const derivation *deriv, FILE *out, const char *prefix)
+{
+  fputc ('\n', out);
+  for (int depth = 0, max_depth = derivation_depth (deriv);
+       depth < max_depth; ++depth)
+    {
+      int padding = 0;
+      fprintf (out, "    %s", prefix);
+      derivation_print_tree_impl (deriv, out, depth, &padding);
+      fputc ('\n', out);
+    }
+}
+
+
 /* Print DERIV, colored according to COUNTER.
    Return false if nothing is printed.  */
 static bool
-derivation_print_impl (const derivation *deriv, FILE *out,
-                       bool leaves_only,
-                       int *counter, const char *prefix)
+derivation_print_flat_impl (derivation *deriv, FILE *out,
+                            bool leaves_only,
+                            int *counter, const char *prefix)
 {
   if (deriv->children)
     {
       const symbol *sym = symbols[deriv->sym];
-      char style[20];
-      snprintf (style, 20, "cex-%d", *counter);
+      deriv->color = *counter;
       ++*counter;
+      char style[20];
+      snprintf (style, 20, "cex-%d", deriv->color);
       begin_use_class (style, out);
 
       if (!leaves_only)
@@ -156,7 +379,8 @@ derivation_print_impl (const derivation *deriv, FILE *out,
            derivation_list_next (&it, &child);
            )
         {
-          if (derivation_print_impl (child, out, leaves_only, counter, prefix))
+          if (derivation_print_flat_impl (child, out,
+                                          leaves_only, counter, prefix))
             {
               prefix = " ";
               res = true;
@@ -194,21 +418,29 @@ derivation_print_impl (const derivation *deriv, FILE *out,
   return true;
 }
 
-void
-derivation_print (const derivation *deriv, FILE *out, const char *prefix)
+static void
+derivation_print_flat (const derivation *deriv, FILE *out, const char *prefix)
 {
   int counter = 0;
   fputs (prefix, out);
-  derivation_print_impl (deriv, out, false, &counter, "");
+  derivation_print_flat_impl ((derivation *)deriv, out, false, &counter, "");
   fputc ('\n', out);
 }
 
-
 void
 derivation_print_leaves (const derivation *deriv, FILE *out, const char *prefix)
 {
   int counter = 0;
   fputs (prefix, out);
-  derivation_print_impl (deriv, out, true, &counter, "");
+  derivation_print_flat_impl ((derivation *)deriv, out, true, &counter, "");
   fputc ('\n', out);
 }
+
+void
+derivation_print (const derivation *deriv, FILE *out, const char *prefix)
+{
+  if (getenv ("YYFLAT"))
+    derivation_print_flat (deriv, out, prefix);
+  else
+    derivation_print_tree (deriv, out, prefix);
+}
