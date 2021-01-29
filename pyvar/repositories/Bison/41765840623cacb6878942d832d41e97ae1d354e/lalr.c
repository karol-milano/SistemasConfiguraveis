@@ -40,10 +40,10 @@
 #include "relation.h"
 #include "symtab.h"
 
-goto_number *goto_map;
-goto_number ngotos;
-state_number *from_state;
-state_number *to_state;
+goto_number *goto_map = NULL;
+goto_number ngotos = 0;
+state_number *from_state = NULL;
+state_number *to_state = NULL;
 bitsetv goto_follows = NULL;
 
 /* Linked list of goto numbers.  */
@@ -70,16 +70,14 @@ static goto_list **lookback;
 void
 set_goto_map (void)
 {
-  state_number s;
   goto_number *temp_map = xnmalloc (nvars + 1, sizeof *temp_map);
 
   goto_map = xcalloc (nvars + 1, sizeof *goto_map);
   ngotos = 0;
-  for (s = 0; s < nstates; ++s)
+  for (state_number s = 0; s < nstates; ++s)
     {
       transitions *sp = states[s]->transitions;
-      int i;
-      for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
+      for (int i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
         {
           ngotos++;
 
@@ -92,14 +90,13 @@ set_goto_map (void)
 
   {
     goto_number k = 0;
-    int i;
-    for (i = ntokens; i < nsyms; i++)
+    for (symbol_number i = ntokens; i < nsyms; ++i)
       {
         temp_map[i - ntokens] = k;
         k += goto_map[i - ntokens];
       }
 
-    for (i = ntokens; i < nsyms; i++)
+    for (symbol_number i = ntokens; i < nsyms; ++i)
       goto_map[i - ntokens] = temp_map[i - ntokens];
 
     goto_map[nsyms - ntokens] = ngotos;
@@ -109,11 +106,10 @@ set_goto_map (void)
   from_state = xcalloc (ngotos, sizeof *from_state);
   to_state = xcalloc (ngotos, sizeof *to_state);
 
-  for (s = 0; s < nstates; ++s)
+  for (state_number s = 0; s < nstates; ++s)
     {
-      transitions *sp = states[s]->transitions;
-      int i;
-      for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
+      const transitions *sp = states[s]->transitions;
+      for (int i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
         {
           goto_number k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
           from_state[k] = s;
@@ -133,11 +129,9 @@ map_goto (state_number s0, symbol_number sym)
 
   for (;;)
     {
-      goto_number middle;
-      state_number s;
       aver (low <= high);
-      middle = (low + high) / 2;
-      s = from_state[middle];
+      goto_number middle = (low + high) / 2;
+      state_number s = from_state[middle];
       if (s == s0)
         return middle;
       else if (s < s0)
@@ -155,20 +149,18 @@ initialize_F (void)
   goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
   goto_number nedges = 0;
 
-  goto_number i;
-
   goto_follows = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
 
-  for (i = 0; i < ngotos; i++)
+  for (goto_number i = 0; i < ngotos; ++i)
     {
       state_number stateno = to_state[i];
-      transitions *sp = states[stateno]->transitions;
+      const transitions *sp = states[stateno]->transitions;
 
       int j;
       FOR_EACH_SHIFT (sp, j)
         bitset_set (goto_follows[i], TRANSITION_SYMBOL (sp, j));
 
-      for (; j < sp->num; j++)
+      for (; j < sp->num; ++j)
         {
           symbol_number sym = TRANSITION_SYMBOL (sp, j);
           if (nullable[sym - ntokens])
@@ -188,7 +180,7 @@ initialize_F (void)
 
   relation_digraph (reads, ngotos, &goto_follows);
 
-  for (i = 0; i < ngotos; i++)
+  for (goto_number i = 0; i < ngotos; ++i)
     free (reads[i]);
 
   free (reads);
@@ -213,19 +205,16 @@ build_relations (void)
 {
   goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
   state_number *states1 = xnmalloc (ritem_longest_rhs () + 1, sizeof *states1);
-  goto_number i;
 
   includes = xnmalloc (ngotos, sizeof *includes);
 
-  for (i = 0; i < ngotos; i++)
+  for (goto_number i = 0; i < ngotos; ++i)
     {
       int nedges = 0;
       symbol_number symbol1 = states[to_state[i]]->accessing_symbol;
-      rule **rulep;
 
-      for (rulep = derives[symbol1 - ntokens]; *rulep; rulep++)
+      for (rule **rulep = derives[symbol1 - ntokens]; *rulep; rulep++)
         {
-          bool done;
           int length = 1;
           item_number const *rp;
           state *s = states[from_state[i]];
@@ -242,7 +231,7 @@ build_relations (void)
             add_lookback_edge (s, *rulep, i);
 
           length--;
-          done = false;
+          bool done = false;
           while (!done)
             {
               done = true;
@@ -265,9 +254,8 @@ build_relations (void)
         includes[i] = NULL;
       else
         {
-          int j;
           includes[i] = xnmalloc (nedges + 1, sizeof includes[i][0]);
-          for (j = 0; j < nedges; j++)
+          for (int j = 0; j < nedges; ++j)
             includes[i][j] = edge[j];
           includes[i][nedges] = END_NODE;
         }
@@ -284,11 +272,9 @@ build_relations (void)
 static void
 compute_FOLLOWS (void)
 {
-  goto_number i;
-
   relation_digraph (includes, ngotos, &goto_follows);
 
-  for (i = 0; i < ngotos; i++)
+  for (goto_number i = 0; i < ngotos; ++i)
     free (includes[i]);
 
   free (includes);
@@ -298,15 +284,12 @@ compute_FOLLOWS (void)
 static void
 compute_lookahead_tokens (void)
 {
-  size_t i;
-  goto_list *sp;
-
-  for (i = 0; i < nLA; i++)
-    for (sp = lookback[i]; sp; sp = sp->next)
+  for (size_t i = 0; i < nLA; ++i)
+    for (goto_list *sp = lookback[i]; sp; sp = sp->next)
       bitset_or (LA[i], LA[i], goto_follows[sp->value]);
 
   /* Free LOOKBACK. */
-  for (i = 0; i < nLA; i++)
+  for (size_t i = 0; i < nLA; ++i)
     LIST_FREE (goto_list, lookback[i]);
 
   free (lookback);
@@ -359,8 +342,6 @@ state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
 void
 initialize_LA (void)
 {
-  state_number i;
-  bitsetv pLA;
   bool default_reduction_only_for_accept;
   {
     char *default_reductions =
@@ -371,7 +352,7 @@ initialize_LA (void)
 
   /* Compute the total number of reductions requiring a lookahead.  */
   nLA = 0;
-  for (i = 0; i < nstates; i++)
+  for (state_number i = 0; i < nstates; ++i)
     nLA +=
       state_lookahead_tokens_count (states[i],
                                     default_reduction_only_for_accept);
@@ -379,11 +360,11 @@ initialize_LA (void)
   if (!nLA)
     nLA = 1;
 
-  pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
+  bitsetv pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
 
   /* Initialize the members LOOKAHEAD_TOKENS for each state whose reductions
      require lookahead tokens.  */
-  for (i = 0; i < nstates; i++)
+  for (state_number i = 0; i < nstates; ++i)
     {
       int count =
         state_lookahead_tokens_count (states[i],
@@ -404,34 +385,30 @@ initialize_LA (void)
 static void
 lookahead_tokens_print (FILE *out)
 {
-  state_number i;
   fprintf (out, "Lookahead tokens: BEGIN\n");
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     {
-      reductions *reds = states[i]->reductions;
-      bitset_iterator iter;
+      const reductions *reds = states[i]->reductions;
       int n_lookahead_tokens = 0;
 
       if (reds->lookahead_tokens)
-        {
-          int j;
-          for (j = 0; j < reds->num; ++j)
-            if (reds->lookahead_tokens[j])
-              ++n_lookahead_tokens;
-        }
+        for (int j = 0; j < reds->num; ++j)
+          if (reds->lookahead_tokens[j])
+            ++n_lookahead_tokens;
 
       fprintf (out, "State %d: %d lookahead tokens\n",
                i, n_lookahead_tokens);
 
       if (reds->lookahead_tokens)
-        {
-          int j, k;
-          for (j = 0; j < reds->num; ++j)
+        for (int j = 0; j < reds->num; ++j)
+          {
+            bitset_iterator iter;
+            int k;
             BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
               fprintf (out, "   on %d (%s) -> rule %d\n",
                        k, symbols[k]->tag,
                        reds->rules[j]->number);
-        }
+          }
     }
   fprintf (out, "Lookahead tokens: END\n");
 }
@@ -458,25 +435,23 @@ lalr_update_state_numbers (state_number old_to_new[], state_number nstates_old)
   goto_number ngotos_reachable = 0;
   symbol_number nonterminal = 0;
   aver (nsyms == nvars + ntokens);
-  {
-    goto_number i;
-    for (i = 0; i < ngotos; ++i)
-      {
-        while (i == goto_map[nonterminal])
-          goto_map[nonterminal++] = ngotos_reachable;
-        /* If old_to_new[from_state[i]] = nstates_old, remove this goto
-           entry.  */
-        if (old_to_new[from_state[i]] != nstates_old)
-          {
-            /* from_state[i] is not removed, so it and thus to_state[i] are
-               reachable, so to_state[i] != nstates_old.  */
-            aver (old_to_new[to_state[i]] != nstates_old);
-            from_state[ngotos_reachable] = old_to_new[from_state[i]];
-            to_state[ngotos_reachable] = old_to_new[to_state[i]];
-            ++ngotos_reachable;
-          }
-      }
-  }
+
+  for (goto_number i = 0; i < ngotos; ++i)
+    {
+      while (i == goto_map[nonterminal])
+        goto_map[nonterminal++] = ngotos_reachable;
+      /* If old_to_new[from_state[i]] = nstates_old, remove this goto
+         entry.  */
+      if (old_to_new[from_state[i]] != nstates_old)
+        {
+          /* from_state[i] is not removed, so it and thus to_state[i] are
+             reachable, so to_state[i] != nstates_old.  */
+          aver (old_to_new[to_state[i]] != nstates_old);
+          from_state[ngotos_reachable] = old_to_new[from_state[i]];
+          to_state[ngotos_reachable] = old_to_new[to_state[i]];
+          ++ngotos_reachable;
+        }
+    }
   while (nonterminal <= nvars)
     {
       aver (ngotos == goto_map[nonterminal]);
@@ -489,8 +464,7 @@ lalr_update_state_numbers (state_number old_to_new[], state_number nstates_old)
 void
 lalr_free (void)
 {
-  state_number s;
-  for (s = 0; s < nstates; ++s)
+  for (state_number s = 0; s < nstates; ++s)
     states[s]->reductions->lookahead_tokens = NULL;
   bitsetv_free (LA);
 }
