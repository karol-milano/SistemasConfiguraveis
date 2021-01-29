@@ -241,14 +241,6 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 ]b4_defines_if([[#include "@basename(]b4_spec_header_file[@)"]],
                [b4_shared_declarations])[
 
-/* Enabling verbose error messages.  */
-#ifdef YYERROR_VERBOSE
-# undef YYERROR_VERBOSE
-# define YYERROR_VERBOSE 1
-#else
-# define YYERROR_VERBOSE ]b4_error_verbose_if([1], [0])[
-#endif
-
 /* Default (constant) value used for initialization for null
    right-hand sides.  Unlike the standard yacc.c template, here we set
    the default value of $$ to a zeroed-out value.  Since the default
@@ -376,7 +368,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if ]b4_api_PREFIX[DEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
+#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag])[
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -567,9 +559,8 @@ static void yypdumpstack (struct yyGLRStack* yystackp)
 #endif
 
 
-#if YYERROR_VERBOSE
-
-# ifndef yystpcpy
+]m4_case(b4_percent_define_get([parse.error]), [verbose],
+[[# ifndef yystpcpy
 #  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
 #   define yystpcpy stpcpy
 #  else
@@ -639,8 +630,7 @@ yytnamerr (char *yyres, const char *yystr)
     return YY_CAST (ptrdiff_t, strlen (yystr));
 }
 # endif
-
-#endif /* !YYERROR_VERBOSE */
+]])[
 
 /** State numbers. */
 typedef int yyStateNum;
@@ -756,7 +746,7 @@ yyMemoryExhausted (yyGLRStack* yystackp)
   YYLONGJMP (yystackp->yyexception_buffer, 2);
 }
 
-#if ]b4_api_PREFIX[DEBUG || YYERROR_VERBOSE
+#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG]])[
 /** A printable representation of TOKEN.  */
 static inline const char*
 yytokenName (yySymbol yytoken)
@@ -2075,10 +2065,11 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
   if (yystackp->yyerrState != 0)
     return;
-#if ! YYERROR_VERBOSE
-  yyerror (]b4_lyyerror_args[YY_("syntax error"));
-#else
-  {
+]m4_case(b4_percent_define_get([parse.error]),
+         [simple],
+[[  yyerror (]b4_lyyerror_args[YY_("syntax error"));]],
+         [verbose],
+[[  {
   yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
   yybool yysize_overflow = yyfalse;
   char* yymsg = YY_NULLPTR;
@@ -2203,8 +2194,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       yyerror (]b4_lyyerror_args[YY_("syntax error"));
       yyMemoryExhausted (yystackp);
     }
-  }
-#endif /* YYERROR_VERBOSE */
+  }]])[
   yynerrs += 1;
 }
 
