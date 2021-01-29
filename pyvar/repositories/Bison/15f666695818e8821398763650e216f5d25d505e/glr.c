@@ -52,7 +52,7 @@ m4_ifndef([b4_pure_flag],
 # This is not shared with yacc.c in c.m4 because  GLR relies on ISO C
 # formal argument declarations.
 m4_define([b4_user_formals],
-[m4_ifset([b4_parse_param], [, b4_c_formals(b4_parse_param)])])
+[m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])])
 
 
 # b4_lex_param
@@ -71,7 +71,7 @@ m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 # a trailing comma.
 m4_define([b4_yyerror_args],
 [b4_pure_if([b4_locations_if([yylocp, ])])dnl
-m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
+m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 
 
 # b4_lyyerror_args
@@ -79,7 +79,7 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 # Same as above, but on the lookahead, hence &yylloc instead of yylocp.
 m4_define([b4_lyyerror_args],
 [b4_pure_if([b4_locations_if([&yylloc, ])])dnl
-m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
+m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 
 
 # b4_pure_args
@@ -178,7 +178,7 @@ m4_define([b4_shared_declarations],
 ]b4_percent_code_get([[requires]])[
 ]b4_token_enums[
 ]b4_declare_yylstype[
-]b4_c_function_decl(b4_prefix[parse], [int], b4_parse_param)[
+]b4_function_declare(b4_prefix[parse], [int], b4_parse_param)[
 ]b4_percent_code_get([[provides]])[]dnl
 ])
 
@@ -268,7 +268,7 @@ b4_percent_code_get[]dnl
 #ifndef lint
 # define YYID(n) (n)
 #else
-]b4_c_function_def([YYID], [static int], [[int i], [i]])[
+]b4_function_define([YYID], [static int], [[int i], [i]])[
 {
   return i;
 }
@@ -444,7 +444,7 @@ dnl We probably ought to introduce a type for confl.
 #endif
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
-#define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
+#define YYLEX ]b4_function_call([yylex], [int], b4_lex_param)[
 
 ]b4_pure_if(
 [
@@ -491,7 +491,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
       YYFPRINTF Args;                           \
   } while (YYID (0))
 
-]b4_yy_symbol_print_generate([b4_c_function_def])[
+]b4_yy_symbol_print_generate([b4_function_define])[
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
   do {                                                                  \
@@ -872,7 +872,7 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 
                               /* Bison grammar-table manipulation.  */
 
-]b4_yydestruct_generate([b4_c_function_def])[
+]b4_yydestruct_generate([b4_function_define])[
 
 /** Number of symbols composing the right hand side of rule #RULE.  */
 static inline int
@@ -2276,7 +2276,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 | yyparse.  |
 `----------*/
 
-]b4_c_function_def([yyparse], [int], b4_parse_param)[
+]b4_function_define([yyparse], [int], b4_parse_param)[
 {
   int yyresult;
   yyGLRStack yystack;
