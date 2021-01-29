@@ -128,7 +128,7 @@ print_shifts (FILE *out, state_t *state)
 static void
 print_errs (FILE *out, state_t *state)
 {
-  errs *errp = state->errs;
+  errs_t *errp = state->errs;
   int i;
 
   for (i = 0; i < errp->nerrs; ++i)
@@ -170,8 +170,8 @@ print_reductions (FILE *out, state_t *state)
 {
   int i;
   shifts_t *shiftp = state->shifts;
-  reductions *redp = state->reductions;
-  errs *errp = state->errs;
+  reductions_t *redp = state->reductions;
+  errs_t *errp = state->errs;
   int nodefault = 0;
 
   if (redp->nreds == 0)
@@ -304,7 +304,7 @@ print_reductions (FILE *out, state_t *state)
 static void
 print_actions (FILE *out, state_t *state)
 {
-  reductions *redp = state->reductions;
+  reductions_t *redp = state->reductions;
   shifts_t *shiftp = state->shifts;
 
   if (shiftp->nshifts == 0 && redp->nreds == 0)
