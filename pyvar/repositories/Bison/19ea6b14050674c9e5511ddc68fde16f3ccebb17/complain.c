@@ -338,12 +338,17 @@ warning_is_unset (warnings flags)
   return true;
 }
 
+bool
+warning_is_enabled (warnings flags)
+{
+  return severity_warning <= warning_severity (flags);
+}
+
 /** Display a "[-Wyacc]" like message on \a out.  */
 
 static void
 warnings_print_categories (warnings warn_flags, FILE *out)
 {
-  /* Display only the first match, the second is "-Wall".  */
   for (size_t i = 0; warnings_args[i]; ++i)
     if (warn_flags & warnings_types[i])
       {
@@ -356,6 +361,7 @@ warnings_print_categories (warnings warn_flags, FILE *out)
                  warnings_args[i]);
         end_use_class (style, out);
         fputc (']', out);
+        /* Display only the first match, the second is "-Wall".  */
         return;
       }
 }
@@ -426,8 +432,7 @@ error_message (const location *loc, warnings flags, severity sever,
   fflush (stderr);
 }
 
-/** Raise a complaint. That can be a fatal error, an error or just a
-    warning.  */
+/** Raise a complaint (fatal error, error or just warning).  */
 
 static void
 complains (const location *loc, warnings flags, const char *message,
