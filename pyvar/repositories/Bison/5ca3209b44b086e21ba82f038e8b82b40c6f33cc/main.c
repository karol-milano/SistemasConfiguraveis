@@ -73,8 +73,8 @@ main (int argc, char *argv[])
   reader ();
   timevar_pop (TV_READER);
 
-  if (complain_message_count)
-    exit (1);
+  if (complaint_issued)
+    exit (EXIT_FAILURE);
 
   /* Find useless nonterminals and productions and reduce the grammar. */
   timevar_push (TV_REDUCE);
@@ -137,8 +137,8 @@ main (int argc, char *argv[])
 
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
-  if (complain_message_count)
-    exit (1);
+  if (complaint_issued)
+    exit (EXIT_FAILURE);
 
   /* Lookaheads are no longer needed. */
   timevar_push (TV_FREE);
@@ -177,5 +177,10 @@ main (int argc, char *argv[])
   timevar_stop (TV_TOTAL);
   timevar_print (stderr);
 
-  return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
+  /* Some ancient SunOS versions exit (0) if main returns, so use
+     `exit' to exit with nonzero status.  */
+  if (complaint_issued)
+    exit (EXIT_FAILURE);
+
+  return EXIT_SUCCESS;
 }
