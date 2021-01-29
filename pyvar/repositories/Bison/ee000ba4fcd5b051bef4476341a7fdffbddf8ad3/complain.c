@@ -116,10 +116,10 @@ unsigned int complain_message_count;
 
 void
 #if defined VA_START && defined __STDC__
-warn_at (int location, const char *message, ...)
+warn_at (location_t location, const char *message, ...)
 #else
 warn_at (location, message, va_alist)
-  int location
+  location_t location
   char *message;
   va_dcl
 #endif
@@ -133,21 +133,18 @@ warn_at (location, message, va_alist)
       static const char *old_infile;
       static int old_lineno;
 
-      if (old_lineno == location &&
+      if (old_lineno == location.first_line &&
 	  (infile == old_infile || !strcmp (old_infile, infile)))
 	/* Simply return and print nothing.  */
 	return;
 
       old_infile = infile;
-      old_lineno = location;
+      old_lineno = location.first_line;
     }
 
   fflush (stdout);
-  if (infile != NULL)
-    fprintf (stderr, "%s:%d: ", infile, location);
-  else
-    fprintf (stderr, "%s:", program_name);
-
+  LOCATION_PRINT (stderr, location);
+  fputs (": ", stderr);
   fputs (_("warning: "), stderr);
 
 #ifdef VA_START
@@ -218,10 +215,10 @@ warn (message, va_alist)
 
 void
 #if defined VA_START && defined __STDC__
-complain_at (int location, const char *message, ...)
+complain_at (location_t location, const char *message, ...)
 #else
 complain_at (location, message, va_alist)
-  int location;
+  location_t location;
   char *message;
   va_dcl
 #endif
@@ -235,20 +232,18 @@ complain_at (location, message, va_alist)
       static const char *old_infile;
       static int old_lineno;
 
-      if (old_lineno == location &&
+      if (old_lineno == location.first_line &&
 	  (infile == old_infile || !strcmp (old_infile, infile)))
 	/* Simply return and print nothing.  */
 	return;
 
       old_infile = infile;
-      old_lineno = location;
+      old_lineno = location.first_line;
     }
 
   fflush (stdout);
-  if (infile != NULL)
-    fprintf (stderr, "%s:%d: ", infile, location);
-  else
-    fprintf (stderr, "%s:", program_name);
+  LOCATION_PRINT (stderr, location);
+  fputs (": ", stderr);
 
 #ifdef VA_START
   VA_START (args, message);
@@ -316,10 +311,10 @@ complain (message, va_alist)
 
 void
 #if defined VA_START && defined __STDC__
-fatal_at (int location, const char *message, ...)
+fatal_at (location_t location, const char *message, ...)
 #else
 fatal (location, message, va_alist)
-  int location;
+  location_t location;
   char *message;
   va_dcl
 #endif
@@ -329,11 +324,8 @@ fatal (location, message, va_alist)
 #endif
 
   fflush (stdout);
-  if (infile != NULL)
-    fprintf (stderr, "%s:%d: ", infile, location);
-  else
-    fprintf (stderr, "%s:", program_name);
-
+  LOCATION_PRINT (stderr, location);
+  fputs (": ", stderr);
   fputs (_("fatal error: "), stderr);
 
 #ifdef VA_START
