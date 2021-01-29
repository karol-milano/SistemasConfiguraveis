@@ -108,7 +108,7 @@ static void
 print_shifts (FILE *out, state_t *state)
 {
   int i;
-  shifts *shiftp = state->shifts;
+  shifts_t *shiftp = state->shifts;
 
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
@@ -145,7 +145,7 @@ static void
 print_gotos (FILE *out, state_t *state)
 {
   int i;
-  shifts *shiftp = state->shifts;
+  shifts_t *shiftp = state->shifts;
 
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     /* Skip token shifts.  */;
@@ -169,7 +169,7 @@ static void
 print_reductions (FILE *out, state_t *state)
 {
   int i;
-  shifts *shiftp = state->shifts;
+  shifts_t *shiftp = state->shifts;
   reductions *redp = state->reductions;
   errs *errp = state->errs;
   int nodefault = 0;
@@ -305,7 +305,7 @@ static void
 print_actions (FILE *out, state_t *state)
 {
   reductions *redp = state->reductions;
-  shifts *shiftp = state->shifts;
+  shifts_t *shiftp = state->shifts;
 
   if (shiftp->nshifts == 0 && redp->nreds == 0)
     {
