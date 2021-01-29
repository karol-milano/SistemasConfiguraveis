@@ -522,6 +522,10 @@ static const yytype_int16 yyrline[] =
 #endif
 
 #if 1
+/* The user-facing name of the symbol whose (internal) number is
+   YYSYMBOL.  No bounds checking.  */
+static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
+
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -553,9 +557,6 @@ static const char *const yytname[] =
   "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
 };
 
-/* The user-facing name of the symbol whose (internal) number is
-   YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
 static const char *
 yysymbol_name (int yysymbol)
 {
