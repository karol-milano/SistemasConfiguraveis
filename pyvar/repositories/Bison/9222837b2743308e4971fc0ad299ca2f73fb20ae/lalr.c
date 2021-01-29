@@ -291,7 +291,7 @@ initialize_F (void)
 
 
 static void
-add_lookback_edge (state_t *state, int ruleno, int gotono)
+add_lookback_edge (state_t *state, rule_number_t ruleno, int gotono)
 {
   int i;
   shorts *sp;
@@ -408,7 +408,7 @@ build_relations (void)
     {
       int nedges = 0;
       symbol_number_t symbol1 = states[to_state[i]]->accessing_symbol;
-      short *rulep;
+      rule_number_t *rulep;
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
 	{
