@@ -90,7 +90,7 @@ resolve_sr_conflict (int state, int lookaheadnum)
   unsigned *fp1;
   unsigned *fp2;
   int redprec;
-  errs *errp = (errs *) xcalloc (sizeof (errs) + ntokens * sizeof (short), 1);
+  errs *errp = ERRS_ALLOC (ntokens + 1);
   short *errtokens = errp->errs;
 
   /* find the rule to reduce by to get precedence of reduction  */
@@ -170,7 +170,7 @@ resolve_sr_conflict (int state, int lookaheadnum)
       /* Some tokens have been explicitly made errors.  Allocate
          a permanent errs structure for this state, to record them.  */
       i = (char *) errtokens - (char *) errp;
-      err_table[state] = (errs *) xcalloc ((unsigned int) i, 1);
+      err_table[state] = ERRS_ALLOC (i + 1);
       bcopy (errp, err_table[state], i);
     }
   else
