@@ -253,6 +253,7 @@ prepare_rules (void)
   muscle_insert_short_table ("merger", merger, 0, 0, nrules);
 
   MUSCLE_INSERT_INT ("rules_number", nrules);
+  MUSCLE_INSERT_INT ("max_left_semantic_context", max_left_semantic_context);
 
   free (rhs);
   free (prhs);
