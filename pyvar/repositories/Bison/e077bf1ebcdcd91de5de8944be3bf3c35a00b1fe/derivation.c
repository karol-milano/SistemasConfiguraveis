@@ -167,7 +167,7 @@ derivation_print_impl (const derivation *deriv, FILE *f,
   else if (deriv == &d_dot)
     {
       begin_use_class ("cex-dot", f);
-      fputs ("•", f);
+      print_dot (f);
       end_use_class ("cex-dot", f);
     }
   else // leaf.
