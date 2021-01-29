@@ -475,8 +475,7 @@ symbol_get (const char *key, location loc)
   symbol probe;
   symbol *entry;
 
-  /* Keep the symbol in a printable form.  */
-  key = uniqstr_new (quotearg_style (escape_quoting_style, key));
+  key = uniqstr_new (key);
   probe.tag = key;
   entry = hash_lookup (symbol_table, &probe);
 
