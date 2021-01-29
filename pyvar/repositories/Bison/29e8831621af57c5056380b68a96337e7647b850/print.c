@@ -122,7 +122,7 @@ print_shifts (FILE *out, state_t *state)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
-	int symbol = state_table[state1]->accessing_symbol;
+	int symbol = states[state1]->accessing_symbol;
 	fprintf (out,
 		 _("    %-4s\tshift, and go to state %d\n"),
 		 escape (symbols[symbol]->tag), state1);
@@ -164,7 +164,7 @@ print_gotos (FILE *out, state_t *state)
 	if (!SHIFT_IS_DISABLED (shiftp, i))
 	  {
 	    int state1 = shiftp->shifts[i];
-	    int symbol = state_table[state1]->accessing_symbol;
+	    int symbol = states[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
 		     escape (symbols[symbol]->tag), state1);
 	  }
@@ -501,7 +501,7 @@ print_results (void)
   shiftset = XCALLOC (unsigned, tokensetsize);
   lookaheadset = XCALLOC (unsigned, tokensetsize);
   for (i = 0; i < nstates; i++)
-    print_state (out, state_table[i]);
+    print_state (out, states[i]);
   free (shiftset);
   free (lookaheadset);
   if (trace_flag)
