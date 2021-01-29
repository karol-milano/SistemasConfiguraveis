@@ -178,7 +178,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	obstack_sgrow (node_obstack, "\\n");
     }
 
-  if (consistent[state] && redp)
+  if (state_table[state].consistent && redp)
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
