@@ -37,15 +37,10 @@
 #include "lalr.h"
 #include "reduce.h"
 
-unsigned int nstates = 0;
-/* Initialize the final state to -1, otherwise, it might be set to 0
-   by default, and since we don't compute the reductions of the final
-   state, we end up not computing the reductions of the initial state,
-   which is of course needed.
-
-   FINAL_STATE is properly set by new_state when it recognizes the
+state_number_t nstates = 0;
+/* FINAL_STATE is properly set by new_state when it recognizes its
    accessing symbol: EOF.  */
-int final_state = -1;
+state_t *final_state = NULL;
 static state_t *first_state = NULL;
 
 static state_t *this_state = NULL;
@@ -55,7 +50,7 @@ static int nshifts;
 static symbol_number_t *shift_symbol = NULL;
 
 static short *redset = NULL;
-static short *shiftset = NULL;
+static state_number_t *shiftset = NULL;
 
 static item_number_t **kernel_base = NULL;
 static int *kernel_size = NULL;
@@ -114,7 +109,7 @@ allocate_storage (void)
 {
   allocate_itemsets ();
 
-  shiftset = XCALLOC (short, nsyms);
+  shiftset = XCALLOC (state_number_t, nsyms);
   redset = XCALLOC (short, nrules + 1);
   state_hash = XCALLOC (state_t *, STATE_HASH_SIZE);
   shift_symbol = XCALLOC (symbol_number_t, nsyms);
@@ -193,8 +188,8 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
 	     nstates, symbol, symbol_tag_get (symbols[symbol]));
 
-  if (nstates >= SHRT_MAX)
-    fatal (_("too many states (max %d)"), SHRT_MAX);
+  if (nstates >= STATE_NUMBER_MAX)
+    fatal (_("too many states (max %d)"), STATE_NUMBER_MAX);
 
   p = STATE_ALLOC (core_size);
   p->accessing_symbol = symbol;
@@ -207,7 +202,7 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
   /* If this is the eoftoken, and this is not the initial state, then
      this is the final state.  */
   if (symbol == 0 && first_state)
-    final_state = p->number;
+    final_state = p;
 
   if (!first_state)
     first_state = p;
@@ -227,7 +222,7 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 | equivalent one exists already.  Used by append_states.        |
 `--------------------------------------------------------------*/
 
-static int
+static state_number_t
 get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 {
   int key;
@@ -363,7 +358,7 @@ save_reductions (void)
 
   /* If this is the final state, we want it to have no reductions at
      all, although it has one for `START_SYMBOL EOF .'.  */
-  if (this_state->number == final_state)
+  if (final_state && this_state->number == final_state->number)
     return;
 
   /* Find and count the active items that represent ends of rules. */
