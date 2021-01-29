@@ -131,29 +131,29 @@ resolve_sr_conflict (int state, int lookaheadnum)
 
 	      switch (sassoc[i])
 		{
-		case RIGHT_ASSOC:
+		case right_assoc:
 		  log_resolution (state, lookaheadnum, i, _("shift"));
 		  break;
 
-		case LEFT_ASSOC:
+		case left_assoc:
 		  log_resolution (state, lookaheadnum, i, _("reduce"));
 		  break;
 
-		case NON_ASSOC:
+		case non_assoc:
 		  log_resolution (state, lookaheadnum, i, _("an error"));
 		  break;
 		}
 
-	      if (sassoc[i] != RIGHT_ASSOC)
+	      if (sassoc[i] != right_assoc)
 		{
 		  *fp2 &= ~mask;	/* flush the shift for this token */
 		  flush_shift (state, i);
 		}
-	      if (sassoc[i] != LEFT_ASSOC)
+	      if (sassoc[i] != left_assoc)
 		{
 		  *fp1 &= ~mask;	/* flush the reduce for this token */
 		}
-	      if (sassoc[i] == NON_ASSOC)
+	      if (sassoc[i] == non_assoc)
 		{
 		  /* Record an explicit error for this token.  */
 		  *errtokens++ = i;
