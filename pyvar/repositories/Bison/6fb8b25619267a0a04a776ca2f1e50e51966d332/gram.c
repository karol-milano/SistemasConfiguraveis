@@ -308,7 +308,7 @@ grammar_rules_useless_report (const char *message)
   for (r = 0; r < nrules ; ++r)
     if (!rules[r].useful)
       {
-        warn_at (rules[r].location, "%s: ", message);
+        complain_at (rules[r].location, Wother, "%s: ", message);
         if (warnings_flag & Wother)
           {
             rule_print (&rules[r], stderr);
