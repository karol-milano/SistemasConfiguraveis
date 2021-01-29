@@ -217,7 +217,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 #define YYLTYPE ]b4_api_PREFIX[LTYPE]])])[
 ]m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
-#define yyparse ]b4_prefix[parse
+#define ]b4_glr_cc_if([yy_parse_impl], [yyparse])[ ]b4_prefix[]b4_glr_cc_if([_parse_impl], [parse])[
 #define yylex   ]b4_prefix[lex
 #define yyerror ]b4_prefix[error
 #define yydebug ]b4_prefix[debug]]b4_pure_if([], [[
@@ -2422,7 +2422,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 `----------*/
 
 int
-yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
+]b4_glr_cc_if([yy_parse_impl], [yyparse])[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
   int yyresult;
   yyGLRStack yystack;
