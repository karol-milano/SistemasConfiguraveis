@@ -836,7 +836,7 @@ m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [yylval])dnl
   /* User initialization code. */
-  b4_initial_action
+b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
 m4_popdef([b4_at_dollar])dnl
 /* Line __line__ of yacc.c.  */
