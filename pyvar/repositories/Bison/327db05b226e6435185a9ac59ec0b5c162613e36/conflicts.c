@@ -601,9 +601,9 @@ conflicts_print (void)
   /* Report the total number of conflicts on STDERR.  */
   if (expected_sr_conflicts == -1 && expected_rr_conflicts == -1)
     {
-      if (!(warnings_flag & warnings_conflicts_sr))
+      if (!(warnings_flag & Wconflicts_sr))
         src_total = 0;
-      if (!(warnings_flag & warnings_conflicts_rr))
+      if (!(warnings_flag & Wconflicts_rr))
         rrc_total = 0;
     }
   if (src_total | rrc_total)
