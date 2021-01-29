@@ -125,7 +125,7 @@ print_actions (state_t *state, const char *node_name)
 {
   int i;
 
-  transitions_t     *transitions = state->shifts;
+  transitions_t     *transitions = state->transitions;
   reductions_t *redp = state->reductions;
 
   static char buff[10];
