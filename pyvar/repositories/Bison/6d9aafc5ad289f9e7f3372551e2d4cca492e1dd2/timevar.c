@@ -20,26 +20,13 @@
 
 #include <config.h>
 
-#if IN_GCC
-
-#include "system.h"
-#include "intl.h"
-#include "rtl.h"
-
-#else
-
-/* This source file is taken from the GCC source code, with slight
-   modifications that are under control of the IN_GCC preprocessor
-   variable.  The !IN_GCC part of this file is specific to Bison.  */
-
-# include "../src/system.h"
-# if HAVE_SYS_TIME_H
-#  include <sys/time.h>
-# endif
-int timevar_report = 0;
+/* This source file was taken from the GCC source code.  */
 
+#include "../src/system.h"
+#if HAVE_SYS_TIME_H
+# include <sys/time.h>
 #endif
-
+int timevar_report = 0;
 
 #ifdef HAVE_SYS_TIMES_H
 # include <sys/times.h>
@@ -72,10 +59,6 @@ extern clock_t times (struct tms *);
 extern clock_t clock (void);
 #endif
 
-#ifndef RUSAGE_SELF
-# define RUSAGE_SELF 0
-#endif
-
 /* Calculation of scale factor to convert ticks to microseconds.
    We mustn't use CLOCKS_PER_SEC except with clock().  */
 #if HAVE_SYSCONF && defined _SC_CLK_TCK
@@ -126,9 +109,6 @@ static float clocks_to_msec;
 #define CLOCKS_TO_MSEC (1.0 / CLOCKS_PER_SEC)
 #endif
 
-#if IN_GCC
-#include "flags.h"
-#endif
 #include "timevar.h"
 
 /* See timevar.h for an explanation of timing variables.  */
@@ -211,21 +191,12 @@ get_time (now)
 #ifdef USE_TIMES
     struct tms tms;
     now->wall = times (&tms)  * ticks_to_msec;
-#if IN_GCC
-    now->user = tms.tms_utime * ticks_to_msec;
-    now->sys  = tms.tms_stime * ticks_to_msec;
-#else
     now->user = (tms.tms_utime + tms.tms_cutime) * ticks_to_msec;
     now->sys  = (tms.tms_stime + tms.tms_cstime) * ticks_to_msec;
 #endif
-#endif
 #ifdef USE_GETRUSAGE
     struct rusage rusage;
-#if IN_GCC
-    getrusage (RUSAGE_SELF, &rusage);
-#else
     getrusage (RUSAGE_CHILDREN, &rusage);
-#endif
     now->user = rusage.ru_utime.tv_sec + rusage.ru_utime.tv_usec * 1e-6;
     now->sys  = rusage.ru_stime.tv_sec + rusage.ru_stime.tv_usec * 1e-6;
 #endif
