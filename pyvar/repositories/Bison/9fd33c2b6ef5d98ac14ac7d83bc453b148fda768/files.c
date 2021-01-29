@@ -139,7 +139,10 @@ xfdopen (int fd, char const *mode)
 {
   FILE *res = fdopen (fd, mode);
   if (! res)
-    error (EXIT_FAILURE, get_errno (), "fdopen");
+    error (EXIT_FAILURE, get_errno (),
+           // On a separate line to please the "unmarked_diagnostics"
+           // syntax-check.
+           "fdopen");
   return res;
 }
 
