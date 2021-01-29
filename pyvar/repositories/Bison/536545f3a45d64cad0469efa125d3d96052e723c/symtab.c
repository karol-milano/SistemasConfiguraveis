@@ -464,6 +464,7 @@ void
 symbols_free (void)
 {
   hash_free (symbol_table);
+  free (symbols);
 }
 
 
