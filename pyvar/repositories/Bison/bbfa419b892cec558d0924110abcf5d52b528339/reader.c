@@ -253,8 +253,8 @@ grammar_current_rule_begin (symbol *lhs, location loc,
 /*----------------------------------------------------------------------.
 | A symbol should be used if either:                                    |
 |   1. It has a destructor.                                             |
-|   2. The symbol is a mid-rule symbol (i.e., the generated LHS         |
-|      replacing a mid-rule action) that was assigned to or used, as in |
+|   2. The symbol is a midrule symbol (i.e., the generated LHS          |
+|      replacing a midrule action) that was assigned to or used, as in  |
 |      "exp: { $$ = 1; } { $$ = $1; }".                                 |
 `----------------------------------------------------------------------*/
 
@@ -373,9 +373,9 @@ grammar_current_rule_end (location loc)
 
 
 /*-------------------------------------------------------------------.
-| The previous action turns out to be a mid-rule action.  Attach it  |
+| The previous action turns out to be a midrule action.  Attach it   |
 | to the current rule, i.e., create a dummy symbol, attach it this   |
-| mid-rule action, and append this dummy nonterminal to the current  |
+| midrule action, and append this dummy nonterminal to the current   |
 | rule.                                                              |
 `-------------------------------------------------------------------*/
 
@@ -512,7 +512,7 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
 }
 
 /* Attach SYM to the current rule.  If needed, move the previous
-   action as a mid-rule action.  */
+   action as a midrule action.  */
 
 void
 grammar_current_rule_symbol_append (symbol *sym, location loc,
