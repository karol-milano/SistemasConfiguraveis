@@ -521,7 +521,7 @@ states_lookaheads_count (void)
     {
       int k;
       int nlookaheads = 0;
-      reductions *rp = states[i]->reductions;
+      reductions_t *rp = states[i]->reductions;
       shifts_t *sp = states[i]->shifts;
 
       /* We need a lookahead either to distinguish different
