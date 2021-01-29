@@ -418,7 +418,7 @@ build_relations (void)
 	  state_t *state = state_table[from_state[i]];
 	  states[0] = state->number;
 
-	  for (rp = ritem + rule_table[*rulep].rhs; *rp > 0; rp++)
+	  for (rp = &ritem[rule_table[*rulep].rhs]; *rp >= 0; rp++)
 	    {
 	      shifts *sp = state->shifts;
 	      int j;
