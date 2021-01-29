@@ -76,7 +76,7 @@
    in a roundabout way, the bounds of the portion you are trying to
    examine.
 
-   Suppose that the portion of yytable starts at index P and the index
+   Suppose that the portion of YYTABLE starts at index P and the index
    to be examined within the portion is I.  Then if YYCHECK[P+I] != I,
    I is outside the bounds of what is actually allocated, and the
    default (from YYDEFACT or YYDEFGOTO) should be used.  Otherwise,
@@ -104,20 +104,80 @@
 /* From src/scan-skel.l. */
 void m4_invoke PARAMS ((const char *definitions));
 
+
+/* Several tables will be indexed both by state and nonterminal
+   numbers.  We call `vector' such a thing (= either a state or a
+   symbol number.
+
+   Of course vector_number_t ought to be wide enough to contain
+   state_number_t and symbol_number_t.  */
+typedef short vector_number_t;
+#define VECTOR_NUMBER_MAX ((vector_number_t) SHRT_MAX)
+#define VECTOR_NUMBER_MIN ((vector_number_t) SHRT_MIN)
+#define state_number_to_vector_number(State) \
+   ((vector_number_t) State)
+#define symbol_number_to_vector_number(Symbol) \
+   ((vector_number_t) (state_number_as_int (nstates) + Symbol - ntokens))
+
 static int nvectors;
-static int nentries;
-static state_number_t **froms = NULL;
-static state_number_t **tos = NULL;
+
+
+/* FROMS and TOS are indexed by vector_number_t.
+
+   If VECTOR is a nonterminal, (FROMS[VECTOR], TOS[VECTOR]) form an
+   array of state numbers of the non defaulted GOTO on VECTOR.
+
+   If VECTOR is a state, TOS[VECTOR] is the array of actions to do on
+   the (array of) symbols FROMS[VECTOR].
+
+   In both cases, TALLY[VECTOR] is the size of the arrays
+   FROMS[VECTOR], TOS[VECTOR]; and WIDTH[VECTOR] =
+   (FROMS[VECTOR][SIZE] - FROMS[VECTOR][0] + 1) where SIZE =
+   TALLY[VECTOR].
+
+   FROMS therefore contains symbol_number_t and action_number_t,
+   TOS state_number_t and action_number_t,
+   TALLY sizes,
+   WIDTH differences of FROMS.
+
+   Let base_t be the type of FROMS, TOS, and WIDTH.  */
+typedef int base_t;
+#define BASE_MAX ((base_t) INT_MAX)
+#define BASE_MIN ((base_t) INT_MIN)
+
+static base_t **froms = NULL;
+static base_t **tos = NULL;
 static unsigned int **conflict_tos = NULL;
 static short *tally = NULL;
-static short *width = NULL;
-static short *actrow = NULL;
-static short *conflrow = NULL;
-static short *state_count = NULL;
-static short *order = NULL;
-static short *base = NULL;
-static short *pos = NULL;
+static base_t *width = NULL;
+
 
+/* For a given state, N = ACTROW[SYMBOL]:
+
+   If N = 0, stands for `run the default action'.
+   If N = MIN, stands for `raise a parse error'.
+   If N > 0, stands for `shift SYMBOL and go to n'.
+   If N < 0, stands for `reduce -N'.  */
+typedef short action_t;
+#define ACTION_MAX ((action_t) SHRT_MAX)
+#define ACTION_MIN ((action_t) SHRT_MIN)
+
+static action_t *actrow = NULL;
+
+/* FROMS and TOS are reordered to be compressed.  ORDER[VECTOR] is the
+   new vector number of VECTOR.  We skip `empty' vectors (i.e.,
+   TALLY[VECTOR] = 0), and call these `entries'.  */
+static vector_number_t *order = NULL;
+static int nentries;
+
+static base_t *base = NULL;
+/* A distinguished value of BASE, negative infinite.  During the
+   computation equals to BASE_MIN, later mapped to BASE_NINF to
+   keep parser tables small.  */
+base_t base_ninf = 0;
+static base_t *pos = NULL;
+
+static unsigned int *conflrow = NULL;
 static unsigned int *conflict_table = NULL;
 static unsigned int *conflict_list = NULL;
 static int conflict_list_cnt;
@@ -127,8 +187,13 @@ static int conflict_list_free;
    We start with the original hard-coded value: SHRT_MAX
    (yes, not USHRT_MAX). */
 static size_t table_size = SHRT_MAX;
-static short *table = NULL;
-static short *check = NULL;
+static base_t *table = NULL;
+static base_t *check = NULL;
+/* The value used in TABLE to denote explicit parse errors
+   (%nonassoc), a negative infinite.  First defaults to ACTION_MIN,
+   but in order to keep small tables, renumbered as TABLE_ERROR, which
+   is the smallest (non error) value minus 1.  */
+base_t table_ninf = 0;
 static int lowzero;
 static int high;
 
@@ -155,8 +220,8 @@ table_grow (size_t desired)
     fprintf (stderr, "growing table and check from: %d to %d\n",
 	     old_size, table_size);
 
-  table = XREALLOC (table, short, table_size);
-  check = XREALLOC (check, short, table_size);
+  table = XREALLOC (table, base_t, table_size);
+  check = XREALLOC (check, base_t, table_size);
   if (glr_parser)
     conflict_table = XREALLOC (conflict_table, unsigned int, table_size);
 
@@ -185,6 +250,7 @@ Name (const char *name,							\
       int begin,							\
       int end)								\
 {									\
+  Type min = first;							\
   Type max = first;							\
   int i;								\
   int j = 1;								\
@@ -201,13 +267,19 @@ Name (const char *name,							\
       else								\
 	++j;								\
       obstack_fgrow1 (&format_obstack, "%6d", table_data[i]);		\
-      if (table_data[i] > max)						\
+      if (table_data[i] < min)						\
+	min = table_data[i];						\
+      if (max < table_data[i])						\
 	max = table_data[i];						\
     }									\
   obstack_1grow (&format_obstack, 0);					\
   muscle_insert (name, obstack_finish (&format_obstack));		\
 									\
-  /* Build `NAME_max' in the obstack. */				\
+  /* Build `NAME_min' and `NAME_max' in the obstack. */			\
+  obstack_fgrow1 (&format_obstack, "%s_min", name);			\
+  obstack_1grow (&format_obstack, 0);					\
+  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack),		\
+			  (long int) min);				\
   obstack_fgrow1 (&format_obstack, "%s_max", name);			\
   obstack_1grow (&format_obstack, 0);					\
   MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack),		\
@@ -215,7 +287,10 @@ Name (const char *name,							\
 }
 
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_int_table, int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_table, short)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_base_table, base_t)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_rule_number_table, rule_number_t)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number_t)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number_t)
@@ -266,14 +341,14 @@ prepare_tokens (void)
     muscle_insert ("tname", obstack_finish (&format_obstack));
   }
 
-    /* Output YYTOKNUM. */
+  /* Output YYTOKNUM. */
   {
     int i;
-    short *values = XCALLOC (short, ntokens + 1);
+    int *values = XCALLOC (int, ntokens + 1);
     for (i = 0; i < ntokens + 1; ++i)
       values[i] = symbols[i]->user_token_number;
-    muscle_insert_short_table ("toknum", values,
-			       0, 1, ntokens + 1);
+    muscle_insert_int_table ("toknum", values,
+			     0, 1, ntokens + 1);
     free (values);
   }
 }
@@ -356,12 +431,12 @@ prepare_states (void)
 
 /*-------------------------------------------------------------------.
 | For GLR parsers, for each conflicted token in STATE, as indicated  |
-| by non-zero entries in conflrow, create a list of possible 	     |
+| by non-zero entries in CONFLROW, create a list of possible 	     |
 | reductions that are alternatives to the shift or reduction	     |
 | currently recorded for that token in STATE.  Store the alternative |
 | reductions followed by a 0 in conflict_list, updating		     |
 | conflict_list_cnt, and storing an index to the start of the list   |
-| back into conflrow.						     |
+| back into CONFLROW.						     |
 `-------------------------------------------------------------------*/
 
 static void
@@ -377,11 +452,12 @@ conflict_row (state_t *state)
       {
 	conflrow[j] = conflict_list_cnt;
 
-	/* find all reductions for token j, and record all that do
-	 * not match actrow[j] */
+	/* Find all reductions for token J, and record all that do not
+	   match ACTROW[J].  */
 	for (i = 0; i < state->nlookaheads; i += 1)
 	  if (bitset_test (state->lookaheads[i], j)
-	      && actrow[j] != -state->lookaheads_rule[i]->number)
+	      && (actrow[j]
+		  != rule_number_as_item_number (state->lookaheads_rule[i]->number)))
 	    {
 	      assert (conflict_list_free > 0);
 	      conflict_list[conflict_list_cnt]
@@ -390,7 +466,7 @@ conflict_row (state_t *state)
 	      conflict_list_free -= 1;
 	    }
 
-	/* Leave a 0 at the end */
+	/* Leave a 0 at the end.  */
 	assert (conflict_list_free > 0);
 	conflict_list_cnt += 1;
 	conflict_list_free -= 1;
@@ -401,23 +477,23 @@ conflict_row (state_t *state)
 /*------------------------------------------------------------------.
 | Decide what to do for each type of token if seen as the lookahead |
 | token in specified state.  The value returned is used as the      |
-| default action (yydefact) for the state.  In addition, actrow is  |
+| default action (yydefact) for the state.  In addition, ACTROW is  |
 | filled with what to do for each kind of token, index by symbol    |
 | number, with zero meaning do the default action.  The value       |
-| SHRT_MIN, a very negative number, means this situation is an      |
+| ACTION_MIN, a very negative number, means this situation is an    |
 | error.  The parser recognizes this value specially.               |
 |                                                                   |
 | This is where conflicts are resolved.  The loop over lookahead    |
 | rules considered lower-numbered rules last, and the last rule     |
 | considered that likes a token gets to handle it.                  |
-|								    |
-| For GLR parsers, also sets conflrow[SYM] to an index into         |
+|                                                                   |
+| For GLR parsers, also sets CONFLROW[SYM] to an index into         |
 | conflict_list iff there is an unresolved conflict (s/r or r/r)    |
 | with symbol SYM. The default reduction is not used for a symbol   |
-| that has any such conflicts.					    |
+| that has any such conflicts.                                      |
 `------------------------------------------------------------------*/
 
-static int
+static rule_number_t
 action_row (state_t *state)
 {
   int i;
@@ -447,7 +523,7 @@ action_row (state_t *state)
 	     token follows.  */
 	  if (actrow[j] != 0)
 	    conflicted = conflrow[j] = 1;
-	  actrow[j] = -state->lookaheads_rule[i]->number;
+	  actrow[j] = rule_number_as_item_number (state->lookaheads_rule[i]->number);
 	}
     }
 
@@ -471,11 +547,11 @@ action_row (state_t *state)
       }
 
   /* See which tokens are an explicit error in this state (due to
-     %nonassoc).  For them, record SHRT_MIN as the action.  */
+     %nonassoc).  For them, record ACTION_MIN as the action.  */
   for (i = 0; i < errp->num; i++)
     {
       symbol_number_t symbol = errp->symbols[i];
-      actrow[symbol] = SHRT_MIN;
+      actrow[symbol] = ACTION_MIN;
     }
 
   /* Now find the most common reduction and make it the default action
@@ -495,7 +571,7 @@ action_row (state_t *state)
 	      symbol_number_t j;
 
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == -rule)
+		if (actrow[j] == rule_number_as_item_number (rule))
 		  count++;
 
 	      if (count > max)
@@ -515,7 +591,7 @@ action_row (state_t *state)
 	    {
 	      int j;
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == -default_rule
+		if (actrow[j] == rule_number_as_item_number (default_rule)
 		    && ! (glr_parser && conflrow[j]))
 		  actrow[j] = 0;
 	    }
@@ -527,7 +603,7 @@ action_row (state_t *state)
 
   if (default_rule == 0)
     for (i = 0; i < ntokens; i++)
-      if (actrow[i] == SHRT_MIN)
+      if (actrow[i] == ACTION_MIN)
 	actrow[i] = 0;
 
   if (conflicted)
@@ -537,16 +613,21 @@ action_row (state_t *state)
 }
 
 
+/*--------------------------------------------.
+| Set FROMS, TOS, TALLY and WIDTH for STATE.  |
+`--------------------------------------------*/
+
 static void
 save_row (state_number_t state)
 {
   symbol_number_t i;
   int count;
-  short *sp = NULL;
-  short *sp1 = NULL;
-  short *sp2 = NULL;
+  base_t *sp = NULL;
+  base_t *sp1 = NULL;
+  base_t *sp2 = NULL;
   unsigned int *sp3 = NULL;
 
+  /* Number of non default actions in STATE.  */
   count = 0;
   for (i = 0; i < ntokens; i++)
     if (actrow[i] != 0)
@@ -555,13 +636,15 @@ save_row (state_number_t state)
   if (count == 0)
     return;
 
-  froms[state] = sp1 = sp = XCALLOC (short, count);
-  tos[state] = sp2 = XCALLOC (short, count);
+  /* Allocate non defaulted actions.  */
+  froms[state] = sp1 = sp = XCALLOC (base_t, count);
+  tos[state] = sp2 = XCALLOC (base_t, count);
   if (glr_parser)
     conflict_tos[state] = sp3 = XCALLOC (unsigned int, count);
   else
     conflict_tos[state] = NULL;
 
+  /* Store non defaulted actions.  */
   for (i = 0; i < ntokens; i++)
     if (actrow[i] != 0)
       {
@@ -590,11 +673,11 @@ token_actions (void)
   state_number_t i;
   int nconflict = conflicts_total_count ();
 
-  short *yydefact = XCALLOC (short, nstates);
+  rule_number_t *yydefact = XCALLOC (rule_number_t, nstates);
 
-  actrow = XCALLOC (short, ntokens);
+  actrow = XCALLOC (action_t, ntokens);
+  conflrow = XCALLOC (unsigned int, ntokens);
 
-  conflrow = XCALLOC (short, ntokens);
   if (glr_parser)
     {
       conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
@@ -610,8 +693,8 @@ token_actions (void)
       save_row (i);
     }
 
-  muscle_insert_short_table ("defact", yydefact,
-			     yydefact[0], 1, nstates);
+  muscle_insert_rule_number_table ("defact", yydefact,
+				   yydefact[0], 1, nstates);
   XFREE (actrow);
   XFREE (conflrow);
   XFREE (yydefact);
@@ -783,19 +866,29 @@ symbol_printers_output (FILE *out)
 }
 
 
+/*------------------------------------------------------------------.
+| Compute FROMS[VECTOR], TOS[VECTOR], TALLY[VECTOR], WIDTH[VECTOR], |
+| i.e., the information related to non defaulted GOTO on the nterm  |
+| SYMBOL.                                                           |
+|                                                                   |
+| DEFAULT_STATE is the principal destination on SYMBOL, i.e., the   |
+| default GOTO destination on SYMBOL.                               |
+`------------------------------------------------------------------*/
+
 static void
 save_column (symbol_number_t symbol, state_number_t default_state)
 {
   int i;
-  state_number_t *sp;
-  state_number_t *sp1;
-  state_number_t *sp2;
+  base_t *sp;
+  base_t *sp1;
+  base_t *sp2;
   int count;
-  int symno = symbol - ntokens + state_number_as_int (nstates);
+  vector_number_t symno = symbol_number_to_vector_number (symbol);
 
   goto_number_t begin = goto_map[symbol];
   goto_number_t end = goto_map[symbol + 1];
 
+  /* Number of non default GOTO.  */
   count = 0;
   for (i = begin; i < end; i++)
     if (to_state[i] != default_state)
@@ -804,9 +897,11 @@ save_column (symbol_number_t symbol, state_number_t default_state)
   if (count == 0)
     return;
 
-  froms[symno] = sp1 = sp = XCALLOC (short, count);
-  tos[symno] = sp2 = XCALLOC (short, count);
+  /* Allocate room for non defaulted gotos.  */
+  froms[symno] = sp1 = sp = XCALLOC (base_t, count);
+  tos[symno] = sp2 = XCALLOC (base_t, count);
 
+  /* Store the state numbers of the non defaulted gotos.  */
   for (i = begin; i < end; i++)
     if (to_state[i] != default_state)
       {
@@ -819,8 +914,12 @@ save_column (symbol_number_t symbol, state_number_t default_state)
 }
 
 
+/*----------------------------------------------------------------.
+| Return `the' most common destination GOTO on SYMBOL (a nterm).  |
+`----------------------------------------------------------------*/
+
 static state_number_t
-default_goto (symbol_number_t symbol)
+default_goto (symbol_number_t symbol, short state_count[])
 {
   state_number_t s;
   int i;
@@ -862,12 +961,14 @@ static void
 goto_actions (void)
 {
   symbol_number_t i;
-  state_number_t *yydefgoto = XMALLOC (state_number_t, nsyms - ntokens);
+  state_number_t *yydefgoto = XMALLOC (state_number_t, nvars);
 
-  state_count = XCALLOC (short, nstates);
+  /* For a given nterm I, STATE_COUNT[S] is the number of times there
+     is a GOTO to S on I.  */
+  short *state_count = XCALLOC (short, nstates);
   for (i = ntokens; i < nsyms; ++i)
     {
-      state_number_t default_state = default_goto (i);
+      state_number_t default_state = default_goto (i, state_count);
       save_column (i, default_state);
       yydefgoto[i - ntokens] = default_state;
     }
@@ -879,8 +980,10 @@ goto_actions (void)
 }
 
 
-/* The next few functions decide how to pack the actions and gotos
-   information into yytable. */
+/*------------------------------------------------------------------.
+| Compute ORDER, a reordering of vectors, in order to decide how to |
+| pack the actions and gotos information into yytable.              |
+`------------------------------------------------------------------*/
 
 static void
 sort_actions (void)
@@ -912,14 +1015,21 @@ sort_actions (void)
 }
 
 
-static int
-matching_state (int vector)
+/* If VECTOR is a state which actions (reflected by FROMS, TOS, TALLY
+   and WIDTH of VECTOR) are common to a previous state, return this
+   state number.
+
+   In any other case, return -1.  */
+
+static state_number_t
+matching_state (vector_number_t vector)
 {
-  int i = order[vector];
+  vector_number_t i = order[vector];
   int t;
   int w;
   int prev;
 
+  /* If VECTOR is a nterm, return -1.  */
   if (i >= (int) nstates)
     return -1;
 
@@ -928,10 +1038,12 @@ matching_state (int vector)
 
   for (prev = vector - 1; prev >= 0; prev--)
     {
-      int j = order[prev];
+      vector_number_t j = order[prev];
       int k;
       int match = 1;
 
+      /* Given how ORDER was computed, if the WIDTH or TALLY is
+	 different, there cannot be a matching state.  */
       if (width[j] != w || tally[j] != t)
 	return -1;
 
@@ -947,15 +1059,15 @@ matching_state (int vector)
 }
 
 
-static int
-pack_vector (int vector)
+static base_t
+pack_vector (vector_number_t vector)
 {
-  int i = order[vector];
+  vector_number_t i = order[vector];
   int j;
   int t = tally[i];
   int loc = 0;
-  short *from = froms[i];
-  short *to = tos[i];
+  base_t *from = froms[i];
+  base_t *to = tos[i];
   unsigned int *conflict_to = conflict_tos[i];
 
   assert (t);
@@ -983,11 +1095,11 @@ pack_vector (int vector)
 	{
 	  for (k = 0; k < t; k++)
 	    {
-	      loc = j + state_number_as_int (from[k]);
-	      table[loc] = state_number_as_int (to[k]);
+	      loc = j + from[k];
+	      table[loc] = to[k];
 	      if (glr_parser && conflict_to != NULL)
 		conflict_table[loc] = conflict_to[k];
-	      check[loc] = state_number_as_int (from[k]);
+	      check[loc] = from[k];
 	    }
 
 	  while (table[lowzero] != 0)
@@ -996,6 +1108,8 @@ pack_vector (int vector)
 	  if (loc > high)
 	    high = loc;
 
+	  if (j < BASE_MIN || BASE_MAX < j)
+	    fatal ("base_t too small to hold %d\n", j);
 	  return j;
 	}
     }
@@ -1005,42 +1119,74 @@ pack_vector (int vector)
 }
 
 
+/*-------------------------------------------------------------.
+| Remap the negative infinite in TAB from NINF to the greatest |
+| possible smallest value.  Return it.                         |
+|                                                              |
+| In most case this allows us to use shorts instead of ints in |
+| parsers.                                                     |
+`-------------------------------------------------------------*/
+
+static base_t
+table_ninf_remap (base_t tab[], size_t size, base_t ninf)
+{
+  base_t res = 0;
+  size_t i;
+
+  for (i = 0; i < size; i++)
+    if (tab[i] < res && tab[i] != ninf)
+      res = base[i];
+
+  --res;
+
+  for (i = 0; i < size; i++)
+    if (tab[i] == ninf)
+      tab[i] = res;
+
+  return res;
+}
+
 static void
 pack_table (void)
 {
   int i;
-  int place;
-  int state;
 
-  base = XCALLOC (short, nvectors);
-  pos = XCALLOC (short, nentries);
-  table = XCALLOC (short, table_size);
+  base = XCALLOC (base_t, nvectors);
+  pos = XCALLOC (base_t, nentries);
+  table = XCALLOC (base_t, table_size);
   if (glr_parser)
     conflict_table = XCALLOC (unsigned int, table_size);
-  check = XCALLOC (short, table_size);
+  check = XCALLOC (base_t, table_size);
 
   lowzero = 0;
   high = 0;
 
   for (i = 0; i < nvectors; i++)
-    base[i] = SHRT_MIN;
+    base[i] = BASE_MIN;
 
   for (i = 0; i < (int) table_size; i++)
     check[i] = -1;
 
   for (i = 0; i < nentries; i++)
     {
-      state = matching_state (i);
+      state_number_t state = matching_state (i);
+      base_t place;
 
       if (state < 0)
+	/* A new set of state actions, or a nonterminal.  */
 	place = pack_vector (i);
       else
+	/* Action of I were already coded for STATE.  */
 	place = base[state];
 
       pos[i] = place;
       base[order[i]] = place;
     }
 
+  /* Use the greatest possible negative infinites.  */
+  base_ninf = table_ninf_remap (base, nvectors, BASE_MIN);
+  table_ninf = table_ninf_remap (table, high + 1, ACTION_MIN);
+
   for (i = 0; i < nvectors; i++)
     {
       XFREE (froms[i]);
@@ -1054,18 +1200,20 @@ pack_table (void)
   free (pos);
 }
 
+
 /* the following functions output yytable, yycheck, yyconflp, yyconfl,
-   and the vectors whose elements index the portion starts */
+   and the vectors whose elements index the portion starts.  */
 
 static void
 output_base (void)
 {
-  /* Output pact. */
-  muscle_insert_short_table ("pact", base,
+  /* Output PACT. */
+  muscle_insert_base_table ("pact", base,
 			     base[0], 1, nstates);
+  MUSCLE_INSERT_INT ("pact_ninf", base_ninf);
 
-  /* Output pgoto. */
-  muscle_insert_short_table ("pgoto", base,
+  /* Output PGOTO. */
+  muscle_insert_base_table ("pgoto", base,
 			     base[nstates], nstates + 1, nvectors);
   XFREE (base);
 }
@@ -1074,8 +1222,9 @@ output_base (void)
 static void
 output_table (void)
 {
-  muscle_insert_short_table ("table", table,
-			     table[0], 1, high + 1);
+  muscle_insert_base_table ("table", table,
+			    table[0], 1, high + 1);
+  MUSCLE_INSERT_INT ("table_ninf", table_ninf);
   XFREE (table);
 }
 
@@ -1105,8 +1254,8 @@ output_conflicts (void)
 static void
 output_check (void)
 {
-  muscle_insert_short_table ("check", check,
-			     check[0], 1, high + 1);
+  muscle_insert_base_table ("check", check,
+			    check[0], 1, high + 1);
   XFREE (check);
 }
 
@@ -1126,11 +1275,11 @@ prepare_actions (void)
 
   nvectors = state_number_as_int (nstates) + nvars;
 
-  froms = XCALLOC (short *, nvectors);
-  tos = XCALLOC (short *, nvectors);
+  froms = XCALLOC (base_t *, nvectors);
+  tos = XCALLOC (base_t *, nvectors);
   conflict_tos = XCALLOC (unsigned int *, nvectors);
   tally = XCALLOC (short, nvectors);
-  width = XCALLOC (short, nvectors);
+  width = XCALLOC (base_t, nvectors);
 
   token_actions ();
   bitsetv_free (LA);
@@ -1141,7 +1290,7 @@ prepare_actions (void)
   XFREE (from_state);
   XFREE (to_state);
 
-  order = XCALLOC (short, nvectors);
+  order = XCALLOC (vector_number_t, nvectors);
   sort_actions ();
   pack_table ();
   free (order);
@@ -1237,7 +1386,6 @@ prepare (void)
 
   /* States. */
   MUSCLE_INSERT_INT ("last", high);
-  MUSCLE_INSERT_INT ("flag", SHRT_MIN);
   MUSCLE_INSERT_INT ("final_state_number", final_state->number);
   MUSCLE_INSERT_INT ("states_number", nstates);
 
