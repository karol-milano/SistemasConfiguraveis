@@ -167,6 +167,9 @@ print_reductions (FILE *out, state_t *state)
   errs *errp = state->errs;
   int nodefault = 0;
 
+  if (redp->nreds == 0)
+    return;
+
   if (state->consistent)
     {
       int rule = redp->rules[0];
@@ -302,7 +305,7 @@ print_actions (FILE *out, state_t *state)
   reductions *redp = state->reductions;
   shifts *shiftp = state->shifts;
 
-  if (!shiftp->nshifts && !redp)
+  if (shiftp->nshifts == 0 && redp->nreds == 0)
     {
       if (final_state == state->number)
 	fprintf (out, _("    $default\taccept\n"));
@@ -313,8 +316,7 @@ print_actions (FILE *out, state_t *state)
 
   print_shifts (out, state);
   print_errs (out, state);
-  if (redp)
-    print_reductions (out, state);
+  print_reductions (out, state);
   print_gotos (out, state);
 }
 
