@@ -560,39 +560,6 @@ set_state_table (void)
       if (!state_table[i]->shifts)
 	state_table[i]->shifts = shifts_new (0);
   }
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
 }
 
 /*-------------------------------------------------------------------.
