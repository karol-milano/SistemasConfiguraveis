@@ -599,8 +599,17 @@ conflicts_print (void)
     return;
 
   /* Report the total number of conflicts on STDERR.  */
+  if (expected_sr_conflicts == -1 && expected_rr_conflicts == -1)
+    {
+      if (!(warnings_flag & warnings_conflicts_sr))
+        src_total = 0;
+      if (!(warnings_flag & warnings_conflicts_rr))
+        rrc_total = 0;
+    }
   if (src_total | rrc_total)
     {
+      if (expected_sr_conflicts == -1 && expected_rr_conflicts == -1)
+        set_warning_issued ();
       if (! yacc_flag)
 	fprintf (stderr, "%s: ", current_file);
       conflict_report (stderr, src_total, rrc_total);
