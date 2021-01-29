@@ -603,21 +603,37 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 #endif
 
 #if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag])[
-/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
+/* The user-facing name of the symbol whose (internal) number is
+   YYSYMBOL.  No bounds checking.  */
+static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
+
+]m4_bmatch(b4_percent_define_get([[parse.error]]),
+           [simple\|verbose],
+[[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
 {
   ]b4_tname[
 };
 
-/* The user-facing name of the symbol whose (internal) number is
+static const char *
+yysymbol_name (int yysymbol)
+{
+  return yytname[yysymbol];
+}]],
+[[/* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
 static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
+
 static const char *
 yysymbol_name (int yysymbol)
 {
-  return yytname[yysymbol];
-}
+  static const char *const yy_sname[] =
+  {
+  ]b4_symbol_names[
+  };
+  return yy_sname[yysymbol];
+}]])[
 #endif
 
 # ifdef YYPRINT
@@ -1177,7 +1193,8 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 ]b4_function_declare([yyreport_syntax_error], [static int],
                      [[[const yyparse_context_t *yyctx]], [[yyctx]]],
                      b4_parse_param)],
-         [verbose],
+         [simple],
+[[]],
 [[# ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
 #   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
@@ -1214,7 +1231,9 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 #  endif
 # endif
 
-# ifndef yytnamerr
+]m4_case(b4_percent_define_get([[parse.error]]),
+         [verbose],
+[[# ifndef yytnamerr
 /* Copy to YYRES the contents of YYSTR after stripping away unnecessary
    quotes and backslashes, so that it's suitable for yyerror.  The
    heuristic is that double-quoting is unnecessary unless the string
@@ -1264,7 +1283,7 @@ yytnamerr (char *yyres, const char *yystr)
     return yystrlen (yystr);
 }
 # endif
-
+]])[
 
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN for the state stack whose top is
@@ -1319,7 +1338,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     for (yyi = 0; yyi < yycount; ++yyi)
       {
         YYPTRDIFF_T yysize1
-          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
+          = yysize + ]m4_case(b4_percent_define_get([[parse.error]]),
+                              [verbose], [[yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]])]],
+                              [[yystrlen (yysymbol_name (yyarg[yyi]))]]);[
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
           yysize = yysize1;
         else
@@ -1344,8 +1365,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     int yyi = 0;
     while ((*yyp = *yyformat) != '\0')
       if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-        {
-          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
+        {]m4_case(b4_percent_define_get([[parse.error]]), [verbose], [[
+          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);]], [[
+          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));]])[
           yyformat += 2;
         }
       else
@@ -1499,7 +1521,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   YYSTYPE yyval;]b4_locations_if([[
   YYLTYPE yyloc;]])[
 
-]m4_case(b4_percent_define_get([[parse.error]]), [verbose],
+]m4_bmatch(b4_percent_define_get([[parse.error]]), [detailed\|verbose],
 [[  /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
   char *yymsg = yymsgbuf;
@@ -1833,7 +1855,6 @@ yyerrlab:
       }]],
          [simple],
 [[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
-         [verbose],
 [[      {
         char const *yymsgp = YY_("syntax error");
         yyparse_context_t yyctx
@@ -2028,7 +2049,7 @@ yyreturn:
 | yypushreturn -- ask for the next token.  |
 `-----------------------------------------*/
 yypushreturn:]])[
-]m4_case(b4_percent_define_get([[parse.error]]), [verbose],
+]m4_bmatch(b4_percent_define_get([[parse.error]]), [detailed\|verbose],
 [[  if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);]])[
   return yyresult;
