@@ -103,6 +103,12 @@ main (int argc, char *argv[])
   reader ();
   timevar_pop (tv_reader);
 
+  /* Fix input file now, even if there are errors: that's less
+     warnings in the following runs.  */
+  if (update_flag)
+    fixits_run ();
+  fixits_free ();
+
   if (complaint_status == status_complaint)
     goto finish;
 
@@ -206,7 +212,6 @@ main (int argc, char *argv[])
   conflicts_free ();
   grammar_free ();
   output_file_names_free ();
-  fixits_free ();
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
