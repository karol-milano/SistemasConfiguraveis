@@ -301,21 +301,21 @@ initialize_F (void)
 
 
 static void
-add_lookback_edge (int stateno, int ruleno, int gotono)
+add_lookback_edge (state_t *state, int ruleno, int gotono)
 {
   int i;
   shorts *sp;
 
-  for (i = 0; i < state_table[stateno]->nlookaheads; ++i)
-    if (LAruleno[state_table[stateno]->lookaheadsp + i] == ruleno)
+  for (i = 0; i < state->nlookaheads; ++i)
+    if (LAruleno[state->lookaheadsp + i] == ruleno)
       break;
 
-  assert (LAruleno[state_table[stateno]->lookaheadsp + i] == ruleno);
+  assert (LAruleno[state->lookaheadsp + i] == ruleno);
 
   sp = XCALLOC (shorts, 1);
-  sp->next = lookback[state_table[stateno]->lookaheadsp + i];
+  sp->next = lookback[state->lookaheadsp + i];
   sp->value = gotono;
-  lookback[state_table[stateno]->lookaheadsp + i] = sp;
+  lookback[state->lookaheadsp + i] = sp;
 }
 
 
@@ -417,7 +417,6 @@ build_relations (void)
   for (i = 0; i < ngotos; i++)
     {
       int nedges = 0;
-      int state1 = from_state[i];
       int symbol1 = state_table[to_state[i]]->accessing_symbol;
       short *rulep;
 
@@ -425,26 +424,26 @@ build_relations (void)
 	{
 	  int done;
 	  int length = 1;
-	  int stateno = state1;
 	  short *rp;
-	  states[0] = state1;
+	  state_t *state = state_table[from_state[i]];
+	  states[0] = state->number;
 
 	  for (rp = ritem + rule_table[*rulep].rhs; *rp > 0; rp++)
 	    {
-	      shifts *sp = state_table[stateno]->shifts;
+	      shifts *sp = state->shifts;
 	      int j;
 	      for (j = 0; j < sp->nshifts; j++)
 		{
-		  stateno = sp->shifts[j];
-		  if (state_table[stateno]->accessing_symbol == *rp)
+		  state = state_table[sp->shifts[j]];
+		  if (state->accessing_symbol == *rp)
 		    break;
 		}
 
-	      states[length++] = stateno;
+	      states[length++] = state->number;
 	    }
 
-	  if (!state_table[stateno]->consistent)
-	    add_lookback_edge (stateno, *rulep, i);
+	  if (!state->consistent)
+	    add_lookback_edge (state, *rulep, i);
 
 	  length--;
 	  done = 0;
@@ -455,8 +454,7 @@ build_relations (void)
 	      /* JF added rp>=ritem &&   I hope to god its right! */
 	      if (rp >= ritem && ISVAR (*rp))
 		{
-		  stateno = states[--length];
-		  edge[nedges++] = map_goto (stateno, *rp);
+		  edge[nedges++] = map_goto (states[--length], *rp);
 		  if (nullable[*rp])
 		    done = 0;
 		}
