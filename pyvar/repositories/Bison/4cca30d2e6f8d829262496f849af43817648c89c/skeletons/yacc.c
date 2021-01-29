@@ -735,9 +735,8 @@ do {                                                                      \
 | TOP (included).                                                   |
 `------------------------------------------------------------------*/
 
-]b4_function_define([yy_stack_print], [static void],
-                   [[yy_state_t *yybottom], [yybottom]],
-                   [[yy_state_t *yytop],    [yytop]])[
+static void
+yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
@@ -759,12 +758,9 @@ do {                                                            \
 | Report that the YYRULE is going to be reduced.  |
 `------------------------------------------------*/
 
-]b4_function_define([yy_reduce_print], [static void],
-                   [[yy_state_t *yyssp], [yyssp]],
-                   [[YYSTYPE *yyvsp], [yyvsp]],
-    b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
-                   ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
-                   b4_parse_param]))[
+static void
+yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,]b4_locations_if([[ YYLTYPE *yylsp,]])[
+                 int yyrule]b4_user_formals[)
 {
   int yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
@@ -1207,8 +1203,8 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 #  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
 # else
 /* Return the length of YYSTR.  */
-]b4_function_define([yystrlen], [static YYPTRDIFF_T],
-   [[const char *yystr], [yystr]])[
+static YYPTRDIFF_T
+yystrlen (const char *yystr)
 {
   YYPTRDIFF_T yylen;
   for (yylen = 0; yystr[yylen]; yylen++)
@@ -1224,8 +1220,8 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 # else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
-]b4_function_define([yystpcpy], [static char *],
-   [[char *yydest], [yydest]], [[const char *yysrc], [yysrc]])[
+static char *
+yystpcpy (char *yydest, const char *yysrc)
 {
   char *yyd = yydest;
   const char *yys = yysrc;
@@ -1388,10 +1384,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 
 ]b4_yydestruct_define[
 
-]b4_pure_if([], [[
-
-]b4_declare_scanner_communication_variables])[]b4_push_if([[
+]b4_pure_if([], [b4_declare_scanner_communication_variables])[
 
+]b4_push_if([[
 struct yypstate
   {]b4_declare_parser_state_variables[
     /* Used to determine if this is the first time this instance has
@@ -1399,17 +1394,16 @@ struct yypstate
     int yynew;
   };]b4_pure_if([], [[
 
-static char yypstate_allocated = 0;]])b4_pull_if([
+static char yypstate_allocated = 0;]])b4_pull_if([[
 
-b4_function_define([[yyparse]], [[int]], b4_parse_param)[
+int
+yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
-  return yypull_parse (YY_NULLPTR]m4_ifset([b4_parse_param],
-                                  [[, ]b4_args(b4_parse_param)])[);
+  return yypull_parse (YY_NULLPTR]b4_user_args[);
 }
 
-]b4_function_define([[yypull_parse]], [[int]],
-  [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
-  b4_parse_param]))[
+int
+yypull_parse (yypstate *yyps]b4_user_formals[)
 {]b4_pure_if([b4_locations_if([[
   static YYLTYPE yyloc_default][]b4_yyloc_default[;
   YYLTYPE yylloc = yyloc_default;]])])[
@@ -1440,7 +1434,8 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 }]])[
 
 /* Initialize the parser data structure.  */
-]b4_function_define([[yypstate_new]], [[yypstate *]])[
+yypstate *
+yypstate_new (void)
 {
   yypstate *yyps;]b4_pure_if([], [[
   if (yypstate_allocated)
@@ -1453,8 +1448,8 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   return yyps;
 }
 
-]b4_function_define([[yypstate_delete]], [[void]],
-                   [[[yypstate *yyps]], [[yyps]]])[
+void
+yypstate_delete (yypstate *yyps)
 {
   if (yyps)
     {
@@ -1488,25 +1483,23 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 #define yyesa yyps->yyesa
 #define yyes yyps->yyes
 #define yyes_capacity yyps->yyes_capacity]])[
+]])[
 
-
+]b4_push_if([[
 /*---------------.
 | yypush_parse.  |
 `---------------*/
 
-]b4_function_define([[yypush_parse]], [[int]],
-  [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
-  [[[int yypushed_char]], [[yypushed_char]]],
-  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
-  b4_parse_param]))], [[
-
-
+int
+yypush_parse (yypstate *yyps]b4_pure_if([[,
+              int yypushed_char, YYSTYPE const *yypushed_val]b4_locations_if([[, YYLTYPE *yypushed_loc]])])b4_user_formals[)]],
+[[
 /*----------.
 | yyparse.  |
 `----------*/
 
-]b4_function_define([yyparse], [int], b4_parse_param)])[
+int
+yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
 {]b4_pure_if([b4_declare_scanner_communication_variables
 ])b4_push_if([b4_pure_if([], [[
   int yypushed_char = yychar;
