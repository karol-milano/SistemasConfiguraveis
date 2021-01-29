@@ -77,7 +77,7 @@ set_goto_map (void)
   for (state_number s = 0; s < nstates; ++s)
     {
       transitions *sp = states[s]->transitions;
-      for (int i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
+      for (int i = sp->num - 1; 0 <= i && TRANSITION_IS_GOTO (sp, i); --i)
         {
           ngotos++;
 
@@ -109,7 +109,7 @@ set_goto_map (void)
   for (state_number s = 0; s < nstates; ++s)
     {
       const transitions *sp = states[s]->transitions;
-      for (int i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
+      for (int i = sp->num - 1; 0 <= i && TRANSITION_IS_GOTO (sp, i); --i)
         {
           goto_number k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
           from_state[k] = s;
