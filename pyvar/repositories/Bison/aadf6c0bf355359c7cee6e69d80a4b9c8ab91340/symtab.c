@@ -450,12 +450,11 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
     complain_class_redeclared (sym, class, loc);
   else
     {
-      s->class = class;
-
       if (class == nterm_sym && s->class != nterm_sym)
         s->number = nvars++;
       else if (class == token_sym && s->number == NUMBER_UNDEFINED)
         s->number = ntokens++;
+      s->class = class;
 
       if (declaring)
         {
