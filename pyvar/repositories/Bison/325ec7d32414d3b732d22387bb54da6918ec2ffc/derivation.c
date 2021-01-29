@@ -245,6 +245,13 @@ derivation_width (const derivation *deriv)
         children_width += empty_width;
       else
         {
+          if (gl_list_size (deriv->children) == 1
+              && gl_list_get_first (deriv->children) == &d_dot)
+            {
+              children_width += empty_width;
+              children_width += derivation_separator_width;
+            }
+
           derivation *child;
           for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
                derivation_list_next (&it, &child);
@@ -310,6 +317,13 @@ derivation_print_tree_impl (const derivation *deriv, FILE *out,
             res += fputs_if (depth == 1, out, padding, empty);
           else
             {
+              if (gl_list_size (deriv->children) == 1
+                  && gl_list_get_first (deriv->children) == &d_dot)
+                {
+                  res += fputs_if (depth == 1, out, padding, empty);
+                  res += fputs_if (depth == 1, out, padding, derivation_separator);
+                }
+
               bool first = true;
               derivation *child;
               for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
