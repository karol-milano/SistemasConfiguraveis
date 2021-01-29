@@ -93,8 +93,8 @@ resolve_sr_conflict (state_t *state, int lookahead)
   int i;
   /* find the rule to reduce by to get precedence of reduction  */
   int redprec = rule_table[LAruleno[lookahead]].prec;
-  errs *errp = ERRS_ALLOC (ntokens + 1);
-  short *errtokens = errp->errs;
+  errs *errp = errs_new (ntokens + 1);
+  errp->nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
     if (BITISSET (LA (lookahead), i)
@@ -137,17 +137,14 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	      flush_shift (state, i);
 	      flush_reduce (lookahead, i);
 	      /* Record an explicit error for this token.  */
-	      *errtokens++ = i;
+	      errp->errs[errp->nerrs++] = i;
 	      break;
 	    }
       }
 
-  errp->nerrs = errtokens - errp->errs;
   /* Some tokens have been explicitly made errors.  Allocate a
      permanent errs structure for this state, to record them.  */
-  i = (char *) errtokens - (char *) errp;
-  state->errs = ERRS_ALLOC (i + 1);
-  memcpy (state->errs, errp, i);
+  state->errs = errs_dup (errp);
   free (errp);
 }
 
