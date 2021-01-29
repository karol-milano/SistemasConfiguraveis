@@ -2302,12 +2302,10 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #endif
 ])
 m4_ifdef([b4_initial_action], [
-m4_pushdef([b4_at_dollar],     [yylloc])dnl
-m4_pushdef([b4_dollar_dollar], [yylval])dnl
-  /* User initialization code.  */
-  b4_user_initial_action
-m4_popdef([b4_dollar_dollar])dnl
-m4_popdef([b4_at_dollar])])dnl
+b4_dollar_pushdef([yylval], [], [yylloc])dnl
+/* User initialization code.  */
+b4_user_initial_action
+b4_dollar_popdef])[]dnl
 [
   if (! yyinitGLRStack (yystackp, YYINITDEPTH))
     goto yyexhaustedlab;
