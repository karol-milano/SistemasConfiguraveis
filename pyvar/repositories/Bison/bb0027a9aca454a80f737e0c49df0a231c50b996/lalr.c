@@ -244,16 +244,16 @@ initialize_F (void)
 
 
 static void
-add_lookback_edge (state_t *state, rule_number_t ruleno, int gotono)
+add_lookback_edge (state_t *state, rule_t *rule, int gotono)
 {
   int i;
   goto_list_t *sp;
 
   for (i = 0; i < state->nlookaheads; ++i)
-    if (state->lookaheads_rule[i]->number == ruleno)
+    if (state->lookaheads_rule[i] == rule)
       break;
 
-  assert (state->lookaheads_rule[i]->number == ruleno);
+  assert (state->lookaheads_rule[i] == rule);
 
   sp = XCALLOC (goto_list_t, 1);
   sp->next = lookback[(state->lookaheads - LA) + i];
@@ -276,9 +276,9 @@ build_relations (void)
     {
       int nedges = 0;
       symbol_number_t symbol1 = states[to_state[i]]->accessing_symbol;
-      rule_number_t *rulep;
+      rule_t **rulep;
 
-      for (rulep = derives[symbol1]; *rulep >= 0; rulep++)
+      for (rulep = derives[symbol1]; *rulep; rulep++)
 	{
 	  int done;
 	  int length = 1;
@@ -286,7 +286,7 @@ build_relations (void)
 	  state_t *state = states[from_state[i]];
 	  states1[0] = state->number;
 
-	  for (rp = rules[*rulep].rhs; *rp >= 0; rp++)
+	  for (rp = (*rulep)->rhs; *rp >= 0; rp++)
 	    {
 	      state = transitions_to (state->transitions,
 				      item_number_as_symbol_number (*rp));
