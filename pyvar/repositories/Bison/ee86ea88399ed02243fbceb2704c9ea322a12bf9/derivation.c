@@ -145,7 +145,9 @@ derivation_print_impl (const derivation *deriv, FILE *f,
         {
           fputs (prefix, f);
           begin_use_class ("cex-step", f);
-          fprintf (f, "%s ::=[ ", sym->tag);
+          fprintf (f, "%s ", sym->tag);
+          print_arrow (f);
+          fprintf (f, " [ ");
           end_use_class ("cex-step", f);
           prefix = "";
         }
