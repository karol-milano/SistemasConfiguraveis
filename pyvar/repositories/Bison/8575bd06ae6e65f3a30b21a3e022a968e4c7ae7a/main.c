@@ -105,8 +105,7 @@ main (int argc, char *argv[])
 
   /* Fix input file now, even if there are errors: that's less
      warnings in the following runs.  */
-  if (update_flag)
-    fixits_run ();
+  fixits_run ();
   fixits_free ();
 
   if (complaint_status == status_complaint)
