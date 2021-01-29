@@ -80,7 +80,10 @@ state_list_append (symbol_number sym, size_t core_size, item_number *core)
 bitset shift_symbol;
 
 static rule **redset;
-/* For the current state, the states that can be reached via a "shift".  */
+/* For the current state, the list of pointers to states that can be
+   reached via a shift/goto.  Could be indexed by the reaching symbol,
+   but labels of incoming transitions can be recovered by the state
+   itself.  */
 static state **shiftset;
 
 static item_number **kernel_base;
