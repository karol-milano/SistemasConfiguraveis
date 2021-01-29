@@ -41,9 +41,6 @@
 void exit ();
 #endif
 
-/* To get error_one_per_line. */
-#include "error.h"
-
 #include "complain.h"
 
 #ifndef HAVE_DECL_STRERROR_R
@@ -128,20 +125,6 @@ warn_at (location, message, va_alist)
   va_list args;
 #endif
 
-  if (error_one_per_line)
-    {
-      static const char *old_infile;
-      static int old_lineno;
-
-      if (old_lineno == location.first_line &&
-	  (infile == old_infile || !strcmp (old_infile, infile)))
-	/* Simply return and print nothing.  */
-	return;
-
-      old_infile = infile;
-      old_lineno = location.first_line;
-    }
-
   fflush (stdout);
   LOCATION_PRINT (stderr, location);
   fputs (": ", stderr);
@@ -178,20 +161,6 @@ complain_at (location, message, va_alist)
   va_list args;
 #endif
 
-  if (error_one_per_line)
-    {
-      static const char *old_infile;
-      static int old_lineno;
-
-      if (old_lineno == location.first_line &&
-	  (infile == old_infile || !strcmp (old_infile, infile)))
-	/* Simply return and print nothing.  */
-	return;
-
-      old_infile = infile;
-      old_lineno = location.first_line;
-    }
-
   fflush (stdout);
   LOCATION_PRINT (stderr, location);
   fputs (": ", stderr);
