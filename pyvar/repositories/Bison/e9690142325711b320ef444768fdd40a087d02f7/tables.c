@@ -152,11 +152,11 @@ table_grow (int desired)
 
   if (trace_flag & trace_resource)
     fprintf (stderr, "growing table and check from: %d to %d\n",
-	     old_size, table_size);
+             old_size, table_size);
 
   table = xnrealloc (table, table_size, sizeof *table);
   conflict_table = xnrealloc (conflict_table, table_size,
-			      sizeof *conflict_table);
+                              sizeof *conflict_table);
   check = xnrealloc (check, table_size, sizeof *check);
 
   for (/* Nothing. */; old_size < table_size; ++old_size)
@@ -172,12 +172,12 @@ table_grow (int desired)
 
 /*-------------------------------------------------------------------.
 | For GLR parsers, for each conflicted token in S, as indicated      |
-| by non-zero entries in CONFLROW, create a list of possible	     |
-| reductions that are alternatives to the shift or reduction	     |
+| by non-zero entries in CONFLROW, create a list of possible         |
+| reductions that are alternatives to the shift or reduction         |
 | currently recorded for that token in S.  Store the alternative     |
-| reductions followed by a 0 in CONFLICT_LIST, updating		     |
+| reductions followed by a 0 in CONFLICT_LIST, updating              |
 | CONFLICT_LIST_CNT, and storing an index to the start of the list   |
-| back into CONFLROW.						     |
+| back into CONFLROW.                                                |
 `-------------------------------------------------------------------*/
 
 static void
@@ -192,26 +192,26 @@ conflict_row (state *s)
   for (j = 0; j < ntokens; j += 1)
     if (conflrow[j])
       {
-	conflrow[j] = conflict_list_cnt;
-
-	/* Find all reductions for token J, and record all that do not
-	   match ACTROW[J].  */
-	for (i = 0; i < reds->num; i += 1)
-	  if (bitset_test (reds->lookahead_tokens[i], j)
-	      && (actrow[j]
-		  != rule_number_as_item_number (reds->rules[i]->number)))
-	    {
-	      aver (0 < conflict_list_free);
-	      conflict_list[conflict_list_cnt] = reds->rules[i]->number + 1;
-	      conflict_list_cnt += 1;
-	      conflict_list_free -= 1;
-	    }
-
-	/* Leave a 0 at the end.  */
-	aver (0 < conflict_list_free);
-	conflict_list[conflict_list_cnt] = 0;
-	conflict_list_cnt += 1;
-	conflict_list_free -= 1;
+        conflrow[j] = conflict_list_cnt;
+
+        /* Find all reductions for token J, and record all that do not
+           match ACTROW[J].  */
+        for (i = 0; i < reds->num; i += 1)
+          if (bitset_test (reds->lookahead_tokens[i], j)
+              && (actrow[j]
+                  != rule_number_as_item_number (reds->rules[i]->number)))
+            {
+              aver (0 < conflict_list_free);
+              conflict_list[conflict_list_cnt] = reds->rules[i]->number + 1;
+              conflict_list_cnt += 1;
+              conflict_list_free -= 1;
+            }
+
+        /* Leave a 0 at the end.  */
+        aver (0 < conflict_list_free);
+        conflict_list[conflict_list_cnt] = 0;
+        conflict_list_cnt += 1;
+        conflict_list_free -= 1;
       }
 }
 
@@ -222,9 +222,9 @@ conflict_row (state *s)
 | default action (yydefact) for the state.  In addition, ACTROW is  |
 | filled with what to do for each kind of token, index by symbol    |
 | number, with zero meaning do the default action.  The value       |
-| ACTION_NUMBER_MINIMUM, a very negative number, means this	    |
-| situation is an error.  The parser recognizes this value	    |
-| specially.							    |
+| ACTION_NUMBER_MINIMUM, a very negative number, means this         |
+| situation is an error.  The parser recognizes this value          |
+| specially.                                                        |
 |                                                                   |
 | This is where conflicts are resolved.  The loop over lookahead    |
 | rules considered lower-numbered rules last, and the last rule     |
@@ -256,22 +256,22 @@ action_row (state *s)
       int j;
       bitset_iterator biter;
       /* loop over all the rules available here which require
-	 lookahead (in reverse order to give precedence to the first
-	 rule) */
+         lookahead (in reverse order to give precedence to the first
+         rule) */
       for (i = reds->num - 1; i >= 0; --i)
-	/* and find each token which the rule finds acceptable
-	   to come next */
-	BITSET_FOR_EACH (biter, reds->lookahead_tokens[i], j, 0)
-	{
-	  /* and record this rule as the rule to use if that
-	     token follows.  */
-	  if (actrow[j] != 0)
-	    {
-	      conflicted = true;
-	      conflrow[j] = 1;
-	    }
-	  actrow[j] = rule_number_as_item_number (reds->rules[i]->number);
-	}
+        /* and find each token which the rule finds acceptable
+           to come next */
+        BITSET_FOR_EACH (biter, reds->lookahead_tokens[i], j, 0)
+        {
+          /* and record this rule as the rule to use if that
+             token follows.  */
+          if (actrow[j] != 0)
+            {
+              conflicted = true;
+              conflrow[j] = 1;
+            }
+          actrow[j] = rule_number_as_item_number (reds->rules[i]->number);
+        }
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
@@ -283,16 +283,16 @@ action_row (state *s)
       state *shift_state = trans->states[i];
 
       if (actrow[sym] != 0)
-	{
-	  conflicted = true;
-	  conflrow[sym] = 1;
-	}
+        {
+          conflicted = true;
+          conflrow[sym] = 1;
+        }
       actrow[sym] = state_number_as_int (shift_state->number);
 
       /* Do not use any default reduction if there is a shift for
-	 error */
+         error */
       if (sym == errtoken->number)
-	nodefault = true;
+        nodefault = true;
     }
 
   /* See which tokens are an explicit error in this state (due to
@@ -321,43 +321,43 @@ action_row (state *s)
   if (reds->num >= 1 && !nodefault)
     {
       if (s->consistent)
-	default_reduction = reds->rules[0];
+        default_reduction = reds->rules[0];
       else
-	{
-	  int max = 0;
-	  for (i = 0; i < reds->num; i++)
-	    {
-	      int count = 0;
-	      rule *r = reds->rules[i];
-	      symbol_number j;
-
-	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == rule_number_as_item_number (r->number))
-		  count++;
-
-	      if (count > max)
-		{
-		  max = count;
-		  default_reduction = r;
-		}
-	    }
-
-	  /* GLR parsers need space for conflict lists, so we can't
-	     default conflicted entries.  For non-conflicted entries
-	     or as long as we are not building a GLR parser,
-	     actions that match the default are replaced with zero,
-	     which means "use the default". */
-
-	  if (max > 0)
-	    {
-	      int j;
-	      for (j = 0; j < ntokens; j++)
-		if (actrow[j]
+        {
+          int max = 0;
+          for (i = 0; i < reds->num; i++)
+            {
+              int count = 0;
+              rule *r = reds->rules[i];
+              symbol_number j;
+
+              for (j = 0; j < ntokens; j++)
+                if (actrow[j] == rule_number_as_item_number (r->number))
+                  count++;
+
+              if (count > max)
+                {
+                  max = count;
+                  default_reduction = r;
+                }
+            }
+
+          /* GLR parsers need space for conflict lists, so we can't
+             default conflicted entries.  For non-conflicted entries
+             or as long as we are not building a GLR parser,
+             actions that match the default are replaced with zero,
+             which means "use the default". */
+
+          if (max > 0)
+            {
+              int j;
+              for (j = 0; j < ntokens; j++)
+                if (actrow[j]
                     == rule_number_as_item_number (default_reduction->number)
-		    && ! (nondeterministic_parser && conflrow[j]))
-		  actrow[j] = 0;
-	    }
-	}
+                    && ! (nondeterministic_parser && conflrow[j]))
+                  actrow[j] = 0;
+            }
+        }
     }
 
   /* If have no default reduction, the default is an error.
@@ -366,7 +366,7 @@ action_row (state *s)
   if (!default_reduction)
     for (i = 0; i < ntokens; i++)
       if (actrow[i] == ACTION_NUMBER_MINIMUM)
-	actrow[i] = 0;
+        actrow[i] = 0;
 
   if (conflicted)
     conflict_row (s);
@@ -408,10 +408,10 @@ save_row (state_number s)
   for (i = 0; i < ntokens; i++)
     if (actrow[i] != 0)
       {
-	*sp1++ = i;
-	*sp2++ = actrow[i];
-	if (nondeterministic_parser)
-	  *sp3++ = conflrow[i];
+        *sp1++ = i;
+        *sp2++ = actrow[i];
+        if (nondeterministic_parser)
+          *sp3++ = conflrow[i];
       }
 
   tally[s] = count;
@@ -457,16 +457,16 @@ token_actions (void)
       save_row (i);
 
       /* Now that the parser was computed, we can find which rules are
-	 really reduced, and which are not because of SR or RR
-	 conflicts.  */
+         really reduced, and which are not because of SR or RR
+         conflicts.  */
       if (!nondeterministic_parser)
-	{
-	  for (j = 0; j < ntokens; ++j)
-	    if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
-	      rules[item_number_as_rule_number (actrow[j])].useful = true;
-	  if (yydefact[i])
-	    rules[yydefact[i] - 1].useful = true;
-	}
+        {
+          for (j = 0; j < ntokens; ++j)
+            if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
+              rules[item_number_as_rule_number (actrow[j])].useful = true;
+          if (yydefact[i])
+            rules[yydefact[i] - 1].useful = true;
+        }
     }
 
   free (actrow);
@@ -513,8 +513,8 @@ save_column (symbol_number sym, state_number default_state)
   for (i = begin; i < end; i++)
     if (to_state[i] != default_state)
       {
-	*sp1++ = from_state[i];
-	*sp2++ = to_state[i];
+        *sp1++ = from_state[i];
+        *sp2++ = to_state[i];
       }
 
   tally[symno] = count;
@@ -548,8 +548,8 @@ default_goto (symbol_number sym, size_t state_count[])
   for (s = 0; s < nstates; s++)
     if (state_count[s] > max)
       {
-	max = state_count[s];
-	default_state = s;
+        max = state_count[s];
+        default_state = s;
       }
 
   return default_state;
@@ -599,22 +599,22 @@ sort_actions (void)
   for (i = 0; i < nvectors; i++)
     if (tally[i] > 0)
       {
-	int k;
-	int t = tally[i];
-	int w = width[i];
-	int j = nentries - 1;
+        int k;
+        int t = tally[i];
+        int w = width[i];
+        int j = nentries - 1;
 
-	while (j >= 0 && (width[order[j]] < w))
-	  j--;
+        while (j >= 0 && (width[order[j]] < w))
+          j--;
 
-	while (j >= 0 && (width[order[j]] == w) && (tally[order[j]] < t))
-	  j--;
+        while (j >= 0 && (width[order[j]] == w) && (tally[order[j]] < t))
+          j--;
 
-	for (k = nentries - 1; k > j; k--)
-	  order[k + 1] = order[k];
+        for (k = nentries - 1; k > j; k--)
+          order[k + 1] = order[k];
 
-	order[j + 1] = i;
-	nentries++;
+        order[j + 1] = i;
+        nentries++;
       }
 }
 
@@ -645,8 +645,8 @@ matching_state (vector_number vector)
     {
       int j;
       for (j = 0; j < t; j += 1)
-	if (conflict_tos[i][j] != 0)
-	  return -1;
+        if (conflict_tos[i][j] != 0)
+          return -1;
     }
 
   for (prev = vector - 1; prev >= 0; prev--)
@@ -656,17 +656,17 @@ matching_state (vector_number vector)
       int match = 1;
 
       /* Given how ORDER was computed, if the WIDTH or TALLY is
-	 different, there cannot be a matching state.  */
+         different, there cannot be a matching state.  */
       if (width[j] != w || tally[j] != t)
-	return -1;
+        return -1;
 
       for (k = 0; match && k < t; k++)
-	if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k]
-	    || (conflict_tos[j] != NULL && conflict_tos[j][k] != 0))
-	  match = 0;
+        if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k]
+            || (conflict_tos[j] != NULL && conflict_tos[j][k] != 0))
+          match = 0;
 
       if (match)
-	return j;
+        return j;
     }
 
   return -1;
@@ -694,39 +694,39 @@ pack_vector (vector_number vector)
       aver (j < table_size);
 
       for (k = 0; ok && k < t; k++)
-	{
-	  loc = j + state_number_as_int (from[k]);
-	  if (table_size <= loc)
-	    table_grow (loc);
+        {
+          loc = j + state_number_as_int (from[k]);
+          if (table_size <= loc)
+            table_grow (loc);
 
-	  if (table[loc] != 0)
-	    ok = false;
-	}
+          if (table[loc] != 0)
+            ok = false;
+        }
 
       for (k = 0; ok && k < vector; k++)
-	if (pos[k] == j)
-	  ok = false;
+        if (pos[k] == j)
+          ok = false;
 
       if (ok)
-	{
-	  for (k = 0; k < t; k++)
-	    {
-	      loc = j + from[k];
-	      table[loc] = to[k];
-	      if (nondeterministic_parser && conflict_to != NULL)
-		conflict_table[loc] = conflict_to[k];
-	      check[loc] = from[k];
-	    }
-
-	  while (table[lowzero] != 0)
-	    lowzero++;
-
-	  if (loc > high)
-	    high = loc;
-
-	  aver (BASE_MINIMUM <= j && j <= BASE_MAXIMUM);
-	  return j;
-	}
+        {
+          for (k = 0; k < t; k++)
+            {
+              loc = j + from[k];
+              table[loc] = to[k];
+              if (nondeterministic_parser && conflict_to != NULL)
+                conflict_table[loc] = conflict_to[k];
+              check[loc] = from[k];
+            }
+
+          while (table[lowzero] != 0)
+            lowzero++;
+
+          if (loc > high)
+            high = loc;
+
+          aver (BASE_MINIMUM <= j && j <= BASE_MAXIMUM);
+          return j;
+        }
     }
 }
 
@@ -784,11 +784,11 @@ pack_table (void)
       base_number place;
 
       if (s < 0)
-	/* A new set of state actions, or a nonterminal.  */
-	place = pack_vector (i);
+        /* A new set of state actions, or a nonterminal.  */
+        place = pack_vector (i);
       else
-	/* Action of I were already coded for S.  */
-	place = base[s];
+        /* Action of I were already coded for S.  */
+        place = base[s];
 
       pos[i] = place;
       base[order[i]] = place;
@@ -817,7 +817,7 @@ tables_generate (void)
      correlated.  In particular the signedness is not taken into
      account.  But it's not useless.  */
   verify (sizeof nstates <= sizeof nvectors
-	  && sizeof nvars <= sizeof nvectors);
+          && sizeof nvars <= sizeof nvectors);
 
   nvectors = state_number_as_int (nstates) + nvars;
 
