@@ -229,9 +229,8 @@ static void add_param (char const *, char *, location);
 
 static symbol_class current_class = unknown_sym;
 static uniqstr current_type = 0;
-symbol *current_lhs;
-location current_lhs_location;
-assoc current_assoc;
+static symbol *current_lhs;
+static location current_lhs_location;
 static int current_prec = 0;
 
 
@@ -254,7 +253,7 @@ static int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 82 "parse-gram.y"
+#line 81 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -264,7 +263,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 197 of yacc.c.  */
-#line 268 "parse-gram.c"
+#line 267 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -288,7 +287,7 @@ typedef struct YYLTYPE
 
 
 /* Line 220 of yacc.c.  */
-#line 292 "parse-gram.c"
+#line 291 "parse-gram.c"
 
 /* Define YYMODERN_C if this compiler supports C89 or better.  If
    __STDC__ is defined, the compiler is modern.  IBM xlc 7.0 when run
@@ -331,7 +330,28 @@ typedef struct YYLTYPE
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#define YYUSE(e) do {;} while (/*CONSTCOND*/ 0 && (e))
+#ifndef lint
+# define YYUSE(e) ((void) (e))
+#else
+# define YYUSE(e) /* empty */
+#endif
+
+/* Identity function, used to suppress warnings about constant conditions.  */
+#ifndef lint
+# define YYID(n) (n)
+#else
+#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+static int
+YYID (int i)
+#else
+static int
+YYID (i)
+    int i;
+#endif
+{
+  return i;
+}
+#endif
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -362,7 +382,7 @@ typedef struct YYLTYPE
 
 # ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning. */
-#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
+#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
        and a page size can be as small as 4096 bytes.  So we cannot safely
@@ -434,7 +454,7 @@ union yyalloc
 	  for (yyi = 0; yyi < (Count); yyi++)	\
 	    (To)[yyi] = (From)[yyi];		\
 	}					\
-      while (/*CONSTCOND*/ 0)
+      while (YYID (0))
 #  endif
 # endif
 
@@ -452,7 +472,7 @@ union yyalloc
 	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
-    while (/*CONSTCOND*/ 0)
+    while (YYID (0))
 
 #endif
 
@@ -564,15 +584,15 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
-       0,   192,   192,   200,   202,   206,   207,   208,   209,   210,
-     211,   212,   213,   214,   215,   216,   221,   225,   226,   227,
-     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
-     238,   242,   243,   244,   248,   254,   261,   268,   272,   279,
-     279,   284,   284,   289,   299,   314,   315,   316,   320,   321,
-     327,   328,   333,   337,   342,   348,   354,   365,   366,   375,
-     376,   382,   383,   388,   395,   395,   399,   400,   401,   406,
-     407,   409,   411,   413,   415,   420,   421,   425,   431,   440,
-     445,   447
+       0,   191,   191,   199,   201,   205,   206,   207,   208,   209,
+     210,   211,   212,   213,   214,   215,   220,   224,   225,   226,
+     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
+     237,   241,   242,   243,   247,   253,   260,   267,   271,   278,
+     278,   283,   283,   288,   298,   313,   314,   315,   319,   320,
+     326,   327,   332,   336,   341,   347,   353,   364,   365,   374,
+     375,   381,   382,   387,   394,   394,   398,   399,   400,   405,
+     406,   408,   410,   412,   414,   419,   420,   424,   430,   439,
+     444,   446
 };
 #endif
 
@@ -794,7 +814,7 @@ do								\
       yyerror (YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
-while (/*CONSTCOND*/ 0)
+while (YYID (0))
 
 
 #define YYTERROR	1
@@ -823,7 +843,7 @@ while (/*CONSTCOND*/ 0)
 	  (Current).first_column = (Current).last_column =		\
 	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
-    while (/*CONSTCOND*/ 0)
+    while (YYID (0))
 #endif
 
 
@@ -863,7 +883,7 @@ while (/*CONSTCOND*/ 0)
 do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
 do {									  \
@@ -874,12 +894,13 @@ do {									  \
                   Type, Value, Location); \
       YYFPRINTF (stderr, "\n");						  \
     }									  \
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 /*--------------------------------.
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/
 
+/*ARGSUSED*/
 #if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
 static void
 yysymprint (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
@@ -909,94 +930,94 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 169 "parse-gram.y"
+#line 168 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 915 "parse-gram.c"
+#line 936 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
-#line 182 "parse-gram.y"
+#line 181 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 920 "parse-gram.c"
+#line 941 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
-#line 171 "parse-gram.y"
+#line 170 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 925 "parse-gram.c"
+#line 946 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
-#line 175 "parse-gram.y"
+#line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 930 "parse-gram.c"
+#line 951 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
-#line 176 "parse-gram.y"
+#line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 935 "parse-gram.c"
+#line 956 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 172 "parse-gram.y"
+#line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 940 "parse-gram.c"
+#line 961 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 173 "parse-gram.y"
+#line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 945 "parse-gram.c"
+#line 966 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 174 "parse-gram.y"
+#line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 950 "parse-gram.c"
+#line 971 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
-#line 180 "parse-gram.y"
+#line 179 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 955 "parse-gram.c"
+#line 976 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
-#line 184 "parse-gram.y"
+#line 183 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 960 "parse-gram.c"
+#line 981 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
-#line 186 "parse-gram.y"
+#line 185 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 965 "parse-gram.c"
+#line 986 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
-#line 178 "parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 970 "parse-gram.c"
+#line 991 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
-#line 178 "parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 975 "parse-gram.c"
+#line 996 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
-#line 177 "parse-gram.y"
+#line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 980 "parse-gram.c"
+#line 1001 "parse-gram.c"
         break;
       case 72: /* "symbol" */
-#line 184 "parse-gram.y"
+#line 183 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 985 "parse-gram.c"
+#line 1006 "parse-gram.c"
         break;
       case 73: /* "action" */
-#line 177 "parse-gram.y"
+#line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 990 "parse-gram.c"
+#line 1011 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
-#line 184 "parse-gram.y"
+#line 183 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 995 "parse-gram.c"
+#line 1016 "parse-gram.c"
         break;
       case 75: /* "string_content" */
-#line 169 "parse-gram.y"
+#line 168 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1000 "parse-gram.c"
+#line 1021 "parse-gram.c"
         break;
       default:
         break;
@@ -1029,7 +1050,7 @@ yy_stack_print (bottom, top)
 do {								\
   if (yydebug)							\
     yy_stack_print ((Bottom), (Top));				\
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 
 /*------------------------------------------------.
@@ -1068,7 +1089,7 @@ yy_reduce_print (yyvsp, yylsp, yyrule
 do {					\
   if (yydebug)				\
     yy_reduce_print (yyvsp, yylsp, Rule); \
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -1114,12 +1135,10 @@ yystrlen (yystr)
      const char *yystr;
 #   endif
 {
-  const char *yys = yystr;
-
-  while (*yys++ != '\0')
+  YYSIZE_T yylen;
+  for (yylen = 0; yystr[yylen]; yylen++)
     continue;
-
-  return yys - yystr - 1;
+  return yylen;
 }
 #  endif
 # endif
@@ -1267,7 +1286,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
               }
             yyarg[yycount++] = yytname[yyx];
             yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-            yysize_overflow |= yysize1 < yysize;
+            yysize_overflow |= (yysize1 < yysize);
             yysize = yysize1;
             yyfmt = yystpcpy (yyfmt, yyprefix);
             yyprefix = yyor;
@@ -1275,7 +1294,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
       yyf = YY_(yyformat);
       yysize1 = yysize + yystrlen (yyf);
-      yysize_overflow |= yysize1 < yysize;
+      yysize_overflow |= (yysize1 < yysize);
       yysize = yysize1;
 
       if (yysize_overflow)
@@ -1288,7 +1307,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
              produced a string with the wrong number of "%s"s.  */
           char *yyp = yyresult;
           int yyi = 0;
-          while ((*yyp = *yyf))
+          while ((*yyp = *yyf) != '\0')
             {
               if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
                 {
@@ -1312,6 +1331,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
+/*ARGSUSED*/
 #if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
 static void
 yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
@@ -1469,7 +1489,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 72 "parse-gram.y"
+#line 71 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1477,8 +1497,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1076 of yacc.c.  */
-#line 1482 "parse-gram.c"
+/* Line 1088 of yacc.c.  */
+#line 1502 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1667,52 +1687,52 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 207 "parse-gram.y"
+#line 206 "parse-gram.y"
     { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 208 "parse-gram.y"
+#line 207 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 209 "parse-gram.y"
+#line 208 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (2)].chars), "1"); }
     break;
 
   case 9:
-#line 210 "parse-gram.y"
+#line 209 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 211 "parse-gram.y"
+#line 210 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 212 "parse-gram.y"
+#line 211 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 213 "parse-gram.y"
+#line 212 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 214 "parse-gram.y"
+#line 213 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 215 "parse-gram.y"
+#line 214 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 217 "parse-gram.y"
+#line 216 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1720,86 +1740,86 @@ yyreduce:
     break;
 
   case 16:
-#line 222 "parse-gram.y"
+#line 221 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
   }
     break;
 
   case 17:
-#line 225 "parse-gram.y"
+#line 224 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 18:
-#line 226 "parse-gram.y"
+#line 225 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 227 "parse-gram.y"
+#line 226 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 228 "parse-gram.y"
+#line 227 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 229 "parse-gram.y"
+#line 228 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 230 "parse-gram.y"
+#line 229 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 231 "parse-gram.y"
+#line 230 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 24:
-#line 232 "parse-gram.y"
+#line 231 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 233 "parse-gram.y"
+#line 232 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 234 "parse-gram.y"
+#line 233 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 235 "parse-gram.y"
+#line 234 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 236 "parse-gram.y"
+#line 235 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 237 "parse-gram.y"
+#line 236 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 245 "parse-gram.y"
+#line 244 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 249 "parse-gram.y"
+#line 248 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[(1) - (1)]).start.line);
@@ -1808,7 +1828,7 @@ yyreduce:
     break;
 
   case 35:
-#line 255 "parse-gram.y"
+#line 254 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1818,7 +1838,7 @@ yyreduce:
     break;
 
   case 36:
-#line 262 "parse-gram.y"
+#line 261 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1828,26 +1848,26 @@ yyreduce:
     break;
 
   case 37:
-#line 269 "parse-gram.y"
+#line 268 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 273 "parse-gram.y"
+#line 272 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 279 "parse-gram.y"
+#line 278 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 280 "parse-gram.y"
+#line 279 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1855,12 +1875,12 @@ yyreduce:
     break;
 
   case 41:
-#line 284 "parse-gram.y"
+#line 283 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 285 "parse-gram.y"
+#line 284 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1868,7 +1888,7 @@ yyreduce:
     break;
 
   case 43:
-#line 290 "parse-gram.y"
+#line 289 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1878,7 +1898,7 @@ yyreduce:
     break;
 
   case 44:
-#line 300 "parse-gram.y"
+#line 299 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1893,49 +1913,49 @@ yyreduce:
     break;
 
   case 45:
-#line 314 "parse-gram.y"
+#line 313 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 315 "parse-gram.y"
+#line 314 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 316 "parse-gram.y"
+#line 315 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 320 "parse-gram.y"
+#line 319 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 321 "parse-gram.y"
+#line 320 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 327 "parse-gram.y"
+#line 326 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 328 "parse-gram.y"
+#line 327 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 334 "parse-gram.y"
+#line 333 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 338 "parse-gram.y"
+#line 337 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]));
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -1943,7 +1963,7 @@ yyreduce:
     break;
 
   case 54:
-#line 343 "parse-gram.y"
+#line 342 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]));
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -1952,7 +1972,7 @@ yyreduce:
     break;
 
   case 55:
-#line 349 "parse-gram.y"
+#line 348 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]));
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -1961,7 +1981,7 @@ yyreduce:
     break;
 
   case 56:
-#line 355 "parse-gram.y"
+#line 354 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]));
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -1971,7 +1991,7 @@ yyreduce:
     break;
 
   case 62:
-#line 384 "parse-gram.y"
+#line 383 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
@@ -1979,74 +1999,74 @@ yyreduce:
     break;
 
   case 63:
-#line 389 "parse-gram.y"
+#line 388 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 395 "parse-gram.y"
+#line 394 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 399 "parse-gram.y"
+#line 398 "parse-gram.y"
     { grammar_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 400 "parse-gram.y"
+#line 399 "parse-gram.y"
     { grammar_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 406 "parse-gram.y"
+#line 405 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 408 "parse-gram.y"
+#line 407 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 71:
-#line 410 "parse-gram.y"
+#line 409 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 72:
-#line 412 "parse-gram.y"
+#line 411 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 414 "parse-gram.y"
+#line 413 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 416 "parse-gram.y"
+#line 415 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 420 "parse-gram.y"
+#line 419 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 421 "parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 426 "parse-gram.y"
+#line 425 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 78:
-#line 432 "parse-gram.y"
+#line 431 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]));
@@ -2054,12 +2074,12 @@ yyreduce:
     break;
 
   case 79:
-#line 441 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 81:
-#line 448 "parse-gram.y"
+#line 447 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       scanner_last_string_free ();
@@ -2072,7 +2092,7 @@ yyreduce:
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
 
 /* Line __line__ of yacc.c.  */
-#line 2076 "parse-gram.c"
+#line 2096 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -2284,7 +2304,7 @@ yyreturn:
 }
 
 
-#line 454 "parse-gram.y"
+#line 453 "parse-gram.y"
 
 
 
