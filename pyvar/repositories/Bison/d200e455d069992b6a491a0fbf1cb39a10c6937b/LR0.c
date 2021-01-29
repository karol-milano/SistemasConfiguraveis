@@ -541,10 +541,7 @@ save_reductions (void)
 static void
 set_state_table (void)
 {
-  /* NSTATES + 1 because lookahead for the pseudo state number NSTATES
-     might be used (see conflicts.c).  It is too opaque for me to
-     provide a probably less hacky implementation. --akim */
-  state_table = XCALLOC (state_t *, nstates + 1);
+  state_table = XCALLOC (state_t *, nstates);
 
   {
     state_t *sp;
