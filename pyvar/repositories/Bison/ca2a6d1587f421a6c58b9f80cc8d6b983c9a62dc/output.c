@@ -204,7 +204,7 @@ prepare_symbols (void)
 
 /*----------------------------------------------------------------.
 | Prepare the muscles related to the rules: r1, r2, rline, dprec, |
-| merger.                                                         |
+| merger, immediate.                                              |
 `----------------------------------------------------------------*/
 
 static void
@@ -215,6 +215,7 @@ prepare_rules (void)
   unsigned int *r2 = xnmalloc (nrules, sizeof *r2);
   int *dprec = xnmalloc (nrules, sizeof *dprec);
   int *merger = xnmalloc (nrules, sizeof *merger);
+  int *immediate = xnmalloc (nrules, sizeof *immediate);
 
   rule_number r;
   for (r = 0; r < nrules; ++r)
@@ -229,6 +230,8 @@ prepare_rules (void)
       dprec[r] = rules[r].dprec;
       /* Merger-function index (GLR).  */
       merger[r] = rules[r].merger;
+      /* Immediate reduction flags (GLR).  */
+      immediate[r] = rules[r].is_predicate;
     }
 
   muscle_insert_unsigned_int_table ("rline", rline, 0, 0, nrules);
@@ -236,6 +239,7 @@ prepare_rules (void)
   muscle_insert_unsigned_int_table ("r2", r2, 0, 0, nrules);
   muscle_insert_int_table ("dprec", dprec, 0, 0, nrules);
   muscle_insert_int_table ("merger", merger, 0, 0, nrules);
+  muscle_insert_int_table ("immediate", immediate, 0, 0, nrules);
 
   MUSCLE_INSERT_INT ("rules_number", nrules);
   MUSCLE_INSERT_INT ("max_left_semantic_context", max_left_semantic_context);
@@ -349,8 +353,9 @@ user_actions_output (FILE *out)
   for (r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
-	fprintf (out, "b4_case(%d, [b4_syncline(%d, ", r + 1,
-		 rules[r].action_location.start.line);
+	fprintf (out, "b4_%scase(%d, [b4_syncline(%d, ",
+		 rules[r].is_predicate ? "predicate_" : "",
+		 r + 1, rules[r].action_location.start.line);
 	escaped_output (out, rules[r].action_location.start.file);
 	fprintf (out, ")\n[    %s]])\n\n", rules[r].action);
       }
