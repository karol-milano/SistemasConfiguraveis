@@ -19,14 +19,10 @@
 /* Based on error.c and error.h,
    written by David MacKenzie <djm@gnu.ai.mit.edu>.  */
 
-#ifdef HAVE_CONFIG_H
-# include <config.h>
-#endif
-
-#include <stdio.h>
+#include "system.h"
 
 #if HAVE_VPRINTF || HAVE_DOPRNT || _LIBC
-# if __STDC__
+# ifdef __STDC__
 #  include <stdarg.h>
 #  define VA_START(args, lastarg) va_start(args, lastarg)
 # else
@@ -119,7 +115,7 @@ int error_one_per_line;
 `--------------------------------*/
 
 void
-#if defined VA_START && __STDC__
+#if defined VA_START && defined __STDC__
 warn (const char *message, ...)
 #else
 warn (message, va_alist)
@@ -171,7 +167,7 @@ warn (message, va_alist)
 `-----------------------------------------------------------*/
 
 void
-#if defined VA_START && __STDC__
+#if defined VA_START && defined __STDC__
 complain (const char *message, ...)
 #else
 complain (message, va_alist)
@@ -221,7 +217,7 @@ complain (message, va_alist)
 `-------------------------------------------------*/
 
 void
-#if defined VA_START && __STDC__
+#if defined VA_START && defined __STDC__
 fatal (const char *message, ...)
 #else
 fatal (message, va_alist)
@@ -259,7 +255,7 @@ fatal (message, va_alist)
 `------------------------------------------------------------------*/
 
 void
-#if defined VA_START && __STDC__
+#if defined VA_START && defined __STDC__
 error (int status, int errnum,
        const char *message, ...)
 #else
