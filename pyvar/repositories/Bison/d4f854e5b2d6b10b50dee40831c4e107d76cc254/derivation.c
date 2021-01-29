@@ -180,18 +180,20 @@ derivation_print_impl (const derivation *deriv, FILE *f,
 }
 
 void
-derivation_print (const derivation *deriv, FILE *f)
+derivation_print (const derivation *deriv, FILE *out, const char *prefix)
 {
   int counter = 0;
-  derivation_print_impl (deriv, f, false, &counter);
-  fputc ('\n', f);
+  fputs (prefix, out);
+  derivation_print_impl (deriv, out, false, &counter);
+  fputc ('\n', out);
 }
 
 
 void
-derivation_print_leaves (const derivation *deriv, FILE *f)
+derivation_print_leaves (const derivation *deriv, FILE *out, const char *prefix)
 {
   int counter = 0;
-  derivation_print_impl (deriv, f, true, &counter);
-  fputc ('\n', f);
+  fputs (prefix, out);
+  derivation_print_impl (deriv, out, true, &counter);
+  fputc ('\n', out);
 }
