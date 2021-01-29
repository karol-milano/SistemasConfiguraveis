@@ -182,6 +182,11 @@ b4_location_if([#define yylloc b4_prefix[]lloc])])[
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
@@ -415,7 +420,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE
+#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
