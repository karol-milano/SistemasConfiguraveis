@@ -55,6 +55,8 @@ main (int argc, char *argv[])
   (void) bindtextdomain (PACKAGE, LOCALEDIR);
   (void) textdomain (PACKAGE);
 
+  struniqs_new ();
+
   getargs (argc, argv);
 
   time_report = trace_flag & trace_time;
@@ -64,7 +66,6 @@ main (int argc, char *argv[])
   if (trace_flag & trace_bitsets)
     bitset_stats_enable ();
 
-  struniqs_new ();
   muscle_init ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
@@ -160,8 +161,6 @@ main (int argc, char *argv[])
   reduce_free ();
   conflicts_free ();
   grammar_free ();
-  /* FIXME: We are leaking all the other file names.  */
-  free (infile);
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
