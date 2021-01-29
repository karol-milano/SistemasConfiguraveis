@@ -189,8 +189,8 @@ static struct timevar_time_def start_time;
 
 static void get_time (struct timevar_time_def *);
 static void timevar_accumulate (struct timevar_time_def *,
-				struct timevar_time_def *,
-				struct timevar_time_def *);
+                                struct timevar_time_def *,
+                                struct timevar_time_def *);
 
 /* Fill the current times into TIME.  The definition of this function
    also defines any or all of the HAVE_USER_TIME, HAVE_SYS_TIME, and
@@ -479,20 +479,20 @@ timevar_print (fp)
       const float tiny = 5e-3;
 
       /* Don't print the total execution time here; that goes at the
-	 end.  */
+         end.  */
       if ((timevar_id_t) id == TV_TOTAL)
-	continue;
+        continue;
 
       /* Don't print timing variables that were never used.  */
       if (!tv->used)
-	continue;
+        continue;
 
       /* Don't print timing variables if we're going to get a row of
-	 zeroes.  */
+         zeroes.  */
       if (tv->elapsed.user < tiny
-	  && tv->elapsed.sys < tiny
-	  && tv->elapsed.wall < tiny)
-	continue;
+          && tv->elapsed.sys < tiny
+          && tv->elapsed.wall < tiny)
+        continue;
 
       /* The timing variable name.  */
       fprintf (fp, " %-22s:", tv->name);
@@ -500,22 +500,22 @@ timevar_print (fp)
 #ifdef HAVE_USER_TIME
       /* Print user-mode time for this process.  */
       fprintf (fp, "%7.2f (%2.0f%%) usr",
-	       tv->elapsed.user,
-	       (total->user == 0 ? 0 : tv->elapsed.user / total->user) * 100);
+               tv->elapsed.user,
+               (total->user == 0 ? 0 : tv->elapsed.user / total->user) * 100);
 #endif /* HAVE_USER_TIME */
 
 #ifdef HAVE_SYS_TIME
       /* Print system-mode time for this process.  */
       fprintf (fp, "%7.2f (%2.0f%%) sys",
-	       tv->elapsed.sys,
-	       (total->sys == 0 ? 0 : tv->elapsed.sys / total->sys) * 100);
+               tv->elapsed.sys,
+               (total->sys == 0 ? 0 : tv->elapsed.sys / total->sys) * 100);
 #endif /* HAVE_SYS_TIME */
 
 #ifdef HAVE_WALL_TIME
       /* Print wall clock time elapsed.  */
       fprintf (fp, "%7.2f (%2.0f%%) wall",
-	       tv->elapsed.wall,
-	       (total->wall == 0 ? 0 : tv->elapsed.wall / total->wall) * 100);
+               tv->elapsed.wall,
+               (total->wall == 0 ? 0 : tv->elapsed.wall / total->wall) * 100);
 #endif /* HAVE_WALL_TIME */
 
       putc ('\n', fp);
@@ -534,7 +534,7 @@ timevar_print (fp)
 #endif
 
 #endif /* defined (HAVE_USER_TIME) || defined (HAVE_SYS_TIME)
-	  || defined (HAVE_WALL_TIME) */
+          || defined (HAVE_WALL_TIME) */
 }
 
 /* Returns time (user + system) used so far by the compiler process,
@@ -558,8 +558,8 @@ print_time (str, total)
 {
   long all_time = get_run_time ();
   fprintf (stderr,
-	   _("time in %s: %ld.%06ld (%ld%%)\n"),
-	   str, total / 1000000, total % 1000000,
-	   all_time == 0 ? 0
-	   : (long) (((100.0 * (double) total) / (double) all_time) + .5));
+           _("time in %s: %ld.%06ld (%ld%%)\n"),
+           str, total / 1000000, total % 1000000,
+           all_time == 0 ? 0
+           : (long) (((100.0 * (double) total) / (double) all_time) + .5));
 }
