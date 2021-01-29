@@ -34,12 +34,12 @@
 
 int nstates;
 int final_state;
-core *first_state = NULL;
+state_t *first_state = NULL;
 shifts *first_shift = NULL;
 reductions *first_reduction = NULL;
 
-static core *this_state = NULL;
-static core *last_state = NULL;
+static state_t *this_state = NULL;
+static state_t *last_state = NULL;
 static shifts *last_shift = NULL;
 static reductions *last_reduction = NULL;
 
@@ -55,8 +55,8 @@ static short *kernel_items = NULL;
 
 /* hash table for states, to recognize equivalent ones.  */
 
-#define	STATE_TABLE_SIZE	1009
-static core **state_table = NULL;
+#define	STATE_HASH_SIZE	1009
+static state_t **state_hash = NULL;
 
 
 static void
@@ -107,7 +107,7 @@ allocate_storage (void)
 
   shiftset = XCALLOC (short, nsyms);
   redset = XCALLOC (short, nrules + 1);
-  state_table = XCALLOC (core *, STATE_TABLE_SIZE);
+  state_hash = XCALLOC (state_t *, STATE_HASH_SIZE);
 }
 
 
@@ -120,7 +120,7 @@ free_storage (void)
   free (kernel_base);
   free (kernel_size);
   XFREE (kernel_items);
-  free (state_table);
+  free (state_hash);
 }
 
 
@@ -176,10 +176,10 @@ new_itemsets (void)
 | necessary.                                                       |
 `-----------------------------------------------------------------*/
 
-static core *
+static state_t *
 new_state (int symbol)
 {
-  core *p;
+  state_t *p;
 
   if (trace_flag)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
@@ -188,7 +188,7 @@ new_state (int symbol)
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
 
-  p = CORE_ALLOC (kernel_size[symbol]);
+  p = STATE_ALLOC (kernel_size[symbol]);
   p->accessing_symbol = symbol;
   p->number = nstates;
   p->nitems = kernel_size[symbol];
@@ -214,7 +214,7 @@ get_state (int symbol)
 {
   int key;
   int i;
-  core *sp;
+  state_t *sp;
 
   if (trace_flag)
     fprintf (stderr, "Entering get_state, state = %d, symbol = %d (%s)\n",
@@ -225,8 +225,8 @@ get_state (int symbol)
   key = 0;
   for (i = 0; i < kernel_size[symbol]; ++i)
     key += kernel_base[symbol][i];
-  key = key % STATE_TABLE_SIZE;
-  sp = state_table[key];
+  key = key % STATE_HASH_SIZE;
+  sp = state_hash[key];
 
   if (sp)
     {
@@ -257,7 +257,7 @@ get_state (int symbol)
     }
   else				/* bucket is empty */
     {
-      state_table[key] = sp = new_state (symbol);
+      state_hash[key] = sp = new_state (symbol);
     }
 
   if (trace_flag)
@@ -306,7 +306,7 @@ append_states (void)
 static void
 new_states (void)
 {
-  first_state = last_state = this_state = CORE_ALLOC (0);
+  first_state = last_state = this_state = STATE_ALLOC (0);
   nstates = 1;
 }
 
@@ -340,10 +340,10 @@ save_shifts (void)
 static void
 insert_start_shift (void)
 {
-  core *statep;
+  state_t *statep;
   shifts *sp;
 
-  statep = CORE_ALLOC (0);
+  statep = STATE_ALLOC (0);
   statep->number = nstates;
   statep->accessing_symbol = start_symbol;
 
@@ -371,7 +371,7 @@ insert_start_shift (void)
 static void
 augment_automaton (void)
 {
-  core *statep;
+  state_t *statep;
   shifts *sp;
   shifts *sp1 = NULL;
 
@@ -500,7 +500,7 @@ augment_automaton (void)
   /* Make the final state--the one that follows a shift from the
      next-to-final state.
      The symbol for that shift is 0 (end-of-file).  */
-  statep = CORE_ALLOC (0);
+  statep = STATE_ALLOC (0);
   statep->number = nstates;
   last_state->next = statep;
   last_state = statep;
@@ -517,7 +517,7 @@ augment_automaton (void)
   final_state = nstates;
 
   /* Make the termination state.  */
-  statep = CORE_ALLOC (0);
+  statep = STATE_ALLOC (0);
   statep->number = nstates++;
   last_state->next = statep;
   last_state = statep;
