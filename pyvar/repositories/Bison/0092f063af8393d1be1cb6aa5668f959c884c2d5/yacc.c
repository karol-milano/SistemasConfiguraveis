@@ -826,8 +826,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif
 ]])
 m4_ifdef([b4_initial_action], [
-m4_pushdef([b4_at_dollar],     [(yylloc)])dnl
-m4_pushdef([b4_dollar_dollar], [(yylval)])dnl
+m4_pushdef([b4_at_dollar],     [yylloc])dnl
+m4_pushdef([b4_dollar_dollar], [yylval])dnl
   /* User initialization code. */
   b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
