@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.75b.  */
+/* A Bison parser, made by GNU Bison 1.75c.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -172,7 +172,7 @@
 #include "reader.h"
 #include "conflicts.h"
 
-/* Produce verbose parse errors.  */
+/* Produce verbose syntax errors.  */
 #define YYERROR_VERBOSE 1
 #define YYLLOC_DEFAULT(Current, Rhs, N)			\
 do {							\
@@ -196,7 +196,7 @@ do {							\
    correctly typed access to it.  */
 #define yycontrol ((gram_control_t *) gram_control)
 
-/* Request detailed parse error messages, and pass them to GRAM_ERROR.
+/* Request detailed syntax error messages, and pass them to GRAM_ERROR.
    FIXME: depends on the undocumented availability of YYLLOC.t */
 #undef  yyerror
 #define yyerror(Msg) \
@@ -259,7 +259,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 215 of /usr/local/share/bison/yacc.c.  */
+/* Line __line__ of __file__.  */
 #line 263 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -327,7 +327,7 @@ union yyalloc
 	{					\
 	  register YYSIZE_T yyi;		\
 	  for (yyi = 0; yyi < (Count); yyi++)	\
-	    (To)[yyi] = (From)[yyi];	\
+	    (To)[yyi] = (From)[yyi];		\
 	}					\
       while (0)
 #  endif
@@ -591,7 +591,7 @@ static const yysigned_char yypgoto[] =
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, parse error.  */
+   If YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF -75
 static const yysigned_char yytable[] =
 {
@@ -696,7 +696,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror ("syntax error: cannot back up");	\
+      yyerror ("syntax error: cannot back up");\
       YYERROR;							\
     }								\
 while (0)
@@ -708,7 +708,7 @@ while (0)
    are run).  */
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)           \
+# define YYLLOC_DEFAULT(Current, Rhs, N)         \
   Current.first_line   = Rhs[1].first_line;      \
   Current.first_column = Rhs[1].first_column;    \
   Current.last_line    = Rhs[N].last_line;       \
@@ -741,12 +741,24 @@ do {						\
   if (yydebug)					\
     yysymprint Args;				\
 } while (0)
+# define YYDSYMPRINTF(Title, Token, Value, Location)		\
+do {								\
+  if (yydebug)							\
+    {								\
+      YYFPRINTF (stderr, "%s ", Title);				\
+      yysymprint (stderr, 					\
+                  Token, Value, Location);	\
+      YYFPRINTF (stderr, "\n");					\
+    }								\
+} while (0)
+
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
 #else /* !YYDEBUG */
 # define YYDPRINTF(Args)
 # define YYDSYMPRINT(Args)
+# define YYDSYMPRINTF(Title, Token, Value, Location)
 #endif /* !YYDEBUG */
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
@@ -943,7 +955,7 @@ int yychar;
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
-/* Number of parse errors so far.  */
+/* Number of syntax errors so far.  */
 int yynerrs;
 /* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;
@@ -1123,9 +1135,7 @@ yybackup:
     {
       /* We have to keep this `#if YYDEBUG', since we use variables
 	 which are defined only if `YYDEBUG' is set.  */
-      YYDPRINTF ((stderr, "Next token is "));
-      YYDSYMPRINT ((stderr, yytoken, &yylval, &yyloc));
-      YYDPRINTF ((stderr, "\n"));
+      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -1146,8 +1156,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the lookahead token.  */
-  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
-	      yytoken, yytname[yytoken]));
+  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
 
   /* Discard the token being shifted unless it is eof.  */
   if (yytoken != YYEOF)
@@ -1202,13 +1211,13 @@ yyreduce:
     {
       int yyi;
 
-      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
+      YYFPRINTF (stderr, "Reducing by rule %d (line %d), ",
 		 yyn - 1, yyrline[yyn]);
 
       /* Print the symbols being reduced, and their result.  */
       for (yyi = yyprhs[yyn]; 0 <= yyrhs[yyi]; yyi++)
 	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
-      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
+      YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyn]]);
     }
 #endif
   switch (yyn)
@@ -1623,8 +1632,8 @@ yyreduce:
 
     }
 
-/* Line 950 of /usr/local/share/bison/yacc.c.  */
-#line 1627 "parse-gram.c"
+/* Line 959 of /usr/local/share/bison/yacc.c.  */
+#line 1636 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1684,12 +1693,12 @@ yyerrlab:
 	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
-	  yysize += yystrlen ("parse error, unexpected ") + 1;
+	  yysize += yystrlen ("syntax error, unexpected ") + 1;
 	  yysize += yystrlen (yytname[yytype]);
 	  yymsg = (char *) YYSTACK_ALLOC (yysize);
 	  if (yymsg != 0)
 	    {
-	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
+	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
 	      yyp = yystpcpy (yyp, yytname[yytype]);
 
 	      if (yycount < 5)
@@ -1710,11 +1719,11 @@ yyerrlab:
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror ("parse error; also virtual memory exhausted");
+	    yyerror ("syntax error; also virtual memory exhausted");
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror ("parse error");
+	yyerror ("syntax error");
     }
   goto yyerrlab1;
 
@@ -1736,19 +1745,14 @@ yyerrlab1:
 	  /* Pop the rest of the stack.  */
 	  while (yyss < yyssp)
 	    {
-	      YYDPRINTF ((stderr, "Error: popping "));
-	      YYDSYMPRINT ((stderr,
-			    yystos[*yyssp],
-			    yyvsp, yylsp));
-	      YYDPRINTF ((stderr, "\n"));
+	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
 	      yydestruct (yystos[*yyssp], yyvsp, yylsp);
 	      YYPOPSTACK;
 	    }
 	  YYABORT;
         }
 
-      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
-		  yytoken, yytname[yytoken]));
+      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
       yydestruct (yytoken, &yylval, &yylloc);
       yytoken = YYEMPTY;
     }
@@ -1776,11 +1780,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-      YYDPRINTF ((stderr, "Error: popping "));
-      YYDSYMPRINT ((stderr,
-		    yystos[*yyssp], yyvsp, yylsp));
-      YYDPRINTF ((stderr, "\n"));
-
+      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
       yydestruct (yystos[yystate], yyvsp, yylsp);
       yyvsp--;
       yystate = *--yyssp;
