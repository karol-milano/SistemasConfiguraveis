@@ -25,31 +25,33 @@
    tokens they accept.  */
 
 #include "system.h"
-#include "bitset.h"
-#include "bitsetv.h"
-#include "relation.h"
-#include "quotearg.h"
-#include "symtab.h"
-#include "gram.h"
-#include "reader.h"
+
+#include <bitset.h>
+#include <bitsetv.h>
+#include <quotearg.h>
+
 #include "LR0.h"
 #include "complain.h"
-#include "lalr.h"
-#include "nullable.h"
 #include "derives.h"
 #include "getargs.h"
+#include "gram.h"
+#include "lalr.h"
+#include "nullable.h"
+#include "reader.h"
+#include "relation.h"
+#include "symtab.h"
 
-goto_number_t *goto_map = NULL;
-static goto_number_t ngotos = 0;
-state_number_t *from_state = NULL;
-state_number_t *to_state = NULL;
+goto_number *goto_map = NULL;
+static goto_number ngotos = 0;
+state_number *from_state = NULL;
+state_number *to_state = NULL;
 
 /* Linked list of goto numbers.  */
-typedef struct goto_list_s
+typedef struct goto_list
 {
-  struct goto_list_s *next;
-  goto_number_t value;
-} goto_list_t;
+  struct goto_list *next;
+  goto_number value;
+} goto_list;
 
 
 /* LA is a LR by NTOKENS matrix of bits.  LA[l, i] is 1 if the rule
@@ -65,8 +67,8 @@ size_t nLA;
    comment is hardly needed.  <grin>.  */
 static bitsetv F = NULL;
 
-static goto_number_t **includes;
-static goto_list_t **lookback;
+static goto_number **includes;
+static goto_list **lookback;
 
 
 
@@ -74,20 +76,20 @@ static goto_list_t **lookback;
 static void
 set_goto_map (void)
 {
-  state_number_t state;
-  goto_number_t *temp_map;
+  state_number s;
+  goto_number *temp_map;
 
-  goto_map = XCALLOC (goto_number_t, nvars + 1) - ntokens;
-  temp_map = XCALLOC (goto_number_t, nvars + 1) - ntokens;
+  goto_map = XCALLOC (goto_number, nvars + 1) - ntokens;
+  temp_map = XCALLOC (goto_number, nvars + 1) - ntokens;
 
   ngotos = 0;
-  for (state = 0; state < nstates; ++state)
+  for (s = 0; s < nstates; ++s)
     {
-      transitions_t *sp = states[state]->transitions;
+      transitions *sp = states[s]->transitions;
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  if (ngotos >= GOTO_NUMBER_MAX)
+	  if (ngotos >= GOTO_NUMBER_MAXIMUM)
 	    abort ();
 	  ngotos++;
 	  goto_map[TRANSITION_SYMBOL (sp, i)]++;
@@ -110,17 +112,17 @@ set_goto_map (void)
     temp_map[nsyms] = ngotos;
   }
 
-  from_state = XCALLOC (state_number_t, ngotos);
-  to_state = XCALLOC (state_number_t, ngotos);
+  from_state = XCALLOC (state_number, ngotos);
+  to_state = XCALLOC (state_number, ngotos);
 
-  for (state = 0; state < nstates; ++state)
+  for (s = 0; s < nstates; ++s)
     {
-      transitions_t *sp = states[state]->transitions;
+      transitions *sp = states[s]->transitions;
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
 	  int k = temp_map[TRANSITION_SYMBOL (sp, i)]++;
-	  from_state[k] = state;
+	  from_state[k] = s;
 	  to_state[k] = sp->states[i]->number;
 	}
     }
@@ -135,15 +137,15 @@ set_goto_map (void)
 `----------------------------------------------------------*/
 
 static int
-map_goto (state_number_t state, symbol_number_t symbol)
+map_goto (state_number s0, symbol_number sym)
 {
   int high;
   int low;
   int middle;
-  state_number_t s;
+  state_number s;
 
-  low = goto_map[symbol];
-  high = goto_map[symbol + 1] - 1;
+  low = goto_map[sym];
+  high = goto_map[sym + 1] - 1;
 
   for (;;)
     {
@@ -151,9 +153,9 @@ map_goto (state_number_t state, symbol_number_t symbol)
 	abort ();
       middle = (low + high) / 2;
       s = from_state[middle];
-      if (s == state)
+      if (s == s0)
 	return middle;
-      else if (s < state)
+      else if (s < s0)
 	low = middle + 1;
       else
 	high = middle - 1;
@@ -164,8 +166,8 @@ map_goto (state_number_t state, symbol_number_t symbol)
 static void
 initialize_F (void)
 {
-  goto_number_t **reads = XCALLOC (goto_number_t *, ngotos);
-  goto_number_t *edge = XCALLOC (goto_number_t, ngotos + 1);
+  goto_number **reads = XCALLOC (goto_number *, ngotos);
+  goto_number *edge = XCALLOC (goto_number, ngotos + 1);
   int nedges = 0;
 
   int i;
@@ -174,8 +176,8 @@ initialize_F (void)
 
   for (i = 0; i < ngotos; i++)
     {
-      state_number_t stateno = to_state[i];
-      transitions_t *sp = states[stateno]->transitions;
+      state_number stateno = to_state[i];
+      transitions *sp = states[stateno]->transitions;
 
       int j;
       FOR_EACH_SHIFT (sp, j)
@@ -183,14 +185,14 @@ initialize_F (void)
 
       for (; j < sp->num; j++)
 	{
-	  symbol_number_t symbol = TRANSITION_SYMBOL (sp, j);
-	  if (nullable[symbol])
-	    edge[nedges++] = map_goto (stateno, symbol);
+	  symbol_number sym = TRANSITION_SYMBOL (sp, j);
+	  if (nullable[sym])
+	    edge[nedges++] = map_goto (stateno, sym);
 	}
 
       if (nedges)
 	{
-	  reads[i] = XCALLOC (goto_number_t, nedges + 1);
+	  reads[i] = XCALLOC (goto_number, nedges + 1);
 	  memcpy (reads[i], edge, nedges * sizeof (edge[0]));
 	  reads[i][nedges] = -1;
 	  nedges = 0;
@@ -208,13 +210,13 @@ initialize_F (void)
 
 
 static void
-add_lookback_edge (state_t *state, rule_t *rule, int gotono)
+add_lookback_edge (state *s, rule *r, int gotono)
 {
-  int r = state_reduction_find (state, rule);
-  goto_list_t *sp = XCALLOC (goto_list_t, 1);
-  sp->next = lookback[(state->reductions->lookaheads - LA) + r];
+  int ri = state_reduction_find (s, r);
+  goto_list *sp = XCALLOC (goto_list, 1);
+  sp->next = lookback[(s->reductions->lookaheads - LA) + ri];
   sp->value = gotono;
-  lookback[(state->reductions->lookaheads - LA) + r] = sp;
+  lookback[(s->reductions->lookaheads - LA) + ri] = sp;
 }
 
 
@@ -222,35 +224,35 @@ add_lookback_edge (state_t *state, rule_t *rule, int gotono)
 static void
 build_relations (void)
 {
-  goto_number_t *edge = XCALLOC (goto_number_t, ngotos + 1);
-  state_number_t *states1 = XCALLOC (state_number_t, ritem_longest_rhs () + 1);
+  goto_number *edge = XCALLOC (goto_number, ngotos + 1);
+  state_number *states1 = XCALLOC (state_number, ritem_longest_rhs () + 1);
   int i;
 
-  includes = XCALLOC (goto_number_t *, ngotos);
+  includes = XCALLOC (goto_number *, ngotos);
 
   for (i = 0; i < ngotos; i++)
     {
       int nedges = 0;
-      symbol_number_t symbol1 = states[to_state[i]]->accessing_symbol;
-      rule_t **rulep;
+      symbol_number symbol1 = states[to_state[i]]->accessing_symbol;
+      rule **rulep;
 
       for (rulep = derives[symbol1]; *rulep; rulep++)
 	{
 	  int done;
 	  int length = 1;
-	  item_number_t *rp;
-	  state_t *state = states[from_state[i]];
-	  states1[0] = state->number;
+	  item_number *rp;
+	  state *s = states[from_state[i]];
+	  states1[0] = s->number;
 
 	  for (rp = (*rulep)->rhs; *rp >= 0; rp++)
 	    {
-	      state = transitions_to (state->transitions,
-				      item_number_as_symbol_number (*rp));
-	      states1[length++] = state->number;
+	      s = transitions_to (s->transitions,
+				  item_number_as_symbol_number (*rp));
+	      states1[length++] = s->number;
 	    }
 
-	  if (!state->consistent)
-	    add_lookback_edge (state, *rulep, i);
+	  if (!s->consistent)
+	    add_lookback_edge (s, *rulep, i);
 
 	  length--;
 	  done = 0;
@@ -261,7 +263,7 @@ build_relations (void)
 	      /* JF added rp>=ritem &&   I hope to god its right! */
 	      if (rp >= ritem && ISVAR (*rp))
 		{
-		  /* Downcasting from item_number_t to symbol_number_t. */
+		  /* Downcasting from item_number to symbol_number.  */
 		  edge[nedges++] = map_goto (states1[--length],
 					     item_number_as_symbol_number (*rp));
 		  if (nullable[*rp])
@@ -273,7 +275,7 @@ build_relations (void)
       if (nedges)
 	{
 	  int j;
-	  includes[i] = XCALLOC (goto_number_t, nedges + 1);
+	  includes[i] = XCALLOC (goto_number, nedges + 1);
 	  for (j = 0; j < nedges; j++)
 	    includes[i][j] = edge[j];
 	  includes[i][nedges] = -1;
@@ -306,7 +308,7 @@ static void
 compute_lookaheads (void)
 {
   size_t i;
-  goto_list_t *sp;
+  goto_list *sp;
 
   for (i = 0; i < nLA; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
@@ -314,25 +316,25 @@ compute_lookaheads (void)
 
   /* Free LOOKBACK. */
   for (i = 0; i < nLA; i++)
-    LIST_FREE (goto_list_t, lookback[i]);
+    LIST_FREE (goto_list, lookback[i]);
 
   XFREE (lookback);
   bitsetv_free (F);
 }
 
 
-/*---------------------------------------------------------------.
-| Count the number of lookaheads required for STATE (NLOOKAHEADS |
-| member).                                                       |
-`---------------------------------------------------------------*/
+/*-----------------------------------------------------------.
+| Count the number of lookaheads required for S (NLOOKAHEADS |
+| member).                                                   |
+`-----------------------------------------------------------*/
 
 static int
-state_lookaheads_count (state_t *state)
+state_lookaheads_count (state *s)
 {
   int k;
   int nlookaheads = 0;
-  reductions_t *rp = state->reductions;
-  transitions_t *sp = state->transitions;
+  reductions *rp = s->reductions;
+  transitions *sp = s->transitions;
 
   /* We need a lookahead either to distinguish different
      reductions (i.e., there are two or more), or to distinguish a
@@ -343,12 +345,12 @@ state_lookaheads_count (state_t *state)
 	  !TRANSITION_IS_DISABLED (sp, 0) && TRANSITION_IS_SHIFT (sp, 0)))
     nlookaheads += rp->num;
   else
-    state->consistent = 1;
+    s->consistent = 1;
 
   for (k = 0; k < sp->num; k++)
     if (!TRANSITION_IS_DISABLED (sp, k) && TRANSITION_IS_ERROR (sp, k))
       {
-	state->consistent = 0;
+	s->consistent = 0;
 	break;
       }
 
@@ -363,7 +365,7 @@ state_lookaheads_count (state_t *state)
 static void
 initialize_LA (void)
 {
-  state_number_t i;
+  state_number i;
   bitsetv pLA;
 
   /* Compute the total number of reductions requiring a lookahead.  */
@@ -375,7 +377,7 @@ initialize_LA (void)
     nLA = 1;
 
   pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
-  lookback = XCALLOC (goto_list_t *, nLA);
+  lookback = XCALLOC (goto_list *, nLA);
 
   /* Initialize the members LOOKAHEADS for each state which reductions
      require lookaheads.  */
@@ -398,12 +400,12 @@ initialize_LA (void)
 static void
 lookaheads_print (FILE *out)
 {
-  state_number_t i;
+  state_number i;
   int j, k;
   fprintf (out, "Lookaheads: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
-      reductions_t *reds = states[i]->reductions;
+      reductions *reds = states[i]->reductions;
       bitset_iterator iter;
       int nlookaheads = 0;
 
@@ -445,7 +447,7 @@ lalr (void)
 void
 lalr_free (void)
 {
-  state_number_t s;
+  state_number s;
   for (s = 0; s < nstates; ++s)
     states[s]->reductions->lookaheads = NULL;
   bitsetv_free (LA);
