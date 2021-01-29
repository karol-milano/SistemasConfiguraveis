@@ -541,22 +541,20 @@ save_reductions (void)
 static void
 set_state_table (void)
 {
+  state_t *sp;
   state_table = XCALLOC (state_t *, nstates);
 
-  {
-    state_t *sp;
-    for (sp = first_state; sp; sp = sp->next)
+  for (sp = first_state; sp; sp = sp->next)
+    {
+      /* Pessimization, but simplification of the code: make sure all
+	 the states have a shifts and errs, even if reduced to 0.  */
+      if (!sp->shifts)
+	sp->shifts = shifts_new (0);
+      if (!sp->errs)
+	sp->errs = errs_new (0);
+
       state_table[sp->number] = sp;
-  }
-
-  /* Pessimization, but simplification of the code: make sure all the
-     states have a shifts, even if reduced to 0 shifts.  */
-  {
-    int i;
-    for (i = 0; i < nstates; i++)
-      if (!state_table[i]->shifts)
-	state_table[i]->shifts = shifts_new (0);
-  }
+    }
 }
 
 /*-------------------------------------------------------------------.
