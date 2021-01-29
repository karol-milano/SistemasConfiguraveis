@@ -57,21 +57,13 @@ Conflict in state %d between rule %d and token %s resolved as %s.\n"),
 static void
 flush_shift (int state, int token)
 {
-  shifts *shiftp;
-  int k, i;
-
-  shiftp = state_table[state].shift_table;
+  shifts *shiftp = state_table[state].shift_table;
+  int i;
 
   if (shiftp)
-    {
-      k = shiftp->nshifts;
-      for (i = 0; i < k; i++)
-	{
-	  if (shiftp->shifts[i]
-	      && token == state_table[shiftp->shifts[i]].accessing_symbol)
-	    (shiftp->shifts[i]) = 0;
-	}
-    }
+    for (i = 0; i < shiftp->nshifts; i++)
+      if (shiftp->shifts[i] && SHIFT_SYMBOL (shiftp, i) == token)
+	shiftp->shifts[i] = 0;
 }
 
 
@@ -86,22 +78,16 @@ static void
 resolve_sr_conflict (int state, int lookaheadnum)
 {
   int i;
-  int mask;
-  unsigned *fp1;
-  unsigned *fp2;
-  int redprec;
+  /* find the rule to reduce by to get precedence of reduction  */
+  int redprec = rule_table[LAruleno[lookaheadnum]].prec;
   errs *errp = ERRS_ALLOC (ntokens + 1);
   short *errtokens = errp->errs;
 
-  /* find the rule to reduce by to get precedence of reduction  */
-  redprec = rule_table[LAruleno[lookaheadnum]].prec;
-
-  mask = 1;
-  fp1 = LA (lookaheadnum);
-  fp2 = lookaheadset;
   for (i = 0; i < ntokens; i++)
     {
-      if ((mask & *fp2 & *fp1) && sprec[i])
+      if (BITISSET (LA (lookaheadnum), i)
+	  && BITISSET (lookaheadset, i)
+	  && sprec[i])
 	/* Shift-reduce conflict occurs for token number i
 	   and it has a precedence.
 	   The precedence of shifting is that of token i.  */
@@ -109,13 +95,15 @@ resolve_sr_conflict (int state, int lookaheadnum)
 	  if (sprec[i] < redprec)
 	    {
 	      log_resolution (state, lookaheadnum, i, _("reduce"));
-	      *fp2 &= ~mask;	/* flush the shift for this token */
+	      /* flush the shift for this token */
+	      RESETBIT (lookaheadset, i);
 	      flush_shift (state, i);
 	    }
 	  else if (sprec[i] > redprec)
 	    {
 	      log_resolution (state, lookaheadnum, i, _("shift"));
-	      *fp1 &= ~mask;	/* flush the reduce for this token */
+	      /* flush the reduce for this token */
+	      RESETBIT (LA (lookaheadnum), i);
 	    }
 	  else
 	    {
@@ -141,12 +129,14 @@ resolve_sr_conflict (int state, int lookaheadnum)
 
 	      if (sassoc[i] != right_assoc)
 		{
-		  *fp2 &= ~mask;	/* flush the shift for this token */
+		  /* flush the shift for this token */
+		  RESETBIT (lookaheadset, i);
 		  flush_shift (state, i);
 		}
 	      if (sassoc[i] != left_assoc)
 		{
-		  *fp1 &= ~mask;	/* flush the reduce for this token */
+		  /* flush the reduce for this token */
+		  RESETBIT (LA (lookaheadnum), i);
 		}
 	      if (sassoc[i] == non_assoc)
 		{
@@ -155,14 +145,6 @@ resolve_sr_conflict (int state, int lookaheadnum)
 		}
 	    }
 	}
-
-      mask <<= 1;
-      if (mask == 0)
-	{
-	  mask = 1;
-	  fp2++;
-	  fp1++;
-	}
     }
   errp->nerrs = errtokens - errp->errs;
   if (errp->nerrs)
