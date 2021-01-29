@@ -190,12 +190,8 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 b4_percent_code_get([[top]])[
 ]m4_if(b4_api_prefix, [yy], [],
 [[/* Substitute the type names.  */
-#define YYSTYPE              ]b4_api_PREFIX[STYPE
-#define YYSTYPE_IS_TRIVIAL   ]b4_api_PREFIX[STYPE_IS_TRIVIAL
-#define YYSTYPE_IS_DECLARED  ]b4_api_PREFIX[STYPE_IS_DECLARED]b4_locations_if([[
-#define YYLTYPE              ]b4_api_PREFIX[LTYPE
-#define YYLTYPE_IS_TRIVIAL   ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
-#define YYLTYPE_IS_DECLARED  ]b4_api_PREFIX[LTYPE_IS_DECLARED]])])[
+#define YYSTYPE ]b4_api_PREFIX[STYPE]b4_locations_if([[
+#define YYLTYPE ]b4_api_PREFIX[LTYPE]])])[
 ]m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
 #define yyparse ]b4_prefix[parse
@@ -613,8 +609,8 @@ int yydebug;
 
 #ifndef YYSTACKEXPANDABLE
 # if (! defined __cplusplus \
-      || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-          && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
+      || (]b4_locations_if([[defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL \
+          && ]])[defined ]b4_api_PREFIX[STYPE_IS_TRIVIAL && ]b4_api_PREFIX[STYPE_IS_TRIVIAL))
 #  define YYSTACKEXPANDABLE 1
 # else
 #  define YYSTACKEXPANDABLE 0
@@ -2319,7 +2315,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yychar = YYEMPTY;
   yylval = yyval_default;
 ]b4_locations_if([
-#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
+#if defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
 #endif
