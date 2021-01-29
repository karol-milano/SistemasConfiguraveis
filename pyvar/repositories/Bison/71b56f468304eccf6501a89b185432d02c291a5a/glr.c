@@ -52,7 +52,7 @@ m4_ifndef([b4_pure_flag],
 # This is not shared with yacc.c in c.m4 because  GLR relies on ISO C
 # formal argument declarations.
 m4_define([b4_user_formals],
-[m4_ifset([b4_parse_param], [, b4_c_ansi_formals(b4_parse_param)])])
+[m4_ifset([b4_parse_param], [, b4_c_formals(b4_parse_param)])])
 
 
 # b4_lex_param
@@ -178,7 +178,7 @@ m4_define([b4_shared_declarations],
 ]b4_percent_code_get([[requires]])[
 ]b4_token_enums[
 ]b4_declare_yylstype[
-]b4_c_ansi_function_decl(b4_prefix[parse], [int], b4_parse_param)[
+]b4_c_function_decl(b4_prefix[parse], [int], b4_parse_param)[
 ]b4_percent_code_get([[provides]])[]dnl
 ])
 
@@ -491,7 +491,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
       YYFPRINTF Args;                           \
   } while (YYID (0))
 
-]b4_yy_symbol_print_generate([b4_c_ansi_function_def])[
+]b4_yy_symbol_print_generate([b4_c_function_def])[
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
   do {                                                                  \
@@ -872,7 +872,7 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 
                               /* Bison grammar-table manipulation.  */
 
-]b4_yydestruct_generate([b4_c_ansi_function_def])[
+]b4_yydestruct_generate([b4_c_function_def])[
 
 /** Number of symbols composing the right hand side of rule #RULE.  */
 static inline int
@@ -2276,7 +2276,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 | yyparse.  |
 `----------*/
 
-]b4_c_ansi_function_def([yyparse], [int], b4_parse_param)[
+]b4_c_function_def([yyparse], [int], b4_parse_param)[
 {
   int yyresult;
   yyGLRStack yystack;
