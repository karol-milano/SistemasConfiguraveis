@@ -52,16 +52,6 @@ typedef struct goto_list_s
 } goto_list_t;
 
 
-/* LARULE is a vector which records the rules that need lookahead in
-   various states.  The elements of LARULE that apply to state S are
-   those from LOOKAHEADS[S] through LOOKAHEADS[S+1]-1.
-
-   If LR is the length of LArule, then a number from 0 to LR-1 can
-   specify both a rule and a state where the rule might be applied.
-   */
-
-static rule_t **LArule = NULL;
-
 /* LA is a LR by NTOKENS matrix of bits.  LA[l, i] is 1 if the rule
    LArule[l] is applicable in the appropriate state when the next
    token is symbol i.  If LA[l, i] and LA[l, j] are both 1 for i != j,
@@ -81,29 +71,6 @@ static goto_list_t **lookback;
 
 
 
-static void
-initialize_LA (void)
-{
-  state_number_t i;
-  int j;
-  rule_t **np;
-
-  /* Avoid having to special case 0.  */
-  if (!nLA)
-    nLA = 1;
-
-  LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
-  LArule = XCALLOC (rule_t *, nLA);
-  lookback = XCALLOC (goto_list_t *, nLA);
-
-  np = LArule;
-  for (i = 0; i < nstates; i++)
-    if (!states[i]->consistent)
-      for (j = 0; j < states[i]->reductions->num; j++)
-	*np++ = states[i]->reductions->rules[j];
-}
-
-
 static void
 set_goto_map (void)
 {
@@ -246,19 +213,11 @@ initialize_F (void)
 static void
 add_lookback_edge (state_t *state, rule_t *rule, int gotono)
 {
-  int i;
-  goto_list_t *sp;
-
-  for (i = 0; i < state->nlookaheads; ++i)
-    if (state->lookaheads_rule[i] == rule)
-      break;
-
-  assert (state->lookaheads_rule[i] == rule);
-
-  sp = XCALLOC (goto_list_t, 1);
-  sp->next = lookback[(state->lookaheads - LA) + i];
+  int r = state_reduction_find (state, rule);
+  goto_list_t *sp = XCALLOC (goto_list_t, 1);
+  sp->next = lookback[(state->reductions->lookaheads - LA) + r];
   sp->value = gotono;
-  lookback[(state->lookaheads - LA) + i] = sp;
+  lookback[(state->reductions->lookaheads - LA) + r] = sp;
 }
 
 
@@ -365,68 +324,72 @@ compute_lookaheads (void)
 }
 
 
-/*-------------------------------------------------------------.
-| Count the number of lookaheads required for each state       |
-| (NLOOKAHEADS member).  Compute the total number of LA, NLA.  |
-`-------------------------------------------------------------*/
+/*---------------------------------------------------------------.
+| Count the number of lookaheads required for STATE (NLOOKAHEADS |
+| member).                                                       |
+`---------------------------------------------------------------*/
 
-static void
-states_lookaheads_count (void)
+static int
+state_lookaheads_count (state_t *state)
 {
-  state_number_t i;
-  nLA = 0;
-
-  /* Count   */
-  for (i = 0; i < nstates; i++)
-    {
-      int k;
-      int nlookaheads = 0;
-      reductions_t *rp = states[i]->reductions;
-      transitions_t *sp = states[i]->transitions;
-
-      /* We need a lookahead either to distinguish different
-	 reductions (i.e., there are two or more), or to distinguish a
-	 reduction from a shift.  Otherwise, it is straightforward,
-	 and the state is `consistent'.  */
-      if (rp->num > 1
-	  || (rp->num == 1 && sp->num &&
-	      !TRANSITION_IS_DISABLED (sp, 0) && TRANSITION_IS_SHIFT (sp, 0)))
-	nlookaheads += rp->num;
-      else
-	states[i]->consistent = 1;
-
-      for (k = 0; k < sp->num; k++)
-	if (!TRANSITION_IS_DISABLED (sp, k) && TRANSITION_IS_ERROR (sp, k))
-	  {
-	    states[i]->consistent = 0;
-	    break;
-	  }
+  int k;
+  int nlookaheads = 0;
+  reductions_t *rp = state->reductions;
+  transitions_t *sp = state->transitions;
+
+  /* We need a lookahead either to distinguish different
+     reductions (i.e., there are two or more), or to distinguish a
+     reduction from a shift.  Otherwise, it is straightforward,
+     and the state is `consistent'.  */
+  if (rp->num > 1
+      || (rp->num == 1 && sp->num &&
+	  !TRANSITION_IS_DISABLED (sp, 0) && TRANSITION_IS_SHIFT (sp, 0)))
+    nlookaheads += rp->num;
+  else
+    state->consistent = 1;
+
+  for (k = 0; k < sp->num; k++)
+    if (!TRANSITION_IS_DISABLED (sp, k) && TRANSITION_IS_ERROR (sp, k))
+      {
+	state->consistent = 0;
+	break;
+      }
 
-      states[i]->nlookaheads = nlookaheads;
-      nLA += nlookaheads;
-    }
+  return nlookaheads;
 }
 
 
-/*--------------------------------------.
-| Initializing the lookaheads members.  |
-`--------------------------------------*/
+/*----------------------------------------------.
+| Compute LA, NLA, and the lookaheads members.  |
+`----------------------------------------------*/
 
 static void
-states_lookaheads_initialize (void)
+initialize_LA (void)
 {
   state_number_t i;
-  bitsetv pLA = LA;
-  rule_t **pLArule = LArule;
+  bitsetv pLA;
 
-  /* Initialize the members LOOKAHEADS and LOOKAHEADS_RULE for each
-     state.  */
+  /* Compute the total number of reductions requiring a lookahead.  */
+  nLA = 0;
+  for (i = 0; i < nstates; i++)
+    nLA += state_lookaheads_count (states[i]);
+  /* Avoid having to special case 0.  */
+  if (!nLA)
+    nLA = 1;
+
+  pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
+  lookback = XCALLOC (goto_list_t *, nLA);
+
+  /* Initialize the members LOOKAHEADS for each state which reductions
+     require lookaheads.  */
   for (i = 0; i < nstates; i++)
     {
-      states[i]->lookaheads = pLA;
-      states[i]->lookaheads_rule = pLArule;
-      pLA += states[i]->nlookaheads;
-      pLArule += states[i]->nlookaheads;
+      int count = state_lookaheads_count (states[i]);
+      if (count)
+	{
+	  states[i]->reductions->lookaheads = pLA;
+	  pLA += count;
+	}
     }
 }
 
@@ -443,18 +406,26 @@ lookaheads_print (FILE *out)
   fprintf (out, "Lookaheads: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
+      reductions_t *reds = states[i]->reductions;
       bitset_iterator iter;
+      int nlookaheads = 0;
+
+      if (reds->lookaheads)
+	for (k = 0; k < reds->num; ++k)
+	  if (reds->lookaheads[k])
+	    ++nlookaheads;
 
       fprintf (out, "State %d: %d lookaheads\n",
-	       i, states[i]->nlookaheads);
+	       i, nlookaheads);
 
-      for (j = 0; j < states[i]->nlookaheads; ++j)
-	BITSET_FOR_EACH (iter, states[i]->lookaheads[j], k, 0)
-	{
-	  fprintf (out, "   on %d (%s) -> rule %d\n",
-		   k, symbols[k]->tag,
-		   states[i]->lookaheads_rule[j]->number);
-	};
+      if (reds->lookaheads)
+	for (j = 0; j < reds->num; ++j)
+	  BITSET_FOR_EACH (iter, reds->lookaheads[j], k, 0)
+	  {
+	    fprintf (out, "   on %d (%s) -> rule %d\n",
+		     k, symbols[k]->tag,
+		     reds->rules[j]->number);
+	  };
     }
   fprintf (out, "Lookaheads: END\n");
 }
@@ -462,9 +433,7 @@ lookaheads_print (FILE *out)
 void
 lalr (void)
 {
-  states_lookaheads_count ();
   initialize_LA ();
-  states_lookaheads_initialize ();
   set_goto_map ();
   initialize_F ();
   build_relations ();
@@ -481,10 +450,6 @@ lalr_free (void)
 {
   state_number_t s;
   for (s = 0; s < nstates; ++s)
-    {
-      states[s]->lookaheads = NULL;
-      states[s]->lookaheads_rule = NULL;
-    }
+    states[s]->reductions->lookaheads = NULL;
   bitsetv_free (LA);
-  free (LArule);
 }
