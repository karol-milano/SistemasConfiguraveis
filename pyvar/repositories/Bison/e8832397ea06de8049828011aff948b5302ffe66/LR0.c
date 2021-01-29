@@ -282,11 +282,6 @@ save_reductions (state_t *state)
   int count = 0;
   int i;
 
-  /* If this is the final state, we want it to have no reductions at
-     all, although it has one for `START_SYMBOL $end .'.  */
-  if (final_state && state->number == final_state->number)
-    return;
-
   /* Find and count the active items that represent ends of rules. */
   for (i = 0; i < nritemset; ++i)
     {
