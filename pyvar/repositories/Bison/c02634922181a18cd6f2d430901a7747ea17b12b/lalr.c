@@ -298,15 +298,15 @@ add_lookback_edge (state_t *state, int ruleno, int gotono)
   shorts *sp;
 
   for (i = 0; i < state->nlookaheads; ++i)
-    if (LArule[state->lookaheadsp + i]->number == ruleno)
+    if (state->lookaheads_rule[i]->number == ruleno)
       break;
 
-  assert (LArule[state->lookaheadsp + i]->number == ruleno);
+  assert (state->lookaheads_rule[i]->number == ruleno);
 
   sp = XCALLOC (shorts, 1);
-  sp->next = lookback[state->lookaheadsp + i];
+  sp->next = lookback[(state->lookaheads - LA) + i];
   sp->value = gotono;
-  lookback[state->lookaheadsp + i] = sp;
+  lookback[(state->lookaheads - LA) + i] = sp;
 }
 
 
@@ -506,15 +506,18 @@ compute_lookaheads (void)
 }
 
 
-/*--------------------------------------.
-| Initializing the lookaheads members.  |
-`--------------------------------------*/
+/*-------------------------------------------------------------.
+| Count the number of lookaheads required for each state       |
+| (NLOOKAHEADS member).  Compute the total number of LA, NLA.  |
+`-------------------------------------------------------------*/
 
 static void
-initialize_lookaheads (void)
+states_lookaheads_count (void)
 {
   size_t i;
   nLA = 0;
+
+  /* Count   */
   for (i = 0; i < nstates; i++)
     {
       int k;
@@ -540,12 +543,34 @@ initialize_lookaheads (void)
 	  }
 
       states[i]->nlookaheads = nlookaheads;
-      states[i]->lookaheadsp = nLA;
       nLA += nlookaheads;
     }
 }
 
 
+/*--------------------------------------.
+| Initializing the lookaheads members.  |
+`--------------------------------------*/
+
+static void
+states_lookaheads_initialize (void)
+{
+  size_t i;
+  bitsetv pLA = LA;
+  rule_t **pLArule = LArule;
+
+  /* Count the number of lookaheads required for each state
+     (NLOOKAHEADS member).  */
+  for (i = 0; i < nstates; i++)
+    {
+      states[i]->lookaheads = pLA;
+      states[i]->lookaheads_rule = pLArule;
+      pLA += states[i]->nlookaheads;
+      pLArule += states[i]->nlookaheads;
+    }
+}
+
+
 /*---------------------------------------.
 | Output the lookaheads for each state.  |
 `---------------------------------------*/
@@ -563,10 +588,10 @@ lookaheads_print (FILE *out)
 
       for (j = 0; j < states[i]->nlookaheads; ++j)
 	for (k = 0; k < ntokens; ++k)
-	  if (bitset_test (LA[states[i]->lookaheadsp + j], k))
+	  if (bitset_test (states[i]->lookaheads[j], k))
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
 		     k, symbol_tag_get (symbols[k]),
-		     LArule[states[i]->lookaheadsp + j]->number - 1);
+		     states[i]->lookaheads_rule[j]->number - 1);
     }
   fprintf (out, "Lookaheads: END\n");
 }
@@ -574,8 +599,9 @@ lookaheads_print (FILE *out)
 void
 lalr (void)
 {
-  initialize_lookaheads ();
+  states_lookaheads_count ();
   initialize_LA ();
+  states_lookaheads_initialize ();
   set_goto_map ();
   initialize_F ();
   build_relations ();
