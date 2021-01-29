@@ -59,7 +59,7 @@ static semantic_type **semantic_types_sorted = NULL;
 symbol *errtoken = NULL;
 symbol *undeftoken = NULL;
 symbol *eoftoken = NULL;
-symbol *accept = NULL;
+symbol *acceptsymbol = NULL;
 symbol *startsymbol = NULL;
 location startsymbol_loc;
 
@@ -849,10 +849,10 @@ symbols_new (void)
                                    hash_symbol_comparator,
                                    symbol_free);
 
-  /* Construct the accept symbol. */
-  accept = symbol_get ("$accept", empty_loc);
-  accept->content->class = nterm_sym;
-  accept->content->number = nnterms++;
+  /* Construct the acceptsymbol symbol. */
+  acceptsymbol = symbol_get ("$accept", empty_loc);
+  acceptsymbol->content->class = nterm_sym;
+  acceptsymbol->content->number = nnterms++;
 
   /* Construct the YYerror/"error" token */
   errtoken = symbol_get ("YYerror", empty_loc);
