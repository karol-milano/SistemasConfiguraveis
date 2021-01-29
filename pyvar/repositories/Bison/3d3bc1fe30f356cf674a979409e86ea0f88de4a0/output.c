@@ -201,38 +201,27 @@ prepare_symbols (void)
 }
 
 
-/*-------------------------------------------------------------.
-| Prepare the muscles related to the rules: rhs, prhs, r1, r2, |
-| rline, dprec, merger.                                        |
-`-------------------------------------------------------------*/
+/*----------------------------------------------------------------.
+| Prepare the muscles related to the rules: r1, r2, rline, dprec, |
+| merger.                                                         |
+`----------------------------------------------------------------*/
 
 static void
 prepare_rules (void)
 {
-  rule_number r;
-  unsigned int i = 0;
-  item_number *rhs = xnmalloc (nritems, sizeof *rhs);
-  unsigned int *prhs = xnmalloc (nrules, sizeof *prhs);
   unsigned int *rline = xnmalloc (nrules, sizeof *rline);
   symbol_number *r1 = xnmalloc (nrules, sizeof *r1);
   unsigned int *r2 = xnmalloc (nrules, sizeof *r2);
   int *dprec = xnmalloc (nrules, sizeof *dprec);
   int *merger = xnmalloc (nrules, sizeof *merger);
 
+  rule_number r;
   for (r = 0; r < nrules; ++r)
     {
-      item_number *rhsp = NULL;
-      /* Index of rule R in RHS. */
-      prhs[r] = i;
-      /* RHS of the rule R. */
-      for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
-	rhs[i++] = *rhsp;
       /* LHS of the rule R. */
       r1[r] = rules[r].lhs->number;
       /* Length of rule R's RHS. */
-      r2[r] = i - prhs[r];
-      /* Separator in RHS. */
-      rhs[i++] = -1;
+      r2[r] = rule_rhs_length(&rules[r]);
       /* Line where rule was defined. */
       rline[r] = rules[r].location.start.line;
       /* Dynamic precedence (GLR).  */
@@ -240,10 +229,7 @@ prepare_rules (void)
       /* Merger-function index (GLR).  */
       merger[r] = rules[r].merger;
     }
-  aver (i == nritems);
 
-  muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
-  muscle_insert_unsigned_int_table ("prhs", prhs, 0, 0, nrules);
   muscle_insert_unsigned_int_table ("rline", rline, 0, 0, nrules);
   muscle_insert_symbol_number_table ("r1", r1, 0, 0, nrules);
   muscle_insert_unsigned_int_table ("r2", r2, 0, 0, nrules);
@@ -253,8 +239,6 @@ prepare_rules (void)
   MUSCLE_INSERT_INT ("rules_number", nrules);
   MUSCLE_INSERT_INT ("max_left_semantic_context", max_left_semantic_context);
 
-  free (rhs);
-  free (prhs);
   free (rline);
   free (r1);
   free (r2);
