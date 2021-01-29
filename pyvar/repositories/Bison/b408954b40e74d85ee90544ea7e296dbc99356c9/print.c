@@ -364,6 +364,9 @@ print_state (FILE *out, state_t *state)
   fputs ("\n\n", out);
   print_core (out, state);
   print_actions (out, state);
+  if ((report_flag & report_solved_conflicts)
+      && state->solved_conflicts)
+    fputs (state->solved_conflicts, out);
   fputs ("\n\n", out);
 }
 
