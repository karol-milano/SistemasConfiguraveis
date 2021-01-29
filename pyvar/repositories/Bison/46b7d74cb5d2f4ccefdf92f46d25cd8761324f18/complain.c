@@ -90,8 +90,8 @@ error_message (const location *loc, warnings flags, const char *prefix,
   if (loc)
     pos += location_print (stderr, *loc);
   else
-    pos += fprintf(stderr, "%s", current_file ? current_file : program_name);
-  pos += fprintf(stderr, ": ");
+    pos += fprintf (stderr, "%s", current_file ? current_file : program_name);
+  pos += fprintf (stderr, ": ");
 
   if (indent_ptr)
     {
