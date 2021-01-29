@@ -166,9 +166,9 @@ symbol_free (void *ptr)
 /* If needed, swap first and second so that first has the earliest
    location (according to location_cmp).
 
-   Many symbol features (e.g., user token numbers) are not assigned
-   during the parsing, but in a second step, via a traversal of the
-   symbol table sorted on tag.
+   Many symbol features (e.g., token codes) are not assigned during
+   parsing, but in a second step, via a traversal of the symbol table
+   sorted on tag.
 
    However, error messages make more sense if we keep the first
    declaration first.
@@ -576,13 +576,13 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
   int *user_token_numberp = &sym->content->user_token_number;
   if (sym->content->class != token_sym)
     complain (&loc, complaint,
-              _("nonterminals cannot be given an explicit number"));
+              _("nonterminals cannot be given a token code"));
   else if (*user_token_numberp != USER_NUMBER_UNDEFINED
            && *user_token_numberp != user_token_number)
-    complain (&loc, complaint, _("redefining user token number of %s"),
+    complain (&loc, complaint, _("redefining code of token %s"),
               sym->tag);
   else if (user_token_number == INT_MAX)
-    complain (&loc, complaint, _("user token number of %s too large"),
+    complain (&loc, complaint, _("code of token %s too large"),
               sym->tag);
   else
     {
@@ -739,7 +739,7 @@ complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
 {
   symbols_sort (&first, &second);
   complain (&second->location, complaint,
-            _("user token number %d redeclaration for %s"),
+            _("code %d reassigned to token %s"),
             num, second->tag);
   subcomplain (&first->location, complaint,
                _("previous declaration for %s"),
@@ -1044,8 +1044,8 @@ symbols_token_translations_init (void)
 {
   bool num_256_available_p = true;
 
-  /* Find the highest user token number, and whether 256, the POSIX
-     preferred user token number for the error token, is used.  */
+  /* Find the highest token code, and whether 256, the POSIX preferred
+     token code for the error token, is used.  */
   max_user_token_number = 0;
   for (int i = 0; i < ntokens; ++i)
     {
