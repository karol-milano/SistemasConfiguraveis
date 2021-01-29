@@ -47,7 +47,7 @@ print_derives (void)
       fprintf (stderr, "  %s derives\n", symbols[i]->tag);
       for (rule **rp = derives[i - ntokens]; *rp; ++rp)
         {
-          fprintf (stderr, "    %3d ", (*rp)->user_number);
+          fprintf (stderr, "    %3d ", (*rp)->code);
           rule_rhs_print (*rp, stderr);
           fprintf (stderr, "\n");
         }
