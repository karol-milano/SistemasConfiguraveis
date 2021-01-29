@@ -307,7 +307,15 @@ b4_copyright([Bison implementation for Yacc-like parsers in C],
 
 ]b4_identification
 b4_percent_code_get([[top]])[]dnl
-m4_if(b4_prefix, [yy], [],
+m4_if(b4_api_prefix, [yy], [],
+[[/* Substitute the type names.  */
+#define YYSTYPE              ]b4_api_PREFIX[STYPE
+#define YYSTYPE_IS_TRIVIAL   ]b4_api_PREFIX[STYPE_IS_TRIVIAL
+#define YYSTYPE_IS_DECLARED  ]b4_api_PREFIX[STYPE_IS_DECLARED]b4_locations_if([[
+#define YYLTYPE              ]b4_api_PREFIX[LTYPE
+#define YYLTYPE_IS_TRIVIAL   ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
+#define YYLTYPE_IS_DECLARED  ]b4_api_PREFIX[LTYPE_IS_DECLARED]])])[
+]m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */]b4_pull_if([[
 #define yyparse         ]b4_prefix[parse]])b4_push_if([[
 #define yypush_parse    ]b4_prefix[push_parse]b4_pull_if([[
