@@ -256,9 +256,9 @@ lookback_find_state (int lookback_index)
   state *res = NULL;
   for (int j = 0; j < nstates; ++j)
     if (states[j]->reductions
-        && states[j]->reductions->lookahead_tokens)
+        && states[j]->reductions->lookaheads)
       {
-        if (states[j]->reductions->lookahead_tokens - LA > lookback_index)
+        if (states[j]->reductions->lookaheads - LA > lookback_index)
           /* Went too far. */
           break;
         else
@@ -280,7 +280,7 @@ lookback_print (FILE *out)
     {
       fprintf (out, "   %3d = ", i);
       const state *s = lookback_find_state (i);
-      int rnum = i - (s->reductions->lookahead_tokens - LA);
+      int rnum = i - (s->reductions->lookaheads - LA);
       const rule *r = s->reductions->rules[rnum];
       fprintf (out, "(%3d, ", s->number);
       rule_print (r, NULL, out);
@@ -305,7 +305,7 @@ static void
 add_lookback_edge (state *s, rule const *r, goto_number gotono)
 {
   int ri = state_reduction_find (s, r);
-  int idx = (s->reductions->lookahead_tokens - LA) + ri;
+  int idx = (s->reductions->lookaheads - LA) + ri;
   lookback[idx] = goto_list_new (gotono, lookback[idx]);
 }
 
@@ -421,7 +421,7 @@ compute_follows (void)
 
 
 static void
-compute_lookahead_tokens (void)
+compute_lookaheads (void)
 {
   if (trace_flag & trace_automaton)
       lookback_print (stderr);
@@ -437,13 +437,12 @@ compute_lookahead_tokens (void)
 }
 
 
-/*----------------------------------------------------.
-| Count the number of lookahead tokens required for S |
-| (N_LOOKAHEAD_TOKENS member).                        |
-`----------------------------------------------------*/
+/*------------------------------------------------------.
+| Count the number of lookahead tokens required for S.  |
+`------------------------------------------------------*/
 
 static int
-state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
+state_lookaheads_count (state *s, bool default_reduction_only_for_accept)
 {
   const reductions *reds = s->reductions;
   const transitions *trans = s->transitions;
@@ -473,9 +472,9 @@ state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
 }
 
 
-/*----------------------------------------------------.
-| Compute LA, NLA, and the lookahead_tokens members.  |
-`----------------------------------------------------*/
+/*----------------------------------------------.
+| Compute LA, NLA, and the lookaheads members.  |
+`----------------------------------------------*/
 
 void
 initialize_LA (void)
@@ -491,25 +490,23 @@ initialize_LA (void)
   /* Compute the total number of reductions requiring a lookahead.  */
   nLA = 0;
   for (state_number i = 0; i < nstates; ++i)
-    nLA +=
-      state_lookahead_tokens_count (states[i],
-                                    default_reduction_only_for_accept);
+    nLA += state_lookaheads_count (states[i],
+                                   default_reduction_only_for_accept);
   /* Avoid having to special case 0.  */
   if (!nLA)
     nLA = 1;
 
   bitsetv pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
 
-  /* Initialize the members LOOKAHEAD_TOKENS for each state whose reductions
+  /* Initialize the members LOOKAHEADS for each state whose reductions
      require lookahead tokens.  */
   for (state_number i = 0; i < nstates; ++i)
     {
-      int count =
-        state_lookahead_tokens_count (states[i],
-                                      default_reduction_only_for_accept);
+      int count = state_lookaheads_count (states[i],
+                                          default_reduction_only_for_accept);
       if (count)
         {
-          states[i]->reductions->lookahead_tokens = pLA;
+          states[i]->reductions->lookaheads = pLA;
           pLA += count;
         }
     }
@@ -521,7 +518,7 @@ initialize_LA (void)
 `---------------------------------------------*/
 
 static void
-lookahead_tokens_print (FILE *out)
+lookaheads_print (FILE *out)
 {
   fputs ("Lookaheads:\n", out);
   for (state_number i = 0; i < nstates; ++i)
@@ -533,11 +530,11 @@ lookahead_tokens_print (FILE *out)
           for (int j = 0; j < reds->num; ++j)
             {
               fprintf (out, "    rule %d:", reds->rules[j]->number);
-              if (reds->lookahead_tokens)
+              if (reds->lookaheads)
               {
                 bitset_iterator iter;
                 int k;
-                BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
+                BITSET_FOR_EACH (iter, reds->lookaheads[j], k, 0)
                   fprintf (out, " %s", symbols[k]->tag);
               }
               fputc ('\n', out);
@@ -564,10 +561,10 @@ lalr (void)
   lookback = xcalloc (nLA, sizeof *lookback);
   build_relations ();
   compute_follows ();
-  compute_lookahead_tokens ();
+  compute_lookaheads ();
 
   if (trace_flag & trace_sets)
-    lookahead_tokens_print (stderr);
+    lookaheads_print (stderr);
   if (trace_flag & trace_automaton)
     {
       begin_use_class ("trace0", stderr);
@@ -614,6 +611,6 @@ void
 lalr_free (void)
 {
   for (state_number s = 0; s < nstates; ++s)
-    states[s]->reductions->lookahead_tokens = NULL;
+    states[s]->reductions->lookaheads = NULL;
   bitsetv_free (LA);
 }
