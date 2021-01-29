@@ -83,8 +83,8 @@ state_list_append (symbol_number_t symbol,
 static int nshifts;
 static symbol_number_t *shift_symbol = NULL;
 
-static short *redset = NULL;
-static state_number_t *shiftset = NULL;
+static rule_t **redset = NULL;
+static state_t **shiftset = NULL;
 
 static item_number_t **kernel_base = NULL;
 static int *kernel_size = NULL;
@@ -139,8 +139,8 @@ allocate_storage (void)
 {
   allocate_itemsets ();
 
-  shiftset = XCALLOC (state_number_t, nsyms);
-  redset = XCALLOC (short, nrules);
+  shiftset = XCALLOC (state_t *, nsyms);
+  redset = XCALLOC (rule_t *, nrules);
   state_hash_new ();
   shift_symbol = XCALLOC (symbol_number_t, nsyms);
 }
@@ -204,13 +204,13 @@ new_itemsets (state_t *state)
 
 
 
-/*--------------------------------------------------------------.
-| Find the state number for the state we would get to (from the |
-| current state) by shifting symbol.  Create a new state if no  |
-| equivalent one exists already.  Used by append_states.        |
-`--------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Find the state we would get to (from the current state) by       |
+| shifting SYMBOL.  Create a new state if no equivalent one exists |
+| already.  Used by append_states.                                 |
+`-----------------------------------------------------------------*/
 
-static state_number_t
+static state_t *
 get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 {
   state_t *sp;
@@ -226,15 +226,15 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
   if (trace_flag)
     fprintf (stderr, "Exiting get_state => %d\n", sp->number);
 
-  return sp->number;
+  return sp;
 }
 
-/*------------------------------------------------------------------.
-| Use the information computed by new_itemsets to find the state    |
-| numbers reached by each shift transition from STATE.              |
-|                                                                   |
-| SHIFTSET is set up as a vector of state numbers of those states.  |
-`------------------------------------------------------------------*/
+/*---------------------------------------------------------------.
+| Use the information computed by new_itemsets to find the state |
+| numbers reached by each shift transition from STATE.           |
+|                                                                |
+| SHIFTSET is set up as a vector of those states.                |
+`---------------------------------------------------------------*/
 
 static void
 append_states (state_t *state)
@@ -292,7 +292,7 @@ save_reductions (state_t *state)
     {
       int item = ritem[itemset[i]];
       if (item < 0)
-	redset[count++] = item_number_as_rule_number (item);
+	redset[count++] = &rules[item_number_as_rule_number (item)];
     }
 
   /* Make a reductions structure and copy the data into it.  */
