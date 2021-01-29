@@ -1833,8 +1833,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 #endif
 ])
 m4_ifdef([b4_initial_action], [
-m4_pushdef([b4_at_dollar],     [(yylval)])dnl
-m4_pushdef([b4_dollar_dollar], [(yylloc)])dnl
+m4_pushdef([b4_at_dollar],     [yylval])dnl
+m4_pushdef([b4_dollar_dollar], [yylloc])dnl
   /* User initialization code. */
   b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
