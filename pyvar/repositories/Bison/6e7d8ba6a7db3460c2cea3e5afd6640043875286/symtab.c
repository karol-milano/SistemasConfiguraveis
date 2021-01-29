@@ -805,6 +805,23 @@ symbols_new (void)
                                    hash_symbol_hasher,
                                    hash_symbol_comparator,
                                    symbol_free);
+
+  /* Construct the accept symbol. */
+  accept = symbol_get ("$accept", empty_loc);
+  accept->content->class = nterm_sym;
+  accept->content->number = nvars++;
+
+  /* Construct the error token */
+  errtoken = symbol_get ("error", empty_loc);
+  errtoken->content->class = token_sym;
+  errtoken->content->number = ntokens++;
+
+  /* Construct a token that represents all undefined literal tokens.
+     It is always token number 2.  */
+  undeftoken = symbol_get ("$undefined", empty_loc);
+  undeftoken->content->class = token_sym;
+  undeftoken->content->number = ntokens++;
+
   semantic_type_table = hash_xinitialize (HT_INITIAL_CAPACITY,
                                           NULL,
                                           hash_semantic_type_hasher,
