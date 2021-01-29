@@ -374,7 +374,7 @@ user_actions_output (FILE *out)
                  rules[r].is_predicate ? "b4_predicate_case" : "b4_case",
                  r + 1, rules[r].action_location.start.line);
         string_output (out, rules[r].action_location.start.file);
-        fprintf (out, ")\n[    %s]])\n\n", rules[r].action);
+        fprintf (out, ")dnl\n[    %s]])\n\n", rules[r].action);
       }
   fputs ("])\n\n", out);
 }
