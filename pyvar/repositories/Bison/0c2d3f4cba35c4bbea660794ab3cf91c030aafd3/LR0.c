@@ -231,7 +231,7 @@ static int
 get_state (token_number_t symbol, size_t core_size, item_number_t *core)
 {
   int key;
-  int i;
+  size_t i;
   state_t *sp;
 
   if (trace_flag)
