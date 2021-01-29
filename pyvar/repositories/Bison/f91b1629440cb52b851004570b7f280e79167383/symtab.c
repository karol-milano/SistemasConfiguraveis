@@ -769,7 +769,7 @@ dummy_symbol_get (location loc)
 
   symbol *sym;
 
-  sprintf (buf, "@%d", ++dummy_count);
+  sprintf (buf, "$@%d", ++dummy_count);
   sym = symbol_get (buf, loc);
   sym->class = nterm_sym;
   sym->number = nvars++;
@@ -779,7 +779,7 @@ dummy_symbol_get (location loc)
 bool
 symbol_is_dummy (const symbol *sym)
 {
-  return sym->tag[0] == '@';
+  return sym->tag[0] == '@' || (sym->tag[0] == '$' && sym->tag[1] == '@');
 }
 
 /*-------------------.
