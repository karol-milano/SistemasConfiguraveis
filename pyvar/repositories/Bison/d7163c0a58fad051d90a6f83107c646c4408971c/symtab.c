@@ -421,7 +421,7 @@ symbol_get (const char *key, location_t location)
 
   /* Keep the symbol in a printable form.  */
   key = quotearg_style (escape_quoting_style, key);
-  (const char *) probe.tag = key;
+  *(char const **) &probe.tag = key;
   entry = hash_lookup (symbol_table, &probe);
 
   if (!entry)
