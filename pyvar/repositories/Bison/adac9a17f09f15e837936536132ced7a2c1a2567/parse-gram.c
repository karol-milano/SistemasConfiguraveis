@@ -526,25 +526,26 @@ static const yytype_int16 yyrline[] =
    YYSYMBOL.  No bounds checking.  */
 static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
 
-/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
-   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
-static const char *const yytname[] =
+/* The user-facing name of the symbol whose (internal) number is
+   YYSYMBOL.  No bounds checking.  */
+static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
+
+static const char *
+yysymbol_name (int yysymbol)
 {
-  "\"end of file\"", "error", "$undefined", "\"string\"", "\"%token\"",
-  "\"%nterm\"", "\"%type\"", "\"%destructor\"", "\"%printer\"",
-  "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%precedence\"",
-  "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
-  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
-  "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
-  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%pure-parser\"",
-  "\"%require\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"%?{...}\"",
-  "\"[identifier]\"", "\"character literal\"", "\":\"", "\"epilogue\"",
-  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
-  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"integer\"",
-  "\"%param\"", "\"%union\"", "\"%empty\"", "$accept", "input",
+  static const char *const yy_sname[] =
+  {
+  "end of file", "error", "$undefined", "string", "%token", "%nterm",
+  "%type", "%destructor", "%printer", "%left", "%right", "%nonassoc",
+  "%precedence", "%prec", "%dprec", "%merge", "%code", "%default-prec",
+  "%define", "%defines", "%error-verbose", "%expect", "%expect-rr",
+  "%<flag>", "%file-prefix", "%glr-parser", "%initial-action", "%language",
+  "%name-prefix", "%no-default-prec", "%no-lines",
+  "%nondeterministic-parser", "%output", "%pure-parser", "%require",
+  "%skeleton", "%start", "%token-table", "%verbose", "%yacc", "{...}",
+  "%?{...}", "[identifier]", "character literal", ":", "epilogue", "=",
+  "identifier", "identifier:", "%%", "|", "%{...%}", ";", "<tag>", "<*>",
+  "<>", "integer", "%param", "%union", "%empty", "$accept", "input",
   "prologue_declarations", "prologue_declaration", "$@1", "params",
   "grammar_declaration", "code_props_type", "union_name",
   "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
@@ -555,12 +556,8 @@ static const char *const yytname[] =
   "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
   "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
   "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
-};
-
-static const char *
-yysymbol_name (int yysymbol)
-{
-  return yytname[yysymbol];
+  };
+  return yy_sname[yysymbol];
 }
 #endif
 
@@ -1577,56 +1574,6 @@ yystpcpy (char *yydest, const char *yysrc)
 #  endif
 # endif
 
-# ifndef yytnamerr
-/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
-   quotes and backslashes, so that it's suitable for yyerror.  The
-   heuristic is that double-quoting is unnecessary unless the string
-   contains an apostrophe, a comma, or backslash (other than
-   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
-   null, do not copy; instead, return the length of what the result
-   would have been.  */
-static YYPTRDIFF_T
-yytnamerr (char *yyres, const char *yystr)
-{
-  if (*yystr == '"')
-    {
-      YYPTRDIFF_T yyn = 0;
-      char const *yyp = yystr;
-
-      for (;;)
-        switch (*++yyp)
-          {
-          case '\'':
-          case ',':
-            goto do_not_strip_quotes;
-
-          case '\\':
-            if (*++yyp != '\\')
-              goto do_not_strip_quotes;
-            else
-              goto append;
-
-          append:
-          default:
-            if (yyres)
-              yyres[yyn] = *yyp;
-            yyn++;
-            break;
-
-          case '"':
-            if (yyres)
-              yyres[yyn] = '\0';
-            return yyn;
-          }
-    do_not_strip_quotes: ;
-    }
-
-  if (yyres)
-    return yystpcpy (yyres, yystr) - yyres;
-  else
-    return yystrlen (yystr);
-}
-# endif
 
 
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
@@ -1682,7 +1629,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     for (yyi = 0; yyi < yycount; ++yyi)
       {
         YYPTRDIFF_T yysize1
-          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
+          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
           yysize = yysize1;
         else
@@ -1708,7 +1655,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     while ((*yyp = *yyformat) != '\0')
       if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
         {
-          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
+          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
           yyformat += 2;
         }
       else
