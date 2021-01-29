@@ -100,8 +100,8 @@ symbol_list_free (symbol_list *list)
 | Return its length.  |
 `--------------------*/
 
-unsigned int
-symbol_list_length (const symbol_list *l)
+int
+symbol_list_length (symbol_list const *l)
 {
   int res = 0;
   for (/* Nothing. */; l && l->sym; l = l->next)
