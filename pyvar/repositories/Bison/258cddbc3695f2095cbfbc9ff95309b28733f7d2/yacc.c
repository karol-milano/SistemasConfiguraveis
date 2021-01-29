@@ -336,11 +336,6 @@ m4_if(b4_prefix, [yy], [],
 # define YYERROR_VERBOSE ]b4_error_verbose_flag[
 #endif
 
-/* Enabling the token table.  */
-#ifndef YYTOKEN_TABLE
-# define YYTOKEN_TABLE ]b4_token_table[
-#endif
-
 /* In a future release of Bison, this section will be replaced
    by #include "@basename(]b4_spec_defines_file[@)".  */
 ]b4_shared_declarations[
@@ -607,7 +602,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
+#if YYDEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
