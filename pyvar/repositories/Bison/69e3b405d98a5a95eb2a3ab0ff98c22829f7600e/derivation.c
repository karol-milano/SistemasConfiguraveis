@@ -126,11 +126,12 @@ derivation_size (const derivation *deriv)
   return size;
 }
 
-/* Print DERIV, colored according to COUNTER.  */
-static void
+/* Print DERIV, colored according to COUNTER.
+   Return false if nothing is printed.  */
+static bool
 derivation_print_impl (const derivation *deriv, FILE *f,
                        bool leaves_only,
-                       int *counter)
+                       int *counter, const char *prefix)
 {
   if (deriv->children)
     {
@@ -142,41 +143,54 @@ derivation_print_impl (const derivation *deriv, FILE *f,
 
       if (!leaves_only)
         {
+          fputs (prefix, f);
           begin_use_class ("cex-step", f);
           fprintf (f, "%s ::=[ ", sym->tag);
           end_use_class ("cex-step", f);
+          prefix = "";
         }
-      const char *sep = "";
+      bool res = false;
       derivation *child;
       for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
            derivation_list_next (&it, &child);
            )
         {
-          fputs (sep, f);
-          sep = " ";
-          derivation_print_impl (child, f, leaves_only, counter);
+          if (derivation_print_impl (child, f, leaves_only, counter, prefix))
+            {
+              prefix = " ";
+              res = true;
+            }
+          else if (!leaves_only)
+            prefix = " ";
         }
       if (!leaves_only)
         {
           begin_use_class ("cex-step", f);
-          fputs (" ]", f);
+          if (res)
+            fputs (" ]", f);
+          else
+            fputs ("]", f);
           end_use_class ("cex-step", f);
         }
       end_use_class (style, f);
+      return res;
     }
   else if (deriv == &d_dot)
     {
+      fputs (prefix, f);
       begin_use_class ("cex-dot", f);
       print_dot (f);
       end_use_class ("cex-dot", f);
     }
   else // leaf.
     {
+      fputs (prefix, f);
       const symbol *sym = symbols[deriv->sym];
       begin_use_class ("cex-leaf", f);
       fprintf (f, "%s", sym->tag);
       end_use_class ("cex-leaf", f);
     }
+  return true;
 }
 
 void
@@ -184,7 +198,7 @@ derivation_print (const derivation *deriv, FILE *out, const char *prefix)
 {
   int counter = 0;
   fputs (prefix, out);
-  derivation_print_impl (deriv, out, false, &counter);
+  derivation_print_impl (deriv, out, false, &counter, "");
   fputc ('\n', out);
 }
 
@@ -194,6 +208,6 @@ derivation_print_leaves (const derivation *deriv, FILE *out, const char *prefix)
 {
   int counter = 0;
   fputs (prefix, out);
-  derivation_print_impl (deriv, out, true, &counter);
+  derivation_print_impl (deriv, out, true, &counter, "");
   fputc ('\n', out);
 }
