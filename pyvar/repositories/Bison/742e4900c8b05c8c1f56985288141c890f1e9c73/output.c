@@ -448,7 +448,7 @@ static void
 prepare_actions (void)
 {
   /* Figure out the actions for the specified state, indexed by
-     look-ahead token type.  */
+     lookahead token type.  */
 
   muscle_insert_rule_number_table ("defact", yydefact,
 				   yydefact[0], 1, nstates);
