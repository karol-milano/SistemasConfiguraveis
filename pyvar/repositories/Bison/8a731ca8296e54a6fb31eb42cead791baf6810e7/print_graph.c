@@ -123,8 +123,8 @@ print_actions (state_t *state, const char *node_name)
 {
   int i;
 
-  shifts_t   *shiftp = state->shifts;
-  reductions *redp = state->reductions;
+  shifts_t     *shiftp = state->shifts;
+  reductions_t *redp = state->reductions;
 
   static char buff[10];
   edge_t edge;
