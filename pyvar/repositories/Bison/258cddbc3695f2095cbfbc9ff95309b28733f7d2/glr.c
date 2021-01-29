@@ -215,11 +215,6 @@ b4_percent_code_get([[top]])[
 # define YYERROR_VERBOSE ]b4_error_verbose_flag[
 #endif
 
-/* Enabling the token table.  */
-#ifndef YYTOKEN_TABLE
-# define YYTOKEN_TABLE ]b4_token_table[
-#endif
-
 /* Default (constant) value used for initialization for null
    right-hand sides.  Unlike the standard yacc.c template,
    here we set the default value of $$ to a zeroed-out value.
@@ -367,7 +362,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
+#if YYDEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
