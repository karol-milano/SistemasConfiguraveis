@@ -132,68 +132,6 @@ digraph (short **relation)
 }
 
 
-/*--------------------.
-| Build STATE_TABLE.  |
-`--------------------*/
-
-static void
-set_state_table (void)
-{
-  /* NSTATES + 1 because lookahead for the pseudo state number NSTATES
-     might be used (see conflicts.c).  It is too opaque for me to
-     provide a probably less hacky implementation. --akim */
-  state_table = XCALLOC (state_t *, nstates + 1);
-
-  {
-    state_t *sp;
-    for (sp = first_state; sp; sp = sp->next)
-      state_table[sp->number] = sp;
-  }
-
-  /* Pessimization, but simplification of the code: make sure all the
-     states have a shifts, even if reduced to 0 shifts.  */
-  {
-    int i;
-    for (i = 0; i < nstates; i++)
-      if (!state_table[i]->shifts)
-	state_table[i]->shifts = shifts_new (0);
-  }
-
-  /* Initializing the lookaheads members.  Please note that it must be
-     performed after having set some of the other members which are
-     used below.  Change with extreme caution.  */
-  {
-    int i;
-    int count = 0;
-    for (i = 0; i < nstates; i++)
-      {
-	int k;
-	reductions *rp = state_table[i]->reductions;
-	shifts *sp = state_table[i]->shifts;
-
-	state_table[i]->lookaheads = count;
-
-	if (rp
-	    && (rp->nreds > 1 || (sp->nshifts && SHIFT_IS_SHIFT (sp, 0))))
-	  count += rp->nreds;
-	else
-	  state_table[i]->consistent = 1;
-
-	for (k = 0; k < sp->nshifts; k++)
-	  if (SHIFT_IS_ERROR (sp, k))
-	    {
-	      state_table[i]->consistent = 0;
-	      break;
-	    }
-      }
-
-    /* Seems to be needed by conflicts.c. */
-    state_table[nstates] = STATE_ALLOC (0);
-    state_table[nstates]->lookaheads = count;
-  }
-}
-
-
 static void
 initialize_LA (void)
 {
@@ -601,7 +539,6 @@ lalr (void)
 {
   tokensetsize = WORDSIZE (ntokens);
 
-  set_state_table ();
   initialize_LA ();
   set_goto_map ();
   initialize_F ();
