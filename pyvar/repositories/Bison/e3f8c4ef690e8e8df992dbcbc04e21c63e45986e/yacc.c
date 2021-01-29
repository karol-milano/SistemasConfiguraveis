@@ -1513,7 +1513,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   int yyn;
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  int yytoken;
+  int yytoken = 0;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
@@ -1538,7 +1538,6 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
       goto yyread_pushed_token;
     }]])[
 
-  yytoken = 0;
   yyss = yyssa;
   yyvs = yyvsa;]b4_locations_if([[
   yyls = yylsa;]])[
