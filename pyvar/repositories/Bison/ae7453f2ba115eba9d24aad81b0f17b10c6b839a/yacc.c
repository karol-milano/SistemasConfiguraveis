@@ -506,13 +506,14 @@ while (0)
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
-b4_pure_if(
-[#ifdef YYLEX_PARAM
-# define YYLEX	yylex (&yylval[]b4_location_if([, &yylloc]), YYLEX_PARAM)
+#ifdef YYLEX_PARAM
+# define YYLEX yylex (b4_pure_if([&yylval[]b4_location_if([, &yylloc]), ])YYLEX_PARAM)
 #else
-# define YYLEX	yylex (&yylval[]b4_location_if([, &yylloc]))
-#endif],
-[#define YYLEX	yylex ()])
+# define YYLEX b4_c_function_call([yylex],
+                   b4_pure_if([[[[]], [[&yylval]]],
+                               b4_location_if([[[], [&yylloc]],])])
+                   m4_fst(b4_lex_param))
+#endif
 
 /* Enable debugging if requested.  */
 #if YYDEBUG
