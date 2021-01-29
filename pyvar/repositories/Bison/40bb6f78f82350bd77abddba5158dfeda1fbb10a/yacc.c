@@ -687,11 +687,7 @@ while (0)
 ]b4_yy_location_print_define[
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
-#ifdef YYLEX_PARAM
-# define YYLEX yylex (]b4_pure_if([&yylval[]b4_locations_if([, &yylloc]), ])[YYLEX_PARAM)
-#else
-# define YYLEX ]b4_function_call([yylex], [int], b4_lex_param)[
-#endif
+#define YYLEX ]b4_function_call([yylex], [int], b4_lex_param)[
 
 /* Enable debugging if requested.  */
 #if ]b4_api_PREFIX[DEBUG
