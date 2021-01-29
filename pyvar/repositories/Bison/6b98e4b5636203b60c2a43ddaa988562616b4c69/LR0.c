@@ -191,8 +191,7 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 
   if (trace_flag)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
-	     nstates, symbol, quotearg_style (escape_quoting_style,
-					      symbols[symbol]->tag));
+	     nstates, symbol, symbol_tag_get (symbols[symbol]));
 
   if (nstates >= SHRT_MAX)
     fatal (_("too many states (max %d)"), SHRT_MAX);
@@ -237,8 +236,8 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 
   if (trace_flag)
     fprintf (stderr, "Entering get_state, state = %d, symbol = %d (%s)\n",
-	     this_state->number, symbol, quotearg_style (escape_quoting_style,
-					      symbols[symbol]->tag));
+	     this_state->number, symbol,
+	     symbol_tag_get (symbols[symbol]));
 
   /* Add up the target state's active item numbers to get a hash key.
      */
@@ -424,8 +423,7 @@ generate_states (void)
       if (trace_flag)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
 		 this_state->number,
-		 quotearg_style (escape_quoting_style,
-				 symbols[this_state->accessing_symbol]->tag));
+		 symbol_tag_get (symbols[this_state->accessing_symbol]));
       /* Set up ruleset and itemset for the transitions out of this
          state.  ruleset gets a 1 bit for each rule that could reduce
          now.  itemset gets a vector of all the items that could be
