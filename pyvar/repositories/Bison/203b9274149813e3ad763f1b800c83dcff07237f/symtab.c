@@ -499,12 +499,11 @@ symbols_new (void)
 `----------------------------------------------------------------*/
 
 symbol *
-symbol_get (const char *key, location loc)
+symbol_from_uniqstr (const uniqstr key, location loc)
 {
   symbol probe;
   symbol *entry;
 
-  key = uniqstr_new (key);
   probe.tag = key;
   entry = hash_lookup (symbol_table, &probe);
 
@@ -518,6 +517,18 @@ symbol_get (const char *key, location loc)
 }
 
 
+/*----------------------------------------------------------------.
+| Find the symbol named KEY, and return it.  If it does not exist |
+| yet, create it.                                                 |
+`----------------------------------------------------------------*/
+
+symbol *
+symbol_get (const char *key, location loc)
+{
+  return symbol_from_uniqstr (uniqstr_new (key), loc);
+}
+
+
 /*------------------------------------------------------------------.
 | Generate a dummy nonterminal, whose name cannot conflict with the |
 | user's names.                                                     |
