@@ -29,7 +29,6 @@
 #include "reader.h"
 #include "LR0.h"
 
-errs **err_table = NULL;
 /* -1 stands for not specified. */
 int expected_conflicts = -1;
 static char *conflicts = NULL;
@@ -57,7 +56,7 @@ Conflict in state %d between rule %d and token %s resolved as %s.\n"),
 static void
 flush_shift (int state, int token)
 {
-  shifts *shiftp = state_table[state].shift_table;
+  shifts *shiftp = state_table[state].shifts;
   int i;
 
   for (i = 0; i < shiftp->nshifts; i++)
@@ -83,79 +82,73 @@ resolve_sr_conflict (int state, int lookaheadnum)
   short *errtokens = errp->errs;
 
   for (i = 0; i < ntokens; i++)
-    {
-      if (BITISSET (LA (lookaheadnum), i)
-	  && BITISSET (lookaheadset, i)
-	  && sprec[i])
-	/* Shift-reduce conflict occurs for token number i
-	   and it has a precedence.
-	   The precedence of shifting is that of token i.  */
-	{
-	  if (sprec[i] < redprec)
-	    {
-	      log_resolution (state, lookaheadnum, i, _("reduce"));
-	      /* flush the shift for this token */
-	      RESETBIT (lookaheadset, i);
-	      flush_shift (state, i);
-	    }
-	  else if (sprec[i] > redprec)
-	    {
-	      log_resolution (state, lookaheadnum, i, _("shift"));
-	      /* flush the reduce for this token */
-	      RESETBIT (LA (lookaheadnum), i);
-	    }
-	  else
-	    {
-	      /* Matching precedence levels.
-	         For left association, keep only the reduction.
-	         For right association, keep only the shift.
-	         For nonassociation, keep neither.  */
+    if (BITISSET (LA (lookaheadnum), i)
+	&& BITISSET (lookaheadset, i)
+	&& sprec[i])
+      /* Shift-reduce conflict occurs for token number i
+	 and it has a precedence.
+	 The precedence of shifting is that of token i.  */
+      {
+	if (sprec[i] < redprec)
+	  {
+	    log_resolution (state, lookaheadnum, i, _("reduce"));
+	    /* flush the shift for this token */
+	    RESETBIT (lookaheadset, i);
+	    flush_shift (state, i);
+	  }
+	else if (sprec[i] > redprec)
+	  {
+	    log_resolution (state, lookaheadnum, i, _("shift"));
+	    /* flush the reduce for this token */
+	    RESETBIT (LA (lookaheadnum), i);
+	  }
+	else
+	  {
+	    /* Matching precedence levels.
+	       For left association, keep only the reduction.
+	       For right association, keep only the shift.
+	       For nonassociation, keep neither.  */
 
-	      switch (sassoc[i])
-		{
-		case right_assoc:
-		  log_resolution (state, lookaheadnum, i, _("shift"));
-		  break;
+	    switch (sassoc[i])
+	      {
+	      case right_assoc:
+		log_resolution (state, lookaheadnum, i, _("shift"));
+		break;
 
-		case left_assoc:
-		  log_resolution (state, lookaheadnum, i, _("reduce"));
-		  break;
+	      case left_assoc:
+		log_resolution (state, lookaheadnum, i, _("reduce"));
+		break;
 
-		case non_assoc:
-		  log_resolution (state, lookaheadnum, i, _("an error"));
-		  break;
-		}
+	      case non_assoc:
+		log_resolution (state, lookaheadnum, i, _("an error"));
+		break;
+	      }
+
+	    if (sassoc[i] != right_assoc)
+	      {
+		/* flush the shift for this token */
+		RESETBIT (lookaheadset, i);
+		flush_shift (state, i);
+	      }
+	    if (sassoc[i] != left_assoc)
+	      {
+		/* flush the reduce for this token */
+		RESETBIT (LA (lookaheadnum), i);
+	      }
+	    if (sassoc[i] == non_assoc)
+	      {
+		/* Record an explicit error for this token.  */
+		*errtokens++ = i;
+	      }
+	  }
+      }
 
-	      if (sassoc[i] != right_assoc)
-		{
-		  /* flush the shift for this token */
-		  RESETBIT (lookaheadset, i);
-		  flush_shift (state, i);
-		}
-	      if (sassoc[i] != left_assoc)
-		{
-		  /* flush the reduce for this token */
-		  RESETBIT (LA (lookaheadnum), i);
-		}
-	      if (sassoc[i] == non_assoc)
-		{
-		  /* Record an explicit error for this token.  */
-		  *errtokens++ = i;
-		}
-	    }
-	}
-    }
   errp->nerrs = errtokens - errp->errs;
-  if (errp->nerrs)
-    {
-      /* Some tokens have been explicitly made errors.  Allocate
-         a permanent errs structure for this state, to record them.  */
-      i = (char *) errtokens - (char *) errp;
-      err_table[state] = ERRS_ALLOC (i + 1);
-      bcopy (errp, err_table[state], i);
-    }
-  else
-    err_table[state] = 0;
+  /* Some tokens have been explicitly made errors.  Allocate a
+     permanent errs structure for this state, to record them.  */
+  i = (char *) errtokens - (char *) errp;
+  state_table[state].errs = ERRS_ALLOC (i + 1);
+  memcpy (state_table[state].errs, errp, i);
   free (errp);
 }
 
@@ -172,7 +165,7 @@ set_conflicts (int state)
   for (i = 0; i < tokensetsize; i++)
     lookaheadset[i] = 0;
 
-  shiftp = state_table[state].shift_table;
+  shiftp = state_table[state].shifts;
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
@@ -216,8 +209,6 @@ solve_conflicts (void)
   shiftset = XCALLOC (unsigned, tokensetsize);
   lookaheadset = XCALLOC (unsigned, tokensetsize);
 
-  err_table = XCALLOC (errs *, nstates);
-
   for (i = 0; i < nstates; i++)
     set_conflicts (i);
 }
@@ -232,7 +223,7 @@ count_sr_conflicts (int state)
 {
   int i, k;
   int src_count = 0;
-  shifts *shiftp = state_table[state].shift_table;
+  shifts *shiftp = state_table[state].shifts;
 
   if (!shiftp)
     return 0;
@@ -433,7 +424,7 @@ print_reductions (FILE *out, int state)
   for (i = 0; i < tokensetsize; i++)
     shiftset[i] = 0;
 
-  shiftp = state_table[state].shift_table;
+  shiftp = state_table[state].shifts;
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
@@ -444,7 +435,7 @@ print_reductions (FILE *out, int state)
 	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
       }
 
-  errp = err_table[state];
+  errp = state_table[state].errs;
   if (errp)
     for (i = 0; i < errp->nerrs; i++)
       if (errp->errs[i])
