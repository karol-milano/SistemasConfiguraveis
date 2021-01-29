@@ -309,7 +309,7 @@ grammar_rules_useless_report (const char *message)
     if (!rules[r].useful)
       {
         warn_at (rules[r].location, "%s: ", message);
-        if (warnings_flag & warnings_other)
+        if (warnings_flag & Wother)
           {
             rule_print (&rules[r], stderr);
             fflush (stderr);
