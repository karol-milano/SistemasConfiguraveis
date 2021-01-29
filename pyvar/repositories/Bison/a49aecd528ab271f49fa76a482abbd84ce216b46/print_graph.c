@@ -140,7 +140,7 @@ print_actions (state_t *state, const char *node_name)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
-	token_number_t symbol = states[state1]->accessing_symbol;
+	symbol_number_t symbol = states[state1]->accessing_symbol;
 
 	new_edge (&edge);
 
