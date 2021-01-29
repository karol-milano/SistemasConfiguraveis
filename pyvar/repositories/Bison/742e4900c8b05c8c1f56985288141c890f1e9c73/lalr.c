@@ -1,4 +1,4 @@
-/* Compute look-ahead criteria for Bison.
+/* Compute lookahead criteria for Bison.
 
    Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005,
    2006 Free Software Foundation, Inc.
@@ -22,7 +22,7 @@
 
 
 /* Compute how to make the finite state machine deterministic; find
-   which rules need look-ahead in each state, and which look-ahead
+   which rules need lookahead in each state, and which lookahead
    tokens they accept.  */
 
 #include <config.h>
@@ -219,9 +219,9 @@ add_lookback_edge (state *s, rule *r, goto_number gotono)
 {
   int ri = state_reduction_find (s, r);
   goto_list *sp = xmalloc (sizeof *sp);
-  sp->next = lookback[(s->reductions->look_ahead_tokens - LA) + ri];
+  sp->next = lookback[(s->reductions->lookahead_tokens - LA) + ri];
   sp->value = gotono;
-  lookback[(s->reductions->look_ahead_tokens - LA) + ri] = sp;
+  lookback[(s->reductions->lookahead_tokens - LA) + ri] = sp;
 }
 
 
@@ -314,7 +314,7 @@ compute_FOLLOWS (void)
 
 
 static void
-compute_look_ahead_tokens (void)
+compute_lookahead_tokens (void)
 {
   size_t i;
   goto_list *sp;
@@ -332,27 +332,27 @@ compute_look_ahead_tokens (void)
 }
 
 
-/*-----------------------------------------------------.
-| Count the number of look-ahead tokens required for S |
-| (N_LOOK_AHEAD_TOKENS member).                        |
-`-----------------------------------------------------*/
+/*----------------------------------------------------.
+| Count the number of lookahead tokens required for S |
+| (N_LOOKAHEAD_TOKENS member).                        |
+`----------------------------------------------------*/
 
 static int
-state_look_ahead_tokens_count (state *s)
+state_lookahead_tokens_count (state *s)
 {
   int k;
-  int n_look_ahead_tokens = 0;
+  int n_lookahead_tokens = 0;
   reductions *rp = s->reductions;
   transitions *sp = s->transitions;
 
-  /* We need a look-ahead either to distinguish different
+  /* We need a lookahead either to distinguish different
      reductions (i.e., there are two or more), or to distinguish a
      reduction from a shift.  Otherwise, it is straightforward,
      and the state is `consistent'.  */
   if (rp->num > 1
       || (rp->num == 1 && sp->num &&
 	  !TRANSITION_IS_DISABLED (sp, 0) && TRANSITION_IS_SHIFT (sp, 0)))
-    n_look_ahead_tokens += rp->num;
+    n_lookahead_tokens += rp->num;
   else
     s->consistent = 1;
 
@@ -363,13 +363,13 @@ state_look_ahead_tokens_count (state *s)
 	break;
       }
 
-  return n_look_ahead_tokens;
+  return n_lookahead_tokens;
 }
 
 
-/*-----------------------------------------------------.
-| Compute LA, NLA, and the look_ahead_tokens members.  |
-`-----------------------------------------------------*/
+/*----------------------------------------------------.
+| Compute LA, NLA, and the lookahead_tokens members.  |
+`----------------------------------------------------*/
 
 static void
 initialize_LA (void)
@@ -377,10 +377,10 @@ initialize_LA (void)
   state_number i;
   bitsetv pLA;
 
-  /* Compute the total number of reductions requiring a look-ahead.  */
+  /* Compute the total number of reductions requiring a lookahead.  */
   nLA = 0;
   for (i = 0; i < nstates; i++)
-    nLA += state_look_ahead_tokens_count (states[i]);
+    nLA += state_lookahead_tokens_count (states[i]);
   /* Avoid having to special case 0.  */
   if (!nLA)
     nLA = 1;
@@ -388,54 +388,54 @@ initialize_LA (void)
   pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
   lookback = xcalloc (nLA, sizeof *lookback);
 
-  /* Initialize the members LOOK_AHEAD_TOKENS for each state whose reductions
-     require look-ahead tokens.  */
+  /* Initialize the members LOOKAHEAD_TOKENS for each state whose reductions
+     require lookahead tokens.  */
   for (i = 0; i < nstates; i++)
     {
-      int count = state_look_ahead_tokens_count (states[i]);
+      int count = state_lookahead_tokens_count (states[i]);
       if (count)
 	{
-	  states[i]->reductions->look_ahead_tokens = pLA;
+	  states[i]->reductions->lookahead_tokens = pLA;
 	  pLA += count;
 	}
     }
 }
 
 
-/*----------------------------------------------.
-| Output the look-ahead tokens for each state.  |
-`----------------------------------------------*/
+/*---------------------------------------------.
+| Output the lookahead tokens for each state.  |
+`---------------------------------------------*/
 
 static void
-look_ahead_tokens_print (FILE *out)
+lookahead_tokens_print (FILE *out)
 {
   state_number i;
   int j, k;
-  fprintf (out, "Look-ahead tokens: BEGIN\n");
+  fprintf (out, "Lookahead tokens: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
       reductions *reds = states[i]->reductions;
       bitset_iterator iter;
-      int n_look_ahead_tokens = 0;
+      int n_lookahead_tokens = 0;
 
-      if (reds->look_ahead_tokens)
+      if (reds->lookahead_tokens)
 	for (k = 0; k < reds->num; ++k)
-	  if (reds->look_ahead_tokens[k])
-	    ++n_look_ahead_tokens;
+	  if (reds->lookahead_tokens[k])
+	    ++n_lookahead_tokens;
 
-      fprintf (out, "State %d: %d look-ahead tokens\n",
-	       i, n_look_ahead_tokens);
+      fprintf (out, "State %d: %d lookahead tokens\n",
+	       i, n_lookahead_tokens);
 
-      if (reds->look_ahead_tokens)
+      if (reds->lookahead_tokens)
 	for (j = 0; j < reds->num; ++j)
-	  BITSET_FOR_EACH (iter, reds->look_ahead_tokens[j], k, 0)
+	  BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
 	  {
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
 		     k, symbols[k]->tag,
 		     reds->rules[j]->number);
 	  };
     }
-  fprintf (out, "Look-ahead tokens: END\n");
+  fprintf (out, "Lookahead tokens: END\n");
 }
 
 void
@@ -446,10 +446,10 @@ lalr (void)
   initialize_F ();
   build_relations ();
   compute_FOLLOWS ();
-  compute_look_ahead_tokens ();
+  compute_lookahead_tokens ();
 
   if (trace_flag & trace_sets)
-    look_ahead_tokens_print (stderr);
+    lookahead_tokens_print (stderr);
 }
 
 
@@ -458,6 +458,6 @@ lalr_free (void)
 {
   state_number s;
   for (s = 0; s < nstates; ++s)
-    states[s]->reductions->look_ahead_tokens = NULL;
+    states[s]->reductions->lookahead_tokens = NULL;
   bitsetv_free (LA);
 }
