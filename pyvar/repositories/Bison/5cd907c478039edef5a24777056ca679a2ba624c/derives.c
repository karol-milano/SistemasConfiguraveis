@@ -47,10 +47,10 @@ print_derives (void)
   for (i = ntokens; i < nsyms; i++)
     {
       rule **rp;
-      fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
+      fprintf (stderr, "  %s derives\n", symbols[i]->tag);
       for (rp = derives[i - ntokens]; *rp; ++rp)
         {
-          fprintf (stderr, "\t\t%3d ", (*rp)->user_number);
+          fprintf (stderr, "    %3d ", (*rp)->user_number);
           rule_rhs_print (*rp, stderr);
           fprintf (stderr, "\n");
         }
