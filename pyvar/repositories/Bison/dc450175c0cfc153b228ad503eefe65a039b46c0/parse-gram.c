@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.194-c20a1-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.266-78f6.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.194-c20a1-dirty"
+#define YYBISON_VERSION "2.4.266-78f6"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -73,12 +73,11 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-
 /* Line 191 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
+   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free Software
    Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -148,9 +147,8 @@ static int current_prec = 0;
 #define YYTYPE_UINT16 uint_fast16_t
 #define YYTYPE_UINT8 uint_fast8_t
 
-
 /* Line 191 of yacc.c  */
-#line 154 "../../src/parse-gram.c"
+#line 152 "../../src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -299,7 +297,6 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-
 /* Line 216 of yacc.c  */
 #line 92 "parse-gram.y"
 
@@ -313,9 +310,8 @@ typedef union YYSTYPE
   unsigned char character;
 
 
-
 /* Line 216 of yacc.c  */
-#line 319 "../../src/parse-gram.c"
+#line 315 "../../src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -338,9 +334,8 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-
 /* Line 266 of yacc.c  */
-#line 344 "../../src/parse-gram.c"
+#line 339 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -615,20 +610,20 @@ static const yytype_uint8 yytranslate[] =
 };
 
 #if YYDEBUG
-/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
+  /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
        0,   203,   203,   211,   213,   217,   218,   228,   229,   233,
-     234,   239,   240,   241,   242,   243,   244,   249,   258,   259,
-     260,   261,   262,   263,   264,   265,   266,   267,   268,   281,
-     282,   306,   307,   308,   309,   313,   314,   315,   319,   326,
-     333,   337,   341,   348,   363,   364,   368,   380,   380,   385,
-     385,   390,   401,   416,   417,   418,   419,   423,   424,   429,
-     431,   436,   437,   442,   444,   449,   450,   454,   455,   456,
-     457,   462,   467,   472,   478,   484,   495,   496,   505,   506,
-     512,   513,   514,   521,   521,   525,   526,   527,   532,   533,
-     535,   537,   539,   541,   551,   552,   558,   561,   570,   590,
-     592,   601,   606,   607,   612,   619,   621
+     234,   239,   243,   244,   245,   246,   247,   252,   261,   262,
+     263,   264,   265,   266,   267,   268,   269,   270,   271,   284,
+     285,   309,   310,   311,   312,   316,   317,   318,   322,   329,
+     336,   340,   344,   351,   366,   367,   371,   383,   383,   388,
+     388,   393,   404,   419,   420,   421,   422,   426,   427,   432,
+     434,   439,   440,   445,   447,   452,   453,   457,   458,   459,
+     460,   465,   470,   475,   481,   487,   498,   499,   508,   509,
+     515,   516,   517,   524,   524,   528,   529,   530,   535,   536,
+     538,   540,   542,   544,   554,   555,   561,   564,   573,   593,
+     595,   604,   609,   610,   615,   622,   624
 };
 #endif
 
@@ -994,150 +989,150 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 # endif
   switch (yytype)
     {
-      case 3: /* "\"string\"" */
+            case 3: // "string"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 181 "parse-gram.y"
-	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
+        { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
+/* Line 647 of yacc.c  */
+#line 999 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1005 "../../src/parse-gram.c"
-	break;
-      case 4: /* "\"integer\"" */
+            case 4: // "integer"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 192 "parse-gram.y"
-	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
+        { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
+/* Line 647 of yacc.c  */
+#line 1008 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1014 "../../src/parse-gram.c"
-	break;
-      case 44: /* "\"{...}\"" */
+            case 44: // "{...}"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 183 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
+/* Line 647 of yacc.c  */
+#line 1017 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1023 "../../src/parse-gram.c"
-	break;
-      case 45: /* "\"char\"" */
+            case 45: // "char"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 175 "parse-gram.y"
-	{ fputs (char_name (((*yyvaluep).character)), stderr); };
+        { fputs (char_name (((*yyvaluep).character)), stderr); }
+/* Line 647 of yacc.c  */
+#line 1026 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1032 "../../src/parse-gram.c"
-	break;
-      case 46: /* "\"epilogue\"" */
+            case 46: // "epilogue"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 183 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+/* Line 647 of yacc.c  */
+#line 1035 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1041 "../../src/parse-gram.c"
-	break;
-      case 48: /* "\"identifier\"" */
+            case 48: // "identifier"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 188 "parse-gram.y"
-	{ fputs (((*yyvaluep).uniqstr), stderr); };
+        { fputs (((*yyvaluep).uniqstr), stderr); }
+/* Line 647 of yacc.c  */
+#line 1044 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1050 "../../src/parse-gram.c"
-	break;
-      case 49: /* "\"identifier:\"" */
+            case 49: // "identifier:"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 189 "parse-gram.y"
-	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
+        { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
+/* Line 647 of yacc.c  */
+#line 1053 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1059 "../../src/parse-gram.c"
-	break;
-      case 52: /* "\"%{...%}\"" */
+            case 52: // "%{...%}"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 183 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+/* Line 647 of yacc.c  */
+#line 1062 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1068 "../../src/parse-gram.c"
-	break;
-      case 54: /* "\"<tag>\"" */
+            case 54: // "<tag>"
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 187 "parse-gram.y"
-	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
+        { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
+/* Line 647 of yacc.c  */
+#line 1071 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1077 "../../src/parse-gram.c"
-	break;
-      case 83: /* "variable" */
+            case 83: // variable
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 188 "parse-gram.y"
-	{ fputs (((*yyvaluep).uniqstr), stderr); };
+        { fputs (((*yyvaluep).uniqstr), stderr); }
+/* Line 647 of yacc.c  */
+#line 1080 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1086 "../../src/parse-gram.c"
-	break;
-      case 84: /* "content.opt" */
+            case 84: // content.opt
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 183 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+/* Line 647 of yacc.c  */
+#line 1089 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1095 "../../src/parse-gram.c"
-	break;
-      case 85: /* "braceless" */
+            case 85: // braceless
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 183 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+/* Line 647 of yacc.c  */
+#line 1098 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1104 "../../src/parse-gram.c"
-	break;
-      case 86: /* "id" */
+            case 86: // id
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 195 "parse-gram.y"
-	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+/* Line 647 of yacc.c  */
+#line 1107 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1113 "../../src/parse-gram.c"
-	break;
-      case 87: /* "id_colon" */
+            case 87: // id_colon
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 196 "parse-gram.y"
-	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
+        { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
+/* Line 647 of yacc.c  */
+#line 1116 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1122 "../../src/parse-gram.c"
-	break;
-      case 88: /* "symbol" */
+            case 88: // symbol
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 195 "parse-gram.y"
-	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+/* Line 647 of yacc.c  */
+#line 1125 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1131 "../../src/parse-gram.c"
-	break;
-      case 89: /* "string_as_id" */
+            case 89: // string_as_id
 
-/* Line 650 of yacc.c  */
+/* Line 647 of yacc.c  */
 #line 195 "parse-gram.y"
-	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+/* Line 647 of yacc.c  */
+#line 1134 "../../src/parse-gram.c"
+        break;
 
-/* Line 650 of yacc.c  */
-#line 1140 "../../src/parse-gram.c"
-	break;
       default:
 	break;
     }
@@ -1375,14 +1370,14 @@ yytnamerr (char *yyres, const char *yystr)
 # endif
 
 /* Copy into YYRESULT an error message about the unexpected token
-   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
+   YYTOKEN while in state YYSTATE.  Return the number of bytes copied,
    including the terminating null byte.  If YYRESULT is null, do not
    copy anything; just return the number of bytes that would be
    copied.  As a special case, return 0 if an ordinary "syntax error"
    message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
    size calculation.  */
 static YYSIZE_T
-yysyntax_error (char *yyresult, int yystate, int yychar)
+yysyntax_error (char *yyresult, int yystate, int yytoken)
 {
   int yyn = yypact[yystate];
 
@@ -1390,34 +1385,15 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
     return 0;
   else
     {
-      int yytype = YYTRANSLATE (yychar);
-      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
+      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
       YYSIZE_T yysize = yysize0;
       YYSIZE_T yysize1;
       int yysize_overflow = 0;
       enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+      /* Internationalized format string. */
+      const char *yyformat = 0;
+      /* Arguments of yyformat. */
       char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-      int yyx;
-
-# if 0
-      /* This is so xgettext sees the translatable formats that are
-	 constructed on the fly.  */
-      YY_("syntax error, unexpected %s");
-      YY_("syntax error, unexpected %s, expecting %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
-# endif
-      char *yyfmt;
-      char const *yyf;
-      static char const yyunexpected[] = "syntax error, unexpected %s";
-      static char const yyexpecting[] = ", expecting %s";
-      static char const yyor[] = " or %s";
-      char yyformat[sizeof yyunexpected
-		    + sizeof yyexpecting - 1
-		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
-		       * (sizeof yyor - 1))];
-      char const *yyprefix = yyexpecting;
 
       /* Start YYX at -YYN if negative to avoid negative indexes in
 	 YYCHECK.  */
@@ -1426,10 +1402,12 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       /* Stay within bounds of both yycheck and yytname.  */
       int yychecklim = YYLAST - yyn + 1;
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-      int yycount = 1;
+      /* Number of reported tokens (one for the "unexpected", one per
+         "expected"). */
+      int yycount = 0;
+      int yyx;
 
-      yyarg[0] = yytname[yytype];
-      yyfmt = yystpcpy (yyformat, yyunexpected);
+      yyarg[yycount++] = yytname[yytoken];
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
@@ -1438,19 +1416,29 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 	      {
 		yycount = 1;
 		yysize = yysize0;
-		yyformat[sizeof yyunexpected - 1] = '\0';
 		break;
 	      }
 	    yyarg[yycount++] = yytname[yyx];
 	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
 	    yysize_overflow |= (yysize1 < yysize);
 	    yysize = yysize1;
-	    yyfmt = yystpcpy (yyfmt, yyprefix);
-	    yyprefix = yyor;
 	  }
 
-      yyf = YY_(yyformat);
-      yysize1 = yysize + yystrlen (yyf);
+        switch (yycount)
+        {
+#define YYCASE_(N, S)                           \
+          case N:                               \
+            yyformat = S;                       \
+          break
+          YYCASE_(1, YY_("syntax error, unexpected %s"));
+          YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+          YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+          YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+          YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+#undef YYCASE_
+        }
+
+      yysize1 = yysize + yystrlen (yyformat);
       yysize_overflow |= (yysize1 < yysize);
       yysize = yysize1;
 
@@ -1464,19 +1452,17 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 	     produced a string with the wrong number of "%s"s.  */
 	  char *yyp = yyresult;
 	  int yyi = 0;
-	  while ((*yyp = *yyf) != '\0')
-	    {
-	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
-		{
-		  yyp += yytnamerr (yyp, yyarg[yyi++]);
-		  yyf += 2;
-		}
-	      else
-		{
-		  yyp++;
-		  yyf++;
-		}
-	    }
+	  while ((*yyp = *yyformat) != '\0')
+            if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
+              {
+                yyp += yytnamerr (yyp, yyarg[yyi++]);
+                yyformat += 2;
+              }
+            else
+              {
+                yyp++;
+                yyformat++;
+              }
 	}
       return yysize;
     }
@@ -1511,7 +1497,6 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 
   switch (yytype)
     {
-
       default:
 	break;
     }
@@ -1519,13 +1504,15 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 
 /* Prevent warnings from -Wmissing-prototypes.  */
 #ifdef YYPARSE_PARAM
-#if defined __STDC__ || defined __cplusplus
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 int yyparse (void *YYPARSE_PARAM);
 #else
 int yyparse ();
 #endif
 #else /* ! YYPARSE_PARAM */
-#if defined __STDC__ || defined __cplusplus
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 int yyparse (void);
 #else
 int yyparse ();
@@ -1656,8 +1643,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-
-/* Line 1179 of yacc.c  */
+/* Line 1167 of yacc.c  */
 #line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1665,9 +1651,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-
-/* Line 1179 of yacc.c  */
-#line 1671 "../../src/parse-gram.c"
+/* Line 1167 of yacc.c  */
+#line 1656 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1853,8 +1838,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-
-/* Line 1392 of yacc.c  */
+/* Line 1380 of yacc.c  */
 #line 219 "parse-gram.y"
     {
       code_props plain_code;
@@ -1865,123 +1849,103 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-
-/* Line 1392 of yacc.c  */
-#line 1871 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1854 "../../src/parse-gram.c"
     break;
 
   case 7:
-
-/* Line 1392 of yacc.c  */
+/* Line 1380 of yacc.c  */
 #line 228 "parse-gram.y"
     { debug_flag = true; }
-
-/* Line 1392 of yacc.c  */
-#line 1881 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1862 "../../src/parse-gram.c"
     break;
 
   case 8:
-
-/* Line 1392 of yacc.c  */
+/* Line 1380 of yacc.c  */
 #line 230 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
     }
-
-/* Line 1392 of yacc.c  */
-#line 1893 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1872 "../../src/parse-gram.c"
     break;
 
   case 9:
-
-/* Line 1392 of yacc.c  */
+/* Line 1380 of yacc.c  */
 #line 233 "parse-gram.y"
     { defines_flag = true; }
-
-/* Line 1392 of yacc.c  */
-#line 1903 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1880 "../../src/parse-gram.c"
     break;
 
   case 10:
-
-/* Line 1392 of yacc.c  */
+/* Line 1380 of yacc.c  */
 #line 235 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-
-/* Line 1392 of yacc.c  */
-#line 1916 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1891 "../../src/parse-gram.c"
     break;
 
   case 11:
-
-/* Line 1392 of yacc.c  */
-#line 239 "parse-gram.y"
-    { error_verbose = true; }
-
-/* Line 1392 of yacc.c  */
-#line 1926 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 240 "parse-gram.y"
+    {
+      muscle_percent_define_insert ("error_verbose", (yyloc), "");
+    }
+/* Line 1380 of yacc.c  */
+#line 1901 "../../src/parse-gram.c"
     break;
 
   case 12:
-
-/* Line 1392 of yacc.c  */
-#line 240 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 243 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-
-/* Line 1392 of yacc.c  */
-#line 1936 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1909 "../../src/parse-gram.c"
     break;
 
   case 13:
-
-/* Line 1392 of yacc.c  */
-#line 241 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 244 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-
-/* Line 1392 of yacc.c  */
-#line 1946 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1917 "../../src/parse-gram.c"
     break;
 
   case 14:
-
-/* Line 1392 of yacc.c  */
-#line 242 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 245 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-
-/* Line 1392 of yacc.c  */
-#line 1956 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1925 "../../src/parse-gram.c"
     break;
 
   case 15:
-
-/* Line 1392 of yacc.c  */
-#line 243 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 246 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-
-/* Line 1392 of yacc.c  */
-#line 1966 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1933 "../../src/parse-gram.c"
     break;
 
   case 16:
-
-/* Line 1392 of yacc.c  */
-#line 245 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 248 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-
-/* Line 1392 of yacc.c  */
-#line 1979 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1944 "../../src/parse-gram.c"
     break;
 
   case 17:
-
-/* Line 1392 of yacc.c  */
-#line 250 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 253 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1990,115 +1954,93 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-
-/* Line 1392 of yacc.c  */
-#line 1996 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1959 "../../src/parse-gram.c"
     break;
 
   case 18:
-
-/* Line 1392 of yacc.c  */
-#line 258 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 261 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-
-/* Line 1392 of yacc.c  */
-#line 2006 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1967 "../../src/parse-gram.c"
     break;
 
   case 19:
-
-/* Line 1392 of yacc.c  */
-#line 259 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 262 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2016 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1975 "../../src/parse-gram.c"
     break;
 
   case 20:
-
-/* Line 1392 of yacc.c  */
-#line 260 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 263 "parse-gram.y"
     { locations_flag = true; }
-
-/* Line 1392 of yacc.c  */
-#line 2026 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1983 "../../src/parse-gram.c"
     break;
 
   case 21:
-
-/* Line 1392 of yacc.c  */
-#line 261 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 264 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-
-/* Line 1392 of yacc.c  */
-#line 2036 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1991 "../../src/parse-gram.c"
     break;
 
   case 22:
-
-/* Line 1392 of yacc.c  */
-#line 262 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 265 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-
-/* Line 1392 of yacc.c  */
-#line 2046 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 1999 "../../src/parse-gram.c"
     break;
 
   case 23:
-
-/* Line 1392 of yacc.c  */
-#line 263 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 266 "parse-gram.y"
     { no_lines_flag = true; }
-
-/* Line 1392 of yacc.c  */
-#line 2056 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2007 "../../src/parse-gram.c"
     break;
 
   case 24:
-
-/* Line 1392 of yacc.c  */
-#line 264 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 267 "parse-gram.y"
     { nondeterministic_parser = true; }
-
-/* Line 1392 of yacc.c  */
-#line 2066 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2015 "../../src/parse-gram.c"
     break;
 
   case 25:
-
-/* Line 1392 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 268 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-
-/* Line 1392 of yacc.c  */
-#line 2076 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2023 "../../src/parse-gram.c"
     break;
 
   case 26:
-
-/* Line 1392 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 269 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-
-/* Line 1392 of yacc.c  */
-#line 2086 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2031 "../../src/parse-gram.c"
     break;
 
   case 27:
-
-/* Line 1392 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 270 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2096 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2039 "../../src/parse-gram.c"
     break;
 
   case 28:
-
-/* Line 1392 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 272 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2111,25 +2053,21 @@ yyreduce:
       if (!muscle_percent_define_flag_if ("api.pure"))
         muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
     }
-
-/* Line 1392 of yacc.c  */
-#line 2117 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2058 "../../src/parse-gram.c"
     break;
 
   case 29:
-
-/* Line 1392 of yacc.c  */
-#line 281 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 284 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-
-/* Line 1392 of yacc.c  */
-#line 2127 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2066 "../../src/parse-gram.c"
     break;
 
   case 30:
-
-/* Line 1392 of yacc.c  */
-#line 283 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 286 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2153,219 +2091,183 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2159 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2096 "../../src/parse-gram.c"
     break;
 
   case 31:
-
-/* Line 1392 of yacc.c  */
-#line 306 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 309 "parse-gram.y"
     { token_table_flag = true; }
-
-/* Line 1392 of yacc.c  */
-#line 2169 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2104 "../../src/parse-gram.c"
     break;
 
   case 32:
-
-/* Line 1392 of yacc.c  */
-#line 307 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 310 "parse-gram.y"
     { report_flag |= report_states; }
-
-/* Line 1392 of yacc.c  */
-#line 2179 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2112 "../../src/parse-gram.c"
     break;
 
   case 33:
-
-/* Line 1392 of yacc.c  */
-#line 308 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 311 "parse-gram.y"
     { yacc_flag = true; }
-
-/* Line 1392 of yacc.c  */
-#line 2189 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2120 "../../src/parse-gram.c"
     break;
 
   case 37:
-
-/* Line 1392 of yacc.c  */
-#line 316 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 319 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2201 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2130 "../../src/parse-gram.c"
     break;
 
   case 38:
-
-/* Line 1392 of yacc.c  */
-#line 320 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 323 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2216 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2143 "../../src/parse-gram.c"
     break;
 
   case 39:
-
-/* Line 1392 of yacc.c  */
-#line 327 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 330 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2231 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2156 "../../src/parse-gram.c"
     break;
 
   case 40:
-
-/* Line 1392 of yacc.c  */
-#line 334 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 337 "parse-gram.y"
     {
       default_prec = true;
     }
-
-/* Line 1392 of yacc.c  */
-#line 2243 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2166 "../../src/parse-gram.c"
     break;
 
   case 41:
-
-/* Line 1392 of yacc.c  */
-#line 338 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 341 "parse-gram.y"
     {
       default_prec = false;
     }
-
-/* Line 1392 of yacc.c  */
-#line 2255 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2176 "../../src/parse-gram.c"
     break;
 
   case 42:
-
-/* Line 1392 of yacc.c  */
-#line 342 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 345 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-
-/* Line 1392 of yacc.c  */
-#line 2270 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2189 "../../src/parse-gram.c"
     break;
 
   case 43:
-
-/* Line 1392 of yacc.c  */
-#line 349 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 352 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-
-/* Line 1392 of yacc.c  */
-#line 2283 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2200 "../../src/parse-gram.c"
     break;
 
   case 44:
-
-/* Line 1392 of yacc.c  */
-#line 363 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 366 "parse-gram.y"
     {}
-
-/* Line 1392 of yacc.c  */
-#line 2293 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2208 "../../src/parse-gram.c"
     break;
 
   case 45:
-
-/* Line 1392 of yacc.c  */
-#line 364 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 367 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2303 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2216 "../../src/parse-gram.c"
     break;
 
   case 46:
-
-/* Line 1392 of yacc.c  */
-#line 369 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 372 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-
-/* Line 1392 of yacc.c  */
-#line 2317 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2228 "../../src/parse-gram.c"
     break;
 
   case 47:
-
-/* Line 1392 of yacc.c  */
-#line 380 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 383 "parse-gram.y"
     { current_class = nterm_sym; }
-
-/* Line 1392 of yacc.c  */
-#line 2327 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2236 "../../src/parse-gram.c"
     break;
 
   case 48:
-
-/* Line 1392 of yacc.c  */
-#line 381 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 384 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-
-/* Line 1392 of yacc.c  */
-#line 2340 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2247 "../../src/parse-gram.c"
     break;
 
   case 49:
-
-/* Line 1392 of yacc.c  */
-#line 385 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 388 "parse-gram.y"
     { current_class = token_sym; }
-
-/* Line 1392 of yacc.c  */
-#line 2350 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2255 "../../src/parse-gram.c"
     break;
 
   case 50:
-
-/* Line 1392 of yacc.c  */
-#line 386 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 389 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-
-/* Line 1392 of yacc.c  */
-#line 2363 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2266 "../../src/parse-gram.c"
     break;
 
   case 51:
-
-/* Line 1392 of yacc.c  */
-#line 391 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 394 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2373,15 +2275,13 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2379 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2280 "../../src/parse-gram.c"
     break;
 
   case 52:
-
-/* Line 1392 of yacc.c  */
-#line 402 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 405 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2393,388 +2293,316 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-
-/* Line 1392 of yacc.c  */
-#line 2399 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2298 "../../src/parse-gram.c"
     break;
 
   case 53:
-
-/* Line 1392 of yacc.c  */
-#line 416 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 419 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-
-/* Line 1392 of yacc.c  */
-#line 2409 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2306 "../../src/parse-gram.c"
     break;
 
   case 54:
-
-/* Line 1392 of yacc.c  */
-#line 417 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 420 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-
-/* Line 1392 of yacc.c  */
-#line 2419 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2314 "../../src/parse-gram.c"
     break;
 
   case 55:
-
-/* Line 1392 of yacc.c  */
-#line 418 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 421 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-
-/* Line 1392 of yacc.c  */
-#line 2429 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2322 "../../src/parse-gram.c"
     break;
 
   case 56:
-
-/* Line 1392 of yacc.c  */
-#line 419 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 422 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-
-/* Line 1392 of yacc.c  */
-#line 2439 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2330 "../../src/parse-gram.c"
     break;
 
   case 57:
-
-/* Line 1392 of yacc.c  */
-#line 423 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 426 "parse-gram.y"
     { current_type = NULL; }
-
-/* Line 1392 of yacc.c  */
-#line 2449 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2338 "../../src/parse-gram.c"
     break;
 
   case 58:
-
-/* Line 1392 of yacc.c  */
-#line 424 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 427 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-
-/* Line 1392 of yacc.c  */
-#line 2459 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2346 "../../src/parse-gram.c"
     break;
 
   case 59:
-
-/* Line 1392 of yacc.c  */
-#line 430 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2469 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2354 "../../src/parse-gram.c"
     break;
 
   case 60:
-
-/* Line 1392 of yacc.c  */
-#line 432 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-
-/* Line 1392 of yacc.c  */
-#line 2479 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2362 "../../src/parse-gram.c"
     break;
 
   case 61:
-
-/* Line 1392 of yacc.c  */
-#line 436 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 439 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-
-/* Line 1392 of yacc.c  */
-#line 2489 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2370 "../../src/parse-gram.c"
     break;
 
   case 62:
-
-/* Line 1392 of yacc.c  */
-#line 437 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 440 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2499 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2378 "../../src/parse-gram.c"
     break;
 
   case 63:
-
-/* Line 1392 of yacc.c  */
-#line 443 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 446 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2509 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2386 "../../src/parse-gram.c"
     break;
 
   case 64:
-
-/* Line 1392 of yacc.c  */
-#line 445 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-
-/* Line 1392 of yacc.c  */
-#line 2519 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2394 "../../src/parse-gram.c"
     break;
 
   case 65:
-
-/* Line 1392 of yacc.c  */
-#line 449 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 452 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-
-/* Line 1392 of yacc.c  */
-#line 2529 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2402 "../../src/parse-gram.c"
     break;
 
   case 66:
-
-/* Line 1392 of yacc.c  */
-#line 450 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-
-/* Line 1392 of yacc.c  */
-#line 2539 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2410 "../../src/parse-gram.c"
     break;
 
   case 67:
-
-/* Line 1392 of yacc.c  */
-#line 454 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2549 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2418 "../../src/parse-gram.c"
     break;
 
   case 68:
-
-/* Line 1392 of yacc.c  */
-#line 455 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2559 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2426 "../../src/parse-gram.c"
     break;
 
   case 69:
-
-/* Line 1392 of yacc.c  */
-#line 456 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 459 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2569 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2434 "../../src/parse-gram.c"
     break;
 
   case 70:
-
-/* Line 1392 of yacc.c  */
-#line 457 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2579 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2442 "../../src/parse-gram.c"
     break;
 
   case 71:
-
-/* Line 1392 of yacc.c  */
-#line 463 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 466 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-
-/* Line 1392 of yacc.c  */
-#line 2592 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2453 "../../src/parse-gram.c"
     break;
 
   case 72:
-
-/* Line 1392 of yacc.c  */
-#line 468 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 471 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-
-/* Line 1392 of yacc.c  */
-#line 2605 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2464 "../../src/parse-gram.c"
     break;
 
   case 73:
-
-/* Line 1392 of yacc.c  */
-#line 473 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 476 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2619 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2476 "../../src/parse-gram.c"
     break;
 
   case 74:
-
-/* Line 1392 of yacc.c  */
-#line 479 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 482 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2633 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2488 "../../src/parse-gram.c"
     break;
 
   case 75:
-
-/* Line 1392 of yacc.c  */
-#line 485 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 488 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2648 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2501 "../../src/parse-gram.c"
     break;
 
   case 82:
-
-/* Line 1392 of yacc.c  */
-#line 515 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 518 "parse-gram.y"
     {
       yyerrok;
     }
-
-/* Line 1392 of yacc.c  */
-#line 2660 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2511 "../../src/parse-gram.c"
     break;
 
   case 83:
-
-/* Line 1392 of yacc.c  */
-#line 521 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 524 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
-
-/* Line 1392 of yacc.c  */
-#line 2670 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2519 "../../src/parse-gram.c"
     break;
 
   case 85:
-
-/* Line 1392 of yacc.c  */
-#line 525 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 528 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2680 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2527 "../../src/parse-gram.c"
     break;
 
   case 86:
-
-/* Line 1392 of yacc.c  */
-#line 526 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 529 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2690 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2535 "../../src/parse-gram.c"
     break;
 
   case 88:
-
-/* Line 1392 of yacc.c  */
-#line 532 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 535 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
-
-/* Line 1392 of yacc.c  */
-#line 2700 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2543 "../../src/parse-gram.c"
     break;
 
   case 89:
-
-/* Line 1392 of yacc.c  */
-#line 534 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 537 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2710 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2551 "../../src/parse-gram.c"
     break;
 
   case 90:
-
-/* Line 1392 of yacc.c  */
-#line 536 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 539 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2720 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2559 "../../src/parse-gram.c"
     break;
 
   case 91:
-
-/* Line 1392 of yacc.c  */
-#line 538 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 541 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2730 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2567 "../../src/parse-gram.c"
     break;
 
   case 92:
-
-/* Line 1392 of yacc.c  */
-#line 540 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 543 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2740 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2575 "../../src/parse-gram.c"
     break;
 
   case 93:
-
-/* Line 1392 of yacc.c  */
-#line 542 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 545 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2750 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2583 "../../src/parse-gram.c"
     break;
 
   case 95:
-
-/* Line 1392 of yacc.c  */
-#line 552 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 555 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-
-/* Line 1392 of yacc.c  */
-#line 2760 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2591 "../../src/parse-gram.c"
     break;
 
   case 96:
-
-/* Line 1392 of yacc.c  */
-#line 558 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 561 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
-
-/* Line 1392 of yacc.c  */
-#line 2772 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2601 "../../src/parse-gram.c"
     break;
 
   case 98:
-
-/* Line 1392 of yacc.c  */
-#line 571 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 574 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2783,62 +2611,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-
-/* Line 1392 of yacc.c  */
-#line 2789 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2616 "../../src/parse-gram.c"
     break;
 
   case 99:
-
-/* Line 1392 of yacc.c  */
-#line 591 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 594 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2799 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2624 "../../src/parse-gram.c"
     break;
 
   case 100:
-
-/* Line 1392 of yacc.c  */
-#line 593 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 596 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-
-/* Line 1392 of yacc.c  */
-#line 2813 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2636 "../../src/parse-gram.c"
     break;
 
   case 101:
-
-/* Line 1392 of yacc.c  */
-#line 601 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 604 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-
-/* Line 1392 of yacc.c  */
-#line 2823 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2644 "../../src/parse-gram.c"
     break;
 
   case 104:
-
-/* Line 1392 of yacc.c  */
-#line 613 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 616 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-
-/* Line 1392 of yacc.c  */
-#line 2836 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2655 "../../src/parse-gram.c"
     break;
 
   case 106:
-
-/* Line 1392 of yacc.c  */
-#line 622 "parse-gram.y"
+/* Line 1380 of yacc.c  */
+#line 625 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2847,15 +2665,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-
-/* Line 1392 of yacc.c  */
-#line 2853 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2670 "../../src/parse-gram.c"
     break;
 
 
-
-/* Line 1392 of yacc.c  */
-#line 2859 "../../src/parse-gram.c"
+/* Line 1380 of yacc.c  */
+#line 2675 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2894,7 +2710,7 @@ yyerrlab:
       yyerror (YY_("syntax error"));
 #else
       {
-	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
+	YYSIZE_T yysize = yysyntax_error (0, yystate, yytoken);
 	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
 	  {
 	    YYSIZE_T yyalloc = 2 * yysize;
@@ -2914,7 +2730,7 @@ yyerrlab:
 
 	if (0 < yysize && yysize <= yymsg_alloc)
 	  {
-	    (void) yysyntax_error (yymsg, yystate, yychar);
+	    (void) yysyntax_error (yymsg, yystate, yytoken);
 	    yyerror (yymsg);
 	  }
 	else
@@ -3071,10 +2887,8 @@ yyreturn:
   return YYID (yyresult);
 }
 
-
-
-/* Line 1612 of yacc.c  */
-#line 632 "parse-gram.y"
+/* Line 1599 of yacc.c  */
+#line 635 "parse-gram.y"
 
 
 
@@ -3195,4 +3009,3 @@ char_name (char c)
       return quotearg_style (escape_quoting_style, buf);
     }
 }
-
