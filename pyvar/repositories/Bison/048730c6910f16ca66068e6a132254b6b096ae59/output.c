@@ -369,7 +369,8 @@ user_actions_output (FILE *out)
   for (rule_number r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
-        fprintf (out, "%s(%d, [",
+        /* The useless "" is there to pacify syntax-check.  */
+        fprintf (out, "%s""(%d, [",
                  rules[r].is_predicate ? "b4_predicate_case" : "b4_case",
                  r + 1);
         if (!no_lines_flag)
