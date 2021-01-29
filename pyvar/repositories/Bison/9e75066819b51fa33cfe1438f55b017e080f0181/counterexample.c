@@ -190,7 +190,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
     {
       node = (si_bfs_node *) gl_list_get_at (queue, 0);
       state_item *silast = state_items + node->si;
-      symbol_number sym = item_number_as_symbol_number (*(silast->item));
+      symbol_number sym = item_number_as_symbol_number (*silast->item);
       if (sym == conflict_sym)
         break;
       if (ISVAR (sym))
@@ -893,10 +893,10 @@ static bool
 has_common_prefix (const item_number *itm1, const item_number *itm2)
 {
   int i = 0;
-  for (; !item_number_is_rule_number (*(itm1 + i)); ++i)
-    if (*(itm1 + i) != *(itm2 + i))
+  for (; !item_number_is_rule_number (itm1[i]); ++i)
+    if (itm1[i] != itm2[i])
       return false;
-  return item_number_is_rule_number (*(itm2 + i));
+  return item_number_is_rule_number (itm2[i]);
 }
 
 /*
