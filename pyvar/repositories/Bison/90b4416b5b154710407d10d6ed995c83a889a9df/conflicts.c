@@ -60,7 +60,7 @@ flush_shift (int state, int token)
   shifts *shiftp;
   int k, i;
 
-  shiftp = shift_table[state];
+  shiftp = state_table[state].shift_table;
 
   if (shiftp)
     {
@@ -197,7 +197,7 @@ set_conflicts (int state)
   for (i = 0; i < tokensetsize; i++)
     lookaheadset[i] = 0;
 
-  shiftp = shift_table[state];
+  shiftp = state_table[state].shift_table;
   if (shiftp)
     {
       k = shiftp->nshifts;
@@ -288,7 +288,7 @@ count_sr_conflicts (int state)
 
   int src_count = 0;
 
-  shiftp = shift_table[state];
+  shiftp = state_table[state].shift_table;
   if (!shiftp)
     return 0;
 
@@ -533,7 +533,7 @@ print_reductions (FILE *out, int state)
   for (i = 0; i < tokensetsize; i++)
     shiftset[i] = 0;
 
-  shiftp = shift_table[state];
+  shiftp = state_table[state].shift_table;
   if (shiftp)
     {
       k = shiftp->nshifts;
