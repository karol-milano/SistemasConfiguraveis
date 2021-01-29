@@ -286,8 +286,11 @@ print_reduction (FILE *out, size_t width,
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
-  fprintf (out, _("reduce using rule %d (%s)"),
-	   rule->number, rule->lhs->tag);
+  if (rule->number)
+    fprintf (out, _("reduce using rule %d (%s)"),
+	     rule->number, rule->lhs->tag);
+  else
+    fprintf (out, _("accept"));
   if (!enabled)
     fputc (']', out);
   fputc ('\n', out);
@@ -393,19 +396,6 @@ print_reductions (FILE *out, state_t *state)
 static void
 print_actions (FILE *out, state_t *state)
 {
-  reductions_t *redp = state->reductions;
-  transitions_t *transitions = state->transitions;
-
-  if (transitions->num == 0 && redp->num == 0)
-    {
-      fputc ('\n', out);
-      if (state->number == final_state->number)
-	fprintf (out, _("    $default\taccept\n"));
-      else
-	fprintf (out, _("    NO ACTIONS\n"));
-      return;
-    }
-
   /* Print shifts.  */
   print_transitions (state, out, TRUE);
   print_errs (out, state);
