@@ -134,6 +134,15 @@ xfclose (FILE *ptr)
 }
 
 
+FILE *
+xfdopen (int fd, char const *mode)
+{
+  FILE *res = fdopen (fd, mode);
+  if (! res)
+    error (EXIT_FAILURE, get_errno (), "fdopen");
+  return res;
+}
+
 /*------------------------------------------------------------------.
 | Compute ALL_BUT_EXT, ALL_BUT_TAB_EXT and output files extensions. |
 `------------------------------------------------------------------*/
