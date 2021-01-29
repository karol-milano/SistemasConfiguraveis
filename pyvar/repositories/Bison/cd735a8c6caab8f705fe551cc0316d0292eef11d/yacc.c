@@ -1570,17 +1570,16 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
 #endif]])
 m4_ifdef([b4_initial_action],[
-m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
-m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
+b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [],
+                  [m4_define([b4_at_dollar_used])yylloc])dnl
 /* User initialization code.  */
 b4_user_initial_action
-m4_popdef([b4_dollar_dollar])dnl
-m4_popdef([b4_at_dollar])])dnl
+b4_dollar_popdef[]dnl
 m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
 ]])dnl
 m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
-]])[
-  goto yysetstate;
+]])])dnl
+[  goto yysetstate;
 
 /*------------------------------------------------------------.
 | yynewstate -- Push a new state, which is found in yystate.  |
