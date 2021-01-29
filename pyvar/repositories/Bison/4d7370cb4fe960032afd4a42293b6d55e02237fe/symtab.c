@@ -615,6 +615,11 @@ dummy_symbol_get (location loc)
   return sym;
 }
 
+bool
+symbol_is_dummy (const symbol *sym)
+{
+  return sym->tag[0] == '@';
+}
 
 /*-------------------.
 | Free the symbols.  |
