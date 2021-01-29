@@ -155,7 +155,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 static void
 set_conflicts (state_t *state)
 {
-  int i, j;
+  int i;
   shifts *shiftp;
 
   if (state->consistent)
@@ -172,25 +172,19 @@ set_conflicts (state_t *state)
      check for shift-reduce conflict, and try to resolve using
      precedence */
   for (i = 0; i < state->nlookaheads; ++i)
-    if (rules[LAruleno[state->lookaheadsp + i]].prec)
-      for (j = 0; j < ntokens; ++j)
-	if (bitset_test (LA[state->lookaheadsp + i], j)
-	    && bitset_test (lookaheadset, j))
-	  {
-	    resolve_sr_conflict (state, state->lookaheadsp + i);
-	    break;
-	  }
-
+    if (rules[LAruleno[state->lookaheadsp + i]].prec
+	&& !bitset_disjoint_p (LA[state->lookaheadsp + i], lookaheadset))
+      {
+	resolve_sr_conflict (state, state->lookaheadsp + i);
+	break;
+      }
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
   for (i = 0; i < state->nlookaheads; ++i)
     {
-      /* FIXME: Here, I need something like `bitset_disjoint_p'. */
-      for (j = 0; j < ntokens; ++j)
-	if (bitset_test (LA[state->lookaheadsp + i], j)
-	    && bitset_test (lookaheadset, j))
-	  conflicts[state->number] = 1;
+      if (!bitset_disjoint_p (LA[state->lookaheadsp + i], lookaheadset))
+	conflicts[state->number] = 1;
 
       bitset_or (lookaheadset, lookaheadset, LA[state->lookaheadsp + i]);
     }
@@ -236,9 +230,7 @@ count_sr_conflicts (state_t *state)
 
   bitset_and (lookaheadset, lookaheadset, shiftset);
 
-  for (i = 0; i < ntokens; i++)
-    if (bitset_test (lookaheadset, i))
-      src_count++;
+  src_count = bitset_count (lookaheadset);
 
   return src_count;
 }
