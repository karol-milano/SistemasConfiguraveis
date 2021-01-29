@@ -117,7 +117,7 @@ warn (const char *message, ...)
   va_list args;
 
   fflush (stdout);
-  fprintf (stderr, "%s: %s", infile ? infile : program_name, _("warning: "));
+  fprintf (stderr, "%s: %s", current_file ? current_file : program_name, _("warning: "));
 
   va_start (args, message);
   vfprintf (stderr, message, args);
@@ -156,7 +156,7 @@ complain (const char *message, ...)
   va_list args;
 
   fflush (stdout);
-  fprintf (stderr, "%s: ", infile ? infile : program_name);
+  fprintf (stderr, "%s: ", current_file ? current_file : program_name);
 
   va_start (args, message);
   vfprintf (stderr, message, args);
@@ -195,7 +195,7 @@ fatal (const char *message, ...)
   va_list args;
 
   fflush (stdout);
-  fprintf (stderr, "%s: ", infile ? infile : program_name);
+  fprintf (stderr, "%s: ", current_file ? current_file : program_name);
 
   fputs (_("fatal error: "), stderr);
 
