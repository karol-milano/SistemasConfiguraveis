@@ -509,7 +509,7 @@ while (0)
 #ifdef YYLEX_PARAM
 # define YYLEX yylex (b4_pure_if([&yylval[]b4_location_if([, &yylloc]), ])YYLEX_PARAM)
 #else
-# define YYLEX b4_c_function_call([yylex],
+# define YYLEX b4_c_function_call([yylex], [int],
                    b4_pure_if([[[[]], [[&yylval]]],
                                b4_location_if([[[], [&yylloc]],])])
                    m4_fst(b4_lex_param))
