@@ -365,14 +365,14 @@ save_reductions (void)
 
 
 /*--------------------.
-| Build STATE_TABLE.  |
+| Build STATES.  |
 `--------------------*/
 
 static void
-set_state_table (void)
+set_states (void)
 {
   state_t *sp;
-  state_table = XCALLOC (state_t *, nstates);
+  states = XCALLOC (state_t *, nstates);
 
   for (sp = first_state; sp; sp = sp->next)
     {
@@ -386,7 +386,7 @@ set_state_table (void)
       if (!sp->reductions)
 	sp->reductions = reductions_new (0);
 
-      state_table[sp->number] = sp;
+      states[sp->number] = sp;
     }
 }
 
@@ -432,6 +432,6 @@ generate_states (void)
   free_closure ();
   free_storage ();
 
-  /* Set up STATE_TABLE. */
-  set_state_table ();
+  /* Set up STATES. */
+  set_states ();
 }
