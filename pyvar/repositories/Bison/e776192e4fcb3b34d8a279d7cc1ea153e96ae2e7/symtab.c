@@ -175,7 +175,7 @@ symbol_precedence_set (symbol_t *symbol, location_t location,
     }
 
   /* Only terminals have a precedence. */
-  symbol_class_set (symbol, token_sym);
+  symbol_class_set (symbol, token_sym, location);
 }
 
 
@@ -184,10 +184,10 @@ symbol_precedence_set (symbol_t *symbol, location_t location,
 `-------------------------------------*/
 
 void
-symbol_class_set (symbol_t *symbol, symbol_class class)
+symbol_class_set (symbol_t *symbol, symbol_class class, location_t location)
 {
   if (symbol->class != unknown_sym && symbol->class != class)
-    complain (_("symbol %s redefined"), symbol_tag_get (symbol));
+    complain_at (location, _("symbol %s redefined"), symbol_tag_get (symbol));
 
   if (class == nterm_sym && symbol->class != nterm_sym)
     symbol->number = nvars++;
@@ -203,14 +203,15 @@ symbol_class_set (symbol_t *symbol, symbol_class class)
 `-------------------------------------------------*/
 
 void
-symbol_user_token_number_set (symbol_t *symbol, int user_token_number)
+symbol_user_token_number_set (symbol_t *symbol,
+			      int user_token_number, location_t location)
 {
   assert (symbol->class == token_sym);
 
   if (symbol->user_token_number != USER_NUMBER_UNDEFINED
       && symbol->user_token_number != user_token_number)
-    complain (_("redefining user token number of %s"),
-	      symbol_tag_get (symbol));
+    complain_at (location, _("redefining user token number of %s"),
+		 symbol_tag_get (symbol));
 
   symbol->user_token_number = user_token_number;
   /* User defined EOF token? */
