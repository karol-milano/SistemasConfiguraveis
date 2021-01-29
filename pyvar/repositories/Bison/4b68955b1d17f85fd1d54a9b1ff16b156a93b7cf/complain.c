@@ -1,5 +1,5 @@
 /* Declaration for error-reporting function for Bison.
-   Copyright (C) 2000, 2001, 2002  Free Software Foundation, Inc.
+   Copyright (C) 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
@@ -32,6 +32,7 @@
 #endif
 
 #include "complain.h"
+#include "files.h"
 
 #ifndef _
 # define _(String) String
@@ -98,7 +99,7 @@ warn_at (location_t location, const char *message, ...)
   va_list args;
 
   fflush (stdout);
-  LOCATION_PRINT (stderr, location);
+  location_print (stderr, location);
   fputs (": ", stderr);
   fputs (_("warning: "), stderr);
 
@@ -138,7 +139,7 @@ complain_at (location_t location, const char *message, ...)
   va_list args;
 
   fflush (stdout);
-  LOCATION_PRINT (stderr, location);
+  location_print (stderr, location);
   fputs (": ", stderr);
 
   va_start (args, message);
@@ -177,7 +178,7 @@ fatal_at (location_t location, const char *message, ...)
   va_list args;
 
   fflush (stdout);
-  LOCATION_PRINT (stderr, location);
+  location_print (stderr, location);
   fputs (": ", stderr);
   fputs (_("fatal error: "), stderr);
 
