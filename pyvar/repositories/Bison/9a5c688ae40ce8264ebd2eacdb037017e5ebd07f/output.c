@@ -64,8 +64,8 @@ Name (char const *name,                                                 \
 {                                                                       \
   Type min = first;                                                     \
   Type max = first;                                                     \
-  long int lmin;                                                        \
-  long int lmax;                                                        \
+  long lmin;                                                        \
+  long lmax;                                                        \
   int i;                                                                \
   int j = 1;                                                            \
                                                                         \
@@ -97,7 +97,7 @@ Name (char const *name,                                                 \
   MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmax);     \
 }
 
-GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_unsigned_int_table, unsigned int)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_unsigned_int_table, unsigned)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_int_table, int)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_base_table, base_number)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_rule_number_table, rule_number)
@@ -213,9 +213,9 @@ prepare_symbols (void)
 static void
 prepare_rules (void)
 {
-  unsigned int *rline = xnmalloc (nrules, sizeof *rline);
+  unsigned *rline = xnmalloc (nrules, sizeof *rline);
   symbol_number *r1 = xnmalloc (nrules, sizeof *r1);
-  unsigned int *r2 = xnmalloc (nrules, sizeof *r2);
+  unsigned *r2 = xnmalloc (nrules, sizeof *r2);
   int *dprec = xnmalloc (nrules, sizeof *dprec);
   int *merger = xnmalloc (nrules, sizeof *merger);
   int *immediate = xnmalloc (nrules, sizeof *immediate);
