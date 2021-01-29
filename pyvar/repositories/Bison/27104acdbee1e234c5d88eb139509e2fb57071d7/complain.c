@@ -279,15 +279,18 @@ error_message (const location *loc, warnings flags, const char *prefix,
         *indent_ptr = pos;
       else if (*indent_ptr > pos)
         fprintf (stderr, "%*s", *indent_ptr - pos, "");
-      indent_ptr = 0;
+      indent_ptr = NULL;
     }
 
   if (prefix)
     fprintf (stderr, "%s: ", prefix);
 
   vfprintf (stderr, message, args);
-  if (! (flags & silent))
+  /* Print the type of warning, only if this is not a sub message
+     (in which case the prefix is null).  */
+  if (! (flags & silent) && prefix)
     warnings_print_categories (flags, stderr);
+
   {
     size_t l = strlen (message);
     if (l < 2 || message[l - 2] != ':' || message[l - 1] != ' ')
