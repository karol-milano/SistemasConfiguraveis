@@ -94,7 +94,7 @@ allocate_itemsets (void)
     }
 
   shift_symbol = symbol_count;
-  kernel_size = XCALLOC (size_t, nsyms);
+  kernel_size = XCALLOC (int, nsyms);
 }
 
 
