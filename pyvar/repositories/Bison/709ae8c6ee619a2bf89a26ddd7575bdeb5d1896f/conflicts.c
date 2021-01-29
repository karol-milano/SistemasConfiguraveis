@@ -60,12 +60,26 @@ flush_shift (int state, int token)
   shifts *shiftp = state_table[state]->shifts;
   int i;
 
+  RESETBIT (lookaheadset, token);
   for (i = 0; i < shiftp->nshifts; i++)
     if (!SHIFT_IS_DISABLED (shiftp, i) && SHIFT_SYMBOL (shiftp, i) == token)
       SHIFT_DISABLE (shiftp, i);
 }
 
 
+/*-------------------------------------------------------------------.
+| Turn off the reduce recorded for the specified token for the       |
+| specified lookahead.  Used when we resolve a shift-reduce conflict |
+| in favor of the shift.                                             |
+`-------------------------------------------------------------------*/
+
+static void
+flush_reduce (int lookahead, int token)
+{
+  RESETBIT (LA (lookahead), token);
+}
+
+
 /*------------------------------------------------------------------.
 | Attempt to resolve shift-reduce conflict for one rule by means of |
 | precedence declarations.  It has already been checked that the    |
@@ -74,74 +88,58 @@ flush_shift (int state, int token)
 `------------------------------------------------------------------*/
 
 static void
-resolve_sr_conflict (int state, int lookaheadnum)
+resolve_sr_conflict (int state, int lookahead)
 {
   int i;
   /* find the rule to reduce by to get precedence of reduction  */
-  int redprec = rule_table[LAruleno[lookaheadnum]].prec;
+  int redprec = rule_table[LAruleno[lookahead]].prec;
   errs *errp = ERRS_ALLOC (ntokens + 1);
   short *errtokens = errp->errs;
 
   for (i = 0; i < ntokens; i++)
-    if (BITISSET (LA (lookaheadnum), i)
+    if (BITISSET (LA (lookahead), i)
 	&& BITISSET (lookaheadset, i)
 	&& sprec[i])
-      /* Shift-reduce conflict occurs for token number i
-	 and it has a precedence.
-	 The precedence of shifting is that of token i.  */
       {
+	/* Shift-reduce conflict occurs for token number i
+	   and it has a precedence.
+	   The precedence of shifting is that of token i.  */
 	if (sprec[i] < redprec)
 	  {
-	    log_resolution (state, lookaheadnum, i, _("reduce"));
-	    /* flush the shift for this token */
-	    RESETBIT (lookaheadset, i);
+	    log_resolution (state, lookahead, i, _("reduce"));
 	    flush_shift (state, i);
 	  }
 	else if (sprec[i] > redprec)
 	  {
-	    log_resolution (state, lookaheadnum, i, _("shift"));
-	    /* flush the reduce for this token */
-	    RESETBIT (LA (lookaheadnum), i);
+	    log_resolution (state, lookahead, i, _("shift"));
+	    flush_reduce (lookahead, i);
 	  }
 	else
-	  {
-	    /* Matching precedence levels.
-	       For left association, keep only the reduction.
-	       For right association, keep only the shift.
-	       For nonassociation, keep neither.  */
-
-	    switch (sassoc[i])
-	      {
-	      case right_assoc:
-		log_resolution (state, lookaheadnum, i, _("shift"));
-		break;
+	  /* Matching precedence levels.
+	     For left association, keep only the reduction.
+	     For right association, keep only the shift.
+	     For nonassociation, keep neither.  */
 
-	      case left_assoc:
-		log_resolution (state, lookaheadnum, i, _("reduce"));
-		break;
-
-	      case non_assoc:
-		log_resolution (state, lookaheadnum, i, _("an error"));
-		break;
-	      }
-
-	    if (sassoc[i] != right_assoc)
-	      {
-		/* flush the shift for this token */
-		RESETBIT (lookaheadset, i);
-		flush_shift (state, i);
-	      }
-	    if (sassoc[i] != left_assoc)
-	      {
-		/* flush the reduce for this token */
-		RESETBIT (LA (lookaheadnum), i);
-	      }
-	    if (sassoc[i] == non_assoc)
-	      {
-		/* Record an explicit error for this token.  */
-		*errtokens++ = i;
-	      }
-	  }
+	  switch (sassoc[i])
+	    {
+	    case right_assoc:
+	      log_resolution (state, lookahead, i, _("shift"));
+	      flush_reduce (lookahead, i);
+	      break;
+
+	    case left_assoc:
+	      log_resolution (state, lookahead, i, _("reduce"));
+	      flush_shift (state, i);
+	      break;
+
+	    case non_assoc:
+	      log_resolution (state, lookahead, i, _("an error"));
+	      flush_shift (state, i);
+	      flush_reduce (lookahead, i);
+	      /* Record an explicit error for this token.  */
+	      *errtokens++ = i;
+	      break;
+	    }
       }
 
   errp->nerrs = errtokens - errp->errs;
