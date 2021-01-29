@@ -309,12 +309,8 @@ b4_copyright([Bison implementation for Yacc-like parsers in C],
 b4_percent_code_get([[top]])[]dnl
 m4_if(b4_api_prefix, [yy], [],
 [[/* Substitute the type names.  */
-#define YYSTYPE              ]b4_api_PREFIX[STYPE
-#define YYSTYPE_IS_TRIVIAL   ]b4_api_PREFIX[STYPE_IS_TRIVIAL
-#define YYSTYPE_IS_DECLARED  ]b4_api_PREFIX[STYPE_IS_DECLARED]b4_locations_if([[
-#define YYLTYPE              ]b4_api_PREFIX[LTYPE
-#define YYLTYPE_IS_TRIVIAL   ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
-#define YYLTYPE_IS_DECLARED  ]b4_api_PREFIX[LTYPE_IS_DECLARED]])])[
+#define YYSTYPE         ]b4_api_PREFIX[STYPE]b4_locations_if([[
+#define YYLTYPE         ]b4_api_PREFIX[LTYPE]])])[
 ]m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */]b4_pull_if([[
 #define yyparse         ]b4_prefix[parse]])b4_push_if([[
@@ -498,8 +494,8 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
-	 || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-	     && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
+	 || (]b4_locations_if([[defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL \
+	     && ]])[defined ]b4_api_PREFIX[STYPE_IS_TRIVIAL && ]b4_api_PREFIX[STYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -776,7 +772,7 @@ while (YYID (0))
    we won't break user code: when these are the locations we know.  */
 
 #ifndef YY_LOCATION_PRINT
-# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
+# if defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
 #  define YY_LOCATION_PRINT(File, Loc)			\
      fprintf (File, "%d.%d-%d.%d",			\
 	      (Loc).first_line, (Loc).first_column,	\
@@ -1585,7 +1581,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yyvsp = yyvs;]b4_locations_if([[
   yylsp = yyls;
 
-#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
+#if defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
