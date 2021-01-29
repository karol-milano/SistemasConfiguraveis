@@ -225,6 +225,7 @@ GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_table, short)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number_t)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number_t)
 
 
 /*-----------------------------------------------------------------.
@@ -350,13 +351,13 @@ prepare_rules (void)
 static void
 prepare_states (void)
 {
-  size_t i;
+  state_number_t i;
   symbol_number_t *values =
     (symbol_number_t *) alloca (sizeof (symbol_number_t) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
   muscle_insert_symbol_number_table ("stos", values,
-				    0, 1, nstates);
+				     0, 1, nstates);
 }
 
 
@@ -463,7 +464,7 @@ action_row (state_t *state)
   for (i = 0; i < shiftp->nshifts; i++)
     {
       symbol_number_t symbol;
-      int shift_state = shiftp->shifts[i];
+      state_number_t shift_state = shiftp->shifts[i];
       if (!shift_state)
 	continue;
 
@@ -474,7 +475,7 @@ action_row (state_t *state)
 
       if (actrow[symbol] != 0)
 	conflicted = conflrow[symbol] = 1;
-      actrow[symbol] = shift_state;
+      actrow[symbol] = state_number_as_int (shift_state);
 
       /* Do not use any default reduction if there is a shift for
 	 error */
@@ -550,9 +551,9 @@ action_row (state_t *state)
 
 
 static void
-save_row (int state)
+save_row (state_number_t state)
 {
-  int i;
+  symbol_number_t i;
   int count;
   short *sp = NULL;
   short *sp1 = NULL;
@@ -599,7 +600,7 @@ save_row (int state)
 static void
 token_actions (void)
 {
-  size_t i;
+  state_number_t i;
   int nconflict = conflicts_total_count ();
 
   short *yydefact = XCALLOC (short, nstates);
@@ -796,17 +797,17 @@ symbol_printers_output (FILE *out)
 
 
 static void
-save_column (int symbol, int default_state)
+save_column (symbol_number_t symbol, state_number_t default_state)
 {
   int i;
   short *sp;
   short *sp1;
   short *sp2;
   int count;
-  int symno = symbol - ntokens + nstates;
+  int symno = symbol - ntokens + state_number_as_int (nstates);
 
-  short begin = goto_map[symbol];
-  short end = goto_map[symbol + 1];
+  int begin = goto_map[symbol];
+  int end = goto_map[symbol + 1];
 
   count = 0;
   for (i = begin; i < end; i++)
@@ -830,29 +831,31 @@ save_column (int symbol, int default_state)
   width[symno] = sp1[-1] - sp[0] + 1;
 }
 
-static int
-default_goto (int symbol)
+
+static state_number_t
+default_goto (symbol_number_t symbol)
 {
-  size_t i;
-  size_t m = goto_map[symbol];
-  size_t n = goto_map[symbol + 1];
-  int default_state = -1;
+  state_number_t s;
+  int i;
+  int m = goto_map[symbol];
+  int n = goto_map[symbol + 1];
+  state_number_t default_state = (state_number_t) -1;
   int max = 0;
 
   if (m == n)
-    return -1;
+    return (state_number_t) -1;
 
-  for (i = 0; i < nstates; i++)
-    state_count[i] = 0;
+  for (s = 0; s < nstates; s++)
+    state_count[s] = 0;
 
   for (i = m; i < n; i++)
     state_count[to_state[i]]++;
 
-  for (i = 0; i < nstates; i++)
-    if (state_count[i] > max)
+  for (s = 0; s < nstates; s++)
+    if (state_count[s] > max)
       {
-	max = state_count[i];
-	default_state = i;
+	max = state_count[s];
+	default_state = s;
       }
 
   return default_state;
@@ -871,19 +874,19 @@ default_goto (int symbol)
 static void
 goto_actions (void)
 {
-  int i;
-  short *yydefgoto = XMALLOC (short, nsyms - ntokens);
+  symbol_number_t i;
+  state_number_t *yydefgoto = XMALLOC (state_number_t, nsyms - ntokens);
 
   state_count = XCALLOC (short, nstates);
   for (i = ntokens; i < nsyms; ++i)
     {
-      int default_state = default_goto (i);
+      state_number_t default_state = default_goto (i);
       save_column (i, default_state);
       yydefgoto[i - ntokens] = default_state;
     }
 
-  muscle_insert_short_table ("defgoto", yydefgoto,
-			     yydefgoto[0], 1, nsyms - ntokens);
+  muscle_insert_state_number_table ("defgoto", yydefgoto,
+				    yydefgoto[0], 1, nsyms - ntokens);
   XFREE (state_count);
   XFREE (yydefgoto);
 }
@@ -978,7 +981,7 @@ pack_vector (int vector)
 
       for (k = 0; ok && k < t; k++)
 	{
-	  loc = j + from[k];
+	  loc = j + state_number_as_int (from[k]);
 	  if (loc > (int) table_size)
 	    table_grow (loc);
 
@@ -994,11 +997,11 @@ pack_vector (int vector)
 	{
 	  for (k = 0; k < t; k++)
 	    {
-	      loc = j + from[k];
-	      table[loc] = to[k];
+	      loc = j + state_number_as_int (from[k]);
+	      table[loc] = state_number_as_int (to[k]);
 	      if (glr_parser && conflict_to != NULL)
 		conflict_table[loc] = conflict_to[k];
-	      check[loc] = from[k];
+	      check[loc] = state_number_as_int (from[k]);
 	    }
 
 	  while (table[lowzero] != 0)
@@ -1129,8 +1132,15 @@ output_check (void)
 static void
 output_actions (void)
 {
-  size_t i;
-  nvectors = nstates + nvars;
+  state_number_t i;
+
+  /* That's a poor way to make sure the sizes are properly corelated,
+     in particular the signedness is not taking into account, but it's
+     not useless.  */
+  assert (sizeof (nvectors) >= sizeof (nstates));
+  assert (sizeof (nvectors) >= sizeof (nvars));
+
+  nvectors = state_number_as_int (nstates) + nvars;
 
   froms = XCALLOC (short *, nvectors);
   tos = XCALLOC (short *, nvectors);
@@ -1266,7 +1276,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("pure", pure_parser);
   MUSCLE_INSERT_INT ("nsym", nsyms);
   MUSCLE_INSERT_INT ("debug", debug_flag);
-  MUSCLE_INSERT_INT ("final", final_state);
+  MUSCLE_INSERT_INT ("final", final_state->number);
   MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
   MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
   MUSCLE_INSERT_INT ("error_verbose", error_verbose);
