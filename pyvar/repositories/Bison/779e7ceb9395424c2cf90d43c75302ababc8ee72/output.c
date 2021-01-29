@@ -1,6 +1,6 @@
 /* Output the generated parsing program for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -106,7 +106,7 @@ Name (const char *name,							\
 
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_int_table, int)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_table, short)
+GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_short_int_table, short int)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_base_table, base_number)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_rule_number_table, rule_number)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number)
@@ -217,8 +217,8 @@ prepare_rules (void)
   unsigned int *rline = MALLOC (rline, nrules);
   symbol_number *r1 = MALLOC (r1, nrules);
   unsigned int *r2 = MALLOC (r2, nrules);
-  short *dprec = MALLOC (dprec, nrules);
-  short *merger = MALLOC (merger, nrules);
+  short int *dprec = MALLOC (dprec, nrules);
+  short int *merger = MALLOC (merger, nrules);
 
   for (r = 0; r < nrules; ++r)
     {
@@ -249,8 +249,8 @@ prepare_rules (void)
   muscle_insert_unsigned_int_table ("rline", rline, 0, 0, nrules);
   muscle_insert_symbol_number_table ("r1", r1, 0, 0, nrules);
   muscle_insert_unsigned_int_table ("r2", r2, 0, 0, nrules);
-  muscle_insert_short_table ("dprec", dprec, 0, 0, nrules);
-  muscle_insert_short_table ("merger", merger, 0, 0, nrules);
+  muscle_insert_short_int_table ("dprec", dprec, 0, 0, nrules);
+  muscle_insert_short_int_table ("merger", merger, 0, 0, nrules);
 
   MUSCLE_INSERT_INT ("rules_number", nrules);
   MUSCLE_INSERT_INT ("max_left_semantic_context", max_left_semantic_context);
