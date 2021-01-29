@@ -534,11 +534,48 @@ compute_lookaheads (void)
 }
 
 
+/*--------------------------------------.
+| Initializing the lookaheads members.  |
+`--------------------------------------*/
+
+static void
+initialize_lookaheads (void)
+{
+  int i;
+  int count = 0;
+  for (i = 0; i < nstates; i++)
+    {
+      int k;
+      reductions *rp = state_table[i]->reductions;
+      shifts *sp = state_table[i]->shifts;
+
+      state_table[i]->lookaheads = count;
+
+      if (rp
+	  && (rp->nreds > 1 || (sp->nshifts && SHIFT_IS_SHIFT (sp, 0))))
+	count += rp->nreds;
+      else
+	state_table[i]->consistent = 1;
+
+      for (k = 0; k < sp->nshifts; k++)
+	if (SHIFT_IS_ERROR (sp, k))
+	  {
+	    state_table[i]->consistent = 0;
+	    break;
+	  }
+    }
+
+  /* Seems to be needed by conflicts.c. */
+  state_table[nstates] = STATE_ALLOC (0);
+  state_table[nstates]->lookaheads = count;
+}
+
 void
 lalr (void)
 {
   tokensetsize = WORDSIZE (ntokens);
 
+  initialize_lookaheads ();
   initialize_LA ();
   set_goto_map ();
   initialize_F ();
