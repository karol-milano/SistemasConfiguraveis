@@ -52,6 +52,7 @@ print_derives (void)
         {
           fprintf (stderr, "\t\t%3d ", (*rp)->user_number);
           rule_rhs_print (*rp, stderr);
+          fprintf (stderr, "\n");
         }
     }
 
