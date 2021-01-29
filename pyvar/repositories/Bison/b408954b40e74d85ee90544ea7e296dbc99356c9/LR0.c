@@ -200,8 +200,9 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
   p = STATE_ALLOC (core_size);
   p->accessing_symbol = symbol;
   p->number = nstates;
-  p->nitems = core_size;
+  p->solved_conflicts = NULL;
 
+  p->nitems = core_size;
   memcpy (p->items, core, core_size * sizeof (core[0]));
 
   /* If this is the eoftoken, and this is not the initial state, then
