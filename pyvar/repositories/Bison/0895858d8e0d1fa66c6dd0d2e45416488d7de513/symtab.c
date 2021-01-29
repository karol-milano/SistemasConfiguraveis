@@ -549,7 +549,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
         complain_pct_type_on_token (&sym->location);
 
       if (class == nterm_sym && s->class != nterm_sym)
-        s->number = nvars++;
+        s->number = nnterms++;
       else if (class == token_sym && s->number == NUMBER_UNDEFINED)
         s->number = ntokens++;
       s->class = class;
@@ -621,7 +621,7 @@ symbol_check_defined (symbol *sym)
     {
       complain_symbol_undeclared (sym);
       s->class = nterm_sym;
-      s->number = nvars++;
+      s->number = nnterms++;
     }
 
   if (s->class == token_sym
@@ -852,7 +852,7 @@ symbols_new (void)
   /* Construct the accept symbol. */
   accept = symbol_get ("$accept", empty_loc);
   accept->content->class = nterm_sym;
-  accept->content->number = nvars++;
+  accept->content->number = nnterms++;
 
   /* Construct the YYerror/"error" token */
   errtoken = symbol_get ("YYerror", empty_loc);
@@ -969,7 +969,7 @@ dummy_symbol_get (location loc)
   assure (len < sizeof buf);
   symbol *sym = symbol_get (buf, loc);
   sym->content->class = nterm_sym;
-  sym->content->number = nvars++;
+  sym->content->number = nnterms++;
   return sym;
 }
 
