@@ -527,10 +527,6 @@ output_skeleton (void)
     error (EXIT_FAILURE, errno, "fdopen");
 
   /* Output the definitions of all the muscles.  */
-
-  /* There are no comments, especially not `#': we do want M4 expansion
-     after `#': think of CPP macros!  */
-  fputs ("m4_changecom()\n", out);
   fputs ("m4_init()\n", out);
 
   user_actions_output (out);
