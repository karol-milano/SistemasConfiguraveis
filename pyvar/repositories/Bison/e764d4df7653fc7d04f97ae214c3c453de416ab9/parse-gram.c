@@ -316,6 +316,9 @@ typedef struct YYLTYPE
 # endif
 #endif
 
+/* Suppress unused-variable warnings by "using" E.  */
+#define YYUSE(e) do {;} while (/*CONSTCOND*/ 0 && (e))
+
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
@@ -420,7 +423,7 @@ union yyalloc
 	  for (yyi = 0; yyi < (Count); yyi++)	\
 	    (To)[yyi] = (From)[yyi];		\
 	}					\
-      while (0)
+      while (/*CONSTCOND*/ 0)
 #  endif
 # endif
 
@@ -438,7 +441,7 @@ union yyalloc
 	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
-    while (0)
+    while (/*CONSTCOND*/ 0)
 
 #endif
 
@@ -780,7 +783,7 @@ do								\
       yyerror (YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
-while (0)
+while (/*CONSTCOND*/ 0)
 
 
 #define YYTERROR	1
@@ -809,7 +812,7 @@ while (0)
 	  (Current).first_column = (Current).last_column =		\
 	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
-    while (0)
+    while (/*CONSTCOND*/ 0)
 #endif
 
 
@@ -849,7 +852,7 @@ while (0)
 do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
@@ -860,7 +863,7 @@ do {								\
                   Type, Value, Location);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 /*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
@@ -887,7 +890,7 @@ yy_stack_print (bottom, top)
 do {								\
   if (yydebug)							\
     yy_stack_print ((Bottom), (Top));				\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 
 /*------------------------------------------------.
@@ -917,7 +920,7 @@ yy_reduce_print (yyrule)
 do {					\
   if (yydebug)				\
     yy_reduce_print (Rule);		\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -1174,9 +1177,8 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
     YYLTYPE *yylocationp;
 #endif
 {
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yyvaluep;
-  (void) yylocationp;
+  YYUSE (yyvaluep);
+  YYUSE (yylocationp);
 
   if (yytype < YYNTOKENS)
     YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
@@ -1195,92 +1197,92 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1199 "parse-gram.c"
+#line 1201 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1204 "parse-gram.c"
+#line 1206 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1209 "parse-gram.c"
+#line 1211 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1214 "parse-gram.c"
+#line 1216 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1219 "parse-gram.c"
+#line 1221 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1224 "parse-gram.c"
+#line 1226 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1229 "parse-gram.c"
+#line 1231 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1234 "parse-gram.c"
+#line 1236 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1239 "parse-gram.c"
+#line 1241 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1244 "parse-gram.c"
+#line 1246 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
 #line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1249 "parse-gram.c"
+#line 1251 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1254 "parse-gram.c"
+#line 1256 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1259 "parse-gram.c"
+#line 1261 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1264 "parse-gram.c"
+#line 1266 "parse-gram.c"
         break;
       case 72: /* "symbol" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1269 "parse-gram.c"
+#line 1271 "parse-gram.c"
         break;
       case 73: /* "action" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1274 "parse-gram.c"
+#line 1276 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1279 "parse-gram.c"
+#line 1281 "parse-gram.c"
         break;
       case 75: /* "string_content" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1284 "parse-gram.c"
+#line 1286 "parse-gram.c"
         break;
       default:
         break;
@@ -1305,9 +1307,8 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
     YYLTYPE *yylocationp;
 #endif
 {
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yyvaluep;
-  (void) yylocationp;
+  YYUSE (yyvaluep);
+  YYUSE (yylocationp);
 
   if (!yymsg)
     yymsg = "Deleting";
@@ -1459,8 +1460,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1053 of yacc.c.  */
-#line 1464 "parse-gram.c"
+/* Line 1056 of yacc.c.  */
+#line 1465 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2052,8 +2053,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1249 of yacc.c.  */
-#line 2057 "parse-gram.c"
+/* Line 1252 of yacc.c.  */
+#line 2058 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -2157,7 +2158,7 @@ yyerrorlab:
   /* Pacify compilers like GCC when the user code never invokes
      YYERROR and the label yyerrorlab therefore never appears in user
      code.  */
-  if (0)
+  if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
   yyerror_range[0] = yylsp[1-yylen];
