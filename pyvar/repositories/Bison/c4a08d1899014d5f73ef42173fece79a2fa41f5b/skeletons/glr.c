@@ -368,15 +368,6 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag])[
-/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
-   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
-static const char *const yytname[] =
-{
-  ]b4_tname[
-};
-#endif
-
 #define YYPACT_NINF (]b4_pact_ninf[)
 #define YYTABLE_NINF (]b4_table_ninf[)
 
@@ -616,13 +607,47 @@ yyMemoryExhausted (yyGLRStack* yystackp)
   YYLONGJMP (yystackp->yyexception_buffer, 2);
 }
 
-#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG]])[
-/** A printable representation of TOKEN.  */
-static inline const char*
-yysymbol_name (yySymbol yytoken)
+#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag])[
+/* The user-facing name of the symbol whose (internal) number is
+   YYSYMBOL.  No bounds checking.  */
+static const char *yysymbol_name (yySymbol yysymbol) YY_ATTRIBUTE_UNUSED;
+
+]m4_bmatch(b4_percent_define_get([[parse.error]]),
+           [simple\|verbose],
+[[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
+   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
+static const char *const yytname[] =
 {
-  return yytoken == YYEMPTY ? "" : yytname[yytoken];
-}
+  ]b4_tname[
+};
+
+static const char *
+yysymbol_name (yySymbol yysymbol)
+{
+  return yytname[yysymbol];
+}]],
+[[/* The user-facing name of the symbol whose (internal) number is
+   YYSYMBOL.  No bounds checking.  */
+static const char *yysymbol_name (yySymbol yysymbol) YY_ATTRIBUTE_UNUSED;
+
+static const char *
+yysymbol_name (yySymbol yysymbol)
+{
+  static const char *const yy_sname[] =
+  {
+  ]b4_symbol_names[
+  };]m4_ifdef([b4_translatable], [[
+  /* YYTRANSLATABLE[SYMBOL-NUM] -- Whether YYTNAME[SYMBOL-NUM] is
+     internationalizable.  */
+  static ]b4_int_type_for([b4_translate])[ yytranslatable[] =
+  {
+  ]b4_translatable[
+  };
+  return (yysymbol < YYNTOKENS && yytranslatable[yysymbol]
+          ? _(yy_sname[yysymbol])
+          : yy_sname[yysymbol]);]], [[
+  return yy_sname[yysymbol];]])[
+}]])[
 #endif
 
 #if ]b4_api_PREFIX[DEBUG
@@ -680,11 +705,19 @@ static void yypdumpstack (yyGLRStack* yystackp)
 
 #endif /* !]b4_api_PREFIX[DEBUG */
 
-]m4_case(b4_percent_define_get([parse.error]), [verbose],
-[[# ifndef yystpcpy
-#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
-#   define yystpcpy stpcpy
-#  else
+]m4_case(b4_percent_define_get([[parse.error]]),
+         [simple],
+[[]],
+[[#ifndef yystrlen
+# define yystrlen(S) (YY_CAST (ptrdiff_t, strlen (S)))
+#endif
+
+]m4_bmatch(b4_percent_define_get([[parse.error]]),
+           [detailed\|verbose],
+[[#ifndef yystpcpy
+# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
+#  define yystpcpy stpcpy
+# else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
 static char *
@@ -698,10 +731,12 @@ yystpcpy (char *yydest, const char *yysrc)
 
   return yyd - 1;
 }
-#  endif
 # endif
+#endif]])[
 
-# ifndef yytnamerr
+]m4_case(b4_percent_define_get([[parse.error]]),
+         [verbose],
+[[#ifndef yytnamerr
 /* Copy to YYRES the contents of YYSTR after stripping away unnecessary
    quotes and backslashes, so that it's suitable for yyerror.  The
    heuristic is that double-quoting is unnecessary unless the string
@@ -748,10 +783,10 @@ yytnamerr (char *yyres, const char *yystr)
   if (yyres)
     return yystpcpy (yyres, yystr) - yyres;
   else
-    return YY_CAST (ptrdiff_t, strlen (yystr));
+    return yystrlen (yystr);
 }
-# endif
-]])[
+#endif
+]])])[
 
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
@@ -2151,9 +2186,11 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   if (yystackp->yyerrState != 0)
     return;
 ]m4_case(b4_percent_define_get([parse.error]),
+         [custom],
+[[  if (yyreport_syntax_error (yystackp]b4_user_args[))
+    yyMemoryExhausted (yystackp);]],
          [simple],
 [[  yyerror (]b4_lyyerror_args[YY_("syntax error"));]],
-         [verbose],
 [[  {
   yybool yysize_overflow = yyfalse;
   char* yymsg = YY_NULLPTR;
@@ -2169,6 +2206,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   /* Actual size of YYARG. */
   int yycount
     = yysyntax_error_arguments (yystackp, yyarg, YYERROR_VERBOSE_ARGS_MAXIMUM);
+  if (yycount == -2)
+    yyMemoryExhausted (yystackp);
 
   switch (yycount)
     {
@@ -2188,12 +2227,15 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Compute error message size.  Don't count the "%s"s, but reserve
      room for the terminator.  */
-  yysize = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
+  yysize = yystrlen (yyformat) - 2 * yycount + 1;
   {
     int yyi;
     for (yyi = 0; yyi < yycount; ++yyi)
       {
-        ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yysymbol_name (yyarg[yyi]));
+        ptrdiff_t yysz
+          = ]m4_case(b4_percent_define_get([[parse.error]]),
+                     [verbose], [[yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]])]],
+                     [[yystrlen (yysymbol_name (yyarg[yyi]))]]);[
         if (YYSIZEMAX - yysize < yysz)
           yysize_overflow = yytrue;
         else
@@ -2211,8 +2253,9 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       while ((*yyp = *yyformat))
         {
           if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-            {
-              yyp += yytnamerr (yyp, yysymbol_name (yyarg[yyi++]));
+            {]m4_case(b4_percent_define_get([[parse.error]]), [verbose], [[
+              yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);]], [[
+              yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));]])[
               yyformat += 2;
             }
           else
