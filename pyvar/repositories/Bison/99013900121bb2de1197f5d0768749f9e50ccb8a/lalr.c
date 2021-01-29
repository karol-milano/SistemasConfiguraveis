@@ -417,7 +417,7 @@ build_relations (void)
 	  state_t *state = states[from_state[i]];
 	  states1[0] = state->number;
 
-	  for (rp = &ritem[rules[*rulep].rhs]; *rp >= 0; rp++)
+	  for (rp = rules[*rulep].rhs; *rp >= 0; rp++)
 	    {
 	      shifts *sp = state->shifts;
 	      int j;
