@@ -447,7 +447,7 @@ symbols_new (void)
 `----------------------------------------------------------------*/
 
 symbol_t *
-getsym (const char *key, location_t location)
+symbol_get (const char *key, location_t location)
 {
   symbol_t probe;
   symbol_t *entry;
@@ -465,6 +465,28 @@ getsym (const char *key, location_t location)
 }
 
 
+/*------------------------------------------------------------------.
+| Generate a dummy nonterminal, whose name cannot conflict with the |
+| user's names.                                                     |
+`------------------------------------------------------------------*/
+
+symbol_t *
+dummy_symbol_get (location_t location)
+{
+  /* Incremented for each generated symbol.  */
+  static int dummy_count = 0;
+  static char buf[256];
+
+  symbol_t *sym;
+
+  sprintf (buf, "@%d", ++dummy_count);
+  sym = symbol_get (buf, location);
+  sym->class = nterm_sym;
+  sym->number = nvars++;
+  return sym;
+}
+
+
 /*-------------------.
 | Free the symbols.  |
 `-------------------*/
