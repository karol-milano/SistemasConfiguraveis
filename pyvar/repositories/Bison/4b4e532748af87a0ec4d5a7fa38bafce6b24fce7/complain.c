@@ -425,7 +425,7 @@ error_message (const location *loc, int *indent, warnings flags,
   if (loc)
     pos += location_print (*loc, stderr);
   else
-    pos += fprintf (stderr, "%s", current_file ? current_file : program_name);
+    pos += fprintf (stderr, "%s", grammar_file ? grammar_file : program_name);
   pos += fprintf (stderr, ": ");
 
   if (indent)
