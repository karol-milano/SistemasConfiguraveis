@@ -103,6 +103,7 @@ print_fderives (void)
         {
           fprintf (stderr, "\t\t%3d ", r);
           rule_rhs_print (&rules[r], stderr);
+          fprintf (stderr, "\n");
         }
     }
   fprintf (stderr, "\n\n");
