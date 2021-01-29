@@ -122,7 +122,7 @@ reductions_new (int num, rule_number_t *reductions)
 
 state_number_t nstates = 0;
 /* FINAL_STATE is properly set by new_state when it recognizes its
-   accessing symbol: EOF.  */
+   accessing symbol: $end.  */
 state_t *final_state = NULL;
 
 #define STATE_ALLOC(Nitems)						\
