@@ -1480,7 +1480,7 @@ yypull_parse (yypstate *yyps]b4_user_formals[)
 ]b4_parse_state_variable_macros([b4_pstate_macro_define])[
 
 /* Initialize the parser data structure.  */
-void
+static void
 yypstate_clear (yypstate *yyps)
 {
 ]b4_initialize_parser_state_variables[
