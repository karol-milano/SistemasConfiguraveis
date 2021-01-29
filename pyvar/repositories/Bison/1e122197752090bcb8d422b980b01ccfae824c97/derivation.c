@@ -29,7 +29,7 @@
 struct derivation
 {
   symbol_number sym;
-  gl_list_t children;
+  derivation_list children;
   int reference_count;
 };
 
@@ -129,7 +129,7 @@ derivation_size (const derivation *deriv)
 /* Print DERIV, colored according to COUNTER.
    Return false if nothing is printed.  */
 static bool
-derivation_print_impl (const derivation *deriv, FILE *f,
+derivation_print_impl (const derivation *deriv, FILE *out,
                        bool leaves_only,
                        int *counter, const char *prefix)
 {
@@ -139,16 +139,16 @@ derivation_print_impl (const derivation *deriv, FILE *f,
       char style[20];
       snprintf (style, 20, "cex-%d", *counter);
       ++*counter;
-      begin_use_class (style, f);
+      begin_use_class (style, out);
 
       if (!leaves_only)
         {
-          fputs (prefix, f);
-          begin_use_class ("cex-step", f);
-          fprintf (f, "%s ", sym->tag);
-          print_arrow (f);
-          fprintf (f, " [ ");
-          end_use_class ("cex-step", f);
+          fputs (prefix, out);
+          begin_use_class ("cex-step", out);
+          fprintf (out, "%s ", sym->tag);
+          print_arrow (out);
+          fprintf (out, " [ ");
+          end_use_class ("cex-step", out);
           prefix = "";
         }
       bool res = false;
@@ -157,7 +157,7 @@ derivation_print_impl (const derivation *deriv, FILE *f,
            derivation_list_next (&it, &child);
            )
         {
-          if (derivation_print_impl (child, f, leaves_only, counter, prefix))
+          if (derivation_print_impl (child, out, leaves_only, counter, prefix))
             {
               prefix = " ";
               res = true;
@@ -167,30 +167,30 @@ derivation_print_impl (const derivation *deriv, FILE *f,
         }
       if (!leaves_only)
         {
-          begin_use_class ("cex-step", f);
+          begin_use_class ("cex-step", out);
           if (res)
-            fputs (" ]", f);
+            fputs (" ]", out);
           else
-            fputs ("]", f);
-          end_use_class ("cex-step", f);
+            fputs ("]", out);
+          end_use_class ("cex-step", out);
         }
-      end_use_class (style, f);
+      end_use_class (style, out);
       return res;
     }
   else if (deriv == &d_dot)
     {
-      fputs (prefix, f);
-      begin_use_class ("cex-dot", f);
-      print_dot (f);
-      end_use_class ("cex-dot", f);
+      fputs (prefix, out);
+      begin_use_class ("cex-dot", out);
+      print_dot (out);
+      end_use_class ("cex-dot", out);
     }
   else // leaf.
     {
-      fputs (prefix, f);
+      fputs (prefix, out);
       const symbol *sym = symbols[deriv->sym];
-      begin_use_class ("cex-leaf", f);
-      fprintf (f, "%s", sym->tag);
-      end_use_class ("cex-leaf", f);
+      begin_use_class ("cex-leaf", out);
+      fprintf (out, "%s", sym->tag);
+      end_use_class ("cex-leaf", out);
     }
   return true;
 }
