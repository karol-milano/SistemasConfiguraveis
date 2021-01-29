@@ -127,7 +127,7 @@ xfclose (FILE *ptr)
     return;
 
   if (ferror (ptr))
-    error (EXIT_FAILURE, 0, _("I/O error"));
+    error (EXIT_FAILURE, 0, _("input/output error"));
 
   if (fclose (ptr) != 0)
     error (EXIT_FAILURE, get_errno (), _("cannot close file"));
