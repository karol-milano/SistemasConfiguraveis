@@ -79,8 +79,7 @@ symbol_new (uniqstr tag, location loc)
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
     fatal (_("too many symbols in input grammar (limit is %d)"),
 	   SYMBOL_NUMBER_MAXIMUM);
-  if (tag[0] != '"')
-    nsyms++;
+  nsyms++;
   return res;
 }
 
@@ -267,8 +266,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 
   if (class == nterm_sym && sym->class != nterm_sym)
     sym->number = nvars++;
-  else if (class == token_sym && sym->number == NUMBER_UNDEFINED
-           && sym->tag[0] != '"')
+  else if (class == token_sym && sym->number == NUMBER_UNDEFINED)
     sym->number = ntokens++;
 
   sym->class = class;
@@ -380,9 +378,6 @@ symbol_check_alias_consistency (symbol *this)
   symbol *alias = this;
   symbol *orig  = this->alias;
 
-  if (this->tag[0] == '"' && !this->alias)
-    complain_at (this->location, _("%s undeclared"), this->tag);
-
   /* Check only those that _are_ the aliases.  */
   if (!(this->alias && this->user_token_number == USER_NUMBER_ALIAS))
     return;
@@ -720,13 +715,35 @@ symbols_token_translations_init (void)
 void
 symbols_pack (void)
 {
-  symbols = xcalloc (nsyms, sizeof *symbols);
-
   symbols_do (symbol_check_alias_consistency_processor, NULL);
-  if (complaint_issued)
-    return;
+
+  symbols = xcalloc (nsyms, sizeof *symbols);
   symbols_do (symbol_pack_processor, NULL);
 
+  /* Aliases leave empty slots in symbols, so remove them.  */
+  {
+    int writei;
+    int readi;
+    int nsyms_old = nsyms;
+    for (writei = 0, readi = 0; readi < nsyms_old; readi += 1)
+      {
+        if (symbols[readi] == NULL)
+          {
+            nsyms -= 1;
+            ntokens -= 1;
+          }
+        else
+          {
+            symbols[writei] = symbols[readi];
+            symbols[writei]->number = writei;
+            if (symbols[writei]->alias)
+              symbols[writei]->alias->number = writei;
+            writei += 1;
+          }
+      }
+  }
+  symbols = xnrealloc (symbols, nsyms, sizeof *symbols);
+
   symbols_token_translations_init ();
 
   if (startsymbol->class == unknown_sym)
