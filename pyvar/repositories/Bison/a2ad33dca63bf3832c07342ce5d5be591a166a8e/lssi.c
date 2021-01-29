@@ -100,7 +100,7 @@ append_lssi (lssi *sn, Hash_table *visited, gl_list_t queue)
 static void
 lssi_print (lssi *l)
 {
-  print_state_item (state_items + l->si, stdout);
+  print_state_item (&state_items[l->si], stdout);
   if (l->lookahead)
     {
       printf ("FOLLOWL = { ");
@@ -175,7 +175,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
           finished = true;
           break;
         }
-      state_item *si = state_items + last;
+      state_item *si = &state_items[last];
       // Transitions don't change follow_L
       if (si->trans >= 0)
         {
@@ -243,7 +243,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
   gl_list_t res =
     gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   for (lssi *sn = n; sn != NULL; sn = sn->parent)
-    gl_list_add_first (res, state_items + sn->si);
+    gl_list_add_first (res, &state_items[sn->si]);
 
   hash_free (visited);
   gl_list_free (queue);
@@ -320,7 +320,7 @@ lssi_reverse_production (const state_item *si, bitset lookahead)
   state_item_number sin;
   BITSET_FOR_EACH (biter, si->revs, sin, 0)
   {
-    state_item *prevsi = state_items + sin;
+    state_item *prevsi = &state_items[sin];
     if (!production_allowed (prevsi, si))
       continue;
     bitset prev_lookahead = prevsi->lookahead;
