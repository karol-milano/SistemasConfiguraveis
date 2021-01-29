@@ -41,7 +41,7 @@ static int start_flag = 0;
 /* Nonzero if %union has been seen.  */
 int typed = 0;
 
-static symbol_list *
+symbol_list *
 symbol_list_new (symbol_t *sym, location_t location)
 {
   symbol_list *res = XMALLOC (symbol_list, 1);
@@ -53,6 +53,14 @@ symbol_list_new (symbol_t *sym, location_t location)
   return res;
 }
 
+symbol_list *
+symbol_list_prepend (symbol_list *list, symbol_t *symbol, location_t location)
+{
+  symbol_list *res = symbol_list_new (symbol, location);
+  res->next = list;
+  return res;
+}
+
 
 /*--------------------------------------------------------------.
 | Get the data type (alternative in the union) of the value for |
