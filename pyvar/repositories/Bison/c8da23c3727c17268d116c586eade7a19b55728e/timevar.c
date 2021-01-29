@@ -208,7 +208,7 @@ timevar_accumulate (struct timevar_time_def *timer,
 /* Initialize timing variables.  */
 
 void
-init_timevar ()
+timevar_init ()
 {
   if (!TIMEVAR_ENABLE)
     return;
