@@ -172,6 +172,11 @@ b4_pre_prologue[
 # define YYERROR_VERBOSE ]b4_error_verbose[
 #endif
 
+/* Enabling the token table.  */
+#ifndef YYTOKEN_TABLE
+# define YYTOKEN_TABLE ]b4_token_table[
+#endif
+
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 ]m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
@@ -331,7 +336,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if (YYDEBUG) || YYERROR_VERBOSE
+#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
