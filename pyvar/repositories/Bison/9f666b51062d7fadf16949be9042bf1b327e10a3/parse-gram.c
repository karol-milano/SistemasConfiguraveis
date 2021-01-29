@@ -503,19 +503,16 @@ static const unsigned short int yyrline[] =
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
-  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor {...}\"",
-  "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
-  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
-  "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
-  "\"%initial-action {...}\"", "\"%lex-param {...}\"", "\"%locations\"",
-  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
-  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"",
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"",
-  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations",
+  "end of file", "error", "$undefined", "string", "integer", "%token",
+  "%nterm", "%type", "%destructor {...}", "%printer {...}", "%union {...}",
+  "%left", "%right", "%nonassoc", "%prec", "%dprec", "%merge", "%debug",
+  "%default-prec", "%define", "%defines", "%error-verbose", "%expect",
+  "%expect-rr", "%file-prefix", "%glr-parser", "%initial-action {...}",
+  "%lex-param {...}", "%locations", "%name-prefix", "%no-default-prec",
+  "%no-lines", "%nondeterministic-parser", "%output", "%parse-param {...}",
+  "%pure-parser", "%skeleton", "%start", "%token-table", "%verbose",
+  "%yacc", "type", "=", ";", "|", "identifier", "identifier:", "%%",
+  "%{...%}", "epilogue", "{...}", "$accept", "input", "declarations",
   "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
   "symbols.1", "symbol_def", "symbol_defs.1", "grammar",
@@ -1162,7 +1159,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 856 of yacc.c.  */
-#line 1166 "parse-gram.c"
+#line 1163 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1747,7 +1744,7 @@ yyreduce:
     }
 
 /* Line 1052 of yacc.c.  */
-#line 1751 "parse-gram.c"
+#line 1748 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
