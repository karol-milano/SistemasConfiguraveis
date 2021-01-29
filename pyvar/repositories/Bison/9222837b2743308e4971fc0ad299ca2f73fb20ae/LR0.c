@@ -74,7 +74,8 @@ static item_number_t *kernel_items = NULL;
 static void
 allocate_itemsets (void)
 {
-  int i, r;
+  symbol_number_t i;
+  rule_number_t r;
   item_number_t *rhsp;
 
   /* Count the number of occurrences of all the symbols in RITEMS.
