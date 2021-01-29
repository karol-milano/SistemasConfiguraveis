@@ -236,7 +236,7 @@ typedef union {
   char *string;
   assoc_t assoc;
 } yystype;
-/* Line 193 of /usr/local/share/bison/yacc.c.  */
+/* Line 203 of /tmp/prefix/share/bison/yacc.c.  */
 #line 241 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -257,7 +257,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 213 of /usr/local/share/bison/yacc.c.  */
+/* Line 223 of /tmp/prefix/share/bison/yacc.c.  */
 #line 262 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -357,6 +357,7 @@ union yyalloc
 
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
+/* YYLAST -- Last index in YYTABLE.  */
 #define YYLAST   152
 
 /* YYNTOKENS -- Number of terminals. */
@@ -714,9 +715,9 @@ while (0)
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
 #ifdef YYLEX_PARAM
-# define YYLEX	yylex (&yylval, &yylloc, YYLEX_PARAM)
+# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
 #else
-# define YYLEX	yylex (&yylval, &yylloc)
+# define YYLEX yylex (&yylval, &yylloc)
 #endif
 
 /* Enable debugging if requested.  */
@@ -827,12 +828,13 @@ yystpcpy (yydest, yysrc)
 | Print this symbol on YYOUT.  |
 `-----------------------------*/
 
-static void
 #if defined (__STDC__) || defined (__cplusplus)
-yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue, YYLTYPE yylocation)
+static void
+yysymprint (FILE *yyout, int yytype, YYSTYPE yyvalue, YYLTYPE yylocation)
 #else
+static void
 yysymprint (yyout, yytype, yyvalue, yylocation)
-    FILE* yyout;
+    FILE *yyout;
     int yytype;
     YYSTYPE yyvalue;
     YYLTYPE yylocation;
@@ -866,10 +868,11 @@ yysymprint (yyout, yytype, yyvalue, yylocation)
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
-static void
 #if defined (__STDC__) || defined (__cplusplus)
+static void
 yydestruct (int yytype, YYSTYPE yyvalue, YYLTYPE yylocation)
 #else
+static void
 yydestruct (yytype, yyvalue, yylocation)
     int yytype;
     YYSTYPE yyvalue;
@@ -889,40 +892,48 @@ yydestruct (yytype, yyvalue, yylocation)
 
 
 
-/* The user can define YYPARSE_PARAM as the name of an argument to be passed
-   into yyparse.  The argument should have type void *.
-   It should actually point to an object.
-   Grammar actions can access the variable by casting it
-   to the proper pointer type.  */
+/* Prevent warnings from -Wmissing-prototypes.  */
 
 #ifdef YYPARSE_PARAM
 # if defined (__STDC__) || defined (__cplusplus)
-#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
-#  define YYPARSE_PARAM_DECL
+int yyparse (void *YYPARSE_PARAM);
 # else
-#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
-#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
+int yyparse ();
 # endif
-#else /* !YYPARSE_PARAM */
-# define YYPARSE_PARAM_ARG
-# define YYPARSE_PARAM_DECL
-#endif /* !YYPARSE_PARAM */
-
-/* Prevent warning if -Wstrict-prototypes.  */
-#ifdef __GNUC__
-# ifdef YYPARSE_PARAM
-int yyparse (void *);
-# else
+#else /* ! YYPARSE_PARAM */
+#if defined (__STDC__) || defined (__cplusplus)
 int yyparse (void);
-# endif
+#else
+int yyparse ();
+#endif
 #endif
 
 
 
 
+
+
+/*----------.
+| yyparse.  |
+`----------*/
+
+#ifdef YYPARSE_PARAM
+# if defined (__STDC__) || defined (__cplusplus)
+int yyparse (void *YYPARSE_PARAM)
+# else
+int yyparse (YYPARSE_PARAM)
+  void *YYPARSE_PARAM;
+# endif
+#else /* ! YYPARSE_PARAM */
+#if defined (__STDC__) || defined (__cplusplus)
+int
+yyparse (void)
+#else
 int
-yyparse (YYPARSE_PARAM_ARG)
-     YYPARSE_PARAM_DECL
+yyparse ()
+
+#endif
+#endif
 {
   /* The lookahead symbol.  */
 int yychar;
@@ -1008,7 +1019,7 @@ YYLTYPE yylloc;
  yysetstate:
   *yyssp = yystate;
 
-  if (yyssp >= yyss + yystacksize - 1)
+  if (yyss + yystacksize - 1 <= yyssp)
     {
       /* Get the current used size of the three stacks, in elements.  */
       YYSIZE_T yysize = yyssp - yyss + 1;
@@ -1040,10 +1051,10 @@ YYLTYPE yylloc;
       goto yyoverflowlab;
 # else
       /* Extend the stack our own way.  */
-      if (yystacksize >= YYMAXDEPTH)
+      if (YYMAXDEPTH <= yystacksize)
 	goto yyoverflowlab;
       yystacksize *= 2;
-      if (yystacksize > YYMAXDEPTH)
+      if (YYMAXDEPTH < yystacksize)
 	yystacksize = YYMAXDEPTH;
 
       {
@@ -1069,7 +1080,7 @@ YYLTYPE yylloc;
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
 
-      if (yyssp >= yyss + yystacksize - 1)
+      if (yyss + yystacksize - 1 <= yyssp)
 	YYABORT;
     }
 
@@ -1201,7 +1212,7 @@ yyreduce:
 		 yyn - 1, yyrline[yyn]);
 
       /* Print the symbols being reduced, and their result.  */
-      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
+      for (yyi = yyprhs[yyn]; 0 <= yyrhs[yyi]; yyi++)
 	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
       YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
     }
@@ -1616,8 +1627,8 @@ yyreduce:
 
     }
 
-/* Line 1016 of /usr/local/share/bison/yacc.c.  */
-#line 1621 "parse-gram.c"
+/* Line 1022 of /tmp/prefix/share/bison/yacc.c.  */
+#line 1632 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1727,7 +1738,7 @@ yyerrlab1:
 	  /* Pop the error token.  */
           YYPOPSTACK;
 	  /* Pop the rest of the stack.  */
-	  while (yyssp > yyss)
+	  while (yyss < yyssp)
 	    {
 	      YYDPRINTF ((stderr, "Error: popping "));
 	      YYDSYMPRINT ((stderr,
