@@ -536,20 +536,23 @@ static const unsigned short int yyrline[] =
 #endif
 
 #if YYDEBUG || YYERROR_VERBOSE
-/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
+/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
-  "end of file", "error", "$undefined", "string", "integer", "%token",
-  "%nterm", "%type", "%destructor {...}", "%printer {...}", "%union {...}",
-  "%left", "%right", "%nonassoc", "%prec", "%dprec", "%merge", "%debug",
-  "%default-prec", "%define", "%defines", "%error-verbose", "%expect",
-  "%expect-rr", "%file-prefix", "%glr-parser", "%initial-action {...}",
-  "%lex-param {...}", "%locations", "%name-prefix", "%no-default-prec",
-  "%no-lines", "%nondeterministic-parser", "%output", "%parse-param {...}",
-  "%pure-parser", "%skeleton", "%start", "%token-table", "%verbose",
-  "%yacc", "type", "=", ";", "|", "identifier", "identifier:", "%%",
-  "%{...%}", "epilogue", "{...}", "$accept", "input", "declarations",
+  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor {...}\"",
+  "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
+  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
+  "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
+  "\"%initial-action {...}\"", "\"%lex-param {...}\"", "\"%locations\"",
+  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
+  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"",
+  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations",
   "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
   "symbols.1", "symbol_def", "symbol_defs.1", "grammar",
@@ -874,8 +877,8 @@ yy_reduce_print (yyrule)
              yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
-    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
-  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
+    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
+  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
 }
 
 # define YY_REDUCE_PRINT(Rule)		\
@@ -964,7 +967,55 @@ yystpcpy (yydest, yysrc)
 #  endif
 # endif
 
-#endif /* !YYERROR_VERBOSE */
+# ifndef yytnamerr
+/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
+   quotes and backslashes, so that it's suitable for yyerror.  The
+   heuristic is that double-quoting is unnecessary unless the string
+   contains an apostrophe, a comma, or backslash (other than
+   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
+   null, do not copy; instead, return the length of what the result
+   would have been.  */
+static YYSIZE_T
+yytnamerr (char *yyres, const char *yystr)
+{
+  if (*yystr == '"')
+    {
+      size_t yyn = 0;
+      char const *yyp = yystr;
+
+      for (;;)
+	switch (*++yyp)
+	  {
+	  case '\'':
+	  case ',':
+	    goto do_not_strip_quotes;
+
+	  case '\\':
+	    if (*++yyp != '\\')
+	      goto do_not_strip_quotes;
+	    /* Fall through.  */
+	  default:
+	    if (yyres)
+	      yyres[yyn] = *yyp;
+	    yyn++;
+	    break;
+
+	  case '"':
+	    if (yyres)
+	      yyres[yyn] = '\0';
+	    return yyn;
+	  }
+    do_not_strip_quotes: ;
+    }
+
+  if (! yyres)
+    return yystrlen (yystr);
+
+  return yystpcpy (yyres, yystr) - yyres;
+}
+# endif
+
+#endif /* YYERROR_VERBOSE */
 
 
 
@@ -1006,92 +1057,92 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1010 "parse-gram.c"
+#line 1061 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1015 "parse-gram.c"
+#line 1066 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 167 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1020 "parse-gram.c"
+#line 1071 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1025 "parse-gram.c"
+#line 1076 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1030 "parse-gram.c"
+#line 1081 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 168 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1035 "parse-gram.c"
+#line 1086 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1040 "parse-gram.c"
+#line 1091 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 170 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1045 "parse-gram.c"
+#line 1096 "parse-gram.c"
         break;
       case 41: /* "\"type\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1050 "parse-gram.c"
+#line 1101 "parse-gram.c"
         break;
       case 45: /* "\"identifier\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1055 "parse-gram.c"
+#line 1106 "parse-gram.c"
         break;
       case 46: /* "\"identifier:\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1060 "parse-gram.c"
+#line 1111 "parse-gram.c"
         break;
       case 48: /* "\"%{...%}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1065 "parse-gram.c"
+#line 1116 "parse-gram.c"
         break;
       case 49: /* "\"epilogue\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1070 "parse-gram.c"
+#line 1121 "parse-gram.c"
         break;
       case 50: /* "\"{...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1075 "parse-gram.c"
+#line 1126 "parse-gram.c"
         break;
       case 71: /* "symbol" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1080 "parse-gram.c"
+#line 1131 "parse-gram.c"
         break;
       case 72: /* "action" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1085 "parse-gram.c"
+#line 1136 "parse-gram.c"
         break;
       case 73: /* "string_as_id" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1090 "parse-gram.c"
+#line 1141 "parse-gram.c"
         break;
       case 74: /* "string_content" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1095 "parse-gram.c"
+#line 1146 "parse-gram.c"
         break;
       default:
         break;
@@ -1264,8 +1315,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 877 of yacc.c.  */
-#line 1269 "parse-gram.c"
+/* Line 925 of yacc.c.  */
+#line 1320 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1847,8 +1898,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1073 of yacc.c.  */
-#line 1852 "parse-gram.c"
+/* Line 1121 of yacc.c.  */
+#line 1903 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1888,7 +1939,7 @@ yyerrlab:
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
 	  int yytype = YYTRANSLATE (yychar);
-	  YYSIZE_T yysize0 = yystrlen (yytname[yytype]);
+	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
 	  YYSIZE_T yysize = yysize0;
 	  YYSIZE_T yysize1;
 	  int yysize_overflow = 0;
@@ -1940,7 +1991,7 @@ yyerrlab:
 		    break;
 		  }
 		yyarg[yycount++] = yytname[yyx];
-		yysize1 = yysize + yystrlen (yytname[yyx]);
+		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
 		yysize_overflow |= yysize1 < yysize;
 		yysize = yysize1;
 		yyfmt = yystpcpy (yyfmt, yyprefix);
@@ -1965,7 +2016,7 @@ yyerrlab:
 		{
 		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
 		    {
-		      yyp = yystpcpy (yyp, yyarg[yyi++]);
+		      yyp += yytnamerr (yyp, yyarg[yyi++]);
 		      yyf += 2;
 		    }
 		  else
