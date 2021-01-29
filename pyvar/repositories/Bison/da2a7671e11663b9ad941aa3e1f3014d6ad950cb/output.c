@@ -192,7 +192,7 @@ prepare_symbols (void)
   /* Output YYTOKNUM. */
   {
     int i;
-    int *values = MALLOC (values, ntokens);
+    int *values = xnmalloc (ntokens, sizeof *values);
     for (i = 0; i < ntokens; ++i)
       values[i] = symbols[i]->user_token_number;
     muscle_insert_int_table ("toknum", values,
@@ -212,13 +212,13 @@ prepare_rules (void)
 {
   rule_number r;
   unsigned int i = 0;
-  item_number *rhs = MALLOC (rhs, nritems);
-  unsigned int *prhs = MALLOC (prhs, nrules);
-  unsigned int *rline = MALLOC (rline, nrules);
-  symbol_number *r1 = MALLOC (r1, nrules);
-  unsigned int *r2 = MALLOC (r2, nrules);
-  short int *dprec = MALLOC (dprec, nrules);
-  short int *merger = MALLOC (merger, nrules);
+  item_number *rhs = xnmalloc (nritems, sizeof *rhs);
+  unsigned int *prhs = xnmalloc (nrules, sizeof *prhs);
+  unsigned int *rline = xnmalloc (nrules, sizeof *rline);
+  symbol_number *r1 = xnmalloc (nrules, sizeof *r1);
+  unsigned int *r2 = xnmalloc (nrules, sizeof *r2);
+  short int *dprec = xnmalloc (nrules, sizeof *dprec);
+  short int *merger = xnmalloc (nrules, sizeof *merger);
 
   for (r = 0; r < nrules; ++r)
     {
@@ -272,7 +272,7 @@ static void
 prepare_states (void)
 {
   state_number i;
-  symbol_number *values = MALLOC (values, nstates);
+  symbol_number *values = xnmalloc (nstates, sizeof *values);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
   muscle_insert_symbol_number_table ("stos", values,
@@ -498,7 +498,7 @@ prepare_actions (void)
   muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table,
 				    conflict_table[0], 1, high + 1);
   muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
-				    conflict_list[0], 1, conflict_list_cnt);
+				    0, 1, conflict_list_cnt);
 }
 
 
