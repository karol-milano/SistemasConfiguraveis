@@ -35,22 +35,93 @@
 /* -1 stands for not specified. */
 int expected_conflicts = -1;
 static char *conflicts = NULL;
+struct obstack solved_conflicts_obstack;
 
 static bitset shiftset;
 static bitset lookaheadset;
+
 
 
+enum conflict_resolution_e
+  {
+    shift_resolution,
+    reduce_resolution,
+    left_resolution,
+    right_resolution,
+    nonassoc_resolution,
+  };
+
+
 static inline void
-log_resolution (state_t *state, int LAno, int token, const char *resolution)
+log_resolution (int lookahead, int token,
+		enum conflict_resolution_e resolution)
 {
-  if (report_flag & report_states)
-    obstack_fgrow4 (&output_obstack,
-		    _("\
-Conflict in state %d between rule %d and token %s resolved as %s.\n"),
-		    state->number,
-		    LArule[LAno]->number,
-		    symbols[token]->tag,
-		    resolution);
+  if (report_flag & report_solved_conflicts)
+    {
+      /* The description of the resolution. */
+      switch (resolution)
+	{
+	case shift_resolution:
+	case left_resolution:
+	  obstack_fgrow2 (&solved_conflicts_obstack,
+			  _("\
+    Conflict between rule %d and token %s resolved as shift"),
+			  LArule[lookahead]->number,
+			  symbols[token]->tag);
+	  break;
+	case reduce_resolution:
+	case right_resolution:
+	  obstack_fgrow2 (&solved_conflicts_obstack,
+			  _("\
+    Conflict between rule %d and token %s resolved as reduce"),
+			  LArule[lookahead]->number,
+			  symbols[token]->tag);
+	  break;
+	case nonassoc_resolution:
+	  obstack_fgrow2 (&solved_conflicts_obstack,
+			  _("\
+    Conflict between rule %d and token %s resolved as an error"),
+			  LArule[lookahead]->number,
+			  symbols[token]->tag);
+	  break;
+	}
+
+      /* The reason. */
+      switch (resolution)
+	{
+	case shift_resolution:
+	  obstack_fgrow2 (&solved_conflicts_obstack,
+			  " (%s < %s)",
+			  LArule[lookahead]->prec->tag,
+			  symbols[token]->tag);
+	  break;
+
+	case reduce_resolution:
+	  obstack_fgrow2 (&solved_conflicts_obstack,
+			  " (%s < %s)",
+			  symbols[token]->tag,
+			  LArule[lookahead]->prec->tag);
+	  break;
+
+	case left_resolution:
+	  obstack_printf (&solved_conflicts_obstack,
+			  " (%%left %s)",
+			  symbols[token]->tag);
+	  break;
+
+	case right_resolution:
+	  obstack_fgrow1 (&solved_conflicts_obstack,
+			  " (%%right %s)",
+			  symbols[token]->tag);
+	  break;
+	case nonassoc_resolution:
+	  obstack_fgrow1 (&solved_conflicts_obstack,
+			  " (%%nonassoc %s)",
+			  symbols[token]->tag);
+	  break;
+	}
+      obstack_sgrow (&solved_conflicts_obstack, ".\n");
+    }
 }
 
 
@@ -112,12 +183,12 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	   The precedence of shifting is that of token i.  */
 	if (symbols[i]->prec < redprec)
 	  {
-	    log_resolution (state, lookahead, i, _("reduce"));
+	    log_resolution (lookahead, i, reduce_resolution);
 	    flush_shift (state, i);
 	  }
 	else if (symbols[i]->prec > redprec)
 	  {
-	    log_resolution (state, lookahead, i, _("shift"));
+	    log_resolution (lookahead, i, shift_resolution);
 	    flush_reduce (lookahead, i);
 	  }
 	else
@@ -129,17 +200,17 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	  switch (symbols[i]->assoc)
 	    {
 	    case right_assoc:
-	      log_resolution (state, lookahead, i, _("shift"));
+	      log_resolution (lookahead, i, right_resolution);
 	      flush_reduce (lookahead, i);
 	      break;
 
 	    case left_assoc:
-	      log_resolution (state, lookahead, i, _("reduce"));
+	      log_resolution (lookahead, i, left_resolution);
 	      flush_shift (state, i);
 	      break;
 
 	    case non_assoc:
-	      log_resolution (state, lookahead, i, _("an error"));
+	      log_resolution (lookahead, i, nonassoc_resolution);
 	      flush_shift (state, i);
 	      flush_reduce (lookahead, i);
 	      /* Record an explicit error for this token.  */
@@ -152,6 +223,12 @@ resolve_sr_conflict (state_t *state, int lookahead)
      permanent errs structure for this state, to record them.  */
   state->errs = errs_dup (errp);
   free (errp);
+
+  if (obstack_object_size (&solved_conflicts_obstack))
+    {
+      obstack_1grow (&solved_conflicts_obstack, '\0');
+      state->solved_conflicts = obstack_finish (&solved_conflicts_obstack);
+    }
 }
 
 
@@ -195,13 +272,14 @@ set_conflicts (state_t *state)
 }
 
 void
-solve_conflicts (void)
+conflicts_solve (void)
 {
   size_t i;
 
   conflicts = XCALLOC (char, nstates);
   shiftset = bitset_create (ntokens, BITSET_FIXED);
   lookaheadset = bitset_create (ntokens, BITSET_FIXED);
+  obstack_init (&solved_conflicts_obstack);
 
   for (i = 0; i < nstates; i++)
     set_conflicts (states[i]);
@@ -393,9 +471,10 @@ conflicts_print (void)
 
 
 void
-free_conflicts (void)
+conflicts_free (void)
 {
   XFREE (conflicts);
   bitset_free (shiftset);
   bitset_free (lookaheadset);
+  obstack_free (&solved_conflicts_obstack, NULL);
 }
