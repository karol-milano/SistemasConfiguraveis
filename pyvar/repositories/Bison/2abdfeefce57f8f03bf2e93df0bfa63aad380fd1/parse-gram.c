@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.1.  */
+/* A Bison parser, made by GNU Bison 2.1a.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
@@ -37,7 +37,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.1"
+#define YYBISON_VERSION "2.1a"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -298,6 +298,8 @@ typedef struct YYLTYPE
 # define YYSIZE_T unsigned int
 #endif
 
+#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
+
 #ifndef YY_
 # if YYENABLE_NLS
 #  if ENABLE_NLS
@@ -342,7 +344,7 @@ typedef struct YYLTYPE
 #  define YYSTACK_ALLOC YYMALLOC
 #  define YYSTACK_FREE YYFREE
 #  ifndef YYSTACK_ALLOC_MAXIMUM
-#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
+#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
 #  endif
 #  ifdef __cplusplus
 extern "C" {
@@ -1024,8 +1026,114 @@ yytnamerr (char *yyres, const char *yystr)
 }
 # endif
 
-#endif /* YYERROR_VERBOSE */
+/* Copy into YYRESULT an error message about the unexpected token
+   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
+   including the terminating null byte.  If YYRESULT is null, do not
+   copy anything; just return the number of bytes that would be
+   copied.  As a special case, return 0 if an ordinary "syntax error"
+   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
+   size calculation.  */
+static YYSIZE_T
+yysyntax_error (char *yyresult, int yystate, int yychar)
+{
+  int yyn = yypact[yystate];
 
+  if (! (YYPACT_NINF < yyn && yyn < YYLAST))
+    return 0;
+  else
+    {
+      int yytype = YYTRANSLATE (yychar);
+      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
+      YYSIZE_T yysize = yysize0;
+      YYSIZE_T yysize1;
+      int yysize_overflow = 0;
+      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+      int yyx;
+
+# if 0
+      /* This is so xgettext sees the translatable formats that are
+         constructed on the fly.  */
+      YY_("syntax error, unexpected %s");
+      YY_("syntax error, unexpected %s, expecting %s");
+      YY_("syntax error, unexpected %s, expecting %s or %s");
+      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
+      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
+# endif
+      char *yyfmt;
+      char const *yyf;
+      static char const yyunexpected[] = "syntax error, unexpected %s";
+      static char const yyexpecting[] = ", expecting %s";
+      static char const yyor[] = " or %s";
+      char yyformat[sizeof yyunexpected
+                    + sizeof yyexpecting - 1
+                    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
+                       * (sizeof yyor - 1))];
+      char const *yyprefix = yyexpecting;
+
+      /* Start YYX at -YYN if negative to avoid negative indexes in
+         YYCHECK.  */
+      int yyxbegin = yyn < 0 ? -yyn : 0;
+
+      /* Stay within bounds of both yycheck and yytname.  */
+      int yychecklim = YYLAST - yyn;
+      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+      int yycount = 1;
+
+      yyarg[0] = yytname[yytype];
+      yyfmt = yystpcpy (yyformat, yyunexpected);
+
+      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
+        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+          {
+            if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
+              {
+                yycount = 1;
+                yysize = yysize0;
+                yyformat[sizeof yyunexpected - 1] = '\0';
+                break;
+              }
+            yyarg[yycount++] = yytname[yyx];
+            yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+            yysize_overflow |= yysize1 < yysize;
+            yysize = yysize1;
+            yyfmt = yystpcpy (yyfmt, yyprefix);
+            yyprefix = yyor;
+          }
+
+      yyf = YY_(yyformat);
+      yysize1 = yysize + yystrlen (yyf);
+      yysize_overflow |= yysize1 < yysize;
+      yysize = yysize1;
+
+      if (yysize_overflow)
+	return YYSIZE_MAXIMUM;
+
+      if (yyresult)
+	{
+          /* Avoid sprintf, as that infringes on the user's name space.
+             Don't have undefined behavior even if the translation
+             produced a string with the wrong number of "%s"s.  */
+          char *yyp = yyresult;
+          int yyi = 0;
+          while ((*yyp = *yyf))
+            {
+              if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+                {
+                  yyp += yytnamerr (yyp, yyarg[yyi++]);
+                  yyf += 2;
+                }
+              else
+                {
+                  yyp++;
+                  yyf++;
+                }
+            }
+        }
+      return yysize;
+    }
+}
+#endif /* YYERROR_VERBOSE */
 
 
 #if YYDEBUG
@@ -1066,92 +1174,92 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1070 "parse-gram.c"
+#line 1178 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1075 "parse-gram.c"
+#line 1183 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 167 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1080 "parse-gram.c"
+#line 1188 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1085 "parse-gram.c"
+#line 1193 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1090 "parse-gram.c"
+#line 1198 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 168 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1095 "parse-gram.c"
+#line 1203 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1100 "parse-gram.c"
+#line 1208 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 170 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1105 "parse-gram.c"
+#line 1213 "parse-gram.c"
         break;
       case 41: /* "\"type\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1110 "parse-gram.c"
+#line 1218 "parse-gram.c"
         break;
       case 45: /* "\"identifier\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1115 "parse-gram.c"
+#line 1223 "parse-gram.c"
         break;
       case 46: /* "\"identifier:\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1120 "parse-gram.c"
+#line 1228 "parse-gram.c"
         break;
       case 48: /* "\"%{...%}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1125 "parse-gram.c"
+#line 1233 "parse-gram.c"
         break;
       case 49: /* "\"epilogue\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1130 "parse-gram.c"
+#line 1238 "parse-gram.c"
         break;
       case 50: /* "\"{...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1135 "parse-gram.c"
+#line 1243 "parse-gram.c"
         break;
       case 71: /* "symbol" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1140 "parse-gram.c"
+#line 1248 "parse-gram.c"
         break;
       case 72: /* "action" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1145 "parse-gram.c"
+#line 1253 "parse-gram.c"
         break;
       case 73: /* "string_as_id" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1150 "parse-gram.c"
+#line 1258 "parse-gram.c"
         break;
       case 74: /* "string_content" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1155 "parse-gram.c"
+#line 1263 "parse-gram.c"
         break;
       default:
         break;
@@ -1254,6 +1362,12 @@ YYLTYPE yylloc;
   int yyerrstatus;
   /* Look-ahead token as an internal (translated) token number.  */
   int yytoken = 0;
+#if YYERROR_VERBOSE
+  /* Buffer for error messages, and its allocated size.  */
+  char yymsgbuf[128];
+  char *yymsg = yymsgbuf;
+  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
+#endif
 
   /* Three stacks and their tools:
      `yyss': related to states,
@@ -1324,8 +1438,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 930 of yacc.c.  */
-#line 1329 "parse-gram.c"
+/* Line 1044 of yacc.c.  */
+#line 1443 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1907,8 +2021,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1126 of yacc.c.  */
-#line 1912 "parse-gram.c"
+/* Line 1240 of yacc.c.  */
+#line 2026 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1942,110 +2056,41 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-#if YYERROR_VERBOSE
-      yyn = yypact[yystate];
-
-      if (YYPACT_NINF < yyn && yyn < YYLAST)
-	{
-	  int yytype = YYTRANSLATE (yychar);
-	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
-	  YYSIZE_T yysize = yysize0;
-	  YYSIZE_T yysize1;
-	  int yysize_overflow = 0;
-	  char *yymsg = 0;
-#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
-	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-	  int yyx;
-
-#if 0
-	  /* This is so xgettext sees the translatable formats that are
-	     constructed on the fly.  */
-	  YY_("syntax error, unexpected %s");
-	  YY_("syntax error, unexpected %s, expecting %s");
-	  YY_("syntax error, unexpected %s, expecting %s or %s");
-	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
-	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
-#endif
-	  char *yyfmt;
-	  char const *yyf;
-	  static char const yyunexpected[] = "syntax error, unexpected %s";
-	  static char const yyexpecting[] = ", expecting %s";
-	  static char const yyor[] = " or %s";
-	  char yyformat[sizeof yyunexpected
-			+ sizeof yyexpecting - 1
-			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
-			   * (sizeof yyor - 1))];
-	  char const *yyprefix = yyexpecting;
-
-	  /* Start YYX at -YYN if negative to avoid negative indexes in
-	     YYCHECK.  */
-	  int yyxbegin = yyn < 0 ? -yyn : 0;
-
-	  /* Stay within bounds of both yycheck and yytname.  */
-	  int yychecklim = YYLAST - yyn;
-	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-	  int yycount = 1;
-
-	  yyarg[0] = yytname[yytype];
-	  yyfmt = yystpcpy (yyformat, yyunexpected);
-
-	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+#if ! YYERROR_VERBOSE
+      yyerror (YY_("syntax error"));
+#else
+      {
+	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
+	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
+	  {
+	    YYSIZE_T yyalloc = 2 * yysize;
+	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
+	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
+	    if (yymsg != yymsgbuf)
+	      YYSTACK_FREE (yymsg);
+	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
+	    if (yymsg)
+	      yymsg_alloc = yyalloc;
+	    else
 	      {
-		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-		  {
-		    yycount = 1;
-		    yysize = yysize0;
-		    yyformat[sizeof yyunexpected - 1] = '\0';
-		    break;
-		  }
-		yyarg[yycount++] = yytname[yyx];
-		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-		yysize_overflow |= yysize1 < yysize;
-		yysize = yysize1;
-		yyfmt = yystpcpy (yyfmt, yyprefix);
-		yyprefix = yyor;
+		yymsg = yymsgbuf;
+		yymsg_alloc = sizeof yymsgbuf;
 	      }
+	  }
 
-	  yyf = YY_(yyformat);
-	  yysize1 = yysize + yystrlen (yyf);
-	  yysize_overflow |= yysize1 < yysize;
-	  yysize = yysize1;
-
-	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
-	    yymsg = (char *) YYSTACK_ALLOC (yysize);
-	  if (yymsg)
-	    {
-	      /* Avoid sprintf, as that infringes on the user's name space.
-		 Don't have undefined behavior even if the translation
-		 produced a string with the wrong number of "%s"s.  */
-	      char *yyp = yymsg;
-	      int yyi = 0;
-	      while ((*yyp = *yyf))
-		{
-		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
-		    {
-		      yyp += yytnamerr (yyp, yyarg[yyi++]);
-		      yyf += 2;
-		    }
-		  else
-		    {
-		      yyp++;
-		      yyf++;
-		    }
-		}
-	      yyerror (yymsg);
-	      YYSTACK_FREE (yymsg);
-	    }
-	  else
-	    {
-	      yyerror (YY_("syntax error"));
+	if (0 < yysize && yysize <= yymsg_alloc)
+	  {
+	    (void) yysyntax_error (yymsg, yystate, yychar);
+	    yyerror (yymsg);
+	  }
+	else
+	  {
+	    yyerror (YY_("syntax error"));
+	    if (yysize != 0)
 	      goto yyexhaustedlab;
-	    }
-	}
-      else
-#endif /* YYERROR_VERBOSE */
-	yyerror (YY_("syntax error"));
+	  }
+      }
+#endif
     }
 
   yyerror_range[0] = yylloc;
@@ -2178,6 +2223,10 @@ yyreturn:
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
+#endif
+#if YYERROR_VERBOSE
+  if (yymsg != yymsgbuf)
+    YYSTACK_FREE (yymsg);
 #endif
   return yyresult;
 }
