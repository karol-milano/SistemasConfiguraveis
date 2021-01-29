@@ -188,7 +188,7 @@ new_state (int symbol)
 
   if (trace_flag)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
-	     this_state->number, symbol, tags[symbol]);
+	     this_state->number, symbol, symbols[symbol]->tag);
 
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
@@ -227,7 +227,7 @@ get_state (int symbol)
 
   if (trace_flag)
     fprintf (stderr, "Entering get_state, state = %d, symbol = %d (%s)\n",
-	     this_state->number, symbol, tags[symbol]);
+	     this_state->number, symbol, symbols[symbol]->tag);
 
   /* Add up the target state's active item numbers to get a hash key.
      */
@@ -406,7 +406,8 @@ generate_states (void)
     {
       if (trace_flag)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
-		 this_state->number, tags[this_state->accessing_symbol]);
+		 this_state->number,
+		 symbols[this_state->accessing_symbol]->tag);
       /* Set up ruleset and itemset for the transitions out of this
          state.  ruleset gets a 1 bit for each rule that could reduce
          now.  itemset gets a vector of all the items that could be
