@@ -700,7 +700,8 @@ packgram (void)
   if (trace_flag & trace_sets)
     ritem_print (stderr);
 }
-
+
+
 /*------------------------------------------------------------------.
 | Read in the grammar specification and record it in the format     |
 | described in gram.h.  All actions are copied into ACTION_OBSTACK, |
@@ -711,25 +712,10 @@ packgram (void)
 void
 reader (void)
 {
-  /* Initialize the symbol table.  */
+  /* Set up symbol_table, semantic_type_table, and the built-in
+     symbols.  */
   symbols_new ();
 
-  /* Construct the accept symbol. */
-  accept = symbol_get ("$accept", empty_loc);
-  accept->content->class = nterm_sym;
-  accept->content->number = nvars++;
-
-  /* Construct the error token */
-  errtoken = symbol_get ("error", empty_loc);
-  errtoken->content->class = token_sym;
-  errtoken->content->number = ntokens++;
-
-  /* Construct a token that represents all undefined literal tokens.
-     It is always token number 2.  */
-  undeftoken = symbol_get ("$undefined", empty_loc);
-  undeftoken->content->class = token_sym;
-  undeftoken->content->number = ntokens++;
-
   gram_in = xfopen (grammar_file, "r");
 
   gram__flex_debug = trace_flag & trace_scan;
