@@ -448,7 +448,7 @@ timevar_print (fp)
 {
   /* Only print stuff if we have some sort of time information.  */
 #if defined HAVE_USER_TIME || defined HAVE_SYS_TIME || defined HAVE_WALL_TIME
-  unsigned int /* timevar_id_t */ id;
+  unsigned /* timevar_id_t */ id;
   struct timevar_time_def *total = &timevars[TV_TOTAL].elapsed;
   struct timevar_time_def now;
 
@@ -473,7 +473,7 @@ timevar_print (fp)
   start_time = now;
 
   fputs (_("\nExecution times (seconds)\n"), fp);
-  for (id = 0; id < (unsigned int) TIMEVAR_LAST; ++id)
+  for (id = 0; id < (unsigned) TIMEVAR_LAST; ++id)
     {
       struct timevar_def *tv = &timevars[(timevar_id_t) id];
       const float tiny = 5e-3;
