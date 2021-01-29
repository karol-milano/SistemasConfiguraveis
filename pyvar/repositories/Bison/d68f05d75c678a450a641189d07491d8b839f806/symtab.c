@@ -478,7 +478,7 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
   int *user_token_numberp = &sym->content->user_token_number;
   if (sym->content->class != token_sym)
     complain (&loc, complaint,
-              _("non-terminals cannot be given an explicit number"));
+              _("nonterminals cannot be given an explicit number"));
   else if (*user_token_numberp != USER_NUMBER_UNDEFINED
            && *user_token_numberp != user_token_number)
     complain (&loc, complaint, _("redefining user token number of %s"),
@@ -614,7 +614,7 @@ symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
   if (sym->content->class != token_sym)
     complain (&loc, complaint,
-              _("non-terminals cannot be given a string alias"));
+              _("nonterminals cannot be given a string alias"));
   else if (str->alias)
     complain (&loc, Wother,
               _("symbol %s used more than once as a literal string"), str->tag);
@@ -677,7 +677,7 @@ complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
 static inline bool
 symbol_translation (symbol *this)
 {
-  /* Non-terminal? */
+  /* Nonterminal? */
   if (this->content->class == token_sym
       && !this->is_alias)
     {
