@@ -505,22 +505,6 @@ count_rr_conflicts (bool one_per_token)
   return res;
 }
 
-/*--------------------------------------------------------.
-| Report the number of conflicts, using the Yacc format.  |
-`--------------------------------------------------------*/
-
-static void
-conflict_report (FILE *out, size_t src_num, size_t rrc_num)
-{
-  if (src_num && rrc_num)
-    fprintf (out, _("conflicts: %zd shift/reduce, %zd reduce/reduce\n"),
-             src_num, rrc_num);
-  else if (src_num)
-    fprintf (out, _("conflicts: %zd shift/reduce\n"), src_num);
-  else if (rrc_num)
-    fprintf (out, _("conflicts: %zd reduce/reduce\n"), rrc_num);
-}
-
 
 /*-----------------------------------------------------------.
 | Output the detailed description of states with conflicts.  |
@@ -536,10 +520,17 @@ conflicts_output (FILE *out)
       state *s = states[i];
       if (conflicts[i])
         {
+          int src = count_state_sr_conflicts (s);
+          int rrc = count_state_rr_conflicts (s, true);
           fprintf (out, _("State %d "), i);
-          conflict_report (out,
-                           count_state_sr_conflicts (s),
-                           count_state_rr_conflicts (s, true));
+          if (src && rrc)
+            fprintf (out,
+                     _("conflicts: %d shift/reduce, %d reduce/reduce\n"),
+                     src, rrc);
+          else if (src)
+            fprintf (out, _("conflicts: %d shift/reduce\n"), src);
+          else if (rrc)
+            fprintf (out, _("conflicts: %d reduce/reduce\n"), rrc);
           printed_sth = true;
         }
     }
@@ -568,64 +559,57 @@ conflicts_total_count (void)
 void
 conflicts_print (void)
 {
-  /* Is the number of SR conflicts OK?  Either EXPECTED_CONFLICTS is
-     not set, and then we want 0 SR, or else it is specified, in which
-     case we want equality.  */
-  bool src_ok;
-  bool rrc_ok;
-
-  int src_expected;
-  int rrc_expected;
-
-  int src_total = count_sr_conflicts ();
-  int rrc_total = count_rr_conflicts (true);
-
   if (! glr_parser && expected_rr_conflicts != -1)
     {
       complain (Wother, _("%%expect-rr applies only to GLR parsers"));
       expected_rr_conflicts = -1;
     }
 
-  src_expected = expected_sr_conflicts == -1 ? 0 : expected_sr_conflicts;
-  rrc_expected = expected_rr_conflicts == -1 ? 0 : expected_rr_conflicts;
-  src_ok = src_total == src_expected;
-  rrc_ok = rrc_total == rrc_expected;
-
-  /* If there are as many RR conflicts and SR conflicts as
-     expected, then there is nothing to report.  */
-  if (rrc_ok & src_ok)
-    return;
-
-  /* Report the total number of conflicts on STDERR.  */
-  if (expected_sr_conflicts == -1 && expected_rr_conflicts == -1)
-    {
-      if (!(warnings_flag & Wconflicts_sr))
-        src_total = 0;
-      if (!(warnings_flag & Wconflicts_rr))
-        rrc_total = 0;
-    }
-  if (src_total | rrc_total)
-    {
-      if (expected_sr_conflicts == -1 && expected_rr_conflicts == -1)
-        set_warning_issued ();
-      if (! yacc_flag)
-        fprintf (stderr, "%s: ", current_file);
-      conflict_report (stderr, src_total, rrc_total);
-    }
+  /* Screams for factoring, but almost useless because of the
+     different strings to translate.  */
+  {
+    int total = count_sr_conflicts ();
+    // If %expect is not used, but %expect-rr is, then expect 0 sr.
+    int expected =
+      (expected_sr_conflicts == -1 && expected_rr_conflicts != -1)
+      ? 0
+      : expected_sr_conflicts;
+    if (expected != -1)
+      {
+        if (expected != total)
+          complain (complaint,
+                    _("shift/reduce conflicts: %d found, %d expected"),
+                    total, expected);
+      }
+    else if (total)
+      complain (Wconflicts_sr,
+                ngettext ("%d shift/reduce conflict",
+                          "%d shift/reduce conflicts",
+                          total),
+                total);
+  }
 
-  if (expected_sr_conflicts != -1 || expected_rr_conflicts != -1)
-    {
-      if (! src_ok)
-        complain (complaint, ngettext ("expected %d shift/reduce conflict",
-                                       "expected %d shift/reduce conflicts",
-                                       src_expected),
-                  src_expected);
-      if (! rrc_ok)
-        complain (complaint, ngettext ("expected %d reduce/reduce conflict",
-                                       "expected %d reduce/reduce conflicts",
-                                       rrc_expected),
-                  rrc_expected);
-    }
+  {
+    int total = count_rr_conflicts (true);
+    // If %expect-rr is not used, but %expect is, then expect 0 rr.
+    int expected =
+      (expected_rr_conflicts == -1 && expected_sr_conflicts != -1)
+      ? 0
+      : expected_rr_conflicts;
+    if (expected != -1)
+      {
+        if (expected != total)
+          complain (complaint,
+                    _("reduce/reduce conflicts: %d found, %d expected"),
+                    total, expected);
+      }
+    else if (total)
+      complain (Wconflicts_rr,
+                ngettext ("%d reduce/reduce conflict",
+                          "%d reduce/reduce conflicts",
+                          total),
+                total);
+  }
 }
 
 
