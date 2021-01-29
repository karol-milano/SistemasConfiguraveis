@@ -51,12 +51,9 @@ bool union_seen = false;
 /* Should rules have a default precedence?  */
 bool default_prec = true;
 
-/*-----------------------.
-| Set the start symbol.  |
-`-----------------------*/
 
 void
-grammar_start_symbols_set (symbol_list *syms)
+grammar_start_symbols_add (symbol_list *syms)
 {
   start_symbols = symbol_list_append (start_symbols, syms);
 }
