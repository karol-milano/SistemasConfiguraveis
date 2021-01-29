@@ -1693,7 +1693,7 @@ token_translations_init (void)
 	max_user_token_number = this->user_token_number;
     }
 
-  token_translations = XCALLOC (token_number_t, max_user_token_number + 1);
+  token_translations = XCALLOC (symbol_number_t, max_user_token_number + 1);
 
   /* Initialize all entries for literal tokens to 2, the internal
      token number for $undefined., which represents all invalid
@@ -1762,9 +1762,9 @@ packgram (void)
       p = p->next;
       while (p && p->sym)
 	{
-	  /* item_number_t = token_number_t.
+	  /* item_number_t = symbol_number_t.
 	     But the former needs to contain more: negative rule numbers. */
-	  ritem[itemno++] = token_number_as_item_number (p->sym->number);
+	  ritem[itemno++] = symbol_number_as_item_number (p->sym->number);
 	  /* A rule gets by default the precedence and associativity
 	     of the last token in it.  */
 	  if (p->sym->class == token_sym)
