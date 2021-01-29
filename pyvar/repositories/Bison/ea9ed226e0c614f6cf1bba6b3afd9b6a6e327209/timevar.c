@@ -19,24 +19,11 @@ along with GCC; see the file COPYING.  If not, write to the Free
 Software Foundation, 59 Temple Place - Suite 330, Boston, MA
 02111-1307, USA.  */
 
-#if IN_GCC
-
-/* These are the original includes --akim.  */
 #include "config.h"
 #include "system.h"
 #include "intl.h"
 #include "rtl.h"
 
-#else
-
-/* These are my replacements by hand --akim.
-   There is another change below, flag with IN_GCC.  */
-# include "../src/system.h"
-int time_report = 0;
-
-#endif
-
-
 #ifdef HAVE_SYS_TIMES_H
 # include <sys/times.h>
 #endif
@@ -122,14 +109,12 @@ static float clocks_to_msec;
 #define CLOCKS_TO_MSEC (1 / (float)CLOCKS_PER_SEC)
 #endif
 
-#if IN_GCC
 #include "flags.h"
-#endif
 #include "timevar.h"
 
 /* See timevar.h for an explanation of timing variables.  */
 
-/* This macro evaluates to non-zero if timing variables are enabled.  */
+/* This macro evaluates to nonzero if timing variables are enabled.  */
 #define TIMEVAR_ENABLE (time_report)
 
 /* A timing variable.  */
@@ -191,7 +176,7 @@ static void timevar_accumulate
 
 /* Fill the current times into TIME.  The definition of this function
    also defines any or all of the HAVE_USER_TIME, HAVE_SYS_TIME, and
-   HAVA_WALL_TIME macros.  */
+   HAVE_WALL_TIME macros.  */
 
 static void
 get_time (now)
@@ -207,18 +192,15 @@ get_time (now)
   {
 #ifdef USE_TIMES
     struct tms tms;
-    now->wall = times (&tms)   * ticks_to_msec;
-    now->user = (tms.tms_utime + tms.tms_cutime) * ticks_to_msec;
-    now->sys  = (tms.tms_stime + tms.tms_cstime) * ticks_to_msec;
+    now->wall = times (&tms)  * ticks_to_msec;
+    now->user = tms.tms_utime * ticks_to_msec;
+    now->sys  = tms.tms_stime * ticks_to_msec;
 #endif
 #ifdef USE_GETRUSAGE
     struct rusage rusage;
     getrusage (RUSAGE_SELF, &rusage);
     now->user = rusage.ru_utime.tv_sec + rusage.ru_utime.tv_usec * 1e-6;
     now->sys  = rusage.ru_stime.tv_sec + rusage.ru_stime.tv_usec * 1e-6;
-    getrusage (RUSAGE_CHILDREN, &rusage);
-    now->user += rusage.ru_utime.tv_sec + rusage.ru_utime.tv_usec * 1e-6;
-    now->sys  += rusage.ru_stime.tv_sec + rusage.ru_stime.tv_usec * 1e-6;
 #endif
 #ifdef USE_CLOCK
     now->user = clock () * clocks_to_msec;
@@ -230,9 +212,9 @@ get_time (now)
 
 static void
 timevar_accumulate (timer, start_time, stop_time)
-  struct timevar_time_def *timer;
-  struct timevar_time_def *start_time;
-  struct timevar_time_def *stop_time;
+     struct timevar_time_def *timer;
+     struct timevar_time_def *start_time;
+     struct timevar_time_def *stop_time;
 {
   timer->user += stop_time->user - start_time->user;
   timer->sys += stop_time->sys - start_time->sys;
@@ -551,6 +533,6 @@ print_time (str, total)
   fprintf (stderr,
 	   _("time in %s: %ld.%06ld (%ld%%)\n"),
 	   str, total / 1000000, total % 1000000,
- 	   all_time == 0 ? 0
- 	   : (long) (((100.0 * (double) total) / (double) all_time) + .5));
+	   all_time == 0 ? 0
+	   : (long) (((100.0 * (double) total) / (double) all_time) + .5));
 }
