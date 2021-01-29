@@ -50,9 +50,6 @@ main (int argc, char *argv[])
   lineno = 0;
   getargs (argc, argv);
 
-  /* Be ready to clean up if we exit. */
-  atexit (done);
-
   open_files ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
@@ -93,6 +90,9 @@ main (int argc, char *argv[])
   free_nullable ();
   free_derives ();
 
+  if (!complain_message_count)
+    output_files ();
+
   exit (complain_message_count ? 1 : 0);
 }
 
