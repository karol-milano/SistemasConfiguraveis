@@ -607,8 +607,7 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
    YYSYMBOL.  No bounds checking.  */
 static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
 
-]m4_bmatch(b4_percent_define_get([[parse.error]]),
-           [simple\|verbose],
+]b4_parse_error_bmatch([simple\|verbose],
 [[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -1067,7 +1066,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
     }
 }]])[
 
-]m4_if(b4_percent_define_get([[parse.error]]), [simple], [],
+]b4_parse_error_case([simple], [],
 [[typedef struct
 {
   yy_state_t *yyssp;
@@ -1185,7 +1184,7 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 }
 ]])[
 
-]m4_case(b4_percent_define_get([[parse.error]]),
+]b4_parse_error_case(
          [custom],
 [b4_locations_if([[/*  The location of this context.  */
 static YYLTYPE *
@@ -1239,7 +1238,7 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 # endif
 #endif
 
-]m4_case(b4_percent_define_get([[parse.error]]),
+]b4_parse_error_case(
          [verbose],
 [[#ifndef yytnamerr
 /* Copy to YYRES the contents of YYSTR after stripping away unnecessary
@@ -1345,7 +1344,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     for (yyi = 0; yyi < yycount; ++yyi)
       {
         YYPTRDIFF_T yysize1
-          = yysize + ]m4_case(b4_percent_define_get([[parse.error]]),
+          = yysize + ]b4_parse_error_case(
                               [verbose], [[yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]])]],
                               [[yystrlen (yysymbol_name (yyarg[yyi]))]]);[
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
@@ -1372,7 +1371,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     int yyi = 0;
     while ((*yyp = *yyformat) != '\0')
       if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-        {]m4_case(b4_percent_define_get([[parse.error]]), [verbose], [[
+        {]b4_parse_error_case([verbose], [[
           yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);]], [[
           yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));]])[
           yyformat += 2;
@@ -1528,7 +1527,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   YYSTYPE yyval;]b4_locations_if([[
   YYLTYPE yyloc;]])[
 
-]m4_bmatch(b4_percent_define_get([[parse.error]]), [detailed\|verbose],
+]b4_parse_error_bmatch([detailed\|verbose],
 [[  /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
   char *yymsg = yymsgbuf;
@@ -1849,7 +1848,7 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-]m4_case(b4_percent_define_get([[parse.error]]),
+]b4_parse_error_case(
          [custom],
 [[      {
         yyparse_context_t yyctx
@@ -2056,7 +2055,7 @@ yyreturn:
 | yypushreturn -- ask for the next token.  |
 `-----------------------------------------*/
 yypushreturn:]])[
-]m4_bmatch(b4_percent_define_get([[parse.error]]), [detailed\|verbose],
+]b4_parse_error_bmatch([detailed\|verbose],
 [[  if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);]])[
   return yyresult;
