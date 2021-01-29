@@ -308,11 +308,16 @@ grammar_rules_useless_report (const char *message)
   for (r = 0; r < nrules ; ++r)
     if (!rules[r].useful)
       {
-        warn_at (rules[r].location, "%s: ", message);
-        if (warnings_flag & warnings_other)
+        if (feature_flag & feature_caret)
+          warn_at (rules[r].location, "%s", message);
+        else
           {
-            rule_print (&rules[r], stderr);
-            fflush (stderr);
+            warn_at (rules[r].location, "%s: ", message);
+            if (warnings_flag & warnings_other)
+              {
+                rule_print (&rules[r], stderr);
+                fflush (stderr);
+              }
           }
       }
 }
