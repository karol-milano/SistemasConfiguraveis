@@ -48,16 +48,6 @@ struct tms
 };
 #endif
 
-#if defined HAVE_DECL_GETRUSAGE && !HAVE_DECL_GETRUSAGE
-int getrusage (int, struct rusage *);
-#endif
-#if defined HAVE_DECL_TIMES && !HAVE_DECL_TIMES
-clock_t times (struct tms *);
-#endif
-#if defined HAVE_DECL_CLOCK && !HAVE_DECL_CLOCK
-clock_t clock (void);
-#endif
-
 /* Calculation of scale factor to convert ticks to microseconds.
    We mustn't use CLOCKS_PER_SEC except with clock().  */
 #if HAVE_SYSCONF && defined _SC_CLK_TCK
@@ -86,6 +76,14 @@ clock_t clock (void);
 # define HAVE_USER_TIME
 #endif
 
+#if defined USE_TIMES && !defined HAVE_DECL_TIMES
+clock_t times (struct tms *);
+#elif defined USE_GETRUSAGE && !defined HAVE_DECL_GETRUSAGE
+int getrusage (int, struct rusage *);
+#elif defined USE_CLOCK && !defined HAVE_DECL_CLOCK
+clock_t clock (void);
+#endif
+
 /* libc is very likely to have snuck a call to sysconf() into one of
    the underlying constants, and that can be very slow, so we have to
    precompute them.  Whose wonderful idea was it to make all those
@@ -172,7 +170,7 @@ set_to_current_time (struct timevar_time_def *now)
   {
 #ifdef USE_TIMES
     struct tms tms;
-    now->wall = times (&tms)  * ticks_to_msec;
+    now->wall = times (&tms) * ticks_to_msec;
     now->user = (tms.tms_utime + tms.tms_cutime) * ticks_to_msec;
     now->sys  = (tms.tms_stime + tms.tms_cstime) * ticks_to_msec;
 #elif defined USE_GETRUSAGE
