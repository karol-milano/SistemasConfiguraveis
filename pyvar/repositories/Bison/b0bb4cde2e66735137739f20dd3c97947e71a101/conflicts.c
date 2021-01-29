@@ -694,12 +694,12 @@ report_counterexamples (void)
       report_state_counterexamples (states[sn]);
 }
 
-/*------------------------------.
-| Reporting per-rule conflicts. |
-`------------------------------*/
+/*------------------------------------------------.
+| Report per-rule %expect/%expect-rr mismatches.  |
+`------------------------------------------------*/
 
 static void
-rule_conflicts_print (void)
+report_rule_expectation_mismatches (void)
 {
   for (rule_number i = 0; i < nrules; i += 1)
     {
@@ -723,8 +723,6 @@ rule_conflicts_print (void)
                       r->code, rr, expected_rr);
         }
     }
-  if (warning_is_enabled (Wcounterexamples))
-    report_counterexamples ();
 }
 
 /*---------------------------------.
@@ -734,7 +732,7 @@ rule_conflicts_print (void)
 void
 conflicts_print (void)
 {
-  rule_conflicts_print ();
+  report_rule_expectation_mismatches ();
 
   if (! glr_parser && expected_rr_conflicts != -1)
     {
@@ -742,8 +740,9 @@ conflicts_print (void)
       expected_rr_conflicts = -1;
     }
 
-  /* Screams for factoring, but almost useless because of the
-     different strings to translate.  */
+  bool has_unexpected_conflicts = false;
+  /* The following two blocks scream for factoring, but i18n support
+     would make it ugly.  */
   {
     int total = count_sr_conflicts ();
     /* If %expect is not used, but %expect-rr is, then expect 0 sr.  */
@@ -754,16 +753,22 @@ conflicts_print (void)
     if (expected != -1)
       {
         if (expected != total)
-          complain (NULL, complaint,
-                    _("shift/reduce conflicts: %d found, %d expected"),
-                    total, expected);
+          {
+            complain (NULL, complaint,
+                      _("shift/reduce conflicts: %d found, %d expected"),
+                      total, expected);
+            has_unexpected_conflicts = true;
+          }
       }
     else if (total)
-      complain (NULL, Wconflicts_sr,
-                ngettext ("%d shift/reduce conflict",
-                          "%d shift/reduce conflicts",
-                          total),
-                total);
+      {
+        complain (NULL, Wconflicts_sr,
+                  ngettext ("%d shift/reduce conflict",
+                            "%d shift/reduce conflicts",
+                            total),
+                  total);
+        has_unexpected_conflicts = true;
+      }
   }
 
   {
@@ -776,17 +781,29 @@ conflicts_print (void)
     if (expected != -1)
       {
         if (expected != total)
-          complain (NULL, complaint,
-                    _("reduce/reduce conflicts: %d found, %d expected"),
-                    total, expected);
+          {
+            complain (NULL, complaint,
+                      _("reduce/reduce conflicts: %d found, %d expected"),
+                      total, expected);
+            has_unexpected_conflicts = true;
+          }
       }
     else if (total)
-      complain (NULL, Wconflicts_rr,
-                ngettext ("%d reduce/reduce conflict",
-                          "%d reduce/reduce conflicts",
-                          total),
-                total);
+      {
+        complain (NULL, Wconflicts_rr,
+                  ngettext ("%d reduce/reduce conflict",
+                            "%d reduce/reduce conflicts",
+                            total),
+                  total);
+        has_unexpected_conflicts = true;
+      }
   }
+
+  if (warning_is_enabled (Wcounterexamples))
+    report_counterexamples ();
+  else if (has_unexpected_conflicts)
+    complain (NULL, Wother,
+              _("rerun with option '-Wcounterexamples' to generate conflict counterexamples"));
 }
 
 void
