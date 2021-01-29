@@ -821,20 +821,23 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 ]b4_location_if([[  yylsp = yyls;
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
-  yyls[0].first_line   = yyls[0].last_line   = 1;
-  yyls[0].first_column = yyls[0].last_column = 0;
+  yylloc.first_line   = yylloc.last_line   = 1;
+  yylloc.first_column = yylloc.last_column = 0;
 #endif
 ]])
 m4_ifdef([b4_initial_action], [
-m4_pushdef([b4_at_dollar],     [(*yylsp)])dnl
-m4_pushdef([b4_dollar_dollar], [(*yyvsp)])dnl
+m4_pushdef([b4_at_dollar],     [(yylloc)])dnl
+m4_pushdef([b4_dollar_dollar], [(yylval)])dnl
   /* User initialization code. */
   b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
 m4_popdef([b4_at_dollar])dnl
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])])dnl
-
+[
+  yyvsp[0] = yylval;
+]b4_location_if([[    yylsp[0] = yylloc;
+]])
 [  goto yysetstate;
 
 /*------------------------------------------------------------.
