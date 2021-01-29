@@ -26,7 +26,6 @@
 #if HAVE_SYS_TIME_H
 # include <sys/time.h>
 #endif
-int timevar_report = 0;
 
 #ifdef HAVE_SYS_TIMES_H
 # include <sys/times.h>
@@ -103,8 +102,7 @@ static float clocks_to_msec;
 
 /* See timevar.h for an explanation of timing variables.  */
 
-/* This macro evaluates to nonzero if timing variables are enabled.  */
-#define TIMEVAR_ENABLE (timevar_report)
+int timevar_enabled = 0;
 
 /* A timing variable.  */
 
@@ -168,7 +166,7 @@ set_to_current_time (struct timevar_time_def *now)
   now->sys  = 0;
   now->wall = 0;
 
-  if (!TIMEVAR_ENABLE)
+  if (!timevar_enabled)
     return;
 
   {
@@ -213,7 +211,7 @@ timevar_accumulate (struct timevar_time_def *timer,
 void
 timevar_init ()
 {
-  if (!TIMEVAR_ENABLE)
+  if (!timevar_enabled)
     return;
 
   /* Zero all elapsed times.  */
@@ -235,7 +233,7 @@ timevar_init ()
 void
 timevar_push (timevar_id_t timevar)
 {
-  if (!TIMEVAR_ENABLE)
+  if (!timevar_enabled)
     return;
 
   struct timevar_def *tv = &timevars[timevar];
@@ -280,7 +278,7 @@ timevar_push (timevar_id_t timevar)
 void
 timevar_pop (timevar_id_t timevar)
 {
-  if (!TIMEVAR_ENABLE)
+  if (!timevar_enabled)
     return;
 
   if (&timevars[timevar] != stack->timevar)
@@ -309,7 +307,7 @@ timevar_pop (timevar_id_t timevar)
 void
 timevar_start (timevar_id_t timevar)
 {
-  if (!TIMEVAR_ENABLE)
+  if (!timevar_enabled)
     return;
 
   struct timevar_def *tv = &timevars[timevar];
@@ -329,7 +327,7 @@ timevar_start (timevar_id_t timevar)
 void
 timevar_stop (timevar_id_t timevar)
 {
-  if (!TIMEVAR_ENABLE)
+  if (!timevar_enabled)
     return;
 
   struct timevar_def *tv = &timevars[timevar];
@@ -368,7 +366,7 @@ timevar_print (FILE *fp)
 {
   /* Only print stuff if we have some sort of time information.  */
 #if defined HAVE_USER_TIME || defined HAVE_SYS_TIME || defined HAVE_WALL_TIME
-  if (!TIMEVAR_ENABLE)
+  if (!timevar_enabled)
     return;
 
   /* Update timing information in case we're calling this from GDB.  */
