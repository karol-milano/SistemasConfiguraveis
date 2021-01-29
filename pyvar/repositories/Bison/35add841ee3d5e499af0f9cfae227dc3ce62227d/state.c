@@ -77,7 +77,8 @@ errs_new (int num, symbol **tokens)
   size_t symbols_size = num * sizeof *tokens;
   errs *res = xmalloc (offsetof (errs, symbols) + symbols_size);
   res->num = num;
-  memcpy (res->symbols, tokens, symbols_size);
+  if (tokens)
+    memcpy (res->symbols, tokens, symbols_size);
   return res;
 }
 
