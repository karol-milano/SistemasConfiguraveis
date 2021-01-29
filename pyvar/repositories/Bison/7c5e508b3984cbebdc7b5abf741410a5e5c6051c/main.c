@@ -105,7 +105,8 @@ main (int argc, char *argv[])
 
   /* Fix input file now, even if there are errors: that's less
      warnings in the following runs.  */
-  fixits_run ();
+  if (update_flag)
+    fixits_run ();
   fixits_free ();
 
   if (complaint_status == status_complaint)
