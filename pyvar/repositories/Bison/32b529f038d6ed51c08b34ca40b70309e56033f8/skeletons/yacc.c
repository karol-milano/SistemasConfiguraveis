@@ -1038,7 +1038,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 }]])[
 
 
-]m4_case(b4_percent_define_get([parse.error]), [verbose],
+]m4_case(b4_percent_define_get([[parse.error]]), [verbose],
 [[# ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
 #   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
@@ -1424,7 +1424,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   YYSTYPE yyval;]b4_locations_if([[
   YYLTYPE yyloc;]])[
 
-]m4_case(b4_percent_define_get([parse.error]), [verbose],
+]m4_case(b4_percent_define_get([[parse.error]]), [verbose],
 [[  /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
   char *yymsg = yymsgbuf;
@@ -1745,7 +1745,7 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-]m4_case(b4_percent_define_get([parse.error]),
+]m4_case(b4_percent_define_get([[parse.error]]),
          [simple],
 [[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
          [verbose],
@@ -1943,7 +1943,7 @@ yyreturn:
 | yypushreturn -- ask for the next token.  |
 `-----------------------------------------*/
 yypushreturn:]])[
-]m4_case(b4_percent_define_get([parse.error]), [verbose],
+]m4_case(b4_percent_define_get([[parse.error]]), [verbose],
 [[  if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);]])[
   return yyresult;
