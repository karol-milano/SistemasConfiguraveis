@@ -372,8 +372,8 @@ user_actions_output (FILE *out)
       {
         fprintf (out, "%s(%d, [b4_syncline(%d, ",
                  rules[r].is_predicate ? "b4_predicate_case" : "b4_case",
-                 r + 1, rules[r].action_location.start.line);
-        string_output (out, rules[r].action_location.start.file);
+                 r + 1, rules[r].action_loc.start.line);
+        string_output (out, rules[r].action_loc.start.file);
         fprintf (out, ")dnl\n[    %s]])\n\n", rules[r].action);
       }
   fputs ("])\n\n", out);
