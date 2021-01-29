@@ -226,8 +226,8 @@ b4_percent_code_get([[top]])[
    right-hand sides.  Unlike the standard yacc.c template, here we set
    the default value of $$ to a zeroed-out value.  Since the default
    value is undefined, this behavior is technically correct.  */
-static YYSTYPE yyval_default;]b4_locations_if([
-b4_yyloc_default_define])[
+static YYSTYPE yyval_default;]b4_locations_if([[
+static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 
 /* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
