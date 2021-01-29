@@ -583,6 +583,9 @@ generate_states (void)
 
   while (this_state)
     {
+      if (trace_flag)
+	fprintf (stderr, "Processing state %d (reached by %s)\n",
+		 this_state->number, tags[this_state->accessing_symbol]);
       /* Set up ruleset and itemset for the transitions out of this
          state.  ruleset gets a 1 bit for each rule that could reduce
          now.  itemset gets a vector of all the items that could be
