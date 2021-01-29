@@ -185,7 +185,7 @@ new_itemsets (void)
 `-----------------------------------------------------------------*/
 
 static state_t *
-new_state (token_number_t symbol)
+new_state (token_number_t symbol, size_t core_size, item_number_t *core)
 {
   state_t *p;
 
@@ -197,13 +197,12 @@ new_state (token_number_t symbol)
   if (nstates >= SHRT_MAX)
     fatal (_("too many states (max %d)"), SHRT_MAX);
 
-  p = STATE_ALLOC (kernel_size[symbol]);
+  p = STATE_ALLOC (core_size);
   p->accessing_symbol = symbol;
   p->number = nstates;
-  p->nitems = kernel_size[symbol];
+  p->nitems = core_size;
 
-  memcpy (p->items, kernel_base[symbol],
-	  kernel_size[symbol] * sizeof (kernel_base[symbol][0]));
+  memcpy (p->items, core, core_size * sizeof (core[0]));
 
   /* If this is the eoftoken, and this is not the initial state, then
      this is the final state.  */
@@ -229,7 +228,7 @@ new_state (token_number_t symbol)
 `--------------------------------------------------------------*/
 
 static int
-get_state (token_number_t symbol)
+get_state (token_number_t symbol, size_t core_size, item_number_t *core)
 {
   int key;
   int i;
@@ -243,8 +242,8 @@ get_state (token_number_t symbol)
   /* Add up the target state's active item numbers to get a hash key.
      */
   key = 0;
-  for (i = 0; i < kernel_size[symbol]; ++i)
-    key += kernel_base[symbol][i];
+  for (i = 0; i < core_size; ++i)
+    key += core[i];
   key = key % STATE_HASH_SIZE;
   sp = state_hash[key];
 
@@ -253,11 +252,11 @@ get_state (token_number_t symbol)
       int found = 0;
       while (!found)
 	{
-	  if (sp->nitems == kernel_size[symbol])
+	  if (sp->nitems == core_size)
 	    {
 	      found = 1;
-	      for (i = 0; i < kernel_size[symbol]; ++i)
-		if (kernel_base[symbol][i] != sp->items[i])
+	      for (i = 0; i < core_size; ++i)
+		if (core[i] != sp->items[i])
 		  found = 0;
 	    }
 
@@ -269,7 +268,7 @@ get_state (token_number_t symbol)
 		}
 	      else		/* bucket exhausted and no match */
 		{
-		  sp = sp->link = new_state (symbol);
+		  sp = sp->link = new_state (symbol, core_size, core);
 		  found = 1;
 		}
 	    }
@@ -277,7 +276,7 @@ get_state (token_number_t symbol)
     }
   else				/* bucket is empty */
     {
-      state_hash[key] = sp = new_state (symbol);
+      state_hash[key] = sp = new_state (symbol, core_size, core);
     }
 
   if (trace_flag)
@@ -319,7 +318,11 @@ append_states (void)
     }
 
   for (i = 0; i < nshifts; i++)
-    shiftset[i] = get_state (shift_symbol[i]);
+    {
+      symbol = shift_symbol[i];
+      shiftset[i] = get_state (symbol,
+			       kernel_size[symbol], kernel_base[symbol]);
+    }
 }
 
 
@@ -329,7 +332,7 @@ new_states (void)
   /* The 0 at the lhs is the index of the item of this initial rule.  */
   kernel_base[0][0] = 0;
   kernel_size[0] = 1;
-  this_state = new_state (0);
+  this_state = new_state (0, kernel_size[0], kernel_base[0]);
 }
 
 
