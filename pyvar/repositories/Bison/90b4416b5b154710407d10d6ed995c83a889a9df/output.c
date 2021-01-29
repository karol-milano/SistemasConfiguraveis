@@ -338,7 +338,7 @@ action_row (int state)
 
   default_rule = 0;
   nreds = 0;
-  redp = reduction_table[state];
+  redp = state_table[state].reduction_table;
 
   if (redp)
     {
@@ -377,7 +377,7 @@ action_row (int state)
 	}
     }
 
-  shiftp = shift_table[state];
+  shiftp = state_table[state].shift_table;
 
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
@@ -552,8 +552,6 @@ free_shifts (void)
 {
   shifts *sp, *sptmp;	/* JF derefrenced freed ptr */
 
-  XFREE (shift_table);
-
   for (sp = first_shift; sp; sp = sptmp)
     {
       sptmp = sp->next;
@@ -567,8 +565,6 @@ free_reductions (void)
 {
   reductions *rp, *rptmp;	/* JF fixed freed ptr */
 
-  XFREE (reduction_table);
-
   for (rp = first_reduction; rp; rp = rptmp)
     {
       rptmp = rp->next;
