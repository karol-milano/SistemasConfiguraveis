@@ -488,9 +488,9 @@ conflicts_print (void)
       expected_rr_conflicts = -1;
     }
 
-  src_ok = 
+  src_ok =
     src_total == (expected_sr_conflicts == -1 ? 0 : expected_sr_conflicts);
-  rrc_ok = 
+  rrc_ok =
     rrc_total == (expected_rr_conflicts == -1 ? 0 : expected_rr_conflicts);
 
   /* If there are as many RR conflicts and SR conflicts as
@@ -522,7 +522,7 @@ conflicts_print (void)
 void
 conflicts_free (void)
 {
-  XFREE (conflicts);
+  free (conflicts);
   bitset_free (shift_set);
   bitset_free (look_ahead_set);
   obstack_free (&solved_conflicts_obstack, NULL);
