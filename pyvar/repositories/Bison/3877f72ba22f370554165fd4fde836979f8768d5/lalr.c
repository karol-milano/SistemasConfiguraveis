@@ -140,7 +140,7 @@ initialize_LA (void)
   short *np;
   reductions *rp;
 
-  size_t nLA = state_table[nstates]->lookaheads;
+  size_t nLA = state_table[nstates]->lookaheadsp;
   if (!nLA)
     nLA = 1;
 
@@ -314,8 +314,8 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
   int found;
   shorts *sp;
 
-  i = state_table[stateno]->lookaheads;
-  k = state_table[stateno + 1]->lookaheads;
+  i = state_table[stateno]->lookaheadsp;
+  k = state_table[stateno + 1]->lookaheadsp;
   found = 0;
   while (!found && i < k)
     {
@@ -516,7 +516,7 @@ compute_lookaheads (void)
   int i;
   shorts *sp;
 
-  for (i = 0; i < state_table[nstates]->lookaheads; i++)
+  for (i = 0; i < state_table[nstates]->lookaheadsp; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
       {
 	int size = LA (i + 1) - LA (i);
@@ -526,7 +526,7 @@ compute_lookaheads (void)
       }
 
   /* Free LOOKBACK. */
-  for (i = 0; i < state_table[nstates]->lookaheads; i++)
+  for (i = 0; i < state_table[nstates]->lookaheadsp; i++)
     LIST_FREE (shorts, lookback[i]);
 
   XFREE (lookback);
@@ -546,14 +546,13 @@ initialize_lookaheads (void)
   for (i = 0; i < nstates; i++)
     {
       int k;
+      int nlookaheads = 0;
       reductions *rp = state_table[i]->reductions;
       shifts *sp = state_table[i]->shifts;
 
-      state_table[i]->lookaheads = count;
-
       if (rp
 	  && (rp->nreds > 1 || (sp->nshifts && SHIFT_IS_SHIFT (sp, 0))))
-	count += rp->nreds;
+	nlookaheads += rp->nreds;
       else
 	state_table[i]->consistent = 1;
 
@@ -563,11 +562,15 @@ initialize_lookaheads (void)
 	    state_table[i]->consistent = 0;
 	    break;
 	  }
+
+      state_table[i]->nlookaheads = nlookaheads;
+      state_table[i]->lookaheadsp = count;
+      count += nlookaheads;
     }
 
   /* Seems to be needed by conflicts.c. */
   state_table[nstates] = STATE_ALLOC (0);
-  state_table[nstates]->lookaheads = count;
+  state_table[nstates]->lookaheadsp = count;
 }
 
 void
