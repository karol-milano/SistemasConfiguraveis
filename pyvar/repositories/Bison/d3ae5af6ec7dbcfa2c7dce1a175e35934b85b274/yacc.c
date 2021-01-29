@@ -175,36 +175,19 @@ m4_define([b4_declare_scanner_communication_variables], [[
 int yychar;
 
 ]b4_pure_if([[
-#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
-/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
-# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
-    _Pragma ("GCC diagnostic push") \
-    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
-    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
-# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
-    _Pragma ("GCC diagnostic pop")
-#else
+/* The semantic value of the lookahead symbol.  */
 /* Default value used for initialization, for pacifying older GCCs
    or non-GCC compilers.  */
-static YYSTYPE yyval_default;
-# define YY_INITIAL_VALUE(Value) = Value
-#endif]b4_locations_if([[
-static YYLTYPE yyloc_default][]b4_yyloc_default[;]])])[
-#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
-# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
-# define YY_IGNORE_MAYBE_UNINITIALIZED_END
-#endif
-#ifndef YY_INITIAL_VALUE
-# define YY_INITIAL_VALUE(Value) /* Nothing. */
-#endif
-
-/* The semantic value of the lookahead symbol.  */
-YYSTYPE yylval YY_INITIAL_VALUE (yyval_default);]b4_locations_if([[
+YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
+YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);]b4_locations_if([[
 
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc]b4_pure_if([ = yyloc_default], [b4_yyloc_default])[;
-]])b4_pure_if([], [[
-
+static YYLTYPE yyloc_default]b4_yyloc_default[;
+YYLTYPE yylloc = yyloc_default;]])],
+[[/* The semantic value of the lookahead symbol.  */
+YYSTYPE yylval;]b4_locations_if([[
+/* Location data for the lookahead symbol.  */
+YYLTYPE yylloc]b4_yyloc_default[;]])[
 /* Number of syntax errors so far.  */
 int yynerrs;]])])
 
