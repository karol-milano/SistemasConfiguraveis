@@ -111,7 +111,7 @@ xfopen (const char *name, const char *mode)
 
   ptr = fopen (name, mode);
   if (!ptr)
-    error (2, errno, _("cannot open file `%s'"), name);
+    error (EXIT_FAILURE, errno, _("cannot open file `%s'"), name);
 
   return ptr;
 }
@@ -130,7 +130,7 @@ xfclose (FILE *ptr)
 
   result = fclose (ptr);
   if (result == EOF)
-    error (2, errno, _("cannot close file"));
+    error (EXIT_FAILURE, errno, _("cannot close file"));
 
   return result;
 }
