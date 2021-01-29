@@ -1,4 +1,4 @@
-/* A Bison parser, made from parse-gram.y, by GNU bison 1.75b.  */
+/* A Bison parser, made by GNU Bison 1.75b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -238,8 +238,8 @@ typedef union {
   assoc_t assoc;
   struniq_t struniq;
 } yystype;
-/* Line 237 of /usr/local/share/bison/yacc.c.  */
-#line 243 "parse-gram.c"
+/* Line 195 of /usr/local/share/bison/yacc.c.  */
+#line 242 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -259,8 +259,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 257 of /usr/local/share/bison/yacc.c.  */
-#line 264 "parse-gram.c"
+/* Line 215 of /usr/local/share/bison/yacc.c.  */
+#line 263 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -375,8 +375,9 @@ union yyalloc
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   301
 
-#define YYTRANSLATE(X) \
-  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)
+#define YYTRANSLATE(YYX) 						\
+  ((YYX <= 0) ? YYEOF :							\
+   (unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const unsigned char yytranslate[] =
@@ -661,7 +662,7 @@ static const unsigned char yystos[] =
 #endif
 
 #define yyerrok		(yyerrstatus = 0)
-#define yyclearin	(yychar = YYEMPTY)
+#define yyclearin	(yytoken = YYEMPTY)
 #define YYEMPTY		-2
 #define YYEOF		0
 
@@ -679,11 +680,11 @@ static const unsigned char yystos[] =
 
 #define YYBACKUP(Token, Value)					\
 do								\
-  if (yychar == YYEMPTY && yylen == 1)				\
+  if (yytoken == YYEMPTY && yylen == 1)				\
     {								\
       yychar = (Token);						\
       yylval = (Value);						\
-      yychar1 = YYTRANSLATE (yychar);				\
+      yytoken = YYTRANSLATE (yychar);				\
       YYPOPSTACK;						\
       goto yybackup;						\
     }								\
@@ -826,25 +827,25 @@ yystpcpy (yydest, yysrc)
 
 #if defined (__STDC__) || defined (__cplusplus)
 static void
-yysymprint (FILE *yyout, int yytype, YYSTYPE yyvalue, YYLTYPE yylocation)
+yysymprint (FILE *yyout, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
 static void
-yysymprint (yyout, yytype, yyvalue, yylocation)
+yysymprint (yyout, yytype, yyvaluep, yylocationp)
     FILE *yyout;
     int yytype;
-    YYSTYPE yyvalue;
-    YYLTYPE yylocation;
+    YYSTYPE *yyvaluep;
+    YYLTYPE *yylocationp;
 #endif
 {
   /* Pacify ``unused variable'' warnings.  */
-  (void) yyvalue;
-  (void) yylocation;
+  (void) yyvaluep;
+  (void) yylocationp;
 
   if (yytype < YYNTOKENS)
     {
       YYFPRINTF (yyout, "token %s (", yytname[yytype]);
 # ifdef YYPRINT
-      YYPRINT (yyout, yytoknum[yytype], yyvalue);
+      YYPRINT (yyout, yytoknum[yytype], *yyvaluep);
 # endif
     }
   else
@@ -857,35 +858,34 @@ yysymprint (yyout, yytype, yyvalue, yylocation)
     }
   YYFPRINTF (yyout, ")");
 }
-#endif /* YYDEBUG. */
-
 
+#endif /* YYDEBUG. */
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
 #if defined (__STDC__) || defined (__cplusplus)
 static void
-yydestruct (int yytype, YYSTYPE yyvalue, YYLTYPE yylocation)
+yydestruct (int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
 static void
-yydestruct (yytype, yyvalue, yylocation)
+yydestruct (yytype, yyvaluep, yylocationp)
     int yytype;
-    YYSTYPE yyvalue;
-    YYLTYPE yylocation;
+    YYSTYPE *yyvaluep;
+    YYLTYPE *yylocationp;
 #endif
 {
   /* Pacify ``unused variable'' warnings.  */
-  (void) yyvalue;
-  (void) yylocation;
+  (void) yyvaluep;
+  (void) yylocationp;
 
   switch (yytype)
     {
+
       default:
         break;
     }
 }
-
 
 
 /* Prevent warnings from -Wmissing-prototypes.  */
@@ -948,7 +948,7 @@ YYLTYPE yylloc;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
   /* Lookahead token as an internal (translated) token number.  */
-  int yychar1 = 0;
+  int yytoken = 0;
 
   /* Three stacks and their tools:
      `yyss': related to states,
@@ -991,7 +991,7 @@ YYLTYPE yylloc;
   yystate = 0;
   yyerrstatus = 0;
   yynerrs = 0;
-  yychar = YYEMPTY;		/* Cause a token to be read.  */
+  yychar = yytoken = YYEMPTY;		/* Cause a token to be read.  */
 
   /* Initialize stack pointers.
      Waste one element of value and location stack
@@ -1101,39 +1101,31 @@ yybackup:
 
   /* Not known => get a lookahead token if don't already have one.  */
 
-  /* yychar is either YYEMPTY or YYEOF
-     or a valid token in external form.  */
-
-  if (yychar == YYEMPTY)
+  /* YYTOKEN is either YYEMPTY or YYEOF or a valid token.  */
+  if (yytoken == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
+      yytoken = YYTRANSLATE (yychar);
     }
 
-  /* Convert token to internal form (in yychar1) for indexing tables with.  */
-
-  if (yychar <= 0)		/* This means end of input.  */
+  if (yytoken == YYEOF)
     {
-      yychar1 = 0;
-      yychar = YYEOF;		/* Don't call YYLEX any more.  */
-
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
-      yychar1 = YYTRANSLATE (yychar);
-
       /* We have to keep this `#if YYDEBUG', since we use variables
 	 which are defined only if `YYDEBUG' is set.  */
       YYDPRINTF ((stderr, "Next token is "));
-      YYDSYMPRINT ((stderr, yychar1, yylval, yyloc));
+      YYDSYMPRINT ((stderr, yytoken, &yylval, &yyloc));
       YYDPRINTF ((stderr, "\n"));
     }
 
-  /* If the proper action on seeing token YYCHAR1 is to reduce or to
+  /* If the proper action on seeing token YYTOKEN is to reduce or to
      detect an error, take that action.  */
-  yyn += yychar1;
-  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
+  yyn += yytoken;
+  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
     goto yydefault;
   yyn = yytable[yyn];
   if (yyn <= 0)
@@ -1149,11 +1141,11 @@ yybackup:
 
   /* Shift the lookahead token.  */
   YYDPRINTF ((stderr, "Shifting token %d (%s), ",
-	      yychar, yytname[yychar1]));
+	      yytoken, yytname[yytoken]));
 
   /* Discard the token being shifted unless it is eof.  */
-  if (yychar != YYEOF)
-    yychar = YYEMPTY;
+  if (yytoken != YYEOF)
+    yytoken = YYEMPTY;
 
   *++yyvsp = yylval;
   *++yylsp = yylloc;
@@ -1611,8 +1603,8 @@ yyreduce:
 
     }
 
-/* Line 1056 of /usr/local/share/bison/yacc.c.  */
-#line 1616 "parse-gram.c"
+/* Line 950 of /usr/local/share/bison/yacc.c.  */
+#line 1607 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1717,7 +1709,7 @@ yyerrlab1:
 	 error, discard it.  */
 
       /* Return failure if at end of input.  */
-      if (yychar == YYEOF)
+      if (yytoken == YYEOF)
         {
 	  /* Pop the error token.  */
           YYPOPSTACK;
@@ -1727,18 +1719,18 @@ yyerrlab1:
 	      YYDPRINTF ((stderr, "Error: popping "));
 	      YYDSYMPRINT ((stderr,
 			    yystos[*yyssp],
-			    *yyvsp, *yylsp));
+			    yyvsp, yylsp));
 	      YYDPRINTF ((stderr, "\n"));
-	      yydestruct (yystos[*yyssp], *yyvsp, *yylsp);
+	      yydestruct (yystos[*yyssp], yyvsp, yylsp);
 	      YYPOPSTACK;
 	    }
 	  YYABORT;
         }
 
       YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
-		  yychar, yytname[yychar1]));
-      yydestruct (yychar1, yylval, yylloc);
-      yychar = YYEMPTY;
+		  yytoken, yytname[yytoken]));
+      yydestruct (yytoken, &yylval, &yylloc);
+      yytoken = YYEMPTY;
     }
 
   /* Else will try to reuse lookahead token after shifting the error
@@ -1766,10 +1758,10 @@ yyerrlab1:
 
       YYDPRINTF ((stderr, "Error: popping "));
       YYDSYMPRINT ((stderr,
-		    yystos[*yyssp], *yyvsp, *yylsp));
+		    yystos[*yyssp], yyvsp, yylsp));
       YYDPRINTF ((stderr, "\n"));
 
-      yydestruct (yystos[yystate], *yyvsp, *yylsp);
+      yydestruct (yystos[yystate], yyvsp, yylsp);
       yyvsp--;
       yystate = *--yyssp;
       yylsp--;
