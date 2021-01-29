@@ -49,7 +49,7 @@ static state_list *last_state = NULL;
 
 /* Print CORE for debugging. */
 static void
-core_print (size_t core_size, item_number *core, FILE *out)
+core_print (size_t core_size, item_index *core, FILE *out)
 {
   for (int i = 0; i < core_size; ++i)
     {
@@ -65,7 +65,7 @@ core_print (size_t core_size, item_number *core, FILE *out)
 `-----------------------------------------------------------------*/
 
 static state *
-state_list_append (symbol_number sym, size_t core_size, item_number *core)
+state_list_append (symbol_number sym, size_t core_size, item_index *core)
 {
   state_list *node = xmalloc (sizeof *node);
   state *res = state_new (sym, core_size, core);
@@ -98,14 +98,14 @@ static rule **redset;
 static state **shiftset;
 
 
-/* KERNEL_BASE[symbol-number] -> list of item numbers (offsets inside
+/* KERNEL_BASE[symbol-number] -> list of item indices (offsets inside
    RITEM) of length KERNEL_SIZE[symbol-number]. */
-static item_number **kernel_base;
+static item_index **kernel_base;
 static int *kernel_size;
 
 /* A single dimension array that serves as storage for
    KERNEL_BASE.  */
-static item_number *kernel_items;
+static item_index *kernel_items;
 
 
 static void
@@ -257,7 +257,7 @@ new_itemsets (state *s)
 `--------------------------------------------------------------*/
 
 static state *
-get_state (symbol_number sym, size_t core_size, item_number *core)
+get_state (symbol_number sym, size_t core_size, item_index *core)
 {
   if (trace_flag & trace_automaton)
     {
@@ -394,7 +394,7 @@ generate_states (void)
 
   /* Create the initial state.  The 0 at the lhs is the index of the
      item of this initial rule.  */
-  item_number initial_core = 0;
+  item_index initial_core = 0;
   state_list_append (0, 1, &initial_core);
 
   /* States are queued when they are created; process them all.  */
