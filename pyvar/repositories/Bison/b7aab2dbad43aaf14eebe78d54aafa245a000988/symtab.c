@@ -137,11 +137,6 @@ symbol_new (uniqstr tag, location loc)
   res->alias = NULL;
   res->content = sym_content_new (res);
   res->is_alias = false;
-
-  if (nsyms == SYMBOL_NUMBER_MAXIMUM)
-    complain (NULL, fatal, _("too many symbols in input grammar (limit is %d)"),
-              SYMBOL_NUMBER_MAXIMUM);
-  nsyms++;
   return res;
 }
 
@@ -406,7 +401,10 @@ void
 symbol_location_as_lhs_set (symbol *sym, location loc)
 {
   if (!sym->location_of_lhs)
-    sym->location = loc;
+    {
+      sym->location = loc;
+      sym->location_of_lhs = true;
+    }
 }
 
 
@@ -556,10 +554,6 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
       if (class == token_sym && s->class == pct_type_sym)
         complain_pct_type_on_token (&sym->location);
 
-      if (class == nterm_sym && s->class != nterm_sym)
-        s->number = nnterms++;
-      else if (class == token_sym && s->number == NUMBER_UNDEFINED)
-        s->number = ntokens++;
       s->class = class;
 
       if (declaring)
@@ -606,10 +600,6 @@ symbol_code_set (symbol *sym, int code, location loc)
       if (code == 0 && !eoftoken)
         {
           eoftoken = sym->content->symbol;
-          /* It is always mapped to 0, so it was already counted in
-             NTOKENS.  */
-          if (eoftoken->content->number != NUMBER_UNDEFINED)
-            --ntokens;
           eoftoken->content->number = 0;
         }
     }
@@ -629,9 +619,11 @@ symbol_check_defined (symbol *sym)
     {
       complain_symbol_undeclared (sym);
       s->class = nterm_sym;
-      s->number = nnterms++;
     }
 
+  if (s->number == NUMBER_UNDEFINED)
+    s->number = s->class == token_sym ? ntokens++ : nnterms++;
+
   if (s->class == token_sym
       && sym->tag[0] == '"'
       && !sym->is_alias)
@@ -975,7 +967,6 @@ dummy_symbol_get (location loc)
   assure (len < sizeof buf);
   symbol *sym = symbol_get (buf, loc);
   sym->content->class = nterm_sym;
-  sym->content->number = nnterms++;
   return sym;
 }
 
