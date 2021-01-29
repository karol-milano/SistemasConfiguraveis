@@ -32,7 +32,7 @@ int timevar_report = 0;
 # include <sys/times.h>
 #endif
 #ifdef HAVE_SYS_RESOURCE_H
-#include <sys/resource.h>
+# include <sys/resource.h>
 #endif
 
 #ifndef HAVE_CLOCK_T
@@ -63,37 +63,29 @@ extern clock_t clock (void);
    We mustn't use CLOCKS_PER_SEC except with clock().  */
 #if HAVE_SYSCONF && defined _SC_CLK_TCK
 # define TICKS_PER_SECOND sysconf (_SC_CLK_TCK) /* POSIX 1003.1-1996 */
+#elif defined CLK_TCK
+# define TICKS_PER_SECOND CLK_TCK /* POSIX 1003.1-1988; obsolescent */
+#elif defined HZ
+# define TICKS_PER_SECOND HZ  /* traditional UNIX */
 #else
-# ifdef CLK_TCK
-#  define TICKS_PER_SECOND CLK_TCK /* POSIX 1003.1-1988; obsolescent */
-# else
-#  ifdef HZ
-#   define TICKS_PER_SECOND HZ  /* traditional UNIX */
-#  else
-#   define TICKS_PER_SECOND 100 /* often the correct value */
-#  endif
-# endif
+# define TICKS_PER_SECOND 100 /* often the correct value */
 #endif
 
 /* Prefer times to getrusage to clock (each gives successively less
    information).  */
-#ifdef HAVE_TIMES
+#if defined HAVE_TIMES
 # define USE_TIMES
 # define HAVE_USER_TIME
 # define HAVE_SYS_TIME
 # define HAVE_WALL_TIME
-#else
-#ifdef HAVE_GETRUSAGE
+#elif defined HAVE_GETRUSAGE
 # define USE_GETRUSAGE
 # define HAVE_USER_TIME
 # define HAVE_SYS_TIME
-#else
-#ifdef HAVE_CLOCK
+#elif defined HAVE_CLOCK
 # define USE_CLOCK
 # define HAVE_USER_TIME
 #endif
-#endif
-#endif
 
 /* libc is very likely to have snuck a call to sysconf() into one of
    the underlying constants, and that can be very slow, so we have to
@@ -101,12 +93,10 @@ extern clock_t clock (void);
    _constants_ variable at run time, anyway?  */
 #ifdef USE_TIMES
 static float ticks_to_msec;
-#define TICKS_TO_MSEC (1.0 / TICKS_PER_SECOND)
-#endif
-
-#ifdef USE_CLOCK
+# define TICKS_TO_MSEC (1.0 / TICKS_PER_SECOND)
+#elif defined USE_CLOCK
 static float clocks_to_msec;
-#define CLOCKS_TO_MSEC (1.0 / CLOCKS_PER_SEC)
+# define CLOCKS_TO_MSEC (1.0 / CLOCKS_PER_SEC)
 #endif
 
 #include "timevar.h"
@@ -192,14 +182,12 @@ get_time (struct timevar_time_def *now)
     now->wall = times (&tms)  * ticks_to_msec;
     now->user = (tms.tms_utime + tms.tms_cutime) * ticks_to_msec;
     now->sys  = (tms.tms_stime + tms.tms_cstime) * ticks_to_msec;
-#endif
-#ifdef USE_GETRUSAGE
+#elif defined USE_GETRUSAGE
     struct rusage rusage;
     getrusage (RUSAGE_CHILDREN, &rusage);
     now->user = rusage.ru_utime.tv_sec + rusage.ru_utime.tv_usec * 1e-6;
     now->sys  = rusage.ru_stime.tv_sec + rusage.ru_stime.tv_usec * 1e-6;
-#endif
-#ifdef USE_CLOCK
+#elif defined USE_CLOCK
     now->user = clock () * clocks_to_msec;
 #endif
   }
@@ -234,10 +222,9 @@ init_timevar ()
 #include "timevar.def"
 #undef DEFTIMEVAR
 
-#ifdef USE_TIMES
+#if defined USE_TIMES
   ticks_to_msec = TICKS_TO_MSEC;
-#endif
-#ifdef USE_CLOCK
+#elif defined USE_CLOCK
   clocks_to_msec = CLOCKS_TO_MSEC;
 #endif
 }
@@ -460,26 +447,26 @@ timevar_print (FILE *fp)
       /* The timing variable name.  */
       fprintf (fp, " %-22s:", tv->name);
 
-#ifdef HAVE_USER_TIME
+# ifdef HAVE_USER_TIME
       /* Print user-mode time for this process.  */
       fprintf (fp, "%7.2f (%2.0f%%) usr",
                tv->elapsed.user,
                (total->user == 0 ? 0 : tv->elapsed.user / total->user) * 100);
-#endif /* HAVE_USER_TIME */
+# endif
 
-#ifdef HAVE_SYS_TIME
+# ifdef HAVE_SYS_TIME
       /* Print system-mode time for this process.  */
       fprintf (fp, "%7.2f (%2.0f%%) sys",
                tv->elapsed.sys,
                (total->sys == 0 ? 0 : tv->elapsed.sys / total->sys) * 100);
-#endif /* HAVE_SYS_TIME */
+# endif
 
-#ifdef HAVE_WALL_TIME
+# ifdef HAVE_WALL_TIME
       /* Print wall clock time elapsed.  */
       fprintf (fp, "%7.2f (%2.0f%%) wall",
                tv->elapsed.wall,
                (total->wall == 0 ? 0 : tv->elapsed.wall / total->wall) * 100);
-#endif /* HAVE_WALL_TIME */
+# endif
 
       putc ('\n', fp);
     }
@@ -496,8 +483,7 @@ timevar_print (FILE *fp)
   fprintf (fp, "%7.2f\n", total->wall);
 #endif
 
-#endif /* defined (HAVE_USER_TIME) || defined (HAVE_SYS_TIME)
-          || defined (HAVE_WALL_TIME) */
+#endif /* defined HAVE_USER_TIME || defined HAVE_SYS_TIME || defined HAVE_WALL_TIME */
 }
 
 /* Returns time (user + system) used so far by the compiler process,
