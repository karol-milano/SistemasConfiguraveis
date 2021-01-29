@@ -312,7 +312,7 @@ grammar_rules_useless_report (const char *message)
       for (r = 0; r < nrules ; ++r)
         if (!rules[r].useful)
           {
-            complain_at (rules[r].location, w | silent, "%s: ", message);
+            complain (&rules[r].location, w | silent, "%s: ", message);
             rule_print (&rules[r], stderr);
             warnings_print_categories (w);
             fprintf (stderr, "\n");
