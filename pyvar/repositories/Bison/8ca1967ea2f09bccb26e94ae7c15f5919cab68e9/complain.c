@@ -74,7 +74,6 @@ warn_at (location loc, const char *message, ...)
 {
   va_list args;
 
-  fflush (stdout);
   location_print (stderr, loc);
   fputs (": ", stderr);
   fputs (_("warning: "), stderr);
@@ -85,7 +84,6 @@ warn_at (location loc, const char *message, ...)
 
   warning_issued = true;
   putc ('\n', stderr);
-  fflush (stderr);
 }
 
 void
@@ -93,7 +91,6 @@ warn (const char *message, ...)
 {
   va_list args;
 
-  fflush (stdout);
   fprintf (stderr, "%s: %s", current_file ? current_file : program_name, _("warning: "));
 
   va_start (args, message);
@@ -102,7 +99,6 @@ warn (const char *message, ...)
 
   warning_issued = true;
   putc ('\n', stderr);
-  fflush (stderr);
 }
 
 /*-----------------------------------------------------------.
@@ -114,7 +110,6 @@ complain_at (location loc, const char *message, ...)
 {
   va_list args;
 
-  fflush (stdout);
   location_print (stderr, loc);
   fputs (": ", stderr);
 
@@ -124,7 +119,6 @@ complain_at (location loc, const char *message, ...)
 
   complaint_issued = true;
   putc ('\n', stderr);
-  fflush (stderr);
 }
 
 void
@@ -132,7 +126,6 @@ complain (const char *message, ...)
 {
   va_list args;
 
-  fflush (stdout);
   fprintf (stderr, "%s: ", current_file ? current_file : program_name);
 
   va_start (args, message);
@@ -141,7 +134,6 @@ complain (const char *message, ...)
 
   complaint_issued = true;
   putc ('\n', stderr);
-  fflush (stderr);
 }
 
 /*-------------------------------------------------.
@@ -153,7 +145,6 @@ fatal_at (location loc, const char *message, ...)
 {
   va_list args;
 
-  fflush (stdout);
   location_print (stderr, loc);
   fputs (": ", stderr);
   fputs (_("fatal error: "), stderr);
@@ -162,7 +153,6 @@ fatal_at (location loc, const char *message, ...)
   vfprintf (stderr, message, args);
   va_end (args);
   putc ('\n', stderr);
-  fflush (stderr);
   exit (EXIT_FAILURE);
 }
 
@@ -171,7 +161,6 @@ fatal (const char *message, ...)
 {
   va_list args;
 
-  fflush (stdout);
   fprintf (stderr, "%s: ", current_file ? current_file : program_name);
 
   fputs (_("fatal error: "), stderr);
@@ -180,6 +169,5 @@ fatal (const char *message, ...)
   vfprintf (stderr, message, args);
   va_end (args);
   putc ('\n', stderr);
-  fflush (stderr);
   exit (EXIT_FAILURE);
 }
