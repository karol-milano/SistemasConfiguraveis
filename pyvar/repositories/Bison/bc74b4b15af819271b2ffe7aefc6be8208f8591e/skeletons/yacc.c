@@ -429,7 +429,7 @@ typedef int yy_state_fast_t;
 ]],
 [[#define YY_ASSERT(E) ((void) (0 && (E)))]])[
 
-#if ]b4_lac_if([[1]], [b4_error_verbose_if([[1]], [[!defined yyoverflow]])])[
+#if ]b4_lac_if([[1]], [b4_parse_error_case([simple], [[!defined yyoverflow]], [[1]])])[
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */]dnl
 b4_push_if([], [b4_lac_if([], [[
@@ -496,7 +496,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 #  endif
 # endif]b4_lac_if([[
 # define YYCOPY_NEEDED 1]])[
-#endif]b4_lac_if([], [b4_error_verbose_if([], [[/* !defined yyoverflow */]])])[
+#endif]b4_lac_if([], [b4_parse_error_case([simple], [[/* !defined yyoverflow */]])])[
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
@@ -602,7 +602,7 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
      [[YYRLINE[YYN] -- Source line where rule number YYN was defined.]])[
 #endif
 
-#if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag])[
+#if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
 static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
@@ -2010,7 +2010,7 @@ yyabortlab:
   goto yyreturn;
 
 
-#if ]b4_lac_if([[1]], [b4_error_verbose_if([[1]], [[!defined yyoverflow]])])[
+#if ]b4_lac_if([[1]], [b4_parse_error_case([simple], [[!defined yyoverflow]], [[1]])])[
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
