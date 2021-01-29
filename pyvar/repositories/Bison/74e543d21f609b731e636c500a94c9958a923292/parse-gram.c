@@ -840,14 +840,9 @@ while (0)
 /* Enable debugging if requested.  */
 #if YYDEBUG
 
-# ifdef YYFPRINTF
-#  define YYFPUTC(Char, Stream) YYFPRINTF (Stream, "%c", Char)
-#  define YYFPUTS(Char, Stream) YYFPRINTF (Stream, "%s", String)
-# else
+# ifndef YYFPRINTF
 #  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYFPRINTF fprintf
-#  define YYFPUTC fputc
-#  define YYFPUTS fputs
 # endif
 
 # define YYDPRINTF(Args)			\
@@ -856,12 +851,6 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
-# define YYDPUTS(String, Stream)		\
-do {						\
-  if (yydebug)					\
-    YYFPUTS (String, Stream);			\
-} while (0)
-
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
   if (yydebug)							\
@@ -869,7 +858,7 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value, Location);	\
-      YYFPUTC ('\n', stderr);					\
+      YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
 
@@ -888,10 +877,10 @@ yy_stack_print (bottom, top)
     short int *top;
 #endif
 {
-  YYFPUTS ("Stack now", stderr);
+  YYFPRINTF (stderr, "Stack now");
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
-  YYFPUTC ('\n', stderr);
+  YYFPRINTF (stderr, "\n");
 }
 
 # define YY_STACK_PRINT(Bottom, Top)				\
@@ -933,15 +922,11 @@ do {					\
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
-
 #else /* !YYDEBUG */
-
-# define YYDPUTS(String, File)
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
-
 #endif /* !YYDEBUG */
 
 
@@ -1199,7 +1184,7 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
     YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
 
   YY_LOCATION_PRINT (yyoutput, *yylocationp);
-  YYFPUTS (": ", yyoutput);
+  YYFPRINTF (yyoutput, ": ");
 
 # ifdef YYPRINT
   if (yytype < YYNTOKENS)
@@ -1210,97 +1195,97 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1214 "parse-gram.c"
+#line 1199 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1219 "parse-gram.c"
+#line 1204 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1224 "parse-gram.c"
+#line 1209 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1229 "parse-gram.c"
+#line 1214 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1234 "parse-gram.c"
+#line 1219 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1239 "parse-gram.c"
+#line 1224 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1244 "parse-gram.c"
+#line 1229 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1249 "parse-gram.c"
+#line 1234 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1254 "parse-gram.c"
+#line 1239 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
 #line 184 "parse-gram.y"
-        { fputs ((yyvaluep->symbol)->tag, stderr); };
-#line 1259 "parse-gram.c"
+        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1244 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
 #line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1264 "parse-gram.c"
+#line 1249 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1269 "parse-gram.c"
+#line 1254 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1274 "parse-gram.c"
+#line 1259 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1279 "parse-gram.c"
+#line 1264 "parse-gram.c"
         break;
       case 72: /* "symbol" */
 #line 184 "parse-gram.y"
-        { fputs ((yyvaluep->symbol)->tag, stderr); };
-#line 1284 "parse-gram.c"
+        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1269 "parse-gram.c"
         break;
       case 73: /* "action" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1289 "parse-gram.c"
+#line 1274 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
 #line 184 "parse-gram.y"
-        { fputs ((yyvaluep->symbol)->tag, stderr); };
-#line 1294 "parse-gram.c"
+        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1279 "parse-gram.c"
         break;
       case 75: /* "string_content" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1299 "parse-gram.c"
+#line 1284 "parse-gram.c"
         break;
       default:
         break;
     }
-  YYFPUTC (')', yyoutput);
+  YYFPRINTF (yyoutput, ")");
 }
 
 #endif /* ! YYDEBUG */
@@ -1376,7 +1361,7 @@ yyparse (void)
 #else
 int
 yyparse ()
-    ;
+
 #endif
 #endif
 {
@@ -1443,7 +1428,7 @@ YYLTYPE yylloc;
      rule.  */
   int yylen;
 
-  YYDPUTS ("Starting parse\n", stderr);
+  YYDPRINTF ((stderr, "Starting parse\n"));
 
   yystate = 0;
   yyerrstatus = 0;
@@ -1474,8 +1459,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1068 of yacc.c.  */
-#line 1479 "parse-gram.c"
+/* Line 1053 of yacc.c.  */
+#line 1464 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1580,14 +1565,14 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPUTS ("Reading a token: ", stderr);
+      YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPUTS ("Now at end of input.\n", stderr);
+      YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
@@ -2067,8 +2052,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1264 of yacc.c.  */
-#line 2072 "parse-gram.c"
+/* Line 1249 of yacc.c.  */
+#line 2057 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
