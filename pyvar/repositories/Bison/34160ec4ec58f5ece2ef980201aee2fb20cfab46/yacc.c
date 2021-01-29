@@ -859,8 +859,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif
 ]])
 m4_ifdef([b4_initial_action], [
-m4_pushdef([b4_at_dollar],     [yylloc])dnl
-m4_pushdef([b4_dollar_dollar], [yylval])dnl
+m4_pushdef([b4_at_dollar],     [[yylsp[0]]])dnl
+m4_pushdef([b4_dollar_dollar], [[yyvsp[0]]])dnl
   /* User initialization code. */
 b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
@@ -868,10 +868,7 @@ m4_popdef([b4_at_dollar])dnl
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])])dnl
 [
-  yyvsp[0] = yylval;
-]b4_location_if([[    yylsp[0] = yylloc;
-]])
-[  goto yysetstate;
+  goto yysetstate;
 
 /*------------------------------------------------------------.
 | yynewstate -- Push a new state, which is found in yystate.  |
