@@ -607,13 +607,12 @@ yyMemoryExhausted (yyGLRStack* yystackp)
   YYLONGJMP (yystackp->yyexception_buffer, 2);
 }
 
-#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag])[
+#if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
 static const char *yysymbol_name (yySymbol yysymbol) YY_ATTRIBUTE_UNUSED;
 
-]m4_bmatch(b4_percent_define_get([[parse.error]]),
-           [simple\|verbose],
+]b4_parse_error_bmatch([simple\|verbose],
 [[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
