@@ -485,28 +485,3 @@ timevar_print (FILE *fp)
 
 #endif /* defined HAVE_USER_TIME || defined HAVE_SYS_TIME || defined HAVE_WALL_TIME */
 }
-
-/* Returns time (user + system) used so far by the compiler process,
-   in microseconds.  */
-
-long
-get_run_time ()
-{
-  struct timevar_time_def total_elapsed;
-  timevar_get (TV_TOTAL, &total_elapsed);
-  return total_elapsed.user + total_elapsed.sys;
-}
-
-/* Prints a message to stderr stating that time elapsed in STR is
-   TOTAL (given in microseconds).  */
-
-void
-print_time (const char *str, long total)
-{
-  long all_time = get_run_time ();
-  fprintf (stderr,
-           _("time in %s: %ld.%06ld (%ld%%)\n"),
-           str, total / 1000000, total % 1000000,
-           all_time == 0 ? 0
-           : (long) (((100.0 * (double) total) / (double) all_time) + .5));
-}
