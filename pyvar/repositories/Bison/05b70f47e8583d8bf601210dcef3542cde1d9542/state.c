@@ -143,7 +143,7 @@ state_new (symbol_number accessing_symbol,
   res->reductions = NULL;
   res->errs = NULL;
   res->state_list = NULL;
-  res->consistent = 0;
+  res->consistent = false;
   res->solved_conflicts = NULL;
   res->solved_conflicts_xml = NULL;
 
