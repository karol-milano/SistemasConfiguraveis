@@ -226,7 +226,7 @@ output_gram (void)
 static void
 output_stos (void)
 {
-  int i;
+  size_t i;
   short *values = (short *) alloca (sizeof (short) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
@@ -356,7 +356,7 @@ action_row (state_t *state)
 	for (j = 0; j < ntokens; j++)
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
-	  if (BITISSET (LA (state->lookaheadsp + i), j))
+	  if (bitset_test (LA[state->lookaheadsp + i], j))
 	    actrow[j] = -LAruleno[state->lookaheadsp + i];
     }
 
@@ -488,7 +488,7 @@ save_row (int state)
 static void
 token_actions (void)
 {
-  int i;
+  size_t i;
   short *yydefact = XCALLOC (short, nstates);
 
   actrow = XCALLOC (short, ntokens);
@@ -641,9 +641,9 @@ save_column (int symbol, int default_state)
 static int
 default_goto (int symbol)
 {
-  int i;
-  int m = goto_map[symbol];
-  int n = goto_map[symbol + 1];
+  size_t i;
+  size_t m = goto_map[symbol];
+  size_t n = goto_map[symbol + 1];
   int default_state = -1;
   int max = 0;
 
@@ -741,7 +741,7 @@ matching_state (int vector)
   int w;
   int prev;
 
-  if (i >= nstates)
+  if (i >= (int) nstates)
     return -1;
 
   t = tally[i];
@@ -913,7 +913,7 @@ output_check (void)
 static void
 output_actions (void)
 {
-  int i;
+  size_t i;
   nvectors = nstates + nvars;
 
   froms = XCALLOC (short *, nvectors);
