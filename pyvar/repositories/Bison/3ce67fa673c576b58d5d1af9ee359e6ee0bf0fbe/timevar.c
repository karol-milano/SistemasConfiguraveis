@@ -230,13 +230,11 @@ timevar_init ()
 void
 timevar_push (timevar_id_t timevar)
 {
-  struct timevar_def *tv = &timevars[timevar];
-  struct timevar_stack_def *context;
-  struct timevar_time_def now;
-
   if (!TIMEVAR_ENABLE)
     return;
 
+  struct timevar_def *tv = &timevars[timevar];
+
   /* Mark this timing variable as used.  */
   tv->used = 1;
 
@@ -245,6 +243,7 @@ timevar_push (timevar_id_t timevar)
     abort ();
 
   /* What time is it?  */
+  struct timevar_time_def now;
   get_time (&now);
 
   /* If the stack isn't empty, attribute the current elapsed time to
@@ -258,6 +257,7 @@ timevar_push (timevar_id_t timevar)
 
   /* See if we have a previously-allocated stack instance.  If so,
      take it off the list.  If not, malloc a new one.  */
+  struct timevar_stack_def *context = NULL;
   if (unused_stack_instances != NULL)
     {
       context = unused_stack_instances;
@@ -276,9 +276,6 @@ timevar_push (timevar_id_t timevar)
 void
 timevar_pop (timevar_id_t timevar)
 {
-  struct timevar_time_def now;
-  struct timevar_stack_def *popped = stack;
-
   if (!TIMEVAR_ENABLE)
     return;
 
@@ -286,9 +283,11 @@ timevar_pop (timevar_id_t timevar)
     abort ();
 
   /* What time is it?  */
+  struct timevar_time_def now;
   get_time (&now);
 
   /* Attribute the elapsed time to the element we're popping.  */
+  struct timevar_stack_def *popped = stack;
   timevar_accumulate (&popped->timevar->elapsed, &start_time, &now);
 
   /* Reset the start time; from now on, time is attributed to the
@@ -307,11 +306,11 @@ timevar_pop (timevar_id_t timevar)
 void
 timevar_start (timevar_id_t timevar)
 {
-  struct timevar_def *tv = &timevars[timevar];
-
   if (!TIMEVAR_ENABLE)
     return;
 
+  struct timevar_def *tv = &timevars[timevar];
+
   /* Mark this timing variable as used.  */
   tv->used = 1;
 
@@ -327,16 +326,16 @@ timevar_start (timevar_id_t timevar)
 void
 timevar_stop (timevar_id_t timevar)
 {
-  struct timevar_def *tv = &timevars[timevar];
-  struct timevar_time_def now;
-
   if (!TIMEVAR_ENABLE)
     return;
 
+  struct timevar_def *tv = &timevars[timevar];
+
   /* TIMEVAR must have been started via timevar_start.  */
   if (!tv->standalone)
     abort ();
 
+  struct timevar_time_def now;
   get_time (&now);
   timevar_accumulate (&tv->elapsed, &tv->start_time, &now);
 }
@@ -346,19 +345,19 @@ timevar_get (timevar_id_t timevar,
              struct timevar_time_def *elapsed)
 {
   struct timevar_def *tv = &timevars[timevar];
-  struct timevar_time_def now;
-
   *elapsed = tv->elapsed;
 
   /* Is TIMEVAR currently running as a standalone timer?  */
   if (tv->standalone)
     {
+      struct timevar_time_def now;
       get_time (&now);
       timevar_accumulate (elapsed, &tv->start_time, &now);
     }
   /* Or is TIMEVAR at the top of the timer stack?  */
   else if (stack->timevar == tv)
     {
+      struct timevar_time_def now;
       get_time (&now);
       timevar_accumulate (elapsed, &start_time, &now);
     }
@@ -369,10 +368,6 @@ timevar_print (FILE *fp)
 {
   /* Only print stuff if we have some sort of time information.  */
 #if defined HAVE_USER_TIME || defined HAVE_SYS_TIME || defined HAVE_WALL_TIME
-  unsigned /* timevar_id_t */ id;
-  struct timevar_time_def *total = &timevars[TV_TOTAL].elapsed;
-  struct timevar_time_def now;
-
   if (!TIMEVAR_ENABLE)
     return;
 
@@ -382,6 +377,7 @@ timevar_print (FILE *fp)
     fp = stderr;
 
   /* What time is it?  */
+  struct timevar_time_def now;
   get_time (&now);
 
   /* If the stack isn't empty, attribute the current elapsed time to
@@ -393,8 +389,10 @@ timevar_print (FILE *fp)
      TIMEVAR.  */
   start_time = now;
 
+  struct timevar_time_def const* total = &timevars[TV_TOTAL].elapsed;
+
   fputs (_("\nExecution times (seconds)\n"), fp);
-  for (id = 0; id < (unsigned) TIMEVAR_LAST; ++id)
+  for (unsigned /* timevar_id_t */ id = 0; id < (unsigned) TIMEVAR_LAST; ++id)
     {
       struct timevar_def *tv = &timevars[(timevar_id_t) id];
       const float tiny = 5e-3;
