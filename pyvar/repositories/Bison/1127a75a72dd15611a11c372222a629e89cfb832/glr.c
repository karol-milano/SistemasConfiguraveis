@@ -287,7 +287,7 @@ b4_percent_code_get[]dnl
 # include <setjmp.h>
 # define YYJMP_BUF jmp_buf
 # define YYSETJMP(Env) setjmp (Env)
-// Pacify clang.
+/* Pacify clang.  */
 # define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
 #endif
 
@@ -2013,6 +2013,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #if ! YYERROR_VERBOSE
   yyerror (]b4_lyyerror_args[YY_("syntax error"));
 #else
+  {
   yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
   size_t yysize0 = yytnamerr (YY_NULL, yytokenName (yytoken));
   size_t yysize = yysize0;
@@ -2133,6 +2134,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       yyerror (]b4_lyyerror_args[YY_("syntax error"));
       yyMemoryExhausted (yystackp);
     }
+  }
 #endif /* YYERROR_VERBOSE */
   yynerrs += 1;
 }
