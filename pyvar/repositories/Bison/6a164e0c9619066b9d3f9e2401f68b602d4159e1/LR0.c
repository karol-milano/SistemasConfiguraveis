@@ -35,8 +35,8 @@
 
 int nstates;
 int final_state;
-state_t *first_state = NULL;
-shifts *first_shift = NULL;
+static state_t *first_state = NULL;
+static shifts *first_shift = NULL;
 
 static state_t *this_state = NULL;
 static state_t *last_state = NULL;
@@ -601,6 +601,67 @@ save_reductions (void)
 }
 
 
+/*--------------------.
+| Build STATE_TABLE.  |
+`--------------------*/
+
+static void
+set_state_table (void)
+{
+  /* NSTATES + 1 because lookahead for the pseudo state number NSTATES
+     might be used (see conflicts.c).  It is too opaque for me to
+     provide a probably less hacky implementation. --akim */
+  state_table = XCALLOC (state_t *, nstates + 1);
+
+  {
+    state_t *sp;
+    for (sp = first_state; sp; sp = sp->next)
+      state_table[sp->number] = sp;
+  }
+
+  /* Pessimization, but simplification of the code: make sure all the
+     states have a shifts, even if reduced to 0 shifts.  */
+  {
+    int i;
+    for (i = 0; i < nstates; i++)
+      if (!state_table[i]->shifts)
+	state_table[i]->shifts = shifts_new (0);
+  }
+
+  /* Initializing the lookaheads members.  Please note that it must be
+     performed after having set some of the other members which are
+     used below.  Change with extreme caution.  */
+  {
+    int i;
+    int count = 0;
+    for (i = 0; i < nstates; i++)
+      {
+	int k;
+	reductions *rp = state_table[i]->reductions;
+	shifts *sp = state_table[i]->shifts;
+
+	state_table[i]->lookaheads = count;
+
+	if (rp
+	    && (rp->nreds > 1 || (sp->nshifts && SHIFT_IS_SHIFT (sp, 0))))
+	  count += rp->nreds;
+	else
+	  state_table[i]->consistent = 1;
+
+	for (k = 0; k < sp->nshifts; k++)
+	  if (SHIFT_IS_ERROR (sp, k))
+	    {
+	      state_table[i]->consistent = 0;
+	      break;
+	    }
+      }
+
+    /* Seems to be needed by conflicts.c. */
+    state_table[nstates] = STATE_ALLOC (0);
+    state_table[nstates]->lookaheads = count;
+  }
+}
+
 /*-------------------------------------------------------------------.
 | Compute the nondeterministic finite state machine (see state.h for |
 | details) from the grammar.                                         |
@@ -644,4 +705,7 @@ generate_states (void)
 
   /* set up initial and final states as parser wants them */
   augment_automaton ();
+
+  /* Set up STATE_TABLE. */
+  set_state_table ();
 }
