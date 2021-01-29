@@ -559,8 +559,8 @@ states_lookaheads_initialize (void)
   bitsetv pLA = LA;
   rule_t **pLArule = LArule;
 
-  /* Count the number of lookaheads required for each state
-     (NLOOKAHEADS member).  */
+  /* Initialize the members LOOKAHEADS and LOOKAHEADS_RULE for each
+     state.  */
   for (i = 0; i < nstates; i++)
     {
       states[i]->lookaheads = pLA;
