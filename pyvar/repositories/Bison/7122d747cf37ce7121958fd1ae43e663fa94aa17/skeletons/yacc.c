@@ -348,14 +348,6 @@ m4_if(b4_api_prefix, [yy], [],
 ]b4_cast_define[
 ]b4_null_define[
 
-/* Enabling verbose error messages.  */
-#ifdef YYERROR_VERBOSE
-# undef YYERROR_VERBOSE
-# define YYERROR_VERBOSE 1
-#else
-# define YYERROR_VERBOSE ]b4_error_verbose_if([1], [0])[
-#endif
-
 ]b4_header_include_if([[#include ]b4_percent_define_get([[api.header.include]])],
                       [m4_ifval(m4_quote(b4_spec_header_file),
                                 [/* Use api.header.include to #include this header
@@ -437,7 +429,7 @@ typedef int yy_state_fast_t;
 ]],
 [[#define YY_ASSERT(E) ((void) (0 && (E)))]])[
 
-#if ]b4_lac_if([[1]], [[! defined yyoverflow || YYERROR_VERBOSE]])[
+#if ]b4_lac_if([[1]], [b4_error_verbose_if([[1]], [[!defined yyoverflow]])])[
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */]dnl
 b4_push_if([], [b4_lac_if([], [[
@@ -504,8 +496,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 #  endif
 # endif]b4_lac_if([[
 # define YYCOPY_NEEDED 1]])[
-#endif]b4_lac_if([], [[ /* ! defined yyoverflow || YYERROR_VERBOSE */]])[
-
+#endif]b4_lac_if([], [b4_error_verbose_if([], [[/* !defined yyoverflow */]])])[
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
@@ -611,7 +602,7 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
      [[YYRLINE[YYN] -- Source line where rule number YYN was defined.]])[
 #endif
 
-#if ]b4_api_PREFIX[DEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
+#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag])[
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -1039,9 +1030,8 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 }]])[
 
 
-#if YYERROR_VERBOSE
-
-# ifndef yystrlen
+]m4_case(b4_percent_define_get([parse.error]), [verbose],
+[[# ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
 #   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
 #  else
@@ -1287,7 +1277,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   }
   return 0;
 }
-#endif /* YYERROR_VERBOSE */
+]])[
 
 ]b4_yydestruct_define[
 
@@ -1428,12 +1418,11 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   YYSTYPE yyval;]b4_locations_if([[
   YYLTYPE yyloc;]])[
 
-#if YYERROR_VERBOSE
-  /* Buffer for error messages, and its allocated size.  */
+]m4_case(b4_percent_define_get([parse.error]), [verbose],
+[[  /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
   char *yymsg = yymsgbuf;
-  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
-#endif
+  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;]])[
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_locations_if([, yylsp -= (N)])[)
 
@@ -1750,10 +1739,11 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-#if ! YYERROR_VERBOSE
-      yyerror (]b4_yyerror_args[YY_("syntax error"));
-#else
-# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \]b4_lac_if([[
+]m4_case(b4_percent_define_get([parse.error]),
+         [simple],
+[[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
+         [verbose],
+[[# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \]b4_lac_if([[
                                         yyesa, &yyes, &yyes_capacity, \]])[
                                         yyssp, yytoken)
       {
@@ -1785,8 +1775,7 @@ yyerrlab:
         if (yysyntax_error_status == 2)
           goto yyexhaustedlab;
       }
-# undef YYSYNTAX_ERROR
-#endif
+# undef YYSYNTAX_ERROR]])[
     }
 
 ]b4_locations_if([[  yyerror_range[1] = yylloc;]])[
@@ -1902,7 +1891,7 @@ yyabortlab:
   goto yyreturn;
 
 
-#if ]b4_lac_if([[1]], [[!defined yyoverflow || YYERROR_VERBOSE]])[
+#if ]b4_lac_if([[1]], [b4_error_verbose_if([[1]], [[!defined yyoverflow]])])[
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
@@ -1948,10 +1937,9 @@ yyreturn:
 | yypushreturn -- ask for the next token.  |
 `-----------------------------------------*/
 yypushreturn:]])[
-#if YYERROR_VERBOSE
-  if (yymsg != yymsgbuf)
-    YYSTACK_FREE (yymsg);
-#endif
+]m4_case(b4_percent_define_get([parse.error]), [verbose],
+[[  if (yymsg != yymsgbuf)
+    YYSTACK_FREE (yymsg);]])[
   return yyresult;
 }
 ]b4_epilogue[]dnl
