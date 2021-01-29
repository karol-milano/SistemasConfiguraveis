@@ -77,7 +77,7 @@ initialize_LA (void)
   np = LArule;
   for (i = 0; i < nstates; i++)
     if (!states[i]->consistent)
-      for (j = 0; j < states[i]->reductions->nreds; j++)
+      for (j = 0; j < states[i]->reductions->num; j++)
 	*np++ = &rules[states[i]->reductions->rules[j]];
 }
 
@@ -366,9 +366,9 @@ states_lookaheads_count (void)
 	 reductions (i.e., there are two or more), or to distinguish a
 	 reduction from a shift.  Otherwise, it is straightforward,
 	 and the state is `consistent'.  */
-      if (rp->nreds > 1
-	  || (rp->nreds == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0)))
-	nlookaheads += rp->nreds;
+      if (rp->num > 1
+	  || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0)))
+	nlookaheads += rp->num;
       else
 	states[i]->consistent = 1;
 
