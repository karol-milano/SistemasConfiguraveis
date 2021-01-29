@@ -157,11 +157,6 @@ static struct timevar_stack_def *unused_stack_instances;
    element.  */
 static struct timevar_time_def start_time;
 
-static void set_to_current_time (struct timevar_time_def *);
-static void timevar_accumulate (struct timevar_time_def *,
-                                struct timevar_time_def *,
-                                struct timevar_time_def *);
-
 /* Fill the current times into TIME.  The definition of this function
    also defines any or all of the HAVE_USER_TIME, HAVE_SYS_TIME, and
    HAVE_WALL_TIME macros.  */
@@ -193,12 +188,22 @@ set_to_current_time (struct timevar_time_def *now)
   }
 }
 
+/* Return the current time.  */
+
+static struct timevar_time_def
+get_current_time (void)
+{
+  struct timevar_time_def now;
+  set_to_current_time (&now);
+  return now;
+}
+
 /* Add the difference between STOP and START to TIMER.  */
 
 static void
 timevar_accumulate (struct timevar_time_def *timer,
-                    struct timevar_time_def *start,
-                    struct timevar_time_def *stop)
+                    const struct timevar_time_def *start,
+                    const struct timevar_time_def *stop)
 {
   timer->user += stop->user - start->user;
   timer->sys += stop->sys - start->sys;
@@ -243,8 +248,7 @@ timevar_push (timevar_id_t timevar)
     abort ();
 
   /* What time is it?  */
-  struct timevar_time_def now;
-  set_to_current_time (&now);
+  struct timevar_time_def const now = get_current_time ();
 
   /* If the stack isn't empty, attribute the current elapsed time to
      the old topmost element.  */
@@ -283,8 +287,7 @@ timevar_pop (timevar_id_t timevar)
     abort ();
 
   /* What time is it?  */
-  struct timevar_time_def now;
-  set_to_current_time (&now);
+  struct timevar_time_def const now = get_current_time ();
 
   /* Attribute the elapsed time to the element we're popping.  */
   struct timevar_stack_def *popped = stack;
@@ -335,8 +338,7 @@ timevar_stop (timevar_id_t timevar)
   if (!tv->standalone)
     abort ();
 
-  struct timevar_time_def now;
-  set_to_current_time (&now);
+  struct timevar_time_def const now = get_current_time ();
   timevar_accumulate (&tv->elapsed, &tv->start_time, &now);
 }
 
@@ -350,15 +352,13 @@ timevar_get (timevar_id_t timevar,
   /* Is TIMEVAR currently running as a standalone timer?  */
   if (tv->standalone)
     {
-      struct timevar_time_def now;
-      set_to_current_time (&now);
+      struct timevar_time_def const now = get_current_time ();
       timevar_accumulate (elapsed, &tv->start_time, &now);
     }
   /* Or is TIMEVAR at the top of the timer stack?  */
   else if (stack->timevar == tv)
     {
-      struct timevar_time_def now;
-      set_to_current_time (&now);
+      struct timevar_time_def const now = get_current_time ();
       timevar_accumulate (elapsed, &start_time, &now);
     }
 }
@@ -377,8 +377,7 @@ timevar_print (FILE *fp)
     fp = stderr;
 
   /* What time is it?  */
-  struct timevar_time_def now;
-  set_to_current_time (&now);
+  struct timevar_time_def const now = get_current_time ();
 
   /* If the stack isn't empty, attribute the current elapsed time to
      the old topmost element.  */
