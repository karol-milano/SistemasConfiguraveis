@@ -18,11 +18,10 @@
    Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.  */
 
-/* As a special exception, when this parser skeleton is copied by
-   Bison into a Bison output file, you may use that output file
-   without restriction.  This special exception was added by the Free
-   Software Foundation for C LALR(1) parsers in version 1.24 of
-   Bison.  */
+/* As a special exception, when this file is copied by Bison into a
+   Bison output file, you may use that output file without restriction.
+   This special exception was added by the Free Software Foundation
+   in version 1.24 of Bison.  */
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
@@ -263,8 +262,8 @@ typedef union YYSTYPE {
   assoc assoc;
   uniqstr uniqstr;
 } YYSTYPE;
-/* Line 197 of yacc.c.  */
-#line 268 "parse-gram.c"
+/* Line 196 of yacc.c.  */
+#line 267 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -287,8 +286,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 220 of yacc.c.  */
-#line 292 "parse-gram.c"
+/* Line 219 of yacc.c.  */
+#line 291 "parse-gram.c"
 
 /* Define YYMODERN_C if this compiler supports C89 or better.  If
    __STDC__ is defined, the compiler is modern.  IBM xlc 7.0 when run
@@ -382,7 +381,7 @@ YYID (i)
 # endif
 
 # ifdef YYSTACK_ALLOC
-   /* Pacify GCC's `empty if-body' warning. */
+   /* Pacify GCC's `empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
@@ -483,18 +482,18 @@ union yyalloc
    typedef short int yysigned_char;
 #endif
 
-/* YYFINAL -- State number of the termination state. */
+/* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
 #define YYLAST   161
 
-/* YYNTOKENS -- Number of terminals. */
+/* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  52
-/* YYNNTS -- Number of nonterminals. */
+/* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  25
-/* YYNRULES -- Number of rules. */
+/* YYNRULES -- Number of rules.  */
 #define YYNRULES  81
-/* YYNRULES -- Number of states. */
+/* YYNRULES -- Number of states.  */
 #define YYNSTATES  110
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
@@ -556,7 +555,7 @@ static const unsigned char yyprhs[] =
      203,   204
 };
 
-/* YYRHS -- A `-1'-separated list of the rules' RHS. */
+/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yysigned_char yyrhs[] =
 {
       53,     0,    -1,    54,    48,    66,    76,    -1,    -1,    54,
@@ -599,7 +598,7 @@ static const unsigned short int yyrline[] =
 
 #if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
-   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
+   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
 {
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
@@ -684,7 +683,7 @@ static const unsigned char yydefact[] =
        0,     0,     0,    77,    70,    71,    67,    72,    73,    74
 };
 
-/* YYDEFGOTO[NTERM-NUM]. */
+/* YYDEFGOTO[NTERM-NUM].  */
 static const yysigned_char yydefgoto[] =
 {
       -1,     1,     2,    41,    67,    43,    47,    46,    44,    45,
@@ -807,7 +806,7 @@ do								\
       yychar = (Token);						\
       yylval = (Value);						\
       yytoken = YYTRANSLATE (yychar);				\
-      YYPOPSTACK;						\
+      YYPOPSTACK (1);						\
       goto yybackup;						\
     }								\
   else								\
@@ -830,7 +829,7 @@ while (YYID (0))
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(Current, Rhs, N)				\
     do									\
-      if (N)								\
+      if (YYID (N))                                                    \
 	{								\
 	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
 	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
@@ -891,12 +890,13 @@ do {									  \
   if (yydebug)								  \
     {									  \
       YYFPRINTF (stderr, "%s ", Title);					  \
-      yysymprint (stderr,						  \
+      yy_symbol_print (stderr,						  \
                   Type, Value, Location); \
       YYFPRINTF (stderr, "\n");						  \
     }									  \
 } while (YYID (0))
 
+
 /*--------------------------------.
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/
@@ -904,10 +904,10 @@ do {									  \
 /*ARGSUSED*/
 #if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
 static void
-yysymprint (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
+yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
 #else
 static void
-yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
+yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     FILE *yyoutput;
     int yytype;
     const YYSTYPE * const yyvaluep;
@@ -916,14 +916,6 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
 {
   YYUSE (yyvaluep);
   YYUSE (yylocationp);
-  if (yytype < YYNTOKENS)
-    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
-  else
-    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
-
-  YY_LOCATION_PRINT (yyoutput, *yylocationp);
-  YYFPRINTF (yyoutput, ": ");
-
 # ifdef YYPRINT
   if (yytype < YYNTOKENS)
     YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
@@ -933,96 +925,123 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 937 "parse-gram.c"
+#line 929 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 942 "parse-gram.c"
+#line 934 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 947 "parse-gram.c"
+#line 939 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 952 "parse-gram.c"
+#line 944 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 957 "parse-gram.c"
+#line 949 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 962 "parse-gram.c"
+#line 954 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 967 "parse-gram.c"
+#line 959 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 972 "parse-gram.c"
+#line 964 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 977 "parse-gram.c"
+#line 969 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 982 "parse-gram.c"
+#line 974 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
 #line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 987 "parse-gram.c"
+#line 979 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 992 "parse-gram.c"
+#line 984 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 997 "parse-gram.c"
+#line 989 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1002 "parse-gram.c"
+#line 994 "parse-gram.c"
         break;
       case 72: /* "symbol" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1007 "parse-gram.c"
+#line 999 "parse-gram.c"
         break;
       case 73: /* "action" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1012 "parse-gram.c"
+#line 1004 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1017 "parse-gram.c"
+#line 1009 "parse-gram.c"
         break;
       case 75: /* "string_content" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1022 "parse-gram.c"
+#line 1014 "parse-gram.c"
         break;
       default:
         break;
     }
+}
+
+
+/*--------------------------------.
+| Print this symbol on YYOUTPUT.  |
+`--------------------------------*/
+
+#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+static void
+yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
+#else
+static void
+yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
+    FILE *yyoutput;
+    int yytype;
+    const YYSTYPE * const yyvaluep;
+    const YYLTYPE * const yylocationp;
+#endif
+{
+  if (yytype < YYNTOKENS)
+    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
+  else
+    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
+
+  YY_LOCATION_PRINT (yyoutput, *yylocationp);
+  YYFPRINTF (yyoutput, ": ");
+  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
   YYFPRINTF (yyoutput, ")");
 }
 
@@ -1042,7 +1061,7 @@ yy_stack_print (bottom, top)
 #endif
 {
   YYFPRINTF (stderr, "Stack now");
-  for (/* Nothing. */; bottom <= top; ++bottom)
+  for (; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
   YYFPRINTF (stderr, "\n");
 }
@@ -1079,9 +1098,9 @@ yy_reduce_print (yyvsp, yylsp, yyrule
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
-      yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
-                  &(yyvsp[(yyi + 1) - (yynrhs)])
-                  , &(yylsp[(yyi + 1) - (yynrhs)])	          );
+      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
+                       &(yyvsp[(yyi + 1) - (yynrhs)])
+                       , &(yylsp[(yyi + 1) - (yynrhs)])	               );
       fprintf (stderr, "\n");
     }
 }
@@ -1451,10 +1470,10 @@ YYLTYPE yylloc;
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
   YYLTYPE *yylsp;
-  /* The locations where the error started and ended. */
+  /* The locations where the error started and ended.  */
   YYLTYPE yyerror_range[2];
 
-#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
+#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
 
   YYSIZE_T yystacksize = YYINITDEPTH;
 
@@ -1463,9 +1482,9 @@ YYLTYPE yylloc;
   YYSTYPE yyval;
   YYLTYPE yyloc;
 
-  /* When reducing, the number of symbols on the RHS of the reduced
-     rule.  */
-  int yylen;
+  /* The number of symbols on the RHS of the reduced rule.
+     Keep to zero when no symbol should be popped.  */
+  int yylen = 0;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
@@ -1489,7 +1508,7 @@ YYLTYPE yylloc;
 #endif
 
 
-  /* User initialization code. */
+  /* User initialization code.  */
 #line 72 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1498,8 +1517,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1088 of yacc.c.  */
-#line 1503 "parse-gram.c"
+/* Line 1087 of yacc.c.  */
+#line 1522 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1508,8 +1527,7 @@ YYLTYPE yylloc;
 `------------------------------------------------------------*/
  yynewstate:
   /* In all cases, when you get here, the value and location stacks
-     have just been pushed. so pushing a state here evens the stacks.
-     */
+     have just been pushed.  So pushing a state here evens the stacks.  */
   yyssp++;
 
  yysetstate:
@@ -1522,7 +1540,7 @@ YYLTYPE yylloc;
 
 #ifdef yyoverflow
       {
-	/* Give user a chance to reallocate the stack. Use copies of
+	/* Give user a chance to reallocate the stack.  Use copies of
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
@@ -1589,12 +1607,10 @@ YYLTYPE yylloc;
 `-----------*/
 yybackup:
 
-/* Do appropriate processing given the current state.  */
-/* Read a look-ahead token if we need one and don't already have one.  */
-/* yyresume: */
+  /* Do appropriate processing given the current state.  Read a
+     look-ahead token if we need one and don't already have one.  */
 
   /* First try to decide what to do without reference to look-ahead token.  */
-
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
@@ -1636,22 +1652,21 @@ yybackup:
   if (yyn == YYFINAL)
     YYACCEPT;
 
+  /* Count tokens shifted since error; after three, turn off error
+     status.  */
+  if (yyerrstatus)
+    yyerrstatus--;
+
   /* Shift the look-ahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
-  /* Discard the token being shifted unless it is eof.  */
+  /* Discard the shifted token unless it is eof.  */
   if (yychar != YYEOF)
     yychar = YYEMPTY;
 
+  yystate = yyn;
   *++yyvsp = yylval;
   *++yylsp = yylloc;
-
-  /* Count tokens shifted since error; after three, turn off error
-     status.  */
-  if (yyerrstatus)
-    yyerrstatus--;
-
-  yystate = yyn;
   goto yynewstate;
 
 
@@ -1682,7 +1697,7 @@ yyreduce:
      GCC warning that YYVAL may be used uninitialized.  */
   yyval = yyvsp[1-yylen];
 
-  /* Default location. */
+  /* Default location.  */
   YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
@@ -2088,17 +2103,14 @@ yyreduce:
     break;
 
 
+/* Line 1276 of yacc.c.  */
+#line 2108 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
 
-/* Line __line__ of yacc.c.  */
-#line 2097 "parse-gram.c"
-
-  yyvsp -= yylen;
-  yyssp -= yylen;
-  yylsp -= yylen;
-
+  YYPOPSTACK (yylen);
+  yylen = 0;
   YY_STACK_PRINT (yyss, yyssp);
 
   *++yyvsp = yyval;
@@ -2202,9 +2214,11 @@ yyerrorlab:
      goto yyerrorlab;
 
   yyerror_range[0] = yylsp[1-yylen];
-  yylsp -= yylen;
-  yyvsp -= yylen;
-  yyssp -= yylen;
+  /* Do not reclaim the symbols of the rule which action triggered
+     this YYERROR.  */
+  YYPOPSTACK (yylen);
+  yylen = 0;
+  YY_STACK_PRINT (yyss, yyssp);
   yystate = *yyssp;
   goto yyerrlab1;
 
@@ -2236,7 +2250,7 @@ yyerrlab1:
       yyerror_range[0] = *yylsp;
       yydestruct ("Error: popping",
                   yystos[yystate], yyvsp, yylsp);
-      YYPOPSTACK;
+      YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
     }
@@ -2248,11 +2262,11 @@ yyerrlab1:
 
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the look-ahead.  YYLOC is available though. */
+     the look-ahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
   *++yylsp = yyloc;
 
-  /* Shift the error token. */
+  /* Shift the error token.  */
   YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
 
   yystate = yyn;
@@ -2287,11 +2301,15 @@ yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
      yydestruct ("Cleanup: discarding lookahead",
 		 yytoken, &yylval, &yylloc);
+  /* Do not reclaim the symbols of the rule which action triggered
+     this YYABORT or YYACCEPT.  */
+  YYPOPSTACK (yylen);
+  YY_STACK_PRINT (yyss, yyssp);
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
 		  yystos[*yyssp], yyvsp, yylsp);
-      YYPOPSTACK;
+      YYPOPSTACK (1);
     }
 #ifndef yyoverflow
   if (yyss != yyssa)
