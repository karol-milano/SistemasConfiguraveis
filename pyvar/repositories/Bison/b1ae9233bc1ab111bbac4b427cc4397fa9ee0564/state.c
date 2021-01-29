@@ -141,8 +141,7 @@ state_new (symbol_number_t accessing_symbol,
 {
   state_t *res;
 
-  if (nstates >= STATE_NUMBER_MAX)
-    fatal (_("too many states (max %d)"), STATE_NUMBER_MAX);
+  assert (nstates < STATE_NUMBER_MAX);
 
   res = STATE_ALLOC (core_size);
   res->accessing_symbol = accessing_symbol;
