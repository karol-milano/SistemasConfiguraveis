@@ -706,7 +706,7 @@ do {								\
 		   [[YYSTYPE *yyvsp], [yyvsp]],
     b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
 		   ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
-		   ])b4_parse_param)[
+		   b4_parse_param]))[
 {
   int yynrhs = yyr2[yyrule];
   int yyi;
@@ -971,7 +971,8 @@ enum { YYPUSH_MORE = 4 };
    [[yypstate *yyps], [yyps]],
    [[int yynchar], [yynchar]],
    [[YYSTYPE const *yynlval], [yynlval]]
-   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
+   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]])
+   m4_ifset([b4_parse_param], [, b4_parse_param]))[
 ],[#ifdef YYPARSE_PARAM
 ]b4_c_function_decl([yyparse], [int],
    [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
@@ -1081,8 +1082,7 @@ m4_define([b4_declare_yyparse_variables],
 ])
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
-b4_push_if([],[b4_pure_if([],
-	   [b4_declare_parser_variables])])
+b4_pure_if([], [b4_declare_parser_variables])
 
 b4_push_if([b4_declare_yyparse_variables])
 
@@ -1094,7 +1094,8 @@ b4_push_if([
 b4_c_function_def([yypush_parse], [int], [[yypstate *yyps], [yyps]], 
                   [[int yynchar], [yynchar]],
                   [[YYSTYPE const *yynlval], [yynlval]]
-		  b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))],[
+		  b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]])
+                  m4_ifset([b4_parse_param], [, b4_parse_param]))],[
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
@@ -1102,7 +1103,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif])
 {[
   ]b4_pure_if([b4_declare_parser_variables])[
-  ]b4_push_if([b4_declare_parser_variables])[
   int yystate;
   int yyn;
   int yyresult;
@@ -1700,7 +1700,8 @@ typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
    [[]b4_prefix[pstate *]b4_prefix[pstate], []b4_prefix[pstate]],
    [[int yynchar], [yynchar]],
    [[YYSTYPE const *yynlval], [yynlval]]
-   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
+   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]])
+   m4_ifset([b4_parse_param], [, b4_parse_param]))[
 enum { YYPUSH_MORE = 4 };])[
 
 m4_ifdef([b4_provides],
