@@ -32,7 +32,7 @@
 symbol_list *
 symbol_list_new (symbol *sym, location loc)
 {
-  symbol_list *res = XMALLOC (symbol_list, 1);
+  symbol_list *res = MALLOC (res, 1);
   res->next = NULL;
   res->sym = sym;
   res->location = loc;
