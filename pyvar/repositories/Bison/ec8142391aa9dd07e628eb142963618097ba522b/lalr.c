@@ -158,7 +158,7 @@ map_goto (state_number src, symbol_number sym)
 
 /* Build goto_follows. */
 static void
-initialize_F (void)
+initialize_goto_follows (void)
 {
   goto_number **reads = xnmalloc (ngotos, sizeof *reads);
   goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
@@ -457,7 +457,7 @@ lalr (void)
 {
   initialize_LA ();
   set_goto_map ();
-  initialize_F ();
+  initialize_goto_follows ();
   lookback = xcalloc (nLA, sizeof *lookback);
   build_relations ();
   compute_follows ();
