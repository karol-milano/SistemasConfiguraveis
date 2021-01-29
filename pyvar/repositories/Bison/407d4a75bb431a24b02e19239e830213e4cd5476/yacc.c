@@ -859,16 +859,20 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif
 ]])
 m4_ifdef([b4_initial_action], [
-m4_pushdef([b4_at_dollar],     [[yylsp[0]]])dnl
-m4_pushdef([b4_dollar_dollar], [[yyvsp[0]]])dnl
+m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
+m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
   /* User initialization code. */
 b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
 m4_popdef([b4_at_dollar])dnl
 /* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])])dnl
-[
-  goto yysetstate;
+b4_syncline([@oline@], [@ofile@])
+])dnl
+m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
+]])dnl
+m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
+]])dnl
+[  goto yysetstate;
 
 /*------------------------------------------------------------.
 | yynewstate -- Push a new state, which is found in yystate.  |
