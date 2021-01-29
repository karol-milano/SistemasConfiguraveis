@@ -577,6 +577,7 @@ output_skeleton (void)
 
   /* Read and process m4's output.  */
   timevar_push (TV_M4);
+  end_of_output_subpipe (pid, filter_fd);
   in = fdopen (filter_fd[1], "r");
   if (! in)
     error (EXIT_FAILURE, get_errno (),
