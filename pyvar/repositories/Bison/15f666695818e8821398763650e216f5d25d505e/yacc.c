@@ -85,7 +85,7 @@ m4_define([b4_yacc_pure_if],
 # Arguments passed to yyerror: user args plus yylloc.
 m4_define([b4_yyerror_args],
 [b4_yacc_pure_if([b4_locations_if([&yylloc, ])])dnl
-m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
+m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 
 
 # b4_lex_param
@@ -239,19 +239,19 @@ enum { YYPUSH_MORE = 4 };
 
 typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
 
-]b4_pull_if([b4_c_function_decl([b4_prefix[parse]], [[int]], b4_parse_param)
-])b4_c_function_decl([b4_prefix[push_parse]], [[int]],
+]b4_pull_if([b4_function_declare([b4_prefix[parse]], [[int]], b4_parse_param)
+])b4_function_declare([b4_prefix[push_parse]], [[int]],
   [[b4_prefix[pstate *ps]], [[ps]]]b4_pure_if([,
   [[[int pushed_char]], [[pushed_char]]],
   [[b4_api_PREFIX[STYPE const *pushed_val]], [[pushed_val]]]b4_locations_if([,
   [[b4_api_PREFIX[LTYPE const *pushed_loc]], [[pushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))
-b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
+b4_pull_if([b4_function_declare([b4_prefix[pull_parse]], [[int]],
   [[b4_prefix[pstate *ps]], [[ps]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))])
-b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
+b4_function_declare([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
                     [[[void]], []])
-b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
+b4_function_declare([b4_prefix[pstate_delete]], [[void]],
                    [[b4_prefix[pstate *ps]], [[ps]]])dnl
 ])
 
@@ -259,7 +259,7 @@ b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
 # -------------------
 # When not the push parser.
 m4_define([b4_declare_yyparse_],
-[b4_c_function_decl(b4_prefix[parse], [int], b4_parse_param)])
+[b4_function_declare(b4_prefix[parse], [int], b4_parse_param)])
 
 
 # b4_declare_yyparse
@@ -414,7 +414,7 @@ typedef short int yytype_int16;
 #ifndef lint
 # define YYID(n) (n)
 #else
-]b4_c_function_def([YYID], [static int], [[int yyi], [yyi]])[
+]b4_function_define([YYID], [static int], [[int yyi], [yyi]])[
 {
   return yyi;
 }
@@ -686,7 +686,7 @@ while (YYID (0))
 #ifdef YYLEX_PARAM
 # define YYLEX yylex (]b4_pure_if([&yylval[]b4_locations_if([, &yylloc]), ])[YYLEX_PARAM)
 #else
-# define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
+# define YYLEX ]b4_function_call([yylex], [int], b4_lex_param)[
 #endif
 
 /* Enable debugging if requested.  */
@@ -714,14 +714,14 @@ do {                                                                      \
     }                                                                     \
 } while (YYID (0))
 
-]b4_yy_symbol_print_generate([b4_c_function_def])[
+]b4_yy_symbol_print_generate([b4_function_define])[
 
 /*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
 | TOP (included).                                                   |
 `------------------------------------------------------------------*/
 
-]b4_c_function_def([yy_stack_print], [static void],
+]b4_function_define([yy_stack_print], [static void],
                    [[yytype_int16 *yybottom], [yybottom]],
                    [[yytype_int16 *yytop],    [yytop]])[
 {
@@ -745,7 +745,7 @@ do {                                                            \
 | Report that the YYRULE is going to be reduced.  |
 `------------------------------------------------*/
 
-]b4_c_function_def([yy_reduce_print], [static void],
+]b4_function_define([yy_reduce_print], [static void],
                    [[yytype_int16 *yyssp], [yyssp]],
                    [[YYSTYPE *yyvsp], [yyvsp]],
     b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
@@ -1047,7 +1047,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
 #   define yystrlen strlen
 #  else
 /* Return the length of YYSTR.  */
-]b4_c_function_def([yystrlen], [static YYSIZE_T],
+]b4_function_define([yystrlen], [static YYSIZE_T],
    [[const char *yystr], [yystr]])[
 {
   YYSIZE_T yylen;
@@ -1064,7 +1064,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
 #  else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
-]b4_c_function_def([yystpcpy], [static char *],
+]b4_function_define([yystpcpy], [static char *],
    [[char *yydest], [yydest]], [[const char *yysrc], [yysrc]])[
 {
   char *yyd = yydest;
@@ -1284,7 +1284,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 }
 #endif /* YYERROR_VERBOSE */
 
-]b4_yydestruct_generate([b4_c_function_def])[
+]b4_yydestruct_generate([b4_function_define])[
 
 ]b4_pure_if([], [
 
@@ -1299,13 +1299,13 @@ struct yypstate
 
 static char yypstate_allocated = 0;]])b4_pull_if([
 
-b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
+b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 {
   return yypull_parse (YY_NULL]m4_ifset([b4_parse_param],
-                                  [[, ]b4_c_args(b4_parse_param)])[);
+                                  [[, ]b4_args(b4_parse_param)])[);
 }
 
-]b4_c_function_def([[yypull_parse]], [[int]],
+]b4_function_define([[yypull_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 {
@@ -1330,7 +1330,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   do {
     yychar = YYLEX;
     yystatus =
-      yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_c_args(b4_parse_param)])[);
+      yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
   if (!yyps)
     yypstate_delete (yyps_local);
@@ -1338,7 +1338,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 }]])[
 
 /* Initialize the parser data structure.  */
-]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
+]b4_function_define([[yypstate_new]], [[yypstate *]])[
 {
   yypstate *yyps;]b4_pure_if([], [[
   if (yypstate_allocated)
@@ -1351,7 +1351,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   return yyps;
 }
 
-]b4_c_function_def([[yypstate_delete]], [[void]],
+]b4_function_define([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])[
 {
 #ifndef yyoverflow
@@ -1389,7 +1389,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 | yypush_parse.  |
 `---------------*/
 
-]b4_c_function_def([[yypush_parse]], [[int]],
+]b4_function_define([[yypush_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
@@ -1401,7 +1401,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 | yyparse.  |
 `----------*/
 
-]b4_c_function_def([yyparse], [int], b4_parse_param)])[
+]b4_function_define([yyparse], [int], b4_parse_param)])[
 {]b4_pure_if([b4_declare_scanner_communication_variables
 ])b4_push_if([b4_pure_if([], [[
   int yypushed_char = yychar;
