@@ -135,12 +135,6 @@ derivation_size (const derivation *deriv)
 }
 
 
-static int
-max (int a, int b)
-{
-  return a < b ? b : a;
-}
-
 // Longest distance from root to leaf.
 static int
 derivation_depth (const derivation *deriv)
@@ -154,7 +148,7 @@ derivation_depth (const derivation *deriv)
       for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
            derivation_list_next (&it, &child);
            )
-        res = max (res, derivation_depth (child));
+        res = max_int (res, derivation_depth (child));
       return res + 1;
     }
   else
@@ -237,7 +231,7 @@ derivation_width (const derivation *deriv)
           // No separator at the beginning.
           children_width -= derivation_separator_width;
         }
-      return max (self_width, children_width);
+      return max_int (self_width, children_width);
     }
   else if (deriv == &d_dot)
     {
