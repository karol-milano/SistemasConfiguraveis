@@ -177,8 +177,7 @@ static void timevar_accumulate (struct timevar_time_def *,
    HAVE_WALL_TIME macros.  */
 
 static void
-get_time (now)
-     struct timevar_time_def *now;
+get_time (struct timevar_time_def *now)
 {
   now->user = 0;
   now->sys  = 0;
@@ -209,10 +208,9 @@ get_time (now)
 /* Add the difference between STOP and START to TIMER.  */
 
 static void
-timevar_accumulate (timer, start, stop)
-     struct timevar_time_def *timer;
-     struct timevar_time_def *start;
-     struct timevar_time_def *stop;
+timevar_accumulate (struct timevar_time_def *timer,
+                    struct timevar_time_def *start,
+                    struct timevar_time_def *stop)
 {
   timer->user += stop->user - start->user;
   timer->sys += stop->sys - start->sys;
@@ -252,8 +250,7 @@ init_timevar ()
    TIMEVAR cannot be running as a standalone timer.  */
 
 void
-timevar_push (timevar)
-     timevar_id_t timevar;
+timevar_push (timevar_id_t timevar)
 {
   struct timevar_def *tv = &timevars[timevar];
   struct timevar_stack_def *context;
@@ -305,8 +302,7 @@ timevar_push (timevar)
    timing variable.  */
 
 void
-timevar_pop (timevar)
-     timevar_id_t timevar;
+timevar_pop (timevar_id_t timevar)
 {
   struct timevar_time_def now;
   struct timevar_stack_def *popped = stack;
@@ -341,8 +337,7 @@ timevar_pop (timevar)
    attributed to TIMEVAR.  */
 
 void
-timevar_start (timevar)
-     timevar_id_t timevar;
+timevar_start (timevar_id_t timevar)
 {
   struct timevar_def *tv = &timevars[timevar];
 
@@ -365,8 +360,7 @@ timevar_start (timevar)
    is attributed to it.  */
 
 void
-timevar_stop (timevar)
-     timevar_id_t timevar;
+timevar_stop (timevar_id_t timevar)
 {
   struct timevar_def *tv = &timevars[timevar];
   struct timevar_time_def now;
@@ -386,9 +380,8 @@ timevar_stop (timevar)
    update-to-date information even if TIMEVAR is currently running.  */
 
 void
-timevar_get (timevar, elapsed)
-     timevar_id_t timevar;
-     struct timevar_time_def *elapsed;
+timevar_get (timevar_id_t timevar,
+             struct timevar_time_def *elapsed)
 {
   struct timevar_def *tv = &timevars[timevar];
   struct timevar_time_def now;
@@ -414,8 +407,7 @@ timevar_get (timevar, elapsed)
    for normalizing the others, and is displayed last.  */
 
 void
-timevar_print (fp)
-     FILE *fp;
+timevar_print (FILE *fp)
 {
   /* Only print stuff if we have some sort of time information.  */
 #if defined HAVE_USER_TIME || defined HAVE_SYS_TIME || defined HAVE_WALL_TIME
@@ -523,9 +515,7 @@ get_run_time ()
    TOTAL (given in microseconds).  */
 
 void
-print_time (str, total)
-     const char *str;
-     long total;
+print_time (const char *str, long total)
 {
   long all_time = get_run_time ();
   fprintf (stderr,
