@@ -159,7 +159,7 @@ free_merger_functions (void)
 `-------------------------------------------------------------------*/
 
 /* The (currently) last symbol of GRAMMAR. */
-symbol_list *grammar_end = NULL;
+static symbol_list *grammar_end = NULL;
 
 /* Append SYM to the grammar.  */
 void
@@ -179,7 +179,7 @@ grammar_symbol_append (symbol *sym, location loc)
    CURRENT_RULE points to the first LHS of the current rule, while
    PREVIOUS_RULE_END points to the *end* of the previous rule (NULL).  */
 symbol_list *current_rule = NULL;
-symbol_list *previous_rule_end = NULL;
+static symbol_list *previous_rule_end = NULL;
 
 
 /*----------------------------------------------.
