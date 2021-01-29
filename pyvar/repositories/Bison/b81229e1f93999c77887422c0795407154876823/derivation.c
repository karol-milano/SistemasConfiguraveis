@@ -428,10 +428,9 @@ derivation_print_flat (const derivation *deriv, FILE *out, const char *prefix)
 }
 
 void
-derivation_print_leaves (const derivation *deriv, FILE *out, const char *prefix)
+derivation_print_leaves (const derivation *deriv, FILE *out)
 {
   int counter = 0;
-  fputs (prefix, out);
   derivation_print_flat_impl ((derivation *)deriv, out, true, &counter, "");
   fputc ('\n', out);
 }
