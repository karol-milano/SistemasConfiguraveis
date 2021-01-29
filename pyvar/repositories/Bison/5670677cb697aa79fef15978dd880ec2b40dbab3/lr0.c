@@ -185,9 +185,7 @@ new_itemsets (state *s)
     if (item_number_is_symbol_number (ritem[itemset[i]]))
       {
         symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
-        if (!kernel_size[sym])
-          bitset_set (shift_symbol, sym);
-
+        bitset_set (shift_symbol, sym);
         kernel_base[sym][kernel_size[sym]] = itemset[i] + 1;
         kernel_size[sym]++;
       }
