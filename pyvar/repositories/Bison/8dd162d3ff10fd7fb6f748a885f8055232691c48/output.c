@@ -454,7 +454,7 @@ static void
 prepare_actions (void)
 {
   /* Figure out the actions for the specified state, indexed by
-     lookahead token type.  */
+     look-ahead token type.  */
 
   muscle_insert_rule_number_table ("defact", yydefact,
 				   yydefact[0], 1, nstates);
