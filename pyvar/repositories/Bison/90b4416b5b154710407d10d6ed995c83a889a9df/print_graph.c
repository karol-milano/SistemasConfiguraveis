@@ -104,8 +104,8 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
   static char buff[10];
   edge_t edge;
 
-  shiftp = shift_table[state];
-  redp = reduction_table[state];
+  shiftp = state_table[state].shift_table;
+  redp = state_table[state].reduction_table;
   errp = err_table[state];
 
   if (!shiftp && !redp)
