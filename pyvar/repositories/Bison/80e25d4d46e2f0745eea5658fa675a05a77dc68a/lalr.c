@@ -153,7 +153,7 @@ set_state_table (void)
   {
     shifts *sp;
     for (sp = first_shift; sp; sp = sp->next)
-      state_table[sp->number]->shifts = sp;
+      assert (state_table[sp->number]->shifts == sp);
   }
 
   /* Pessimization, but simplification of the code: make sure all the
