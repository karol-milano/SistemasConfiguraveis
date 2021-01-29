@@ -500,8 +500,9 @@ output_skeleton (void)
   full_path[pkgdatadirlen] = '/';
   strcpy (full_path + pkgdatadirlen + 1, m4sugar);
   in = fopen (full_path, "r");
-  if (! in || fclose (in) != 0)
+  if (! in)
     error (EXIT_FAILURE, errno, "%s", full_path);
+  xfclose (in);
   strcpy (full_path + pkgdatadirlen + 1, skeleton);
 
   /* Create an m4 subprocess connected to us via two pipes.  */
@@ -539,8 +540,6 @@ output_skeleton (void)
 
   fputs ("m4_wrap([m4_divert_pop(0)])\n", out);
   fputs ("m4_divert_push(0)dnl\n", out);
-  if (ferror (out))
-    error (EXIT_FAILURE, 0, "pipe output error");
   xfclose (out);
 
   /* Read and process m4's output.  */
@@ -549,8 +548,6 @@ output_skeleton (void)
   if (! in)
     error (EXIT_FAILURE, errno, "fdopen");
   scan_skel (in);
-  if (ferror (in))
-    error (EXIT_FAILURE, 0, "pipe input error");
   xfclose (in);
   reap_subpipe (pid, m4);
   timevar_pop (TV_M4);
