@@ -87,6 +87,50 @@ symbol_precedence_set (symbol_t *symbol,
 }
 
 
+/*-------------------------------------.
+| Set the CLASS associated to SYMBOL.  |
+`-------------------------------------*/
+
+void
+symbol_class_set (symbol_t *symbol, symbol_class class)
+{
+  if (symbol->class != unknown_sym && symbol->class != class)
+    complain (_("symbol %s redefined"), symbol->tag);
+
+  if (class == nterm_sym && symbol->class != nterm_sym)
+    symbol->number = nvars++;
+  else if (class == token_sym && symbol->number == NUMBER_UNDEFINED)
+    symbol->number = ntokens++;
+
+  symbol->class = class;
+}
+
+
+/*-------------------------------------------------.
+| Set the USER_TOKEN_NUMBER associated to SYMBOL.  |
+`-------------------------------------------------*/
+
+void
+symbol_user_token_number_set (symbol_t *symbol, int user_token_number)
+{
+  assert (symbol->class == token_sym);
+
+  if (symbol->user_token_number != USER_NUMBER_UNDEFINED)
+    complain (_("redefining user token number of %s"), symbol->tag);
+
+  symbol->user_token_number = user_token_number;
+  /* User defined EOF token? */
+  if (user_token_number == 0)
+    {
+      eoftoken = symbol;
+      eoftoken->number = 0;
+      /* It is always mapped to 0, so it was already counted in
+	 NTOKENS.  */
+      --ntokens;
+    }
+}
+
+
 /*------------.
 | Free THIS.  |
 `------------*/
