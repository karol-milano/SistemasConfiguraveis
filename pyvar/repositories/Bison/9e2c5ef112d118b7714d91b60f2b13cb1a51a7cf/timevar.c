@@ -118,12 +118,12 @@ extern clock_t clock PARAMS ((void));
    _constants_ variable at run time, anyway?  */
 #ifdef USE_TIMES
 static float ticks_to_msec;
-#define TICKS_TO_MSEC (1 / (float)TICKS_PER_SECOND)
+#define TICKS_TO_MSEC (1.0 / TICKS_PER_SECOND)
 #endif
 
 #ifdef USE_CLOCK
 static float clocks_to_msec;
-#define CLOCKS_TO_MSEC (1 / (float)CLOCKS_PER_SEC)
+#define CLOCKS_TO_MSEC (1.0 / CLOCKS_PER_SEC)
 #endif
 
 #if IN_GCC
@@ -236,17 +236,17 @@ get_time (now)
   }
 }
 
-/* Add the difference between STOP_TIME and START_TIME to TIMER.  */
+/* Add the difference between STOP and START to TIMER.  */
 
 static void
-timevar_accumulate (timer, start_time, stop_time)
+timevar_accumulate (timer, start, stop)
      struct timevar_time_def *timer;
-     struct timevar_time_def *start_time;
-     struct timevar_time_def *stop_time;
+     struct timevar_time_def *start;
+     struct timevar_time_def *stop;
 {
-  timer->user += stop_time->user - start_time->user;
-  timer->sys += stop_time->sys - start_time->sys;
-  timer->wall += stop_time->wall - start_time->wall;
+  timer->user += stop->user - start->user;
+  timer->sys += stop->sys - start->sys;
+  timer->wall += stop->wall - start->wall;
 }
 
 /* Initialize timing variables.  */
