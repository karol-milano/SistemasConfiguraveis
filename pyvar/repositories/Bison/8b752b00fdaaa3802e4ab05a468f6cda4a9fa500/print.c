@@ -125,7 +125,7 @@ print_core (FILE *out, state_t *state)
 static void
 print_transitions (state_t *state, FILE *out, bool display_transitions_p)
 {
-  transitions_t *transitions = state->shifts;
+  transitions_t *transitions = state->transitions;
   size_t width = 0;
   int i;
 
@@ -224,7 +224,7 @@ state_default_rule (state_t *state)
      we shift (S/R conflicts)...  */
   bitset_zero (shiftset);
   {
-    transitions_t *transitions = state->shifts;
+    transitions_t *transitions = state->transitions;
     for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
       if (!TRANSITION_IS_DISABLED (transitions, i))
 	{
@@ -302,7 +302,7 @@ print_reduction (FILE *out, size_t width,
 static void
 print_reductions (FILE *out, state_t *state)
 {
-  transitions_t *transitions = state->shifts;
+  transitions_t *transitions = state->transitions;
   reductions_t *redp = state->reductions;
   rule_t *default_rule = NULL;
   size_t width = 0;
@@ -396,7 +396,7 @@ static void
 print_actions (FILE *out, state_t *state)
 {
   reductions_t *redp = state->reductions;
-  transitions_t *transitions = state->shifts;
+  transitions_t *transitions = state->transitions;
 
   if (transitions->num == 0 && redp->num == 0)
     {
