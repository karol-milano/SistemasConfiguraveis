@@ -1,7 +1,7 @@
 /* A Bison parser, made from parse-gram.y, by GNU bison 1.49b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -233,7 +233,7 @@ typedef union {
   char *string;
   assoc_t assoc;
 } yystype;
-/* Line 187 of /usr/local/share/bison/yacc.c.  */
+/* Line 188 of /tmp/prefix/share/bison/yacc.c.  */
 #line 238 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -254,7 +254,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 207 of /usr/local/share/bison/yacc.c.  */
+/* Line 208 of /tmp/prefix/share/bison/yacc.c.  */
 #line 259 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -348,7 +348,6 @@ union yyalloc
 
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
-#define YYFLAG	 -32768
 #define YYLAST   127
 
 /* YYNTOKENS -- Number of terminals. */
@@ -461,7 +460,7 @@ static const unsigned short yyrline[] =
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
-  "\"end of string\"", "error", "$undefined.", "STRING", "CHARACTER", "INT", 
+  "\"end of string\"", "error", "$undefined", "STRING", "CHARACTER", "INT", 
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"", 
   "\"%printer\"", "\"%union\"", "\"%left\"", "\"%right\"", 
   "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", "\"%dprec\"", 
@@ -471,24 +470,25 @@ static const char *const yytname[] =
   "\"%debug\"", "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", 
   "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", 
   "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", "BRACED_CODE", 
-  "$axiom", "input", "declarations", "declaration", "grammar_declaration", 
-  "@1", "@2", "symbol_declaration", "@3", "@4", "precedence_declaration", 
-  "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
-  "@5", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
-  "string_content", "epilogue.opt", "semi_colon.opt", 0
+  "$accept", "input", "declarations", "declaration", 
+  "grammar_declaration", "@1", "@2", "symbol_declaration", "@3", "@4", 
+  "precedence_declaration", "precedence_declarator", "type.opt", 
+  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
+  "rules_or_grammar_declaration", "rules", "@5", "rhses.1", "rhs", 
+  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 
+  "semi_colon.opt", 0
 };
 #endif
 
 /* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
-static const short yytoknum[] =
+static const unsigned short yytoknum[] =
 {
        0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,    -1
+     295,   296,   297,   298,   299
 };
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -520,9 +520,9 @@ static const unsigned char yyr2[] =
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
    STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
    means the default is an error.  */
-static const short yydefact[] =
+static const unsigned char yydefact[] =
 {
-       3,     0,     0,     0,    33,    31,     0,    27,    29,     0,
+       3,     0,     0,     1,    33,    31,     0,    27,    29,     0,
       37,    38,    39,     0,     0,    21,    10,     0,     0,     0,
        0,    17,    18,     9,    22,     7,    13,    15,     0,    20,
        0,     6,    74,     5,    24,    23,    40,     0,     0,     0,
@@ -535,8 +535,8 @@ static const short yydefact[] =
        0,    69,    61,    62,    59,    63,    64,    65
 };
 
-/* YYPGOTO[NTERM-NUM]. */
-static const short yydefgoto[] =
+/* YYDEFGOTO[NTERM-NUM]. */
+static const signed char yydefgoto[] =
 {
       -1,     1,     2,    32,    57,    40,    41,    34,    38,    37,
       35,    36,    64,    70,    67,    68,    58,    59,    60,    91,
@@ -545,33 +545,35 @@ static const short yydefgoto[] =
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-static const short yypact[] =
+#define YYPACT_NINF -61
+static const signed char yypact[] =
 {
-  -32768,    35,    85,-32768,-32768,-32768,     2,-32768,-32768,    -5,
-  -32768,-32768,-32768,    31,     0,-32768,-32768,    18,    21,    22,
-      59,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    59,-32768,
-      37,-32768,    26,-32768,-32768,-32768,    29,   -19,   -19,     0,
-      23,    24,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    59,
-      59,    59,-32768,    59,-32768,    28,    33,    32,     1,-32768,
-  -32768,-32768,-32768,-32768,     0,-32768,    17,-32768,   -19,   -19,
-       0,-32768,     0,     0,-32768,-32768,-32768,-32768,-32768,-32768,
-  -32768,    30,-32768,-32768,     0,    63,-32768,-32768,-32768,     0,
-       0,-32768,-32768,-32768,    -8,    15,-32768,-32768,     0,    67,
-      39,-32768,-32768,-32768,    15,-32768,-32768,-32768
+     -61,    35,    85,   -61,   -61,   -61,     2,   -61,   -61,    -5,
+     -61,   -61,   -61,    31,     0,   -61,   -61,    18,    21,    22,
+      59,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    59,   -61,
+      37,   -61,    26,   -61,   -61,   -61,    29,   -19,   -19,     0,
+      23,    24,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    59,
+      59,    59,   -61,    59,   -61,    28,    33,    32,     1,   -61,
+     -61,   -61,   -61,   -61,     0,   -61,    17,   -61,   -19,   -19,
+       0,   -61,     0,     0,   -61,   -61,   -61,   -61,   -61,   -61,
+     -61,    30,   -61,   -61,     0,    63,   -61,   -61,   -61,     0,
+       0,   -61,   -61,   -61,    -8,    15,   -61,   -61,     0,    67,
+      39,   -61,   -61,   -61,    15,   -61,   -61,   -61
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const short yypgoto[] =
+static const signed char yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,    76,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,   -12,   -45,    41,-32768,    25,-32768,-32768,
-  -32768,   -17,   -14,-32768,   -60,   -23,-32768,-32768
+     -61,   -61,   -61,   -61,    76,   -61,   -61,   -61,   -61,   -61,
+     -61,   -61,   -61,   -12,   -45,    41,   -61,    25,   -61,   -61,
+     -61,   -17,   -14,   -61,   -60,   -23,   -61,   -61
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.  */
-static const short yytable[] =
+#define YYTABLE_NINF -62
+static const signed char yytable[] =
 {
       47,   -72,    55,    44,    45,    54,    86,     4,     5,     6,
        7,     8,     9,    10,    11,    12,    65,    14,    44,    45,
@@ -588,7 +590,7 @@ static const short yytable[] =
        0,     0,     0,     0,     0,     0,    30,    31
 };
 
-static const short yycheck[] =
+static const signed char yycheck[] =
 {
       14,     0,     1,     3,     4,    28,    66,     6,     7,     8,
        9,    10,    11,    12,    13,    14,    35,    16,     3,     4,
@@ -797,6 +799,145 @@ yystpcpy (yydest, yysrc)
 
 
 
+#if YYDEBUG
+/*-----------------------------.
+| Print this symbol on YYOUT.  |
+`-----------------------------*/
+
+static void
+#if defined (__STDC__) || defined (__cplusplus)
+yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue, YYLTYPE yylocation)
+#else
+yysymprint (yyout, yytype, yyvalue, yylocation)
+    FILE* yyout;
+    int yytype;
+    YYSTYPE yyvalue;
+    YYLTYPE yylocation;
+#endif
+{
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+  (void) yylocation;
+
+  if (yytype < YYNTOKENS)
+    {
+      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
+# ifdef YYPRINT
+      YYPRINT (yyout, yytoknum[yytype], yyvalue);
+# endif
+    }
+  else
+    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);
+
+  switch (yytype)
+    {
+      default:
+        break;
+    }
+  YYFPRINTF (yyout, ")");
+}
+#endif /* YYDEBUG. */
+
+
+/*----------------------------------------------------------.
+| yyreport_parse_error -- report a parse error in YYSTATE.  |
+`----------------------------------------------------------*/
+
+static void
+#if defined (__STDC__) || defined (__cplusplus)
+yyreport_parse_error (int yystate, int yychar, YYSTYPE yyvalue, YYLTYPE yylloc)
+#else
+yyreport_parse_error (yystate, yychar, yyvalue, yylloc)
+    int yystate;
+    int yychar;
+    YYSTYPE yyvalue;
+    YYLTYPE yylloc;
+#endif
+{
+#if YYERROR_VERBOSE
+  int yyn = yypact[yystate];
+
+  if (YYPACT_NINF < yyn && yyn < YYLAST)
+    {
+      YYSIZE_T yysize = 0;
+      int yytype = YYTRANSLATE (yychar);
+      char *yymsg;
+      int yyx, yycount;
+
+      yycount = 0;
+      /* Start YYX at -YYN if negative to avoid negative indexes in
+	 YYCHECK.  */
+      for (yyx = yyn < 0 ? -yyn : 0;
+	   yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	  yysize += yystrlen (yytname[yyx]) + 15, yycount++;
+      yysize += yystrlen ("parse error, unexpected ") + 1;
+      yysize += yystrlen (yytname[yytype]);
+      yymsg = (char *) YYSTACK_ALLOC (yysize);
+      if (yymsg != 0)
+	{
+	  char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
+	  yyp = yystpcpy (yyp, yytname[yytype]);
+
+	  if (yycount < 5)
+	    {
+	      yycount = 0;
+	      for (yyx = yyn < 0 ? -yyn : 0;
+		   yyx < (int) (sizeof (yytname) / sizeof (char *));
+		   yyx++)
+		if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+		  {
+		    const char *yyq = ! yycount ? ", expecting " : " or ";
+		    yyp = yystpcpy (yyp, yyq);
+		    yyp = yystpcpy (yyp, yytname[yyx]);
+		    yycount++;
+		  }
+	    }
+	  yyerror (yymsg);
+	  YYSTACK_FREE (yymsg);
+	}
+      else
+	yyerror ("parse error; also virtual memory exhausted");
+    }
+  else
+#endif /* YYERROR_VERBOSE */
+    yyerror ("parse error");
+
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yystate;
+  (void) yychar;
+  (void) yyvalue;
+  (void) yylloc;
+}
+
+
+/*-----------------------------------------------.
+| Release the memory associated to this symbol.  |
+`-----------------------------------------------*/
+
+static void
+#if defined (__STDC__) || defined (__cplusplus)
+yydestruct (int yytype, YYSTYPE yyvalue, YYLTYPE yylocation)
+#else
+yydestruct (yytype, yyvalue, yylocation)
+    int yytype;
+    YYSTYPE yyvalue;
+    YYLTYPE yylocation;
+#endif
+{
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+  (void) yylocation;
+
+  switch (yytype)
+    {
+      default:
+        break;
+    }
+}
+
+
+
 /* The user can define YYPARSE_PARAM as the name of an argument to be passed
    into yyparse.  The argument should have type void *.
    It should actually point to an object.
@@ -825,15 +966,6 @@ int yyparse (void);
 # endif
 #endif
 
-#if defined (__STDC__) || defined (__cplusplus)
-static void yydestruct (int yytype,
-			YYSTYPE yyvalue, YYLTYPE yylocation);
-# if YYDEBUG
-static void yysymprint (FILE* out, int yytype,
-			YYSTYPE yyvalue, YYLTYPE yylocation);
-# endif
-#endif
-
 
 
 
@@ -1006,7 +1138,7 @@ yybackup:
   /* First try to decide what to do without reference to lookahead token.  */
 
   yyn = yypact[yystate];
-  if (yyn == YYFLAG)
+  if (yyn == YYPACT_NINF)
     goto yydefault;
 
   /* Not known => get a lookahead token if don't already have one.  */
@@ -1041,7 +1173,7 @@ yybackup:
     }
 
   yyn += yychar1;
-  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
+  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
     goto yydefault;
 
   yyn = yytable[yyn];
@@ -1055,7 +1187,7 @@ yybackup:
 
   if (yyn < 0)
     {
-      if (yyn == YYFLAG)
+      if (yyn == YYTABLE_NINF)
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
@@ -1106,8 +1238,8 @@ yyreduce:
   /* If YYLEN is nonzero, implement the default value of the action:
      `$$ = $1'.
 
-     Otherwise, the following line sets YYVAL to the semantic value of
-     the lookahead token.  This behavior is undocumented and Bison
+     Otherwise, the following line sets YYVAL to garbage.
+     This behavior is undocumented and Bison
      users should not rely upon it.  Assigning to YYVAL
      unconditionally makes the parser a bit smaller, and it avoids a
      GCC warning that YYVAL may be used uninitialized.  */
@@ -1532,8 +1664,8 @@ yyreduce:
 
     }
 
-/* Line 955 of /usr/local/share/bison/yacc.c.  */
-#line 1537 "parse-gram.c"
+/* Line 1079 of /tmp/prefix/share/bison/yacc.c.  */
+#line 1669 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1560,7 +1692,7 @@ yyreduce:
   yyn = yyr1[yyn];
 
   yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
-  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
+  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
     yystate = yytable[yystate];
   else
     yystate = yydefgoto[yyn - YYNTOKENS];
@@ -1576,54 +1708,7 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-
-#if YYERROR_VERBOSE
-      yyn = yypact[yystate];
-
-      if (yyn > YYFLAG && yyn < YYLAST)
-	{
-	  YYSIZE_T yysize = 0;
-	  char *yymsg;
-	  int yyx, yycount;
-
-	  yycount = 0;
-	  /* Start YYX at -YYN if negative to avoid negative indexes in
-	     YYCHECK.  */
-	  for (yyx = yyn < 0 ? -yyn : 0;
-	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
-	    if (yycheck[yyx + yyn] == yyx)
-	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
-	  yysize += yystrlen ("parse error, unexpected ") + 1;
-	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
-	  yymsg = (char *) YYSTACK_ALLOC (yysize);
-	  if (yymsg != 0)
-	    {
-	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
-	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);
-
-	      if (yycount < 5)
-		{
-		  yycount = 0;
-		  for (yyx = yyn < 0 ? -yyn : 0;
-		       yyx < (int) (sizeof (yytname) / sizeof (char *));
-		       yyx++)
-		    if (yycheck[yyx + yyn] == yyx)
-		      {
-			const char *yyq = ! yycount ? ", expecting " : " or ";
-			yyp = yystpcpy (yyp, yyq);
-			yyp = yystpcpy (yyp, yytname[yyx]);
-			yycount++;
-		      }
-		}
-	      yyerror (yymsg);
-	      YYSTACK_FREE (yymsg);
-  	    }
-  	  else
-  	    yyerror ("parse error; also virtual memory exhausted");
-        }
-      else
-#endif /* YYERROR_VERBOSE */
-        yyerror ("parse error");
+      yyreport_parse_error (yystate, yychar, yylval, yylloc);
     }
   goto yyerrlab1;
 
@@ -1670,7 +1755,7 @@ yyerrlab1:
   for (;;)
     {
       yyn = yypact[yystate];
-      if (yyn != YYFLAG)
+      if (yyn != YYPACT_NINF)
 	{
 	  yyn += YYTERROR;
 	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
@@ -1752,58 +1837,6 @@ yyreturn:
 }
 
 
-/*-----------------------------------------------.
-| Release the memory associated to this symbol.  |
-`-----------------------------------------------*/
-
-static void
-yydestruct (int yytype,
-	    YYSTYPE yyvalue, YYLTYPE yylocation)
-{
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yyvalue;
-  (void) yylocation;
-
-  switch (yytype)
-    {
-      default:
-        break;
-    }
-}
-
-
-#if YYDEBUG
-/*-----------------------------.
-| Print this symbol on YYOUT.  |
-`-----------------------------*/
-
-static void
-yysymprint (FILE* yyout, int yytype,
-	    YYSTYPE yyvalue, YYLTYPE yylocation)
-{
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yyvalue;
-  (void) yylocation;
-
-  if (yytype < YYNTOKENS)
-    {
-      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
-# ifdef YYPRINT
-      YYPRINT (yyout, yytoknum[yytype], yyvalue);
-# endif
-    }
-  else
-    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);
-
-  switch (yytype)
-    {
-      default:
-        break;
-    }
-  YYFPRINTF (yyout, ")");
-}
-#endif /* YYDEBUG. */
-
 #line 421 "parse-gram.y"
 
 /*------------------------------------------------------------------.
@@ -1851,27 +1884,3 @@ gram_error (location_t *yylloc, const char *msg)
   complain_at (*yylloc, "%s", msg);
 }
 
-/* A Bison parser, made from parse-gram.y, by GNU bison 1.49b.  */
-
-/* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
-
-   This program is free software; you can redistribute it and/or modify
-   it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2, or (at your option)
-   any later version.
-
-   This program is distributed in the hope that it will be useful,
-   but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
-
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330,
-   Boston, MA 02111-1307, USA.  */
-
-/* As a special exception, when this file is copied by Bison into a
-   Bison output file, you may use that output file without restriction.
-   This special exception was added by the Free Software Foundation
-   in version 1.24 of Bison.  */
