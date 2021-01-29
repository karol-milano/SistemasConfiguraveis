@@ -50,7 +50,7 @@ static short *redset = NULL;
 static short *shiftset = NULL;
 
 static short **kernel_base = NULL;
-static short **kernel_end = NULL;
+static size_t *kernel_size = NULL;
 static short *kernel_items = NULL;
 
 /* hash table for states, to recognize equivalent ones.  */
@@ -94,7 +94,7 @@ allocate_itemsets (void)
     }
 
   shift_symbol = symbol_count;
-  kernel_end = XCALLOC (short *, nsyms);
+  kernel_size = XCALLOC (size_t, nsyms);
 }
 
 
@@ -116,7 +116,7 @@ free_storage (void)
   XFREE (redset);
   XFREE (shiftset);
   XFREE (kernel_base);
-  XFREE (kernel_end);
+  XFREE (kernel_size);
   XFREE (kernel_items);
   XFREE (state_table);
 }
@@ -132,8 +132,7 @@ free_storage (void)
 | shift_symbol is set to a vector of the symbols that can be      |
 | shifted.  For each symbol in the grammar, kernel_base[symbol]   |
 | points to a vector of item numbers activated if that symbol is  |
-| shifted, and kernel_end[symbol] points after the end of that    |
-| vector.                                                         |
+| shifted, and kernel_size[symbol] is their numbers.              |
 `----------------------------------------------------------------*/
 
 static void
@@ -147,7 +146,7 @@ new_itemsets (void)
 	     this_state->number);
 
   for (i = 0; i < nsyms; i++)
-    kernel_end[i] = NULL;
+    kernel_size[i] = 0;
 
   shiftcount = 0;
 
@@ -156,17 +155,14 @@ new_itemsets (void)
       int symbol = ritem[itemset[i]];
       if (symbol > 0)
 	{
-	  short *ksp = kernel_end[symbol];
-
-	  if (!ksp)
+	  if (!kernel_size[symbol])
 	    {
 	      shift_symbol[shiftcount] = symbol;
-	      ksp = kernel_base[symbol];
 	      shiftcount++;
 	    }
 
-	  *ksp++ = itemset[i] + 1;
-	  kernel_end[symbol] = ksp;
+	  kernel_base[symbol][kernel_size[symbol]] = itemset[i] + 1;
+	  kernel_size[symbol]++;
 	}
     }
 
@@ -183,7 +179,6 @@ new_itemsets (void)
 static core *
 new_state (int symbol)
 {
-  int n;
   core *p;
 
   if (trace_flag)
@@ -193,14 +188,12 @@ new_state (int symbol)
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
 
-  n = kernel_end[symbol] - kernel_base[symbol];
-
-  p = CORE_ALLOC (n);
+  p = CORE_ALLOC (kernel_size[symbol]);
   p->accessing_symbol = symbol;
   p->number = nstates;
-  p->nitems = n;
+  p->nitems = kernel_size[symbol];
 
-  shortcpy (p->items, kernel_base[symbol], n);
+  shortcpy (p->items, kernel_base[symbol], kernel_size[symbol]);
 
   last_state->next = p;
   last_state = p;
@@ -224,8 +217,6 @@ get_state (int symbol)
   int i;
   core *sp;
 
-  int n = kernel_end[symbol] - kernel_base[symbol];
-
   if (trace_flag)
     fprintf (stderr, "Entering get_state, state = %d, symbol = %d (%s)\n",
 	     this_state->number, symbol, tags[symbol]);
@@ -233,7 +224,7 @@ get_state (int symbol)
   /* Add up the target state's active item numbers to get a hash key.
      */
   key = 0;
-  for (i = 0; i < n; ++i)
+  for (i = 0; i < kernel_size[symbol]; ++i)
     key += kernel_base[symbol][i];
   key = key % STATE_TABLE_SIZE;
   sp = state_table[key];
@@ -243,11 +234,11 @@ get_state (int symbol)
       int found = 0;
       while (!found)
 	{
-	  if (sp->nitems == n)
+	  if (sp->nitems == kernel_size[symbol])
 	    {
 	      int i;
 	      found = 1;
-	      for (i = 0; i < n; ++i)
+	      for (i = 0; i < kernel_size[symbol]; ++i)
 		if (kernel_base[symbol][i] != sp->items[i])
 		  found = 0;
 	    }
