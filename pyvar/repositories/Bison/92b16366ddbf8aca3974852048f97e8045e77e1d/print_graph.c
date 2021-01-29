@@ -85,8 +85,8 @@ print_actions (int state, const char *node_name)
 {
   int i;
 
-  shifts   *shiftp = state_table[state].shift_table;
-  reductions *redp = state_table[state].reduction_table;
+  shifts   *shiftp = state_table[state].shifts;
+  reductions *redp = state_table[state].reductions;
 #if 0
   errs       *errp = err_table[state];
 #endif
