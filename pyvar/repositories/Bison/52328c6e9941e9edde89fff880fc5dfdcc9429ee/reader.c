@@ -181,7 +181,7 @@ free_merger_functions (void)
 /* The (currently) last symbol of GRAMMAR. */
 symbol_list *grammar_end = NULL;
 
-/* Append S to the GRAMMAR. */
+/* Append SYM to the grammar.  */
 void
 grammar_symbol_append (symbol *sym, location loc)
 {
