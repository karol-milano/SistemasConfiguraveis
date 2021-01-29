@@ -412,9 +412,16 @@ static const char *const yytname[] =
 };
 #endif
 
-/* INFRINGES ON USER NAME SPACE */
-#ifndef _
-# define _(msgid) msgid
+#ifndef YYI18N
+# if YYENABLE_NLS
+#  if ENABLE_NLS
+#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
+#   define YYI18N(msgid) dgettext ("bison-runtime", msgid)
+#  endif
+# endif
+# ifndef YYI18N
+#  define YYI18N(msgid) msgid
+# endif
 #endif
 
 # ifdef YYPRINT
@@ -518,7 +525,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror (]b4_yyerror_args[_("syntax error: cannot back up")); \
+      yyerror (]b4_yyerror_args[YYI18N ("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
 while (0)
@@ -612,7 +619,7 @@ do {								\
                    [[short int *bottom], [bottom]],
                    [[short int *top],    [top]])[
 {
-  YYFPRINTF (stderr, _("Stack now"));
+  YYFPRINTF (stderr, YYI18N ("Stack now"));
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
   YYFPRINTF (stderr, "\n");
@@ -634,7 +641,7 @@ do {								\
 {
   int yyi;
   unsigned int yylno = yyrline[yyrule];
-  YYFPRINTF (stderr, _("Reducing stack by rule %d (line %u), "),
+  YYFPRINTF (stderr, YYI18N ("Reducing stack by rule %d (line %u), "),
              yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
@@ -904,7 +911,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   data in use in that stack, in bytes.  This used to be a
 	   conditional around just the two extra args, but that might
 	   be undefined if yyoverflow is a macro.  */
-	yyoverflow (_("parser stack overflow"),
+	yyoverflow (YYI18N ("parser stack overflow"),
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
 ]b4_location_if([		    &yyls1, yysize * sizeof (*yylsp),])[
@@ -944,14 +951,14 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
       yyvsp = yyvs + yysize - 1;
 ]b4_location_if([      yylsp = yyls + yysize - 1;])[
 
-      YYDPRINTF ((stderr, _("Stack size increased to %lu\n"),
+      YYDPRINTF ((stderr, YYI18N ("Stack size increased to %lu\n"),
 		  (unsigned long int) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
 	YYABORT;
     }
 
-  YYDPRINTF ((stderr, _("Entering state %d\n"), yystate));
+  YYDPRINTF ((stderr, YYI18N ("Entering state %d\n"), yystate));
 
   goto yybackup;
 
@@ -975,19 +982,19 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, _("Reading a token: ")));
+      YYDPRINTF ((stderr, YYI18N ("Reading a token: ")));
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPRINTF ((stderr, _("Now at end of input.\n")));
+      YYDPRINTF ((stderr, YYI18N ("Now at end of input.\n")));
     }
   else
     {
       yytoken = YYTRANSLATE (yychar);
-      YY_SYMBOL_PRINT (_("Next token is"), yytoken, &yylval, &yylloc);
+      YY_SYMBOL_PRINT (YYI18N ("Next token is"), yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -1008,7 +1015,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the look-ahead token.  */
-  YY_SYMBOL_PRINT (_("Shifting"), yytoken, &yylval, &yylloc);
+  YY_SYMBOL_PRINT (YYI18N ("Shifting"), yytoken, &yylval, &yylloc);
 
   /* Discard the token being shifted unless it is eof.  */
   if (yychar != YYEOF)
@@ -1116,11 +1123,11 @@ yyerrlab:
 #if 0
 	  /* This is so xgettext sees the translatable formats that are
 	     constructed on the fly.  */
-	  _("syntax error, unexpected %s");
-	  _("syntax error, unexpected %s, expecting %s");
-	  _("syntax error, unexpected %s, expecting %s or %s");
-	  _("syntax error, unexpected %s, expecting %s or %s or %s");
-	  _("syntax error, unexpected %s, expecting %s or %s or %s or %s");
+	  YYI18N ("syntax error, unexpected %s");
+	  YYI18N ("syntax error, unexpected %s, expecting %s");
+	  YYI18N ("syntax error, unexpected %s, expecting %s or %s");
+	  YYI18N ("syntax error, unexpected %s, expecting %s or %s or %s");
+	  YYI18N ("syntax error, unexpected %s, expecting %s or %s or %s or %s");
 #endif
 	  char *yyfmt;
 	  char const *yyf;
@@ -1163,7 +1170,7 @@ yyerrlab:
 		yyprefix = yyor;
 	      }
 
-	  yyf = _(yyformat);
+	  yyf = YYI18N (yyformat);
 	  yysize1 = yysize + yystrlen (yyf);
 	  yysize_overflow |= yysize1 < yysize;
 	  yysize = yysize1;
@@ -1194,11 +1201,11 @@ yyerrlab:
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_yyerror_args[_("syntax error; also memory exhausted"));
+	    yyerror (]b4_yyerror_args[YYI18N ("syntax error; also memory exhausted"));
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror (]b4_yyerror_args[_("syntax error"));
+	yyerror (]b4_yyerror_args[YYI18N ("syntax error"));
     }
 
 ]b4_location_if([[  yyerror_range[0] = yylloc;]])[
@@ -1217,7 +1224,7 @@ yyerrlab:
         }
       else
 	{
-	  yydestruct (_("Error: discarding"), yytoken, &yylval]b4_location_if([, &yylloc])[);
+	  yydestruct (YYI18N ("Error: discarding"), yytoken, &yylval]b4_location_if([, &yylloc])[);
 	  yychar = YYEMPTY;
 	}
     }
@@ -1271,7 +1278,7 @@ yyerrlab1:
 	YYABORT;
 
 ]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
-      yydestruct (_("Error: popping"), yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
+      yydestruct (YYI18N ("Error: popping"), yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1289,7 +1296,7 @@ yyerrlab1:
   *++yylsp = yyloc;]])[
 
   /* Shift the error token. */
-  YY_SYMBOL_PRINT (_("Shifting"), yystos[yyn], yyvsp, yylsp);
+  YY_SYMBOL_PRINT (YYI18N ("Shifting"), yystos[yyn], yyvsp, yylsp);
 
   yystate = yyn;
   goto yynewstate;
@@ -1314,14 +1321,14 @@ yyabortlab:
 | yyoverflowlab -- parser overflow comes here.  |
 `----------------------------------------------*/
 yyoverflowlab:
-  yyerror (]b4_yyerror_args[_("parser stack overflow"));
+  yyerror (]b4_yyerror_args[YYI18N ("parser stack overflow"));
   yyresult = 2;
   /* Fall through.  */
 #endif
 
 yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
-     yydestruct (_("Error: discarding lookahead"),
+     yydestruct (YYI18N ("Error: discarding lookahead"),
 		 yytoken, &yylval]b4_location_if([, &yylloc])[);
   if (yyssp != yyss)
     for (;;)
@@ -1330,7 +1337,7 @@ yyreturn:
 	YYPOPSTACK;
 	if (yyssp == yyss)
 	  break;
-	yydestruct (_("Error: popping"),
+	yydestruct (YYI18N ("Error: popping"),
 		    yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
       }
 #ifndef yyoverflow
