@@ -365,14 +365,14 @@ prepare_rules (void)
   rule_number_t r;
   unsigned int i = 0;
   item_number_t *rhs = XMALLOC (item_number_t, nritems);
-  unsigned int *prhs = XMALLOC (unsigned int, nrules + 1);
-  unsigned int *rline = XMALLOC (unsigned int, nrules + 1);
-  symbol_number_t *r1 = XMALLOC (symbol_number_t, nrules + 1);
-  unsigned int *r2 = XMALLOC (unsigned int, nrules + 1);
-  short *dprec = XMALLOC (short, nrules + 1);
-  short *merger = XMALLOC (short, nrules + 1);
-
-  for (r = 1; r < nrules + 1; ++r)
+  unsigned int *prhs = XMALLOC (unsigned int, nrules);
+  unsigned int *rline = XMALLOC (unsigned int, nrules);
+  symbol_number_t *r1 = XMALLOC (symbol_number_t, nrules);
+  unsigned int *r2 = XMALLOC (unsigned int, nrules);
+  short *dprec = XMALLOC (short, nrules);
+  short *merger = XMALLOC (short, nrules);
+
+  for (r = 0; r < nrules; ++r)
     {
       item_number_t *rhsp = NULL;
       /* Index of rule R in RHS. */
@@ -396,12 +396,12 @@ prepare_rules (void)
   assert (i == nritems);
 
   muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
-  muscle_insert_unsigned_int_table ("prhs", prhs, 0, 1, nrules + 1);
-  muscle_insert_unsigned_int_table ("rline", rline, 0, 1, nrules + 1);
-  muscle_insert_symbol_number_table ("r1", r1, 0, 1, nrules + 1);
-  muscle_insert_unsigned_int_table ("r2", r2, 0, 1, nrules + 1);
-  muscle_insert_short_table ("dprec", dprec, 0, 1, nrules + 1);
-  muscle_insert_short_table ("merger", merger, 0, 1, nrules + 1);
+  muscle_insert_unsigned_int_table ("prhs", prhs, 0, 0, nrules);
+  muscle_insert_unsigned_int_table ("rline", rline, 0, 0, nrules);
+  muscle_insert_symbol_number_table ("r1", r1, 0, 0, nrules);
+  muscle_insert_unsigned_int_table ("r2", r2, 0, 0, nrules);
+  muscle_insert_short_table ("dprec", dprec, 0, 0, nrules);
+  muscle_insert_short_table ("merger", merger, 0, 0, nrules);
 
   free (rhs);
   free (prhs);
@@ -434,8 +434,8 @@ prepare_states (void)
 | by non-zero entries in CONFLROW, create a list of possible 	     |
 | reductions that are alternatives to the shift or reduction	     |
 | currently recorded for that token in STATE.  Store the alternative |
-| reductions followed by a 0 in conflict_list, updating		     |
-| conflict_list_cnt, and storing an index to the start of the list   |
+| reductions followed by a 0 in CONFLICT_LIST, updating		     |
+| CONFLICT_LIST_CNT, and storing an index to the start of the list   |
 | back into CONFLROW.						     |
 `-------------------------------------------------------------------*/
 
@@ -461,7 +461,7 @@ conflict_row (state_t *state)
 	    {
 	      assert (conflict_list_free > 0);
 	      conflict_list[conflict_list_cnt]
-		= state->lookaheads_rule[i]->number;
+		= state->lookaheads_rule[i]->number + 1;
 	      conflict_list_cnt += 1;
 	      conflict_list_free -= 1;
 	    }
@@ -488,7 +488,7 @@ conflict_row (state_t *state)
 | considered that likes a token gets to handle it.                  |
 |                                                                   |
 | For GLR parsers, also sets CONFLROW[SYM] to an index into         |
-| conflict_list iff there is an unresolved conflict (s/r or r/r)    |
+| CONFLICT_LIST iff there is an unresolved conflict (s/r or r/r)    |
 | with symbol SYM. The default reduction is not used for a symbol   |
 | that has any such conflicts.                                      |
 `------------------------------------------------------------------*/
@@ -497,7 +497,7 @@ static rule_number_t
 action_row (state_t *state)
 {
   int i;
-  rule_number_t default_rule = 0;
+  rule_number_t default_rule = -1;
   reductions_t *redp = state->reductions;
   transitions_t *transitions = state->transitions;
   errs_t *errp = state->errs;
@@ -601,7 +601,7 @@ action_row (state_t *state)
   /* If have no default rule, the default is an error.
      So replace any action which says "error" with "use default".  */
 
-  if (default_rule == 0)
+  if (default_rule == -1)
     for (i = 0; i < ntokens; i++)
       if (actrow[i] == ACTION_MIN)
 	actrow[i] = 0;
@@ -689,7 +689,7 @@ token_actions (void)
 
   for (i = 0; i < nstates; ++i)
     {
-      yydefact[i] = action_row (states[i]);
+      yydefact[i] = action_row (states[i]) + 1;
       save_row (i);
     }
 
@@ -711,10 +711,10 @@ actions_output (FILE *out)
   rule_number_t r;
 
   fputs ("m4_define([b4_actions], \n[[", out);
-  for (r = 1; r < nrules + 1; ++r)
+  for (r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
-	fprintf (out, "  case %d:\n", r);
+	fprintf (out, "  case %d:\n", r + 1);
 
 	if (!no_lines_flag)
 	  fprintf (out, muscle_find ("linef"),
