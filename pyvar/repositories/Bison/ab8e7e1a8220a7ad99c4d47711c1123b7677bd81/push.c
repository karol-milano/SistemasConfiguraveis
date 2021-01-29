@@ -151,11 +151,11 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
 ]b4_identification
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
-#define yyparse b4_prefix[]parse
 ]b4_push_if([#define yypush_parse b4_prefix[]push_parse
 #define yypstate_new b4_prefix[]pstate_new
 #define yypstate_delete b4_prefix[]pstate_delete
-#define yypstate b4_prefix[]pstate])[
+#define yypstate b4_prefix[]pstate],
+[#define yyparse b4_prefix[]parse])[
 #define yylex   b4_prefix[]lex
 #define yyerror b4_prefix[]error
 #define yylval  b4_prefix[]lval
@@ -961,13 +961,6 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 /* Prevent warnings from -Wmissing-prototypes.  */
 
-#ifdef YYPARSE_PARAM
-]b4_c_function_decl([yyparse], [int],
-   [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
-#else /* ! YYPARSE_PARAM */
-]b4_c_function_decl([yyparse], [int], b4_parse_param)[
-#endif /* ! YYPARSE_PARAM */
-
 ]b4_push_if([
 struct yypstate;
 enum { YYPUSH_MORE = 4 };
@@ -978,7 +971,12 @@ enum { YYPUSH_MORE = 4 };
    [[int yynchar], [yynchar]],
    [[YYSTYPE const *yynlval], [yynlval]]
    b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
-])[
+],[#ifdef YYPARSE_PARAM
+]b4_c_function_decl([yyparse], [int],
+   [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
+#else /* ! YYPARSE_PARAM */
+]b4_c_function_decl([yyparse], [int], b4_parse_param)[
+#endif /* ! YYPARSE_PARAM */])[
 
 ]m4_divert_push([KILL])# ======================== M4 code.
 # b4_declare_parser_variables
