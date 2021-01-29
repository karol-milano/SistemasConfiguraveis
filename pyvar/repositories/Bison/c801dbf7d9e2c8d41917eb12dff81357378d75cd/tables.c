@@ -21,16 +21,18 @@
 
 
 #include "system.h"
-#include "bitsetv.h"
-#include "quotearg.h"
-#include "getargs.h"
+
+#include <bitsetv.h>
+#include <quotearg.h>
+
+#include "complain.h"
+#include "conflicts.h"
 #include "files.h"
+#include "getargs.h"
 #include "gram.h"
-#include "complain.h"
 #include "lalr.h"
 #include "reader.h"
 #include "symtab.h"
-#include "conflicts.h"
 #include "tables.h"
 
 /* Several tables are indexed both by state and nonterminal numbers.
@@ -38,19 +40,17 @@
    or a nonterminal number.
 
    Of course vector_number_t ought to be wide enough to contain
-   state_number_t and symbol_number_t.  */
-typedef short vector_number_t;
-#define VECTOR_NUMBER_MAX ((vector_number_t) SHRT_MAX)
-#define VECTOR_NUMBER_MIN ((vector_number_t) SHRT_MIN)
+   state_number and symbol_number.  */
+typedef short vector_number;
 #define state_number_to_vector_number(State) \
-   ((vector_number_t) State)
+   ((vector_number) State)
 #define symbol_number_to_vector_number(Symbol) \
-   ((vector_number_t) (state_number_as_int (nstates) + Symbol - ntokens))
+   ((vector_number) (state_number_as_int (nstates) + Symbol - ntokens))
 
 int nvectors;
 
 
-/* FROMS and TOS are indexed by vector_number_t.
+/* FROMS and TOS are indexed by vector_number.
 
    If VECTOR is a nonterminal, (FROMS[VECTOR], TOS[VECTOR]) form an
    array of state numbers of the non defaulted GOTO on VECTOR.
@@ -63,20 +63,20 @@ int nvectors;
    (FROMS[VECTOR][SIZE] - FROMS[VECTOR][0] + 1) where SIZE =
    TALLY[VECTOR].
 
-   FROMS therefore contains symbol_number_t and action_number_t,
-   TOS state_number_t and action_number_t,
+   FROMS therefore contains symbol_number and action_number,
+   TOS state_number and action_number,
    TALLY sizes,
    WIDTH differences of FROMS.
 
-   Let base_t be the type of FROMS, TOS, and WIDTH.  */
-#define BASE_MAX ((base_t) INT_MAX)
-#define BASE_MIN ((base_t) INT_MIN)
+   Let base_number be the type of FROMS, TOS, and WIDTH.  */
+#define BASE_MAXIMUM INT_MAX
+#define BASE_MINIMUM INT_MIN
 
-static base_t **froms = NULL;
-static base_t **tos = NULL;
+static base_number **froms = NULL;
+static base_number **tos = NULL;
 static unsigned int **conflict_tos = NULL;
 static short *tally = NULL;
-static base_t *width = NULL;
+static base_number *width = NULL;
 
 
 /* For a given state, N = ACTROW[SYMBOL]:
@@ -85,24 +85,23 @@ static base_t *width = NULL;
    If N = MIN, stands for `raise a syntax error'.
    If N > 0, stands for `shift SYMBOL and go to n'.
    If N < 0, stands for `reduce -N'.  */
-typedef short action_t;
-#define ACTION_MAX ((action_t) SHRT_MAX)
-#define ACTION_MIN ((action_t) SHRT_MIN)
+typedef short action_number;
+#define ACTION_NUMBER_MINIMUM SHRT_MIN
 
-static action_t *actrow = NULL;
+static action_number *actrow = NULL;
 
 /* FROMS and TOS are reordered to be compressed.  ORDER[VECTOR] is the
    new vector number of VECTOR.  We skip `empty' vectors (i.e.,
    TALLY[VECTOR] = 0), and call these `entries'.  */
-static vector_number_t *order = NULL;
+static vector_number *order = NULL;
 static int nentries;
 
-base_t *base = NULL;
+base_number *base = NULL;
 /* A distinguished value of BASE, negative infinite.  During the
-   computation equals to BASE_MIN, later mapped to BASE_NINF to
+   computation equals to BASE_MINIMUM, later mapped to BASE_NINF to
    keep parser tables small.  */
-base_t base_ninf = 0;
-static base_t *pos = NULL;
+base_number base_ninf = 0;
+static base_number *pos = NULL;
 
 static unsigned int *conflrow = NULL;
 unsigned int *conflict_table = NULL;
@@ -114,18 +113,18 @@ static int conflict_list_free;
    with more or less the original hard-coded value (which was
    SHRT_MAX).  */
 static size_t table_size = 32768;
-base_t *table = NULL;
-base_t *check = NULL;
+base_number *table = NULL;
+base_number *check = NULL;
 /* The value used in TABLE to denote explicit syntax errors
-   (%nonassoc), a negative infinite.  First defaults to ACTION_MIN,
+   (%nonassoc), a negative infinite.  First defaults to ACTION_NUMBER_MININUM,
    but in order to keep small tables, renumbered as TABLE_ERROR, which
    is the smallest (non error) value minus 1.  */
-base_t table_ninf = 0;
+base_number table_ninf = 0;
 static int lowzero;
 int high;
 
-state_number_t *yydefgoto;
-rule_number_t *yydefact;
+state_number *yydefgoto;
+rule_number *yydefact;
 
 /*----------------------------------------------------------------.
 | If TABLE (and CHECK) appear to be small to be addressed at      |
@@ -145,8 +144,8 @@ table_grow (size_t desired)
     fprintf (stderr, "growing table and check from: %d to %d\n",
 	     old_size, table_size);
 
-  table = XREALLOC (table, base_t, table_size);
-  check = XREALLOC (check, base_t, table_size);
+  table = XREALLOC (table, base_number, table_size);
+  check = XREALLOC (check, base_number, table_size);
   conflict_table = XREALLOC (conflict_table, unsigned int, table_size);
 
   for (/* Nothing. */; old_size < table_size; ++old_size)
@@ -160,20 +159,20 @@ table_grow (size_t desired)
 
 
 /*-------------------------------------------------------------------.
-| For GLR parsers, for each conflicted token in STATE, as indicated  |
+| For GLR parsers, for each conflicted token in S, as indicated      |
 | by non-zero entries in CONFLROW, create a list of possible 	     |
 | reductions that are alternatives to the shift or reduction	     |
-| currently recorded for that token in STATE.  Store the alternative |
+| currently recorded for that token in S.  Store the alternative     |
 | reductions followed by a 0 in CONFLICT_LIST, updating		     |
 | CONFLICT_LIST_CNT, and storing an index to the start of the list   |
 | back into CONFLROW.						     |
 `-------------------------------------------------------------------*/
 
 static void
-conflict_row (state_t *state)
+conflict_row (state *s)
 {
   int i, j;
-  reductions_t *reds = state->reductions;
+  reductions *reds = s->reductions;
 
   if (! glr_parser)
     return;
@@ -212,8 +211,9 @@ conflict_row (state_t *state)
 | default action (yydefact) for the state.  In addition, ACTROW is  |
 | filled with what to do for each kind of token, index by symbol    |
 | number, with zero meaning do the default action.  The value       |
-| ACTION_MIN, a very negative number, means this situation is an    |
-| error.  The parser recognizes this value specially.               |
+| ACTION_NUMBER_MINIMUM, a very negative number, means this	    |
+| situation is an error.  The parser recognizes this value	    |
+| specially.							    |
 |                                                                   |
 | This is where conflicts are resolved.  The loop over lookahead    |
 | rules considered lower-numbered rules last, and the last rule     |
@@ -225,14 +225,14 @@ conflict_row (state_t *state)
 | that has any such conflicts.                                      |
 `------------------------------------------------------------------*/
 
-static rule_t *
-action_row (state_t *state)
+static rule *
+action_row (state *s)
 {
   int i;
-  rule_t *default_rule = NULL;
-  reductions_t *redp = state->reductions;
-  transitions_t *transitions = state->transitions;
-  errs_t *errp = state->errs;
+  rule *default_rule = NULL;
+  reductions *reds = s->reductions;
+  transitions *trans = s->transitions;
+  errs *errp = s->errs;
   /* Set to nonzero to inhibit having any default reduction.  */
   int nodefault = 0;
   int conflicted = 0;
@@ -240,76 +240,77 @@ action_row (state_t *state)
   for (i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
 
-  if (redp->lookaheads)
+  if (reds->lookaheads)
     {
       int j;
       bitset_iterator biter;
       /* loop over all the rules available here which require
 	 lookahead (in reverse order to give precedence to the first
 	 rule) */
-      for (i = redp->num - 1; i >= 0; --i)
+      for (i = reds->num - 1; i >= 0; --i)
 	/* and find each token which the rule finds acceptable
 	   to come next */
-	BITSET_FOR_EACH (biter, redp->lookaheads[i], j, 0)
+	BITSET_FOR_EACH (biter, reds->lookaheads[i], j, 0)
 	{
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
 	  if (actrow[j] != 0)
 	    conflicted = conflrow[j] = 1;
-	  actrow[j] = rule_number_as_item_number (redp->rules[i]->number);
+	  actrow[j] = rule_number_as_item_number (reds->rules[i]->number);
 	}
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  FOR_EACH_SHIFT (transitions, i)
+  FOR_EACH_SHIFT (trans, i)
     {
-      symbol_number_t symbol = TRANSITION_SYMBOL (transitions, i);
-      state_t *shift_state = transitions->states[i];
+      symbol_number sym = TRANSITION_SYMBOL (trans, i);
+      state *shift_state = trans->states[i];
 
-      if (actrow[symbol] != 0)
-	conflicted = conflrow[symbol] = 1;
-      actrow[symbol] = state_number_as_int (shift_state->number);
+      if (actrow[sym] != 0)
+	conflicted = conflrow[sym] = 1;
+      actrow[sym] = state_number_as_int (shift_state->number);
 
       /* Do not use any default reduction if there is a shift for
 	 error */
-      if (symbol == errtoken->number)
+      if (sym == errtoken->number)
 	nodefault = 1;
     }
 
   /* See which tokens are an explicit error in this state (due to
-     %nonassoc).  For them, record ACTION_MIN as the action.  */
+     %nonassoc).  For them, record ACTION_NUMBER_MINIMUM as the
+     action.  */
   for (i = 0; i < errp->num; i++)
     {
-      symbol_t *symbol = errp->symbols[i];
-      actrow[symbol->number] = ACTION_MIN;
+      symbol *sym = errp->symbols[i];
+      actrow[sym->number] = ACTION_NUMBER_MINIMUM;
     }
 
   /* Now find the most common reduction and make it the default action
      for this state.  */
 
-  if (redp->num >= 1 && !nodefault)
+  if (reds->num >= 1 && !nodefault)
     {
-      if (state->consistent)
-	default_rule = redp->rules[0];
+      if (s->consistent)
+	default_rule = reds->rules[0];
       else
 	{
 	  int max = 0;
-	  for (i = 0; i < redp->num; i++)
+	  for (i = 0; i < reds->num; i++)
 	    {
 	      int count = 0;
-	      rule_t *rule = redp->rules[i];
-	      symbol_number_t j;
+	      rule *r = reds->rules[i];
+	      symbol_number j;
 
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == rule_number_as_item_number (rule->number))
+		if (actrow[j] == rule_number_as_item_number (r->number))
 		  count++;
 
 	      if (count > max)
 		{
 		  max = count;
-		  default_rule = rule;
+		  default_rule = r;
 		}
 	    }
 
@@ -335,31 +336,31 @@ action_row (state_t *state)
 
   if (!default_rule)
     for (i = 0; i < ntokens; i++)
-      if (actrow[i] == ACTION_MIN)
+      if (actrow[i] == ACTION_NUMBER_MINIMUM)
 	actrow[i] = 0;
 
   if (conflicted)
-    conflict_row (state);
+    conflict_row (s);
 
   return default_rule;
 }
 
 
-/*--------------------------------------------.
-| Set FROMS, TOS, TALLY and WIDTH for STATE.  |
-`--------------------------------------------*/
+/*----------------------------------------.
+| Set FROMS, TOS, TALLY and WIDTH for S.  |
+`----------------------------------------*/
 
 static void
-save_row (state_number_t state)
+save_row (state_number s)
 {
-  symbol_number_t i;
+  symbol_number i;
   int count;
-  base_t *sp = NULL;
-  base_t *sp1 = NULL;
-  base_t *sp2 = NULL;
+  base_number *sp = NULL;
+  base_number *sp1 = NULL;
+  base_number *sp2 = NULL;
   unsigned int *sp3 = NULL;
 
-  /* Number of non default actions in STATE.  */
+  /* Number of non default actions in S.  */
   count = 0;
   for (i = 0; i < ntokens; i++)
     if (actrow[i] != 0)
@@ -369,12 +370,12 @@ save_row (state_number_t state)
     return;
 
   /* Allocate non defaulted actions.  */
-  froms[state] = sp1 = sp = XCALLOC (base_t, count);
-  tos[state] = sp2 = XCALLOC (base_t, count);
+  froms[s] = sp1 = sp = XCALLOC (base_number, count);
+  tos[s] = sp2 = XCALLOC (base_number, count);
   if (glr_parser)
-    conflict_tos[state] = sp3 = XCALLOC (unsigned int, count);
+    conflict_tos[s] = sp3 = XCALLOC (unsigned int, count);
   else
-    conflict_tos[state] = NULL;
+    conflict_tos[s] = NULL;
 
   /* Store non defaulted actions.  */
   for (i = 0; i < ntokens; i++)
@@ -386,8 +387,8 @@ save_row (state_number_t state)
 	  *sp3++ = conflrow[i];
       }
 
-  tally[state] = count;
-  width[state] = sp1[-1] - sp[0] + 1;
+  tally[s] = count;
+  width[s] = sp1[-1] - sp[0] + 1;
 }
 
 
@@ -402,15 +403,15 @@ save_row (state_number_t state)
 static void
 token_actions (void)
 {
-  state_number_t i;
-  symbol_number_t j;
-  rule_number_t r;
+  state_number i;
+  symbol_number j;
+  rule_number r;
 
   int nconflict = glr_parser ? conflicts_total_count () : 0;
 
-  yydefact = XCALLOC (rule_number_t, nstates);
+  yydefact = XCALLOC (rule_number, nstates);
 
-  actrow = XCALLOC (action_t, ntokens);
+  actrow = XCALLOC (action_number, ntokens);
   conflrow = XCALLOC (unsigned int, ntokens);
 
   conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
@@ -424,7 +425,7 @@ token_actions (void)
 
   for (i = 0; i < nstates; ++i)
     {
-      rule_t *default_rule = action_row (states[i]);
+      rule *default_rule = action_row (states[i]);
       yydefact[i] = default_rule ? default_rule->number + 1 : 0;
       save_row (i);
 
@@ -434,7 +435,7 @@ token_actions (void)
       if (!glr_parser)
 	{
 	  for (j = 0; j < ntokens; ++j)
-	    if (actrow[j] < 0 && actrow[j] != ACTION_MIN)
+	    if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
 	      rules[item_number_as_rule_number (actrow[j])].useful = true;
 	  if (yydefact[i])
 	    rules[yydefact[i] - 1].useful = true;
@@ -449,24 +450,24 @@ token_actions (void)
 /*------------------------------------------------------------------.
 | Compute FROMS[VECTOR], TOS[VECTOR], TALLY[VECTOR], WIDTH[VECTOR], |
 | i.e., the information related to non defaulted GOTO on the nterm  |
-| SYMBOL.                                                           |
+| SYM.                                                              |
 |                                                                   |
-| DEFAULT_STATE is the principal destination on SYMBOL, i.e., the   |
-| default GOTO destination on SYMBOL.                               |
+| DEFAULT_STATE is the principal destination on SYM, i.e., the      |
+| default GOTO destination on SYM.                                  |
 `------------------------------------------------------------------*/
 
 static void
-save_column (symbol_number_t symbol, state_number_t default_state)
+save_column (symbol_number sym, state_number default_state)
 {
   int i;
-  base_t *sp;
-  base_t *sp1;
-  base_t *sp2;
+  base_number *sp;
+  base_number *sp1;
+  base_number *sp2;
   int count;
-  vector_number_t symno = symbol_number_to_vector_number (symbol);
+  vector_number symno = symbol_number_to_vector_number (sym);
 
-  goto_number_t begin = goto_map[symbol];
-  goto_number_t end = goto_map[symbol + 1];
+  goto_number begin = goto_map[sym];
+  goto_number end = goto_map[sym + 1];
 
   /* Number of non default GOTO.  */
   count = 0;
@@ -478,8 +479,8 @@ save_column (symbol_number_t symbol, state_number_t default_state)
     return;
 
   /* Allocate room for non defaulted gotos.  */
-  froms[symno] = sp1 = sp = XCALLOC (base_t, count);
-  tos[symno] = sp2 = XCALLOC (base_t, count);
+  froms[symno] = sp1 = sp = XCALLOC (base_number, count);
+  tos[symno] = sp2 = XCALLOC (base_number, count);
 
   /* Store the state numbers of the non defaulted gotos.  */
   for (i = begin; i < end; i++)
@@ -494,22 +495,22 @@ save_column (symbol_number_t symbol, state_number_t default_state)
 }
 
 
-/*----------------------------------------------------------------.
-| Return `the' most common destination GOTO on SYMBOL (a nterm).  |
-`----------------------------------------------------------------*/
+/*-------------------------------------------------------------.
+| Return `the' most common destination GOTO on SYM (a nterm).  |
+`-------------------------------------------------------------*/
 
-static state_number_t
-default_goto (symbol_number_t symbol, short state_count[])
+static state_number
+default_goto (symbol_number sym, short state_count[])
 {
-  state_number_t s;
+  state_number s;
   int i;
-  goto_number_t m = goto_map[symbol];
-  goto_number_t n = goto_map[symbol + 1];
-  state_number_t default_state = (state_number_t) -1;
+  goto_number m = goto_map[sym];
+  goto_number n = goto_map[sym + 1];
+  state_number default_state = (state_number) -1;
   int max = 0;
 
   if (m == n)
-    return (state_number_t) -1;
+    return (state_number) -1;
 
   for (s = 0; s < nstates; s++)
     state_count[s] = 0;
@@ -540,15 +541,15 @@ default_goto (symbol_number_t symbol, short state_count[])
 static void
 goto_actions (void)
 {
-  symbol_number_t i;
+  symbol_number i;
   short *state_count = XCALLOC (short, nstates);
-  yydefgoto = XMALLOC (state_number_t, nvars);
+  yydefgoto = XMALLOC (state_number, nvars);
 
   /* For a given nterm I, STATE_COUNT[S] is the number of times there
      is a GOTO to S on I.  */
   for (i = ntokens; i < nsyms; ++i)
     {
-      state_number_t default_state = default_goto (i, state_count);
+      state_number default_state = default_goto (i, state_count);
       save_column (i, default_state);
       yydefgoto[i - ntokens] = default_state;
     }
@@ -597,10 +598,10 @@ sort_actions (void)
 
    In any other case, return -1.  */
 
-static state_number_t
-matching_state (vector_number_t vector)
+static state_number
+matching_state (vector_number vector)
 {
-  vector_number_t i = order[vector];
+  vector_number i = order[vector];
   int t;
   int w;
   int prev;
@@ -623,7 +624,7 @@ matching_state (vector_number_t vector)
 
   for (prev = vector - 1; prev >= 0; prev--)
     {
-      vector_number_t j = order[prev];
+      vector_number j = order[prev];
       int k;
       int match = 1;
 
@@ -645,15 +646,15 @@ matching_state (vector_number_t vector)
 }
 
 
-static base_t
-pack_vector (vector_number_t vector)
+static base_number
+pack_vector (vector_number vector)
 {
-  vector_number_t i = order[vector];
+  vector_number i = order[vector];
   int j;
   int t = tally[i];
   int loc = 0;
-  base_t *from = froms[i];
-  base_t *to = tos[i];
+  base_number *from = froms[i];
+  base_number *to = tos[i];
   unsigned int *conflict_to = conflict_tos[i];
 
   if (! t)
@@ -698,7 +699,7 @@ pack_vector (vector_number_t vector)
 	  if (loc > high)
 	    high = loc;
 
-	  if (! (BASE_MIN <= j && j <= BASE_MAX))
+	  if (! (BASE_MINIMUM <= j && j <= BASE_MAXIMUM))
 	    abort ();
 	  return j;
 	}
@@ -714,10 +715,10 @@ pack_vector (vector_number_t vector)
 | parsers.                                                     |
 `-------------------------------------------------------------*/
 
-static base_t
-table_ninf_remap (base_t tab[], size_t size, base_t ninf)
+static base_number
+table_ninf_remap (base_number tab[], size_t size, base_number ninf)
 {
-  base_t res = 0;
+  base_number res = 0;
   size_t i;
 
   for (i = 0; i < size; i++)
@@ -738,40 +739,40 @@ pack_table (void)
 {
   int i;
 
-  base = XCALLOC (base_t, nvectors);
-  pos = XCALLOC (base_t, nentries);
-  table = XCALLOC (base_t, table_size);
+  base = XCALLOC (base_number, nvectors);
+  pos = XCALLOC (base_number, nentries);
+  table = XCALLOC (base_number, table_size);
   conflict_table = XCALLOC (unsigned int, table_size);
-  check = XCALLOC (base_t, table_size);
+  check = XCALLOC (base_number, table_size);
 
   lowzero = 0;
   high = 0;
 
   for (i = 0; i < nvectors; i++)
-    base[i] = BASE_MIN;
+    base[i] = BASE_MINIMUM;
 
   for (i = 0; i < (int) table_size; i++)
     check[i] = -1;
 
   for (i = 0; i < nentries; i++)
     {
-      state_number_t state = matching_state (i);
-      base_t place;
+      state_number s = matching_state (i);
+      base_number place;
 
-      if (state < 0)
+      if (s < 0)
 	/* A new set of state actions, or a nonterminal.  */
 	place = pack_vector (i);
       else
-	/* Action of I were already coded for STATE.  */
-	place = base[state];
+	/* Action of I were already coded for S.  */
+	place = base[s];
 
       pos[i] = place;
       base[order[i]] = place;
     }
 
   /* Use the greatest possible negative infinites.  */
-  base_ninf = table_ninf_remap (base, nvectors, BASE_MIN);
-  table_ninf = table_ninf_remap (table, high + 1, ACTION_MIN);
+  base_ninf = table_ninf_remap (base, nvectors, BASE_MINIMUM);
+  table_ninf = table_ninf_remap (table, high + 1, ACTION_NUMBER_MINIMUM);
 
   free (pos);
 }
@@ -797,11 +798,11 @@ tables_generate (void)
 
   nvectors = state_number_as_int (nstates) + nvars;
 
-  froms = XCALLOC (base_t *, nvectors);
-  tos = XCALLOC (base_t *, nvectors);
+  froms = XCALLOC (base_number *, nvectors);
+  tos = XCALLOC (base_number *, nvectors);
   conflict_tos = XCALLOC (unsigned int *, nvectors);
   tally = XCALLOC (short, nvectors);
-  width = XCALLOC (base_t, nvectors);
+  width = XCALLOC (base_number, nvectors);
 
   token_actions ();
 
@@ -810,7 +811,7 @@ tables_generate (void)
   free (from_state);
   free (to_state);
 
-  order = XCALLOC (vector_number_t, nvectors);
+  order = XCALLOC (vector_number, nvectors);
   sort_actions ();
   pack_table ();
   free (order);
