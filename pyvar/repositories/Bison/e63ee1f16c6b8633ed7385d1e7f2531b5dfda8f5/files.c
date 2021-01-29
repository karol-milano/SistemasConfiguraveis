@@ -120,19 +120,17 @@ xfopen (const char *name, const char *mode)
 | Try to close file PTR, and print an error message if fails.  |
 `-------------------------------------------------------------*/
 
-int
+void
 xfclose (FILE *ptr)
 {
-  int result;
-
   if (ptr == NULL)
-    return 0;
+    return;
 
-  result = fclose (ptr);
-  if (result == EOF)
-    error (EXIT_FAILURE, errno, _("cannot close file"));
+  if (ferror (ptr))
+    error (EXIT_FAILURE, 0, _("I/O error"));
 
-  return result;
+  if (fclose (ptr) != 0)
+    error (EXIT_FAILURE, errno, _("cannot close file"));
 }
 
 
