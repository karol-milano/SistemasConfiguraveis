@@ -357,8 +357,8 @@ user_actions_output (FILE *out)
   for (r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
-        fprintf (out, "b4_%scase(%d, [b4_syncline(%d, ",
-                 rules[r].is_predicate ? "predicate_" : "",
+        fprintf (out, "%s(%d, [b4_syncline(%d, ",
+                 rules[r].is_predicate ? "b4_predicate_case" : "b4_case",
                  r + 1, rules[r].action_location.start.line);
         string_output (out, rules[r].action_location.start.file);
         fprintf (out, ")\n[    %s]])\n\n", rules[r].action);
