@@ -174,9 +174,8 @@ symbol_list_length (symbol_list const *l)
 symbol_list *
 symbol_list_n_get (symbol_list *l, int n)
 {
-  int i;
   aver (0 <= n);
-  for (i = 0; i < n; ++i)
+  for (int i = 0; i < n; ++i)
     {
       l = l->next;
       aver (l);
