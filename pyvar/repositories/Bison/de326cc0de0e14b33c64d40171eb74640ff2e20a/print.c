@@ -165,7 +165,7 @@ print_actions (FILE *out, int state)
 	fputc ('\n', out);
     }
 
-  if (consistent[state] && redp)
+  if (state_table[state].consistent && redp)
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
