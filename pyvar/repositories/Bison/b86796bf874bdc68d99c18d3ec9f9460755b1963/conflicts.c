@@ -35,8 +35,8 @@
 int expected_conflicts = -1;
 static char *conflicts = NULL;
 
-static unsigned *shiftset = NULL;
-static unsigned *lookaheadset = NULL;
+static bitset shiftset;
+static bitset lookaheadset;
 
 
 static inline void
@@ -63,7 +63,7 @@ flush_shift (state_t *state, int token)
   shifts *shiftp = state->shifts;
   int i;
 
-  RESETBIT (lookaheadset, token);
+  bitset_reset (lookaheadset, token);
   for (i = 0; i < shiftp->nshifts; i++)
     if (!SHIFT_IS_DISABLED (shiftp, i) && SHIFT_SYMBOL (shiftp, i) == token)
       SHIFT_DISABLE (shiftp, i);
@@ -101,7 +101,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 
   for (i = 0; i < ntokens; i++)
     if (bitset_test (LA[lookahead], i)
-	&& BITISSET (lookaheadset, i)
+	&& bitset_test (lookaheadset, i)
 	&& symbols[i]->prec)
       {
 	/* Shift-reduce conflict occurs for token number i
@@ -161,13 +161,12 @@ set_conflicts (state_t *state)
   if (state->consistent)
     return;
 
-  for (i = 0; i < tokensetsize; i++)
-    lookaheadset[i] = 0;
+  bitset_zero (lookaheadset);
 
   shiftp = state->shifts;
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
-      SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
+      bitset_set (lookaheadset, SHIFT_SYMBOL (shiftp, i));
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
@@ -176,7 +175,7 @@ set_conflicts (state_t *state)
     if (rules[LAruleno[state->lookaheadsp + i]].prec)
       for (j = 0; j < ntokens; ++j)
 	if (bitset_test (LA[state->lookaheadsp + i], j)
-	    && BITISSET (lookaheadset, j))
+	    && bitset_test (lookaheadset, j))
 	  {
 	    resolve_sr_conflict (state, state->lookaheadsp + i);
 	    break;
@@ -189,12 +188,12 @@ set_conflicts (state_t *state)
     {
       for (j = 0; j < ntokens; ++j)
 	if (bitset_test (LA[state->lookaheadsp + i], j)
-	    && BITISSET (lookaheadset, j))
+	    && bitset_test (lookaheadset, j))
 	  conflicts[state->number] = 1;
 
       for (j = 0; j < ntokens; ++j)
 	if (bitset_test (LA[state->lookaheadsp + i], j))
-	  SETBIT (lookaheadset, j);
+	  bitset_set (lookaheadset, j);
     }
 }
 
@@ -204,8 +203,10 @@ solve_conflicts (void)
   size_t i;
 
   conflicts = XCALLOC (char, nstates);
-  shiftset = XCALLOC (unsigned, tokensetsize);
-  lookaheadset = XCALLOC (unsigned, tokensetsize);
+  shiftset = bitset_create (ntokens, BITSET_FIXED);
+  bitset_zero (shiftset);
+  lookaheadset = bitset_create (ntokens, BITSET_FIXED);
+  bitset_zero (lookaheadset);
 
   for (i = 0; i < nstates; i++)
     set_conflicts (states[i]);
@@ -226,26 +227,22 @@ count_sr_conflicts (state_t *state)
   if (!shiftp)
     return 0;
 
-  for (i = 0; i < tokensetsize; i++)
-    {
-      shiftset[i] = 0;
-      lookaheadset[i] = 0;
-    }
+  bitset_zero (lookaheadset);
+  bitset_zero (shiftset);
 
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
-      SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+      bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
 
   for (i = 0; i < state->nlookaheads; ++i)
     for (k = 0; k < ntokens; ++k)
       if (bitset_test (LA[state->lookaheadsp + i], k))
-	SETBIT (lookaheadset, k);
+	bitset_set (lookaheadset, k);
 
-  for (k = 0; k < tokensetsize; ++k)
-    lookaheadset[k] &= shiftset[k];
+  bitset_and (lookaheadset, lookaheadset, shiftset);
 
   for (i = 0; i < ntokens; i++)
-    if (BITISSET (lookaheadset, i))
+    if (bitset_test (lookaheadset, i))
       src_count++;
 
   return src_count;
@@ -408,6 +405,6 @@ void
 free_conflicts (void)
 {
   XFREE (conflicts);
-  XFREE (shiftset);
-  XFREE (lookaheadset);
+  bitset_free (shiftset);
+  bitset_free (lookaheadset);
 }
