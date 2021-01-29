@@ -602,8 +602,10 @@ conflicts_print (void)
     }
   if (src_total | rrc_total)
     {
-      if (expected_sr_conflicts == -1 && expected_rr_conflicts == -1)
-        set_warning_issued ();
+      if (expected_sr_conflicts == -1 && src_total)
+        set_warning_issued (Wconflicts_sr);
+      if (expected_rr_conflicts == -1 && rrc_total)
+        set_warning_issued (Wconflicts_rr);
       if (! yacc_flag)
         fprintf (stderr, "%s: ", current_file);
       conflict_report (stderr, src_total, rrc_total);
