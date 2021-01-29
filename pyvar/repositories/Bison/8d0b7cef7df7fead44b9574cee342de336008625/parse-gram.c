@@ -80,11 +80,11 @@
 
 #line 82 "src/parse-gram.c" /* yacc.c:339  */
 
-# ifndef YY_NULL
+# ifndef YY_NULLPTR
 #  if defined __cplusplus && 201103L <= __cplusplus
-#   define YY_NULL nullptr
+#   define YY_NULLPTR nullptr
 #  else
-#   define YY_NULL 0
+#   define YY_NULLPTR 0
 #  endif
 # endif
 
@@ -639,7 +639,7 @@ static const char *const yytname[] =
   "symbols.1", "generic_symlist", "generic_symlist_item", "tag",
   "symbol_def", "symbol_defs.1", "grammar", "rules_or_grammar_declaration",
   "rules", "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value",
-  "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
+  "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULLPTR
 };
 #endif
 
@@ -1569,11 +1569,11 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yytype_int16 *yyesa, yytype_int16 **yyes,
                 YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
 {
-  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
+  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
-  const char *yyformat = YY_NULL;
+  const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Number of reported tokens (one for the "unexpected", one per
@@ -1628,7 +1628,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   }
                 yyarg[yycount++] = yytname[yyx];
                 {
-                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
+                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                   if (! (yysize <= yysize1
                          && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                     return 2;
