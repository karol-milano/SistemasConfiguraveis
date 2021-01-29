@@ -215,7 +215,7 @@ Name (const char *name,							\
 
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_table, short)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_token_number_table, token_number_t)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number_t)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
 
 
@@ -227,7 +227,7 @@ GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
 static void
 prepare_tokens (void)
 {
-  muscle_insert_token_number_table ("translate",
+  muscle_insert_symbol_number_table ("translate",
 				    token_translations,
 				    0, 1, max_user_token_number + 1);
 
@@ -290,7 +290,7 @@ prepare_rules (void)
   item_number_t *rhs = XMALLOC (item_number_t, nritems);
   unsigned int *prhs = XMALLOC (unsigned int, nrules + 1);
   unsigned int *rline = XMALLOC (unsigned int, nrules + 1);
-  token_number_t *r1 = XMALLOC (token_number_t, nrules + 1);
+  symbol_number_t *r1 = XMALLOC (symbol_number_t, nrules + 1);
   unsigned int *r2 = XMALLOC (unsigned int, nrules + 1);
 
   for (r = 1; r < nrules + 1; ++r)
@@ -315,7 +315,7 @@ prepare_rules (void)
   muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
   muscle_insert_unsigned_int_table ("prhs", prhs, 0, 1, nrules + 1);
   muscle_insert_unsigned_int_table ("rline", rline, 0, 1, nrules + 1);
-  muscle_insert_token_number_table ("r1", r1, 0, 1, nrules + 1);
+  muscle_insert_symbol_number_table ("r1", r1, 0, 1, nrules + 1);
   muscle_insert_unsigned_int_table ("r2", r2, 0, 1, nrules + 1);
 
   free (rhs);
@@ -333,11 +333,11 @@ static void
 prepare_states (void)
 {
   size_t i;
-  token_number_t *values =
-    (token_number_t *) alloca (sizeof (token_number_t) * nstates);
+  symbol_number_t *values =
+    (symbol_number_t *) alloca (sizeof (symbol_number_t) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
-  muscle_insert_token_number_table ("stos", values,
+  muscle_insert_symbol_number_table ("stos", values,
 				    0, 1, nstates);
 }
 
@@ -390,7 +390,7 @@ action_row (state_t *state)
      to reduce.  */
   for (i = 0; i < shiftp->nshifts; i++)
     {
-      token_number_t symbol;
+      symbol_number_t symbol;
       int shift_state = shiftp->shifts[i];
       if (!shift_state)
 	continue;
