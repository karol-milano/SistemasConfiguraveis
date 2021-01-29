@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.537-34db.  */
+/* A Bison parser, made by GNU Bison 2.4.542-10bae.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.537-34db"
+#define YYBISON_VERSION "2.4.542-10bae"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -73,7 +73,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 252 of yacc.c  */
+/* Line 262 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -128,7 +128,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 252 of yacc.c  */
+/* Line 262 of yacc.c  */
 #line 133 "src/parse-gram.c"
 
 /* Enabling traces.  */
@@ -150,7 +150,7 @@ static char const *char_name (char);
 #endif
 
 /* "%code requires" blocks.  */
-/* Line 272 of yacc.c  */
+/* Line 282 of yacc.c  */
 #line 202 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
@@ -165,7 +165,7 @@ static char const *char_name (char);
 # endif
 
 
-/* Line 272 of yacc.c  */
+/* Line 282 of yacc.c  */
 #line 170 "src/parse-gram.c"
 
 /* Tokens.  */
@@ -294,7 +294,7 @@ static char const *char_name (char);
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 277 of yacc.c  */
+/* Line 287 of yacc.c  */
 #line 88 "src/parse-gram.y"
 
   assoc assoc;
@@ -307,13 +307,13 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 277 of yacc.c  */
+/* Line 287 of yacc.c  */
 #line 226 "src/parse-gram.y"
 
   param_type param;
 
 
-/* Line 277 of yacc.c  */
+/* Line 287 of yacc.c  */
 #line 318 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -337,10 +337,10 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 327 of yacc.c  */
+/* Line 337 of yacc.c  */
 #line 342 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 328 of yacc.c  */
+/* Line 338 of yacc.c  */
 #line 56 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -355,7 +355,7 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 328 of yacc.c  */
+/* Line 338 of yacc.c  */
 #line 215 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -368,7 +368,7 @@ typedef struct YYLTYPE
   static param_type current_param = param_none;
 
 
-/* Line 328 of yacc.c  */
+/* Line 338 of yacc.c  */
 #line 373 "src/parse-gram.c"
 
 #ifdef short
@@ -1033,106 +1033,106 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1041 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1050 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1059 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1068 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 182 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1077 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1086 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1095 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1104 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1113 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1122 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1131 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 231 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1146,79 +1146,79 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1151 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1160 "src/parse-gram.c"
         break;
 
             case 85: // variable
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1169 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1178 "src/parse-gram.c"
         break;
 
             case 87: // braceless
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1187 "src/parse-gram.c"
         break;
 
             case 88: // id
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1196 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1205 "src/parse-gram.c"
         break;
 
             case 90: // symbol
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1214 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
 
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 729 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1223 "src/parse-gram.c"
         break;
 
@@ -1355,7 +1355,6 @@ int yydebug;
 # define YYMAXDEPTH 10000
 #endif
 
-
 
 #if YYERROR_VERBOSE
 
@@ -1459,7 +1458,8 @@ yytnamerr (char *yyres, const char *yystr)
 # endif
 
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
-   about the unexpected token YYTOKEN while in state YYSTATE.
+   about the unexpected token YYTOKEN for the state stack whose top is
+   YYSSP.
 
    Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
@@ -1467,7 +1467,7 @@ yytnamerr (char *yyres, const char *yystr)
    required number of bytes is too large to store.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
-                int yystate, int yytoken)
+                yytype_int16 *yyssp, int yytoken)
 {
   YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -1510,7 +1510,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[yystate];
+      int yyn = yypact[*yyssp];
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
         {
@@ -1522,6 +1522,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
           int yychecklim = YYLAST - yyn + 1;
           int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
           int yyx;
+
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                 && !yytable_value_is_error (yytable[yyx + yyn]))
@@ -1544,7 +1545,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 
   switch (yycount)
     {
-#define YYCASE_(N, S)                       \
+# define YYCASE_(N, S)                      \
       case N:                               \
         yyformat = S;                       \
       break
@@ -1554,7 +1555,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
       YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
       YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
-#undef YYCASE_
+# undef YYCASE_
     }
 
   yysize1 = yysize + yystrlen (yyformat);
@@ -1592,7 +1593,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   return 0;
 }
 #endif /* YYERROR_VERBOSE */
-
 
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
@@ -1765,7 +1765,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1230 of yacc.c  */
+/* Line 1430 of yacc.c  */
 #line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1773,7 +1773,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1230 of yacc.c  */
+/* Line 1430 of yacc.c  */
 #line 1778 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
@@ -1905,7 +1905,7 @@ yybackup:
   if (yyn <= 0)
     {
       if (yytable_value_is_error (yyn))
-	goto yyerrlab;
+        goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
     }
@@ -1960,7 +1960,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 267 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -1971,106 +1971,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 1976 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 277 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 1986 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 281 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 1997 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 285 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2005 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 287 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2016 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 292 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2027 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 296 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2035 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 297 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2043 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2051 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 299 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2059 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 301 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2070 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 306 "src/parse-gram.y"
     {
       code_props action;
@@ -2080,92 +2080,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2085 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 314 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2093 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2101 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2109 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2117 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2125 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2133 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 320 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2141 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2149 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2157 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 322 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2165 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 324 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2190,62 +2190,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2195 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 347 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2203 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 348 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2211 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 349 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2219 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2227 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 355 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2235 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 367 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2245 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 371 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2253,12 +2253,12 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2258 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 378 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2266,32 +2266,32 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2271 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 385 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2281 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 389 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2291 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 393 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2299,89 +2299,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2304 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 400 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2315 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 414 "src/parse-gram.y"
     {}
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2323 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 415 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2331 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 420 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2343 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2351 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2362 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 436 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2370 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2381 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 442 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2390,12 +2390,12 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2395 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 453 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2408,202 +2408,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2413 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 467 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2421 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 468 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2429 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 469 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2437 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 470 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2445 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 474 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2453 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 475 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2461 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 481 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2469 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 483 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2477 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2485 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 488 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2493 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2501 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 496 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2509 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2517 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2525 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2533 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2541 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2549 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2557 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 514 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2568 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 519 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2579 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 524 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2591 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 530 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2603 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 536 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2611,144 +2611,144 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2616 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 566 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2626 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 572 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2635 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2643 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 578 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2651 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 584 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2660 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 587 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2668 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 589 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2676 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 591 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2684 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 593 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2692 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 595 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2700 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 597 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2708 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 601 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2716 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 603 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2724 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 614 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2732 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2740 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 620 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2748 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 631 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2758,51 +2758,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2763 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 651 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2771 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 653 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2783 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 661 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2791 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 673 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2802 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 682 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2812,12 +2812,12 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2817 "src/parse-gram.c"
     break;
 
 
-/* Line 1443 of yacc.c  */
+/* Line 1646 of yacc.c  */
 #line 2822 "src/parse-gram.c"
       default: break;
     }
@@ -2871,11 +2871,12 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (YY_("syntax error"));
 #else
-# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yystate, \
+# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yyssp, \
                                         yytoken)
       {
         char const *yymsgp = YY_("syntax error");
-        int yysyntax_error_status = YYSYNTAX_ERROR;
+        int yysyntax_error_status;
+        yysyntax_error_status = YYSYNTAX_ERROR;
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
         else if (yysyntax_error_status == 1)
@@ -3052,7 +3053,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1680 of yacc.c  */
+/* Line 1903 of yacc.c  */
 #line 692 "src/parse-gram.y"
 
 
