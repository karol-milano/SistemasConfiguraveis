@@ -205,8 +205,6 @@ timevar_accumulate (struct timevar_time_def *timer,
   timer->wall += stop->wall - start->wall;
 }
 
-/* Initialize timing variables.  */
-
 void
 timevar_init ()
 {
@@ -229,13 +227,6 @@ timevar_init ()
 #endif
 }
 
-/* Push TIMEVAR onto the timing stack.  No further elapsed time is
-   attributed to the previous topmost timing variable on the stack;
-   subsequent elapsed time is attributed to TIMEVAR, until it is
-   popped or another element is pushed on top.
-
-   TIMEVAR cannot be running as a standalone timer.  */
-
 void
 timevar_push (timevar_id_t timevar)
 {
@@ -282,12 +273,6 @@ timevar_push (timevar_id_t timevar)
   stack = context;
 }
 
-/* Pop the topmost timing variable element off the timing stack.  The
-   popped variable must be TIMEVAR.  Elapsed time since the that
-   element was pushed on, or since it was last exposed on top of the
-   stack when the element above it was popped off, is credited to that
-   timing variable.  */
-
 void
 timevar_pop (timevar_id_t timevar)
 {
@@ -319,10 +304,6 @@ timevar_pop (timevar_id_t timevar)
   unused_stack_instances = popped;
 }
 
-/* Start timing TIMEVAR independently of the timing stack.  Elapsed
-   time until timevar_stop is called for the same timing variable is
-   attributed to TIMEVAR.  */
-
 void
 timevar_start (timevar_id_t timevar)
 {
@@ -343,9 +324,6 @@ timevar_start (timevar_id_t timevar)
   get_time (&tv->start_time);
 }
 
-/* Stop timing TIMEVAR.  Time elapsed since timevar_start was called
-   is attributed to it.  */
-
 void
 timevar_stop (timevar_id_t timevar)
 {
@@ -363,9 +341,6 @@ timevar_stop (timevar_id_t timevar)
   timevar_accumulate (&tv->elapsed, &tv->start_time, &now);
 }
 
-/* Fill the elapsed time for TIMEVAR into ELAPSED.  Returns
-   update-to-date information even if TIMEVAR is currently running.  */
-
 void
 timevar_get (timevar_id_t timevar,
              struct timevar_time_def *elapsed)
@@ -389,10 +364,6 @@ timevar_get (timevar_id_t timevar,
     }
 }
 
-/* Summarize timing variables to FP.  The timing variable TV_TOTAL has
-   a special meaning -- it's considered to be the total elapsed time,
-   for normalizing the others, and is displayed last.  */
-
 void
 timevar_print (FILE *fp)
 {
