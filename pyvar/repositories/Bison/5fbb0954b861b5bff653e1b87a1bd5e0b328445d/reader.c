@@ -199,13 +199,13 @@ symbol_pack (symbol_t *this)
       /* This symbol and its alias are a single token defn.
 	 Allocate a tokno, and assign to both check agreement of
 	 prec and assoc fields and make both the same */
-      if (this->number == -1)
+      if (this->number == NUMBER_UNDEFINED)
 	{
 	  if (this == eoftoken || this->alias == eoftoken)
 	    this->number = this->alias->number = 0;
 	  else
 	    {
-	      assert (this->alias->number != -1);
+	      assert (this->alias->number != NUMBER_UNDEFINED);
 	      this->number = this->alias->number;
 	    }
 	}
@@ -215,7 +215,7 @@ symbol_pack (symbol_t *this)
     }
   else /* this->class == token_sym */
     {
-      assert (this->number != -1);
+      assert (this->number != NUMBER_UNDEFINED);
     }
 
   symbols[this->number] = this;
@@ -705,7 +705,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	  symbol->class = what_is;
 	  if (what_is == nterm_sym && oldclass != nterm_sym)
 	    symbol->number = nvars++;
-	  if (what_is == token_sym && symbol->number == -1)
+	  if (what_is == token_sym && symbol->number == NUMBER_UNDEFINED)
 	    symbol->number = ntokens++;
 
 	  if (typename)
@@ -857,7 +857,7 @@ parse_assoc_decl (associativity assoc)
 	  symval->assoc = assoc;
 	  if (symval->class == nterm_sym)
 	    complain (_("symbol %s redefined"), symval->tag);
-	  if (symval->number == -1)
+	  if (symval->number == NUMBER_UNDEFINED)
 	    {
 	      symval->number = ntokens++;
 	      symval->class = token_sym;
@@ -1763,7 +1763,9 @@ packgram (void)
       p = p->next;
       while (p && p->sym)
 	{
-	  ritem[itemno++] = p->sym->number;
+	  /* item_number_t = token_number_t.
+	     But the former needs to contain more: negative rule numbers. */
+	  ritem[itemno++] = token_number_as_item_number (p->sym->number);
 	  /* A rule gets by default the precedence and associativity
 	     of the last token in it.  */
 	  if (p->sym->class == token_sym)
