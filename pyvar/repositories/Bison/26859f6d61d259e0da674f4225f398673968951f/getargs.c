@@ -724,7 +724,7 @@ getargs (int argc, char *argv[])
   if (argc - optind != 1)
     {
       if (argc - optind < 1)
-        error (0, 0, _("%s: missing operand"), quotearg_colon (argv[argc - 1]));
+        error (0, 0, _("missing operand"));
       else
         error (0, 0, _("extra operand %s"), quote (argv[optind + 1]));
       usage (EXIT_FAILURE);
