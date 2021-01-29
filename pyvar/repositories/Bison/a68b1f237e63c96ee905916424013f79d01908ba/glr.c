@@ -223,11 +223,11 @@ b4_percent_code_get([[top]])[
 #endif
 
 /* Default (constant) value used for initialization for null
-   right-hand sides.  Unlike the standard yacc.c template,
-   here we set the default value of $$ to a zeroed-out value.
-   Since the default value is undefined, this behavior is
-   technically correct.  */
-static YYSTYPE yyval_default;
+   right-hand sides.  Unlike the standard yacc.c template, here we set
+   the default value of $$ to a zeroed-out value.  Since the default
+   value is undefined, this behavior is technically correct.  */
+static YYSTYPE yyval_default;]b4_locations_if([
+b4_yyloc_default_define])[
 
 /* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
@@ -2295,14 +2295,9 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   yychar = YYEMPTY;
-  yylval = yyval_default;
-]b4_locations_if([
-#if defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
-  yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
-  yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
-#endif
-])
-m4_ifdef([b4_initial_action], [
+  yylval = yyval_default;]b4_locations_if([
+  yylloc = yyloc_default;])[
+]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([yylval], [], [yylloc])dnl
 /* User initialization code.  */
 b4_user_initial_action
