@@ -91,7 +91,6 @@ Name (char const *name, Type *table_data, Type first,                   \
   MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmax);     \
 }
 
-GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_unsigned_table, unsigned)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_int_table, int)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_base_table, base_number)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_rule_number_table, rule_number)
@@ -214,17 +213,17 @@ prepare_symbols (void)
 static void
 prepare_rules (void)
 {
-  unsigned *prhs = xnmalloc (nrules, sizeof *prhs);
+  int *prhs = xnmalloc (nrules, sizeof *prhs);
   item_number *rhs = xnmalloc (nritems, sizeof *rhs);
-  unsigned *rline = xnmalloc (nrules, sizeof *rline);
+  int *rline = xnmalloc (nrules, sizeof *rline);
   symbol_number *r1 = xnmalloc (nrules, sizeof *r1);
-  unsigned *r2 = xnmalloc (nrules, sizeof *r2);
+  int *r2 = xnmalloc (nrules, sizeof *r2);
   int *dprec = xnmalloc (nrules, sizeof *dprec);
   int *merger = xnmalloc (nrules, sizeof *merger);
   int *immediate = xnmalloc (nrules, sizeof *immediate);
 
   /* Index in RHS.  */
-  unsigned i = 0;
+  int i = 0;
   for (rule_number r = 0; r < nrules; ++r)
     {
       /* Index of rule R in RHS. */
@@ -251,10 +250,10 @@ prepare_rules (void)
   aver (i == nritems);
 
   muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
-  muscle_insert_unsigned_table ("prhs", prhs, 0, 0, nrules);
-  muscle_insert_unsigned_table ("rline", rline, 0, 0, nrules);
+  muscle_insert_int_table ("prhs", prhs, 0, 0, nrules);
+  muscle_insert_int_table ("rline", rline, 0, 0, nrules);
   muscle_insert_symbol_number_table ("r1", r1, 0, 0, nrules);
-  muscle_insert_unsigned_table ("r2", r2, 0, 0, nrules);
+  muscle_insert_int_table ("r2", r2, 0, 0, nrules);
   muscle_insert_int_table ("dprec", dprec, 0, 0, nrules);
   muscle_insert_int_table ("merger", merger, 0, 0, nrules);
   muscle_insert_int_table ("immediate", immediate, 0, 0, nrules);
@@ -542,10 +541,10 @@ prepare_actions (void)
      parser, so we could avoid accidents by not writing them out in
      that case.  Nevertheless, it seems even better to be able to use
      the GLR skeletons even without the non-deterministic tables.  */
-  muscle_insert_unsigned_table ("conflict_list_heads", conflict_table,
-                                conflict_table[0], 1, high + 1);
-  muscle_insert_unsigned_table ("conflicting_rules", conflict_list,
-                                0, 1, conflict_list_cnt);
+  muscle_insert_int_table ("conflict_list_heads", conflict_table,
+                           conflict_table[0], 1, high + 1);
+  muscle_insert_int_table ("conflicting_rules", conflict_list,
+                           0, 1, conflict_list_cnt);
 }
 
 
