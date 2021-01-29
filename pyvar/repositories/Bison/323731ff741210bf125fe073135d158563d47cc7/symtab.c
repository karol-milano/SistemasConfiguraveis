@@ -704,13 +704,13 @@ symbol_make_alias (symbol *sym, symbol *str, location loc)
 `-------------------------------------------------------------------*/
 
 static void
-symbol_pack (symbol *this)
+symbol_pack (symbol *sym)
 {
-  aver (this->content->number != NUMBER_UNDEFINED);
-  if (this->content->class == nterm_sym)
-    this->content->number += ntokens;
+  aver (sym->content->number != NUMBER_UNDEFINED);
+  if (sym->content->class == nterm_sym)
+    sym->content->number += ntokens;
 
-  symbols[this->content->number] = this->content->symbol;
+  symbols[sym->content->number] = sym->content->symbol;
 }
 
 static void
@@ -725,26 +725,26 @@ complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
                first->tag);
 }
 
-/*--------------------------------------------------.
-| Put THIS in TOKEN_TRANSLATIONS if it is a token.  |
-`--------------------------------------------------*/
+/*-------------------------------------------------.
+| Put SYM in TOKEN_TRANSLATIONS if it is a token.  |
+`-------------------------------------------------*/
 
 static void
-symbol_translation (symbol *this)
+symbol_translation (symbol *sym)
 {
   /* Nonterminal? */
-  if (this->content->class == token_sym
-      && !this->is_alias)
+  if (sym->content->class == token_sym
+      && !sym->is_alias)
     {
       /* A token which translation has already been set?*/
-      if (token_translations[this->content->user_token_number]
+      if (token_translations[sym->content->user_token_number]
           != undeftoken->content->number)
         complain_user_token_number_redeclared
-          (this->content->user_token_number,
-           symbols[token_translations[this->content->user_token_number]], this);
+          (sym->content->user_token_number,
+           symbols[token_translations[sym->content->user_token_number]], sym);
       else
-        token_translations[this->content->user_token_number]
-          = this->content->number;
+        token_translations[sym->content->user_token_number]
+          = sym->content->number;
     }
 }
 
@@ -1018,12 +1018,12 @@ symbols_token_translations_init (void)
   max_user_token_number = 0;
   for (int i = 0; i < ntokens; ++i)
     {
-      sym_content *this = symbols[i]->content;
-      if (this->user_token_number != USER_NUMBER_UNDEFINED)
+      sym_content *sym = symbols[i]->content;
+      if (sym->user_token_number != USER_NUMBER_UNDEFINED)
         {
-          if (this->user_token_number > max_user_token_number)
-            max_user_token_number = this->user_token_number;
-          if (this->user_token_number == 256)
+          if (sym->user_token_number > max_user_token_number)
+            max_user_token_number = sym->user_token_number;
+          if (sym->user_token_number == 256)
             num_256_available_p = false;
         }
     }
@@ -1039,17 +1039,17 @@ symbols_token_translations_init (void)
 
   for (int i = 0; i < ntokens; ++i)
     {
-      sym_content *this = symbols[i]->content;
-      if (this->user_token_number == USER_NUMBER_UNDEFINED)
+      sym_content *sym = symbols[i]->content;
+      if (sym->user_token_number == USER_NUMBER_UNDEFINED)
         {
           IGNORE_TYPE_LIMITS_BEGIN
           if (INT_ADD_WRAPV (max_user_token_number, 1, &max_user_token_number))
             complain (NULL, fatal, _("token number too large"));
           IGNORE_TYPE_LIMITS_END
-          this->user_token_number = max_user_token_number;
+          sym->user_token_number = max_user_token_number;
         }
-      if (this->user_token_number > max_user_token_number)
-        max_user_token_number = this->user_token_number;
+      if (sym->user_token_number > max_user_token_number)
+        max_user_token_number = sym->user_token_number;
     }
 
   token_translations = xnmalloc (max_user_token_number + 1,
