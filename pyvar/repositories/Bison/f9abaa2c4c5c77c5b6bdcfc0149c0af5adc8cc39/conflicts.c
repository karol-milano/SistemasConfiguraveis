@@ -186,14 +186,13 @@ set_conflicts (state_t *state)
      for conflicts not resolved above.  */
   for (i = 0; i < state->nlookaheads; ++i)
     {
+      /* FIXME: Here, I need something like `bitset_disjoint_p'. */
       for (j = 0; j < ntokens; ++j)
 	if (bitset_test (LA[state->lookaheadsp + i], j)
 	    && bitset_test (lookaheadset, j))
 	  conflicts[state->number] = 1;
 
-      for (j = 0; j < ntokens; ++j)
-	if (bitset_test (LA[state->lookaheadsp + i], j))
-	  bitset_set (lookaheadset, j);
+      bitset_or (lookaheadset, lookaheadset, LA[state->lookaheadsp + i]);
     }
 }
 
@@ -220,7 +219,7 @@ solve_conflicts (void)
 static int
 count_sr_conflicts (state_t *state)
 {
-  int i, k;
+  int i;
   int src_count = 0;
   shifts *shiftp = state->shifts;
 
@@ -235,9 +234,7 @@ count_sr_conflicts (state_t *state)
       bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
 
   for (i = 0; i < state->nlookaheads; ++i)
-    for (k = 0; k < ntokens; ++k)
-      if (bitset_test (LA[state->lookaheadsp + i], k))
-	bitset_set (lookaheadset, k);
+    bitset_or (lookaheadset, lookaheadset, LA[state->lookaheadsp + i]);
 
   bitset_and (lookaheadset, lookaheadset, shiftset);
 
