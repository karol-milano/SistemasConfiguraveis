@@ -157,7 +157,7 @@ static struct timevar_stack_def *unused_stack_instances;
    element.  */
 static struct timevar_time_def start_time;
 
-static void get_time (struct timevar_time_def *);
+static void set_to_current_time (struct timevar_time_def *);
 static void timevar_accumulate (struct timevar_time_def *,
                                 struct timevar_time_def *,
                                 struct timevar_time_def *);
@@ -167,7 +167,7 @@ static void timevar_accumulate (struct timevar_time_def *,
    HAVE_WALL_TIME macros.  */
 
 static void
-get_time (struct timevar_time_def *now)
+set_to_current_time (struct timevar_time_def *now)
 {
   now->user = 0;
   now->sys  = 0;
@@ -244,7 +244,7 @@ timevar_push (timevar_id_t timevar)
 
   /* What time is it?  */
   struct timevar_time_def now;
-  get_time (&now);
+  set_to_current_time (&now);
 
   /* If the stack isn't empty, attribute the current elapsed time to
      the old topmost element.  */
@@ -284,7 +284,7 @@ timevar_pop (timevar_id_t timevar)
 
   /* What time is it?  */
   struct timevar_time_def now;
-  get_time (&now);
+  set_to_current_time (&now);
 
   /* Attribute the elapsed time to the element we're popping.  */
   struct timevar_stack_def *popped = stack;
@@ -320,7 +320,7 @@ timevar_start (timevar_id_t timevar)
     abort ();
   tv->standalone = 1;
 
-  get_time (&tv->start_time);
+  set_to_current_time (&tv->start_time);
 }
 
 void
@@ -336,7 +336,7 @@ timevar_stop (timevar_id_t timevar)
     abort ();
 
   struct timevar_time_def now;
-  get_time (&now);
+  set_to_current_time (&now);
   timevar_accumulate (&tv->elapsed, &tv->start_time, &now);
 }
 
@@ -351,14 +351,14 @@ timevar_get (timevar_id_t timevar,
   if (tv->standalone)
     {
       struct timevar_time_def now;
-      get_time (&now);
+      set_to_current_time (&now);
       timevar_accumulate (elapsed, &tv->start_time, &now);
     }
   /* Or is TIMEVAR at the top of the timer stack?  */
   else if (stack->timevar == tv)
     {
       struct timevar_time_def now;
-      get_time (&now);
+      set_to_current_time (&now);
       timevar_accumulate (elapsed, &start_time, &now);
     }
 }
@@ -378,7 +378,7 @@ timevar_print (FILE *fp)
 
   /* What time is it?  */
   struct timevar_time_def now;
-  get_time (&now);
+  set_to_current_time (&now);
 
   /* If the stack isn't empty, attribute the current elapsed time to
      the old topmost element.  */
