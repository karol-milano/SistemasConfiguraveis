@@ -66,7 +66,7 @@ static bucket *errtoken;
 static bucket *undeftoken;
 
 
-symbol_list *
+static symbol_list *
 symbol_list_new (bucket *sym)
 {
   symbol_list *res = XMALLOC (symbol_list, 1);
