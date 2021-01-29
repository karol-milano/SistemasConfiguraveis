@@ -958,10 +958,9 @@ static void
 output_skeleton (void)
 {
   /* Store the definition of all the muscles. */
-  char *tempdir = getenv ("TMPDIR");
+  const char *tempdir = getenv ("TMPDIR");
   char *tempfile = NULL;
   FILE *out = NULL;
-  ssize_t bytes_read;
   int fd;
 
   if (tempdir == NULL)
