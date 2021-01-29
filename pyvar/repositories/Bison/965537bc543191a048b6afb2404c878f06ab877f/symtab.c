@@ -79,7 +79,8 @@ symbol_new (uniqstr tag, location loc)
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
     fatal (_("too many symbols in input grammar (limit is %d)"),
 	   SYMBOL_NUMBER_MAXIMUM);
-  nsyms++;
+  if (tag[0] != '"')
+    nsyms++;
   return res;
 }
 
@@ -266,7 +267,8 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 
   if (class == nterm_sym && sym->class != nterm_sym)
     sym->number = nvars++;
-  else if (class == token_sym && sym->number == NUMBER_UNDEFINED)
+  else if (class == token_sym && sym->number == NUMBER_UNDEFINED
+           && sym->tag[0] != '"')
     sym->number = ntokens++;
 
   sym->class = class;
@@ -361,12 +363,7 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
       sym->user_token_number = USER_NUMBER_ALIAS;
       symval->alias = sym;
       sym->alias = symval;
-      /* sym and symval combined are only one symbol.  */
-      nsyms--;
-      ntokens--;
-      assert (ntokens == sym->number || ntokens == symval->number);
-      sym->number = symval->number =
-	(symval->number < sym->number) ? symval->number : sym->number;
+      symval->number = sym->number;
       symbol_type_set (symval, sym->type_name, loc);
     }
 }
@@ -383,6 +380,9 @@ symbol_check_alias_consistency (symbol *this)
   symbol *alias = this;
   symbol *orig  = this->alias;
 
+  if (this->tag[0] == '"' && !this->alias)
+    complain_at (this->location, _("%s undeclared"), this->tag);
+
   /* Check only those that _are_ the aliases.  */
   if (!(this->alias && this->user_token_number == USER_NUMBER_ALIAS))
     return;
@@ -723,6 +723,8 @@ symbols_pack (void)
   symbols = xcalloc (nsyms, sizeof *symbols);
 
   symbols_do (symbol_check_alias_consistency_processor, NULL);
+  if (complaint_issued)
+    return;
   symbols_do (symbol_pack_processor, NULL);
 
   symbols_token_translations_init ();
