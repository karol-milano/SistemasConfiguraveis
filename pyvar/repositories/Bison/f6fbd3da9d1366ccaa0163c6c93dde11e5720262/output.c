@@ -106,7 +106,6 @@ Name (const char *name,							\
 
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_int_table, int)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_int_table, short int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_base_table, base_number)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_rule_number_table, rule_number)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number)
@@ -217,8 +216,8 @@ prepare_rules (void)
   unsigned int *rline = xnmalloc (nrules, sizeof *rline);
   symbol_number *r1 = xnmalloc (nrules, sizeof *r1);
   unsigned int *r2 = xnmalloc (nrules, sizeof *r2);
-  short int *dprec = xnmalloc (nrules, sizeof *dprec);
-  short int *merger = xnmalloc (nrules, sizeof *merger);
+  int *dprec = xnmalloc (nrules, sizeof *dprec);
+  int *merger = xnmalloc (nrules, sizeof *merger);
 
   for (r = 0; r < nrules; ++r)
     {
@@ -249,8 +248,8 @@ prepare_rules (void)
   muscle_insert_unsigned_int_table ("rline", rline, 0, 0, nrules);
   muscle_insert_symbol_number_table ("r1", r1, 0, 0, nrules);
   muscle_insert_unsigned_int_table ("r2", r2, 0, 0, nrules);
-  muscle_insert_short_int_table ("dprec", dprec, 0, 0, nrules);
-  muscle_insert_short_int_table ("merger", merger, 0, 0, nrules);
+  muscle_insert_int_table ("dprec", dprec, 0, 0, nrules);
+  muscle_insert_int_table ("merger", merger, 0, 0, nrules);
 
   MUSCLE_INSERT_INT ("rules_number", nrules);
   MUSCLE_INSERT_INT ("max_left_semantic_context", max_left_semantic_context);
