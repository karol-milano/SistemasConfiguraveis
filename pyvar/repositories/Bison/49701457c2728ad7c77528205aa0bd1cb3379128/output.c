@@ -885,6 +885,7 @@ output_check (void)
 static void
 output_actions (void)
 {
+  int i;
   nvectors = nstates + nvars;
 
   froms = XCALLOC (short *, nvectors);
@@ -893,8 +894,6 @@ output_actions (void)
   width = XCALLOC (short, nvectors);
 
   token_actions ();
-  LIST_FREE (shifts, first_shift);
-  LIST_FREE (reductions, first_reduction);
   XFREE (LA);
   XFREE (LAruleno);
 
@@ -910,7 +909,14 @@ output_actions (void)
   output_table ();
 
   output_check ();
-  LIST_FREE (state_t, first_state);
+
+  for (i = 0; i < nstates; ++i)
+    {
+      XFREE (state_table[i]->shifts);
+      XFREE (state_table[i]->reductions);
+      XFREE (state_table[i]->errs);
+      free (state_table[i]);
+    }
   XFREE (state_table);
 }
 
