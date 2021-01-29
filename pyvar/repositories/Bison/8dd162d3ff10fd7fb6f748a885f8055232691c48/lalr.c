@@ -1,6 +1,6 @@
 /* Compute look-ahead criteria for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -22,7 +22,7 @@
 
 
 /* Compute how to make the finite state machine deterministic; find
-   which rules need lookahead in each state, and which lookahead
+   which rules need look-ahead in each state, and which look-ahead
    tokens they accept.  */
 
 #include "system.h"
@@ -215,9 +215,9 @@ add_lookback_edge (state *s, rule *r, int gotono)
 {
   int ri = state_reduction_find (s, r);
   goto_list *sp = MALLOC (sp, 1);
-  sp->next = lookback[(s->reductions->lookaheads - LA) + ri];
+  sp->next = lookback[(s->reductions->look_ahead_tokens - LA) + ri];
   sp->value = gotono;
-  lookback[(s->reductions->lookaheads - LA) + ri] = sp;
+  lookback[(s->reductions->look_ahead_tokens - LA) + ri] = sp;
 }
 
 
@@ -306,7 +306,7 @@ compute_FOLLOWS (void)
 
 
 static void
-compute_lookaheads (void)
+compute_look_ahead_tokens (void)
 {
   size_t i;
   goto_list *sp;
@@ -324,27 +324,27 @@ compute_lookaheads (void)
 }
 
 
-/*-----------------------------------------------------------.
-| Count the number of lookaheads required for S (NLOOKAHEADS |
-| member).                                                   |
-`-----------------------------------------------------------*/
+/*-----------------------------------------------------.
+| Count the number of look-ahead tokens required for S |
+| (N_LOOK_AHEAD_TOKENS member).                        |
+`-----------------------------------------------------*/
 
 static int
-state_lookaheads_count (state *s)
+state_look_ahead_tokens_count (state *s)
 {
   int k;
-  int nlookaheads = 0;
+  int n_look_ahead_tokens = 0;
   reductions *rp = s->reductions;
   transitions *sp = s->transitions;
 
-  /* We need a lookahead either to distinguish different
+  /* We need a look-ahead either to distinguish different
      reductions (i.e., there are two or more), or to distinguish a
      reduction from a shift.  Otherwise, it is straightforward,
      and the state is `consistent'.  */
   if (rp->num > 1
       || (rp->num == 1 && sp->num &&
 	  !TRANSITION_IS_DISABLED (sp, 0) && TRANSITION_IS_SHIFT (sp, 0)))
-    nlookaheads += rp->num;
+    n_look_ahead_tokens += rp->num;
   else
     s->consistent = 1;
 
@@ -355,13 +355,13 @@ state_lookaheads_count (state *s)
 	break;
       }
 
-  return nlookaheads;
+  return n_look_ahead_tokens;
 }
 
 
-/*----------------------------------------------.
-| Compute LA, NLA, and the lookaheads members.  |
-`----------------------------------------------*/
+/*-----------------------------------------------------.
+| Compute LA, NLA, and the look_ahead_tokens members.  |
+`-----------------------------------------------------*/
 
 static void
 initialize_LA (void)
@@ -369,10 +369,10 @@ initialize_LA (void)
   state_number i;
   bitsetv pLA;
 
-  /* Compute the total number of reductions requiring a lookahead.  */
+  /* Compute the total number of reductions requiring a look-ahead.  */
   nLA = 0;
   for (i = 0; i < nstates; i++)
-    nLA += state_lookaheads_count (states[i]);
+    nLA += state_look_ahead_tokens_count (states[i]);
   /* Avoid having to special case 0.  */
   if (!nLA)
     nLA = 1;
@@ -380,54 +380,54 @@ initialize_LA (void)
   pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
   CALLOC (lookback, nLA);
 
-  /* Initialize the members LOOKAHEADS for each state which reductions
-     require lookaheads.  */
+  /* Initialize the members LOOK_AHEAD_TOKENS for each state whose reductions
+     require look-ahead tokens.  */
   for (i = 0; i < nstates; i++)
     {
-      int count = state_lookaheads_count (states[i]);
+      int count = state_look_ahead_tokens_count (states[i]);
       if (count)
 	{
-	  states[i]->reductions->lookaheads = pLA;
+	  states[i]->reductions->look_ahead_tokens = pLA;
 	  pLA += count;
 	}
     }
 }
 
 
-/*---------------------------------------.
-| Output the lookaheads for each state.  |
-`---------------------------------------*/
+/*----------------------------------------------.
+| Output the look-ahead tokens for each state.  |
+`----------------------------------------------*/
 
 static void
-lookaheads_print (FILE *out)
+look_ahead_tokens_print (FILE *out)
 {
   state_number i;
   int j, k;
-  fprintf (out, "Lookaheads: BEGIN\n");
+  fprintf (out, "Look-ahead tokens: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
       reductions *reds = states[i]->reductions;
       bitset_iterator iter;
-      int nlookaheads = 0;
+      int n_look_ahead_tokens = 0;
 
-      if (reds->lookaheads)
+      if (reds->look_ahead_tokens)
 	for (k = 0; k < reds->num; ++k)
-	  if (reds->lookaheads[k])
-	    ++nlookaheads;
+	  if (reds->look_ahead_tokens[k])
+	    ++n_look_ahead_tokens;
 
-      fprintf (out, "State %d: %d lookaheads\n",
-	       i, nlookaheads);
+      fprintf (out, "State %d: %d look-ahead tokens\n",
+	       i, n_look_ahead_tokens);
 
-      if (reds->lookaheads)
+      if (reds->look_ahead_tokens)
 	for (j = 0; j < reds->num; ++j)
-	  BITSET_FOR_EACH (iter, reds->lookaheads[j], k, 0)
+	  BITSET_FOR_EACH (iter, reds->look_ahead_tokens[j], k, 0)
 	  {
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
 		     k, symbols[k]->tag,
 		     reds->rules[j]->number);
 	  };
     }
-  fprintf (out, "Lookaheads: END\n");
+  fprintf (out, "Look-ahead tokens: END\n");
 }
 
 void
@@ -438,10 +438,10 @@ lalr (void)
   initialize_F ();
   build_relations ();
   compute_FOLLOWS ();
-  compute_lookaheads ();
+  compute_look_ahead_tokens ();
 
   if (trace_flag & trace_sets)
-    lookaheads_print (stderr);
+    look_ahead_tokens_print (stderr);
 }
 
 
@@ -450,6 +450,6 @@ lalr_free (void)
 {
   state_number s;
   for (s = 0; s < nstates; ++s)
-    states[s]->reductions->lookaheads = NULL;
+    states[s]->reductions->look_ahead_tokens = NULL;
   bitsetv_free (LA);
 }
