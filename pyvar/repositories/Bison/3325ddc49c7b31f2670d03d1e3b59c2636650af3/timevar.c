@@ -207,15 +207,18 @@ get_time (now)
   {
 #ifdef USE_TIMES
     struct tms tms;
-    now->wall = times (&tms)  * ticks_to_msec;
-    now->user = tms.tms_utime * ticks_to_msec;
-    now->sys  = tms.tms_stime * ticks_to_msec;
+    now->wall = times (&tms)   * ticks_to_msec;
+    now->user = (tms.tms_utime + tms.tms_cutime) * ticks_to_msec;
+    now->sys  = (tms.tms_stime + tms.tms_cstime) * ticks_to_msec;
 #endif
 #ifdef USE_GETRUSAGE
     struct rusage rusage;
     getrusage (RUSAGE_SELF, &rusage);
     now->user = rusage.ru_utime.tv_sec + rusage.ru_utime.tv_usec * 1e-6;
     now->sys  = rusage.ru_stime.tv_sec + rusage.ru_stime.tv_usec * 1e-6;
+    getrusage (RUSAGE_CHILDREN, &rusage);
+    now->user += rusage.ru_utime.tv_sec + rusage.ru_utime.tv_usec * 1e-6;
+    now->sys  += rusage.ru_stime.tv_sec + rusage.ru_stime.tv_usec * 1e-6;
 #endif
 #ifdef USE_CLOCK
     now->user = clock () * clocks_to_msec;
