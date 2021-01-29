@@ -52,7 +52,7 @@ static state_t *this_state = NULL;
 static state_t *last_state = NULL;
 
 static int nshifts;
-static token_number_t *shift_symbol = NULL;
+static symbol_number_t *shift_symbol = NULL;
 
 static short *redset = NULL;
 static short *shiftset = NULL;
@@ -117,7 +117,7 @@ allocate_storage (void)
   shiftset = XCALLOC (short, nsyms);
   redset = XCALLOC (short, nrules + 1);
   state_hash = XCALLOC (state_t *, STATE_HASH_SIZE);
-  shift_symbol = XCALLOC (token_number_t, nsyms);
+  shift_symbol = XCALLOC (symbol_number_t, nsyms);
 }
 
 
@@ -164,8 +164,8 @@ new_itemsets (void)
   for (i = 0; i < nritemset; ++i)
     if (ritem[itemset[i]] >= 0)
       {
-	token_number_t symbol
-	  = item_number_as_token_number (ritem[itemset[i]]);
+	symbol_number_t symbol
+	  = item_number_as_symbol_number (ritem[itemset[i]]);
 	if (!kernel_size[symbol])
 	  {
 	    shift_symbol[nshifts] = symbol;
@@ -185,7 +185,7 @@ new_itemsets (void)
 `-----------------------------------------------------------------*/
 
 static state_t *
-new_state (token_number_t symbol, size_t core_size, item_number_t *core)
+new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 {
   state_t *p;
 
@@ -228,7 +228,7 @@ new_state (token_number_t symbol, size_t core_size, item_number_t *core)
 `--------------------------------------------------------------*/
 
 static int
-get_state (token_number_t symbol, size_t core_size, item_number_t *core)
+get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 {
   int key;
   size_t i;
@@ -297,7 +297,7 @@ append_states (void)
 {
   int i;
   int j;
-  token_number_t symbol;
+  symbol_number_t symbol;
 
   if (trace_flag)
     fprintf (stderr, "Entering append_states, state = %d\n",
