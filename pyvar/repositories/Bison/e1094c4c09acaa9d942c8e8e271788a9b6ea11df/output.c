@@ -99,6 +99,7 @@ GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_int_table, int)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_base_table, base_number)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_rule_number_table, rule_number)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_symbol_number_table, symbol_number)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_item_number_table, item_number)
 GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_state_number_table, state_number)
 
 /*----------------------------------------------------------------.
@@ -200,14 +201,16 @@ prepare_symbols (void)
 }
 
 
-/*----------------------------------------------------------------.
-| Prepare the muscles related to the rules: r1, r2, rline, dprec, |
-| merger, immediate.                                              |
-`----------------------------------------------------------------*/
+/*-------------------------------------------------------------.
+| Prepare the muscles related to the rules: rhs, prhs, r1, r2, |
+| rline, dprec, merger, immediate.                             |
+`-------------------------------------------------------------*/
 
 static void
 prepare_rules (void)
 {
+  unsigned *prhs = xnmalloc (nrules, sizeof *prhs);
+  item_number *rhs = xnmalloc (nritems, sizeof *rhs);
   unsigned *rline = xnmalloc (nrules, sizeof *rline);
   symbol_number *r1 = xnmalloc (nrules, sizeof *r1);
   unsigned *r2 = xnmalloc (nrules, sizeof *r2);
@@ -215,14 +218,24 @@ prepare_rules (void)
   int *merger = xnmalloc (nrules, sizeof *merger);
   int *immediate = xnmalloc (nrules, sizeof *immediate);
 
+  /* Index in RHS.  */
+  unsigned i = 0;
   for (rule_number r = 0; r < nrules; ++r)
     {
+      /* Index of rule R in RHS. */
+      prhs[r] = i;
+      /* RHS of the rule R. */
+      for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
+	rhs[i++] = *rhsp;
+      /* Separator in RHS. */
+      rhs[i++] = -1;
+
+      /* Line where rule was defined. */
+      rline[r] = rules[r].location.start.line;
       /* LHS of the rule R. */
       r1[r] = rules[r].lhs->number;
       /* Length of rule R's RHS. */
-      r2[r] = rule_rhs_length (&rules[r]);
-      /* Line where rule was defined. */
-      rline[r] = rules[r].location.start.line;
+      r2[r] = rule_rhs_length(&rules[r]);
       /* Dynamic precedence (GLR).  */
       dprec[r] = rules[r].dprec;
       /* Merger-function index (GLR).  */
@@ -230,7 +243,10 @@ prepare_rules (void)
       /* Immediate reduction flags (GLR).  */
       immediate[r] = rules[r].is_predicate;
     }
+  aver (i == nritems);
 
+  muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
+  muscle_insert_unsigned_int_table ("prhs", prhs, 0, 0, nrules);
   muscle_insert_unsigned_int_table ("rline", rline, 0, 0, nrules);
   muscle_insert_symbol_number_table ("r1", r1, 0, 0, nrules);
   muscle_insert_unsigned_int_table ("r2", r2, 0, 0, nrules);
@@ -241,6 +257,8 @@ prepare_rules (void)
   MUSCLE_INSERT_INT ("rules_number", nrules);
   MUSCLE_INSERT_INT ("max_left_semantic_context", max_left_semantic_context);
 
+  free (prhs);
+  free (rhs);
   free (rline);
   free (r1);
   free (r2);
