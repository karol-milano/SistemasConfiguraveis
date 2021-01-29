@@ -137,7 +137,6 @@ initialize_LA (void)
   int i;
   int j;
   short *np;
-  reductions *rp;
 
   /* Avoid having to special case 0.  */
   if (!nLA)
@@ -150,9 +149,8 @@ initialize_LA (void)
   np = LAruleno;
   for (i = 0; i < nstates; i++)
     if (!state_table[i]->consistent)
-      if ((rp = state_table[i]->reductions))
-	for (j = 0; j < rp->nreds; j++)
-	  *np++ = rp->rules[j];
+      for (j = 0; j < state_table[i]->reductions->nreds; j++)
+	*np++ = state_table[i]->reductions->rules[j];
 }
 
 
@@ -525,8 +523,12 @@ initialize_lookaheads (void)
       reductions *rp = state_table[i]->reductions;
       shifts *sp = state_table[i]->shifts;
 
-      if (rp
-	  && (rp->nreds > 1 || (sp->nshifts && SHIFT_IS_SHIFT (sp, 0))))
+      /* We need a lookahead either to distinguish different
+	 reductions (i.e., there are two or more), or to distinguish a
+	 reduction from a shift.  Otherwise, it is straightforward,
+	 and the state is `consistent'.  */
+      if (rp->nreds > 1
+	  || (rp->nreds == 1 && sp->nshifts && SHIFT_IS_SHIFT (sp, 0)))
 	nlookaheads += rp->nreds;
       else
 	state_table[i]->consistent = 1;
