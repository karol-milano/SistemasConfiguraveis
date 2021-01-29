@@ -52,11 +52,6 @@ static item_number_t **kernel_base = NULL;
 static int *kernel_size = NULL;
 static item_number_t *kernel_items = NULL;
 
-/* hash table for states, to recognize equivalent ones.  */
-
-#define	STATE_HASH_SIZE	1009
-static state_t **state_hash = NULL;
-
 
 static void
 allocate_itemsets (void)
@@ -107,7 +102,7 @@ allocate_storage (void)
 
   shiftset = XCALLOC (state_number_t, nsyms);
   redset = XCALLOC (short, nrules + 1);
-  state_hash = XCALLOC (state_t *, STATE_HASH_SIZE);
+  state_hash_new ();
   shift_symbol = XCALLOC (symbol_number_t, nsyms);
 }
 
@@ -121,7 +116,7 @@ free_storage (void)
   free (kernel_base);
   free (kernel_size);
   XFREE (kernel_items);
-  free (state_hash);
+  state_hash_free ();
 }
 
 
@@ -185,6 +180,7 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 	     nstates, symbol, symbol_tag_get (symbols[symbol]));
 
   res = state_new (symbol, core_size, core);
+  state_hash_insert (res);
 
   /* If this is the eoftoken, and this is not the initial state, then
      this is the final state.  */
@@ -210,8 +206,6 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 static state_number_t
 get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 {
-  int key;
-  size_t i;
   state_t *sp;
 
   if (trace_flag)
@@ -219,45 +213,9 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 	     this_state->number, symbol,
 	     symbol_tag_get (symbols[symbol]));
 
-  /* Add up the target state's active item numbers to get a hash key.
-     */
-  key = 0;
-  for (i = 0; i < core_size; ++i)
-    key += core[i];
-  key = key % STATE_HASH_SIZE;
-  sp = state_hash[key];
-
-  if (sp)
-    {
-      int found = 0;
-      while (!found)
-	{
-	  if (sp->nitems == core_size)
-	    {
-	      found = 1;
-	      for (i = 0; i < core_size; ++i)
-		if (core[i] != sp->items[i])
-		  found = 0;
-	    }
-
-	  if (!found)
-	    {
-	      if (sp->link)
-		{
-		  sp = sp->link;
-		}
-	      else		/* bucket exhausted and no match */
-		{
-		  sp = sp->link = new_state (symbol, core_size, core);
-		  found = 1;
-		}
-	    }
-	}
-    }
-  else				/* bucket is empty */
-    {
-      state_hash[key] = sp = new_state (symbol, core_size, core);
-    }
+  sp = state_hash_lookup (core_size, core);
+  if (!sp)
+    sp = new_state (symbol, core_size, core);
 
   if (trace_flag)
     fprintf (stderr, "Exiting get_state => %d\n", sp->number);
@@ -386,6 +344,7 @@ set_states (void)
     }
 }
 
+
 /*-------------------------------------------------------------------.
 | Compute the nondeterministic finite state machine (see state.h for |
 | details) from the grammar.                                         |
