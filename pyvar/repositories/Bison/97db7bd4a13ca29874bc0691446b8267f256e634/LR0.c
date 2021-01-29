@@ -1,5 +1,5 @@
 /* Generate the nondeterministic finite state machine for bison,
-   Copyright 1984, 1986, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 2000, 2001  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -146,9 +146,6 @@ new_itemsets (void)
 {
   int i;
   int shiftcount;
-  short *isp;
-  short *ksp;
-  int symbol;
 
 #if TRACE
   fprintf (stderr, "Entering new_itemsets, state = %d\n",
@@ -160,23 +157,21 @@ new_itemsets (void)
 
   shiftcount = 0;
 
-  isp = itemset;
-
-  while (isp < itemsetend)
+  for (i = 0; i < itemsetend - itemset; ++i)
     {
-      i = *isp++;
-      symbol = ritem[i];
+      int symbol = ritem[itemset[i]];
       if (symbol > 0)
 	{
-	  ksp = kernel_end[symbol];
+	  short *ksp = kernel_end[symbol];
 
 	  if (!ksp)
 	    {
-	      shift_symbol[shiftcount++] = symbol;
+	      shift_symbol[shiftcount] = symbol;
 	      ksp = kernel_base[symbol];
+	      shiftcount++;
 	    }
 
-	  *ksp++ = i + 1;
+	  *ksp++ = itemset[i] + 1;
 	  kernel_end[symbol] = ksp;
 	}
     }
@@ -216,7 +211,6 @@ new_state (int symbol)
 
   last_state->next = p;
   last_state = p;
-
   nstates++;
 
   return p;
@@ -226,55 +220,44 @@ new_state (int symbol)
 /*--------------------------------------------------------------.
 | Find the state number for the state we would get to (from the |
 | current state) by shifting symbol.  Create a new state if no  |
-| equivalent one exists already.  Used by append_states.         |
+| equivalent one exists already.  Used by append_states.        |
 `--------------------------------------------------------------*/
 
 static int
 get_state (int symbol)
 {
   int key;
-  short *isp1;
   short *isp2;
-  short *iend;
+  int i;
   core *sp;
-  int found;
 
-  int n;
+  int n = kernel_end[symbol] - kernel_base[symbol];
 
 #if TRACE
   fprintf (stderr, "Entering get_state, state = %d, symbol = %d\n",
 	   nstates, symbol);
 #endif
 
-  isp1 = kernel_base[symbol];
-  iend = kernel_end[symbol];
-  n = iend - isp1;
-
-  /* add up the target state's active item numbers to get a hash key */
+  /* Add up the target state's active item numbers to get a hash key.
+     */
   key = 0;
-  while (isp1 < iend)
-    key += *isp1++;
-
+  for (i = 0; i < n; ++i)
+    key += kernel_base[symbol][i];
   key = key % STATE_TABLE_SIZE;
-
   sp = state_table[key];
 
   if (sp)
     {
-      found = 0;
+      int found = 0;
       while (!found)
 	{
 	  if (sp->nitems == n)
 	    {
+	      int i;
 	      found = 1;
-	      isp1 = kernel_base[symbol];
-	      isp2 = sp->items;
-
-	      while (found && isp1 < iend)
-		{
-		  if (*isp1++ != *isp2++)
-		    found = 0;
-		}
+	      for (i = 0; i < n; ++i)
+		if (kernel_base[symbol][i] != sp->items[i])
+		  found = 0;
 	    }
 
 	  if (!found)
@@ -332,20 +315,14 @@ append_states (void)
     }
 
   for (i = 0; i < nshifts; i++)
-    {
-      symbol = shift_symbol[i];
-      shiftset[i] = get_state (symbol);
-    }
+    shiftset[i] = get_state (shift_symbol[i]);
 }
 
 
 static void
 new_states (void)
 {
-  core *p;
-
-  p = CORE_ALLOC (0);
-  first_state = last_state = this_state = p;
+  first_state = last_state = this_state = CORE_ALLOC (0);
   nstates = 1;
 }
 
@@ -353,9 +330,7 @@ new_states (void)
 static void
 save_shifts (void)
 {
-  shifts *p;
-
-  p = SHIFTS_ALLOC (nshifts);
+  shifts *p = SHIFTS_ALLOC (nshifts);
 
   p->number = this_state->number;
   p->nshifts = nshifts;
@@ -363,15 +338,10 @@ save_shifts (void)
   shortcpy (p->shifts, shiftset, nshifts);
 
   if (last_shift)
-    {
-      last_shift->next = p;
-      last_shift = p;
-    }
+    last_shift->next = p;
   else
-    {
-      first_shift = p;
-      last_shift = p;
-    }
+    first_shift = p;
+  last_shift = p;
 }
 
 
@@ -617,15 +587,10 @@ save_reductions (void)
       shortcpy (p->rules, redset, count);
 
       if (last_reduction)
-	{
-	  last_reduction->next = p;
-	  last_reduction = p;
-	}
+	last_reduction->next = p;
       else
-	{
-	  first_reduction = p;
-	  last_reduction = p;
-	}
+	first_reduction = p;
+      last_reduction = p;
     }
 }
 
