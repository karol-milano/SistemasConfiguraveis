@@ -807,7 +807,17 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   yyssp = yyss;
   yyvsp = yyvs;
 ]b4_location_if([  yylsp = yyls;])[
-  goto yysetstate;
+]m4_ifdef([b4_initial_action], [
+m4_pushdef([b4_at_dollar],     [(*yylsp)])dnl
+m4_pushdef([b4_dollar_dollar], [(*yyvsp)])dnl
+  /* User initialization code. */
+  b4_initial_action
+m4_popdef([b4_dollar_dollar])dnl
+m4_popdef([b4_at_dollar])dnl
+/* Line __line__ of yacc.c.  */
+b4_syncline([@oline@], [@ofile@])])dnl
+
+[  goto yysetstate;
 
 /*------------------------------------------------------------.
 | yynewstate -- Push a new state, which is found in yystate.  |
