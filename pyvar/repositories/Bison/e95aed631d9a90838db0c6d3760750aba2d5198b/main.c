@@ -74,7 +74,7 @@ main (int argc, char *argv[])
   timevar_pop (TV_READER);
 
   if (complaint_issued)
-    exit (EXIT_FAILURE);
+    return EXIT_FAILURE;
 
   /* Find useless nonterminals and productions and reduce the grammar. */
   timevar_push (TV_REDUCE);
@@ -138,7 +138,7 @@ main (int argc, char *argv[])
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
   if (complaint_issued)
-    exit (EXIT_FAILURE);
+    return EXIT_FAILURE;
 
   /* Lookaheads are no longer needed. */
   timevar_push (TV_FREE);
@@ -177,10 +177,5 @@ main (int argc, char *argv[])
   timevar_stop (TV_TOTAL);
   timevar_print (stderr);
 
-  /* Some ancient SunOS versions exit (0) if main returns, so use
-     `exit' to exit with nonzero status.  */
-  if (complaint_issued)
-    exit (EXIT_FAILURE);
-
-  return EXIT_SUCCESS;
+  return complaint_issued ? EXIT_FAILURE : EXIT_SUCCESS;
 }
