@@ -100,6 +100,7 @@ error_message (const location *loc, warnings flags, const char *prefix,
     fprintf (stderr, "%s: ", prefix);
 
   vfprintf (stderr, message, args);
+  warnings_print_categories (flags);
   {
     size_t l = strlen (message);
     if (l < 2 || message[l-2] != ':' || message[l-1] != ' ')
