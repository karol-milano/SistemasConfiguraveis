@@ -422,7 +422,10 @@ print_state (FILE *out, state_t *state)
   print_actions (out, state);
   if ((report_flag & report_solved_conflicts)
       && state->solved_conflicts)
-    fputs (state->solved_conflicts, out);
+    {
+      fputc ('\n', out);
+      fputs (state->solved_conflicts, out);
+    }
 }
 
 /*-----------------------------------------.
