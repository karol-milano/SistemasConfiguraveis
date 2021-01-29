@@ -102,8 +102,8 @@ print_actions (FILE *out, int state)
   reductions *redp;
   int rule;
 
-  shiftp = shift_table[state];
-  redp = reduction_table[state];
+  shiftp = state_table[state].shift_table;
+  redp = state_table[state].reduction_table;
   errp = err_table[state];
 
   if (!shiftp && !redp)
