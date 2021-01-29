@@ -156,12 +156,6 @@ set_state_table (void)
       state_table[sp->number]->shifts = sp;
   }
 
-  {
-    reductions *rp;
-    for (rp = first_reduction; rp; rp = rp->next)
-      state_table[rp->number]->reductions = rp;
-  }
-
   /* Pessimization, but simplification of the code: make sure all the
      states have a shifts, even if reduced to 0 shifts.  */
   {
