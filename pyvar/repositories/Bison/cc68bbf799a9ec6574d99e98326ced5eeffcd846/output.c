@@ -596,9 +596,7 @@ prepare_symbol_definitions (void)
 static void
 prepare_actions (void)
 {
-  /* Figure out the actions for the specified state, indexed by
-     lookahead token type.  */
-
+  /* Figure out the actions for the specified state.  */
   muscle_insert_rule_number_table ("defact", yydefact,
                                    yydefact[0], 1, nstates);
 
