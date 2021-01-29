@@ -182,20 +182,18 @@ table_grow (int desired)
 static void
 conflict_row (state *s)
 {
-  int i, j;
-  reductions *reds = s->reductions;
-
   if (!nondeterministic_parser)
     return;
 
-  for (j = 0; j < ntokens; j += 1)
+  const reductions *reds = s->reductions;
+  for (state_number j = 0; j < ntokens; j += 1)
     if (conflrow[j])
       {
         conflrow[j] = conflict_list_cnt;
 
         /* Find all reductions for token J, and record all that do not
            match ACTROW[J].  */
-        for (i = 0; i < reds->num; i += 1)
+        for (int i = 0; i < reds->num; i += 1)
           if (bitset_test (reds->lookahead_tokens[i], j)
               && (actrow[j]
                   != rule_number_as_item_number (reds->rules[i]->number)))
@@ -238,7 +236,6 @@ conflict_row (state *s)
 static rule *
 action_row (state *s)
 {
-  int i;
   rule *default_reduction = NULL;
   reductions *reds = s->reductions;
   transitions *trans = s->transitions;
@@ -247,57 +244,60 @@ action_row (state *s)
   bool nodefault = false;
   bool conflicted = false;
 
-  for (i = 0; i < ntokens; i++)
+  for (state_number i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
 
   if (reds->lookahead_tokens)
-    {
-      int j;
-      bitset_iterator biter;
-      /* loop over all the rules available here which require
-         lookahead (in reverse order to give precedence to the first
-         rule) */
-      for (i = reds->num - 1; i >= 0; --i)
-        /* and find each token which the rule finds acceptable
-           to come next */
+    /* loop over all the rules available here which require
+       lookahead (in reverse order to give precedence to the first
+       rule) */
+    for (int i = reds->num - 1; i >= 0; --i)
+      /* and find each token which the rule finds acceptable
+         to come next */
+      {
+        bitset_iterator biter;
+        int j;
         BITSET_FOR_EACH (biter, reds->lookahead_tokens[i], j, 0)
-        {
-          /* and record this rule as the rule to use if that
-             token follows.  */
-          if (actrow[j] != 0)
-            {
-              conflicted = true;
-              conflrow[j] = 1;
-            }
-          actrow[j] = rule_number_as_item_number (reds->rules[i]->number);
-        }
-    }
+          {
+            /* and record this rule as the rule to use if that
+               token follows.  */
+            if (actrow[j] != 0)
+              {
+                conflicted = true;
+                conflrow[j] = 1;
+              }
+            actrow[j] = rule_number_as_item_number (reds->rules[i]->number);
+          }
+      }
 
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  FOR_EACH_SHIFT (trans, i)
-    {
-      symbol_number sym = TRANSITION_SYMBOL (trans, i);
-      state *shift_state = trans->states[i];
+  {
+    int i;
+    FOR_EACH_SHIFT (trans, i)
+      {
+        symbol_number sym = TRANSITION_SYMBOL (trans, i);
+        state *shift_state = trans->states[i];
 
-      if (actrow[sym] != 0)
-        {
-          conflicted = true;
-          conflrow[sym] = 1;
-        }
-      actrow[sym] = state_number_as_int (shift_state->number);
+        if (actrow[sym] != 0)
+          {
+            conflicted = true;
+            conflrow[sym] = 1;
+          }
+        actrow[sym] = state_number_as_int (shift_state->number);
 
-      /* Do not use any default reduction if there is a shift for
-         error */
-      if (sym == errtoken->content->number)
-        nodefault = true;
-    }
+        /* Do not use any default reduction if there is a shift for
+           error */
+        if (sym == errtoken->content->number)
+          nodefault = true;
+      }
+  }
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record ACTION_NUMBER_MINIMUM as the
      action.  */
-  for (i = 0; i < errp->num; i++)
+  for (int i = 0; i < errp->num; i++)
     {
       symbol *sym = errp->symbols[i];
       actrow[sym->content->number] = ACTION_NUMBER_MINIMUM;
@@ -324,13 +324,11 @@ action_row (state *s)
       else
         {
           int max = 0;
-          for (i = 0; i < reds->num; i++)
+          for (int i = 0; i < reds->num; i++)
             {
               int count = 0;
               rule *r = reds->rules[i];
-              symbol_number j;
-
-              for (j = 0; j < ntokens; j++)
+              for (symbol_number j = 0; j < ntokens; j++)
                 if (actrow[j] == rule_number_as_item_number (r->number))
                   count++;
 
@@ -349,8 +347,7 @@ action_row (state *s)
 
           if (max > 0)
             {
-              int j;
-              for (j = 0; j < ntokens; j++)
+              for (symbol_number j = 0; j < ntokens; j++)
                 if (actrow[j]
                     == rule_number_as_item_number (default_reduction->number)
                     && ! (nondeterministic_parser && conflrow[j]))
@@ -363,7 +360,7 @@ action_row (state *s)
      So replace any action which says "error" with "use default".  */
 
   if (!default_reduction)
-    for (i = 0; i < ntokens; i++)
+    for (symbol_number i = 0; i < ntokens; i++)
       if (actrow[i] == ACTION_NUMBER_MINIMUM)
         actrow[i] = 0;
 
@@ -381,11 +378,9 @@ action_row (state *s)
 static void
 save_row (state_number s)
 {
-  symbol_number i;
-
   /* Number of non default actions in S.  */
   size_t count = 0;
-  for (i = 0; i < ntokens; i++)
+  for (symbol_number i = 0; i < ntokens; i++)
     if (actrow[i] != 0)
       count++;
 
@@ -398,7 +393,7 @@ save_row (state_number s)
         nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;
 
       /* Store non defaulted actions.  */
-      for (i = 0; i < ntokens; i++)
+      for (symbol_number i = 0; i < ntokens; i++)
         if (actrow[i] != 0)
           {
             *sp1++ = i;
@@ -437,34 +432,27 @@ token_actions (void)
 
   /* Find the rules which are reduced.  */
   if (!nondeterministic_parser)
+    for (rule_number r = 0; r < nrules; ++r)
+      rules[r].useful = false;
+
+  for (state_number i = 0; i < nstates; ++i)
     {
-      rule_number r;
-      for (r = 0; r < nrules; ++r)
-        rules[r].useful = false;
+      rule *default_reduction = action_row (states[i]);
+      yydefact[i] = default_reduction ? default_reduction->number + 1 : 0;
+      save_row (i);
+
+      /* Now that the parser was computed, we can find which rules are
+         really reduced, and which are not because of SR or RR
+         conflicts.  */
+      if (!nondeterministic_parser)
+        {
+          for (symbol_number j = 0; j < ntokens; ++j)
+            if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
+              rules[item_number_as_rule_number (actrow[j])].useful = true;
+          if (yydefact[i])
+            rules[yydefact[i] - 1].useful = true;
+        }
     }
-
-  {
-    state_number i;
-    for (i = 0; i < nstates; ++i)
-      {
-        rule *default_reduction = action_row (states[i]);
-        yydefact[i] = default_reduction ? default_reduction->number + 1 : 0;
-        save_row (i);
-
-        /* Now that the parser was computed, we can find which rules are
-           really reduced, and which are not because of SR or RR
-           conflicts.  */
-        if (!nondeterministic_parser)
-          {
-            symbol_number j;
-            for (j = 0; j < ntokens; ++j)
-              if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
-                rules[item_number_as_rule_number (actrow[j])].useful = true;
-            if (yydefact[i])
-              rules[yydefact[i] - 1].useful = true;
-          }
-      }
-  }
   free (actrow);
   free (conflrow);
 }
@@ -482,13 +470,12 @@ token_actions (void)
 static void
 save_column (symbol_number sym, state_number default_state)
 {
-  goto_number i;
-  goto_number begin = goto_map[sym - ntokens];
-  goto_number end = goto_map[sym - ntokens + 1];
+  const goto_number begin = goto_map[sym - ntokens];
+  const goto_number end = goto_map[sym - ntokens + 1];
 
   /* Number of non default GOTO.  */
   size_t count = 0;
-  for (i = begin; i < end; i++)
+  for (goto_number i = begin; i < end; i++)
     if (to_state[i] != default_state)
       count++;
 
@@ -500,7 +487,7 @@ save_column (symbol_number sym, state_number default_state)
       base_number *sp2 = tos[symno] = xnmalloc (count, sizeof *sp2);
 
       /* Store the state numbers of the non defaulted gotos.  */
-      for (i = begin; i < end; i++)
+      for (goto_number i = begin; i < end; i++)
         if (to_state[i] != default_state)
           {
             *sp1++ = from_state[i];
@@ -521,23 +508,20 @@ save_column (symbol_number sym, state_number default_state)
 static state_number
 default_goto (symbol_number sym, size_t state_count[])
 {
-  goto_number begin = goto_map[sym - ntokens];
-  goto_number end = goto_map[sym - ntokens + 1];
+  const goto_number begin = goto_map[sym - ntokens];
+  const goto_number end = goto_map[sym - ntokens + 1];
   state_number res = -1;
 
   if (begin != end)
     {
-      size_t max = 0;
-      goto_number i;
-      state_number s;
-
-      for (s = 0; s < nstates; s++)
+      for (state_number s = 0; s < nstates; s++)
         state_count[s] = 0;
 
-      for (i = begin; i < end; i++)
+      for (goto_number i = begin; i < end; i++)
         state_count[to_state[i]]++;
 
-      for (s = 0; s < nstates; s++)
+      size_t max = 0;
+      for (state_number s = 0; s < nstates; s++)
         if (max < state_count[s])
           {
             max = state_count[s];
@@ -560,13 +544,12 @@ default_goto (symbol_number sym, size_t state_count[])
 static void
 goto_actions (void)
 {
-  symbol_number i;
   size_t *state_count = xnmalloc (nstates, sizeof *state_count);
   yydefgoto = xnmalloc (nvars, sizeof *yydefgoto);
 
   /* For a given nterm I, STATE_COUNT[S] is the number of times there
      is a GOTO to S on I.  */
-  for (i = ntokens; i < nsyms; ++i)
+  for (symbol_number i = ntokens; i < nsyms; ++i)
     {
       state_number default_state = default_goto (i, state_count);
       save_column (i, default_state);
@@ -584,16 +567,13 @@ goto_actions (void)
 static void
 sort_actions (void)
 {
-  int i;
-
   nentries = 0;
 
-  for (i = 0; i < nvectors; i++)
+  for (int i = 0; i < nvectors; i++)
     if (0 < tally[i])
       {
-        int k;
-        size_t t = tally[i];
-        int w = width[i];
+        const size_t t = tally[i];
+        const int w = width[i];
         int j = nentries - 1;
 
         while (0 <= j && width[order[j]] < w)
@@ -602,7 +582,7 @@ sort_actions (void)
         while (0 <= j && width[order[j]] == w && tally[order[j]] < t)
           j--;
 
-        for (k = nentries - 1; k > j; k--)
+        for (int k = nentries - 1; k > j; k--)
           order[k + 1] = order[k];
 
         order[j + 1] = i;
@@ -630,12 +610,9 @@ matching_state (vector_number vector)
 
       /* If VECTOR has GLR conflicts, return -1 */
       if (conflict_tos[i] != NULL)
-        {
-          int j;
-          for (j = 0; j < t; j += 1)
-            if (conflict_tos[i][j] != 0)
-              return -1;
-        }
+        for (int j = 0; j < t; j += 1)
+          if (conflict_tos[i][j] != 0)
+            return -1;
 
       for (prev = vector - 1; 0 <= prev; prev--)
         {
@@ -647,8 +624,7 @@ matching_state (vector_number vector)
           else
             {
               bool match = true;
-              int k;
-              for (k = 0; match && k < t; k++)
+              for (int k = 0; match && k < t; k++)
                 if (tos[j][k] != tos[i][k]
                     || froms[j][k] != froms[i][k]
                     || (conflict_tos[j] != NULL && conflict_tos[j][k] != 0))
@@ -665,7 +641,6 @@ matching_state (vector_number vector)
 static base_number
 pack_vector (vector_number vector)
 {
-  base_number res;
   vector_number i = order[vector];
   size_t t = tally[i];
   base_number *from = froms[i];
@@ -674,13 +649,12 @@ pack_vector (vector_number vector)
 
   aver (t != 0);
 
-  for (res = lowzero - from[0]; ; res++)
+  for (base_number res = lowzero - from[0]; ; res++)
     {
       bool ok = true;
       aver (res < table_size);
       {
-        int k;
-        for (k = 0; ok && k < t; k++)
+        for (int k = 0; ok && k < t; k++)
           {
             int loc = res + state_number_as_int (from[k]);
             if (table_size <= loc)
@@ -691,7 +665,7 @@ pack_vector (vector_number vector)
           }
 
         if (ok)
-          for (k = 0; k < vector; k++)
+          for (int k = 0; k < vector; k++)
             if (pos[k] == res)
               ok = false;
       }
@@ -699,8 +673,7 @@ pack_vector (vector_number vector)
       if (ok)
         {
           int loc PACIFY_CC (= -1);
-          int k;
-          for (k = 0; k < t; k++)
+          for (int k = 0; k < t; k++)
             {
               loc = res + state_number_as_int (from[k]);
               table[loc] = to[k];
@@ -734,15 +707,14 @@ static base_number
 table_ninf_remap (base_number tab[], int size, base_number ninf)
 {
   base_number res = 0;
-  int i;
 
-  for (i = 0; i < size; i++)
+  for (int i = 0; i < size; i++)
     if (tab[i] < res && tab[i] != ninf)
       res = tab[i];
 
   --res;
 
-  for (i = 0; i < size; i++)
+  for (int i = 0; i < size; i++)
     if (tab[i] == ninf)
       tab[i] = res;
 
@@ -752,8 +724,6 @@ table_ninf_remap (base_number tab[], int size, base_number ninf)
 static void
 pack_table (void)
 {
-  int i;
-
   base = xnmalloc (nvectors, sizeof *base);
   pos = xnmalloc (nentries, sizeof *pos);
   table = xcalloc (table_size, sizeof *table);
@@ -763,13 +733,13 @@ pack_table (void)
   lowzero = 0;
   high = 0;
 
-  for (i = 0; i < nvectors; i++)
+  for (int i = 0; i < nvectors; i++)
     base[i] = BASE_MINIMUM;
 
-  for (i = 0; i < table_size; i++)
+  for (int i = 0; i < table_size; i++)
     check[i] = -1;
 
-  for (i = 0; i < nentries; i++)
+  for (int i = 0; i < nentries; i++)
     {
       state_number s = matching_state (i);
       base_number place;
@@ -802,13 +772,11 @@ pack_table (void)
 void
 tables_generate (void)
 {
-  int i;
-
   /* This is a poor way to make sure the sizes are properly
      correlated.  In particular the signedness is not taken into
      account.  But it's not useless.  */
-  verify (sizeof nstates <= sizeof nvectors
-          && sizeof nvars <= sizeof nvectors);
+  verify (sizeof nstates <= sizeof nvectors);
+  verify (sizeof nvars <= sizeof nvectors);
 
   nvectors = state_number_as_int (nstates) + nvars;
 
@@ -833,7 +801,7 @@ tables_generate (void)
   free (tally);
   free (width);
 
-  for (i = 0; i < nvectors; i++)
+  for (int i = 0; i < nvectors; i++)
     {
       free (froms[i]);
       free (tos[i]);
