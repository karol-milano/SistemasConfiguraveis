@@ -126,7 +126,7 @@ state *final_state = NULL;
 
 state *
 state_new (symbol_number accessing_symbol,
-           size_t nitems, item_number *core)
+           size_t nitems, item_index *core)
 {
   aver (nstates < STATE_NUMBER_MAXIMUM);
 
@@ -395,7 +395,7 @@ state_hash_insert (state *s)
 `------------------------------------------------------------------*/
 
 state *
-state_hash_lookup (size_t nitems, item_number *core)
+state_hash_lookup (size_t nitems, item_index *core)
 {
   size_t items_size = nitems * sizeof *core;
   state *probe = xmalloc (offsetof (state, items) + items_size);
