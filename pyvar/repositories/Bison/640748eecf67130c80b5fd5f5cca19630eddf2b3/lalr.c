@@ -86,7 +86,7 @@ initialize_LA (void)
   for (i = 0; i < nstates; i++)
     if (!states[i]->consistent)
       for (j = 0; j < states[i]->reductions->num; j++)
-	*np++ = &rules[states[i]->reductions->rules[j]];
+	*np++ = states[i]->reductions->rules[j];
 }
 
 
@@ -141,7 +141,7 @@ set_goto_map (void)
 	{
 	  int k = temp_map[TRANSITION_SYMBOL (sp, i)]++;
 	  from_state[k] = state;
-	  to_state[k] = sp->states[i];
+	  to_state[k] = sp->states[i]->number;
 	}
     }
 
@@ -200,7 +200,7 @@ initialize_F (void)
       transitions_t *sp = states[stateno]->transitions;
 
       int j;
-      for (j = 0; j < sp->num && TRANSITION_IS_SHIFT (sp, j); j++)
+      FOR_EACH_SHIFT (sp, j)
 	bitset_set (F[i], TRANSITION_SYMBOL (sp, j));
 
       for (; j < sp->num; j++)
@@ -375,13 +375,14 @@ states_lookaheads_count (void)
 	 reduction from a shift.  Otherwise, it is straightforward,
 	 and the state is `consistent'.  */
       if (rp->num > 1
-	  || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0)))
+	  || (rp->num == 1 && sp->num &&
+	      !TRANSITION_IS_DISABLED (sp, 0) && TRANSITION_IS_SHIFT (sp, 0)))
 	nlookaheads += rp->num;
       else
 	states[i]->consistent = 1;
 
       for (k = 0; k < sp->num; k++)
-	if (TRANSITION_IS_ERROR (sp, k))
+	if (!TRANSITION_IS_DISABLED (sp, k) && TRANSITION_IS_ERROR (sp, k))
 	  {
 	    states[i]->consistent = 0;
 	    break;
