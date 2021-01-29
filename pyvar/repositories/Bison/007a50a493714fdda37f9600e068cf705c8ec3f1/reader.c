@@ -237,7 +237,7 @@ symbol_translation (symbol_t *this)
       && this->user_token_number != SALIAS)
     {
       /* A token which translation has already been set? */
-      if (token_translations[this->user_token_number] != 2)
+      if (token_translations[this->user_token_number] != undeftoken->number)
 	complain (_("tokens %s and %s both assigned number %d"),
 		  symbols[token_translations[this->user_token_number]]->tag,
 		  this->tag, this->user_token_number);
@@ -1697,7 +1697,7 @@ token_translations_init (void)
      token number for $undefined., which represents all invalid
      inputs.  */
   for (i = 0; i < max_user_token_number + 1; i++)
-    token_translations[i] = 2;
+    token_translations[i] = undeftoken->number;
 
   symbols_do (symbol_translation, NULL);
 }
@@ -1718,8 +1718,6 @@ packsymbols (void)
 
   token_translations_init ();
 
-  error_token_number = errtoken->number;
-
   if (startval->class == unknown_sym)
     fatal (_("the start symbol %s is undefined"), startval->tag);
   else if (startval->class == token_sym)
@@ -1831,7 +1829,6 @@ reader (void)
   undeftoken = getsym ("$undefined.");
   undeftoken->class = token_sym;
   undeftoken->number = ntokens++;
-  undeftoken->user_token_number = 2;
 
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
