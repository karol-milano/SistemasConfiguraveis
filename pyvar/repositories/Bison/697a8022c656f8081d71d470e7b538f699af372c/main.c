@@ -94,7 +94,7 @@ main (int argc, char *argv[])
   reader ();
   timevar_pop (TV_READER);
 
-  if (complaint_issued)
+  if (complaint_status == status_complaint)
     goto finish;
 
   /* Find useless nonterminals and productions and reduce the grammar. */
@@ -173,7 +173,7 @@ main (int argc, char *argv[])
 
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
-  if (complaint_issued)
+  if (complaint_status == status_complaint)
     goto finish;
 
   /* Lookahead tokens are no longer needed. */
@@ -215,5 +215,5 @@ main (int argc, char *argv[])
   timevar_stop (TV_TOTAL);
   timevar_print (stderr);
 
-  return complaint_issued ? EXIT_FAILURE : EXIT_SUCCESS;
+  return complaint_status ? EXIT_FAILURE : EXIT_SUCCESS;
 }
