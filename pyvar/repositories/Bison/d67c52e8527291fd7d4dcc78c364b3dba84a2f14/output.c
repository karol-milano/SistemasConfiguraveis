@@ -473,7 +473,7 @@ output_skeleton (void)
   FILE *in;
   FILE *out;
   int filter_fd[2];
-  char const *argv[7];
+  char const *argv[9];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton files.  */
@@ -524,6 +524,8 @@ output_skeleton (void)
   {
     int i = 0;
     argv[i++] = m4;
+    argv[i++] = "-I";
+    argv[i++] = pkgdatadir;
     if (trace_flag & trace_m4)
       argv[i++] = "-dV";
     argv[i++] = full_m4sugar;
