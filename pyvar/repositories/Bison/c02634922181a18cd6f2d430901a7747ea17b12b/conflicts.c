@@ -256,11 +256,11 @@ set_conflicts (state_t *state)
      check for shift-reduce conflict, and try to resolve using
      precedence */
   for (i = 0; i < state->nlookaheads; ++i)
-    if (LArule[state->lookaheadsp + i]->prec
-	&& LArule[state->lookaheadsp + i]->prec->prec
-	&& !bitset_disjoint_p (LA[state->lookaheadsp + i], lookaheadset))
+    if (state->lookaheads_rule[i]->prec
+	&& state->lookaheads_rule[i]->prec->prec
+	&& !bitset_disjoint_p (state->lookaheads[i], lookaheadset))
       {
-	resolve_sr_conflict (state, state->lookaheadsp + i);
+	resolve_sr_conflict (state, (state->lookaheads - LA) + i);
 	break;
       }
 
@@ -268,10 +268,10 @@ set_conflicts (state_t *state)
      for conflicts not resolved above.  */
   for (i = 0; i < state->nlookaheads; ++i)
     {
-      if (!bitset_disjoint_p (LA[state->lookaheadsp + i], lookaheadset))
+      if (!bitset_disjoint_p (state->lookaheads[i], lookaheadset))
 	conflicts[state->number] = 1;
 
-      bitset_or (lookaheadset, lookaheadset, LA[state->lookaheadsp + i]);
+      bitset_or (lookaheadset, lookaheadset, state->lookaheads[i]);
     }
 }
 
@@ -312,7 +312,7 @@ count_sr_conflicts (state_t *state)
       bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
 
   for (i = 0; i < state->nlookaheads; ++i)
-    bitset_or (lookaheadset, lookaheadset, LA[state->lookaheadsp + i]);
+    bitset_or (lookaheadset, lookaheadset, state->lookaheads[i]);
 
   bitset_and (lookaheadset, lookaheadset, shiftset);
 
@@ -340,7 +340,7 @@ count_rr_conflicts (state_t *state)
       int count = 0;
       int j;
       for (j = 0; j < state->nlookaheads; ++j)
-	if (bitset_test (LA[state->lookaheadsp + j], i))
+	if (bitset_test (state->lookaheads[j], i))
 	  count++;
 
       if (count >= 2)
