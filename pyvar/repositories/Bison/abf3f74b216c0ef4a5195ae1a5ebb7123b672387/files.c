@@ -109,7 +109,7 @@ xfopen (const char *name, const char *mode)
 
   ptr = fopen_safer (name, mode);
   if (!ptr)
-    error (EXIT_FAILURE, get_errno (), _("cannot open file `%s'"), name);
+    error (EXIT_FAILURE, get_errno (), _("cannot open file '%s'"), name);
 
   return ptr;
 }
