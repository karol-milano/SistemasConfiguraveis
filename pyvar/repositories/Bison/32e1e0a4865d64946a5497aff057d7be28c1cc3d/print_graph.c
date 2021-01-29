@@ -123,7 +123,7 @@ print_actions (state_t *state, const char *node_name)
 {
   int i;
 
-  shifts   *shiftp = state->shifts;
+  shifts_t   *shiftp = state->shifts;
   reductions *redp = state->reductions;
 
   static char buff[10];
