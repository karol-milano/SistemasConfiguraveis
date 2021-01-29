@@ -287,13 +287,19 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 void
 symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
+  int *user_token_numberp;
+
   assert (sym->class == token_sym);
 
-  if (sym->user_token_number != USER_NUMBER_UNDEFINED
-      && sym->user_token_number != user_token_number)
+  if (sym->user_token_number != USER_NUMBER_ALIAS)
+    user_token_numberp = &sym->user_token_number;
+  else
+    user_token_numberp = &sym->alias->user_token_number;
+  if (*user_token_numberp != USER_NUMBER_UNDEFINED
+      && *user_token_numberp != user_token_number)
     complain_at (loc, _("redefining user token number of %s"), sym->tag);
 
-  sym->user_token_number = user_token_number;
+  *user_token_numberp = user_token_number;
   /* User defined $end token? */
   if (user_token_number == 0)
     {
