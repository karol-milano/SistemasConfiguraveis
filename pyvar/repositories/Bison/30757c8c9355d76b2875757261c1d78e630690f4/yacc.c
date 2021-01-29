@@ -228,6 +228,18 @@ b4_syncline([@oline@], [@ofile@])[
 # define YYSIZE_T unsigned int
 #endif
 
+#ifndef YY_
+# if YYENABLE_NLS
+#  if ENABLE_NLS
+#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
+#   define YY_(msgid) dgettext ("bison-runtime", msgid)
+#  endif
+# endif
+# ifndef YY_
+#  define YY_(msgid) msgid
+# endif
+#endif
+
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
@@ -412,18 +424,6 @@ static const char *const yytname[] =
 };
 #endif
 
-#ifndef YYI18N
-# if YYENABLE_NLS
-#  if ENABLE_NLS
-#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
-#   define YYI18N(msgid) dgettext ("bison-runtime", msgid)
-#  endif
-# endif
-# ifndef YYI18N
-#  define YYI18N(msgid) msgid
-# endif
-#endif
-
 # ifdef YYPRINT
 /* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
@@ -525,7 +525,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror (]b4_yyerror_args[YYI18N ("syntax error: cannot back up")); \
+      yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
 while (0)
@@ -619,7 +619,7 @@ do {								\
                    [[short int *bottom], [bottom]],
                    [[short int *top],    [top]])[
 {
-  YYFPRINTF (stderr, YYI18N ("Stack now"));
+  YYFPRINTF (stderr, "Stack now");
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
   YYFPRINTF (stderr, "\n");
@@ -640,8 +640,8 @@ do {								\
                    [[int yyrule], [yyrule]])[
 {
   int yyi;
-  unsigned int yylno = yyrline[yyrule];
-  YYFPRINTF (stderr, YYI18N ("Reducing stack by rule %d (line %u), "),
+  unsigned long int yylno = yyrline[yyrule];
+  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
              yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
@@ -911,7 +911,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   data in use in that stack, in bytes.  This used to be a
 	   conditional around just the two extra args, but that might
 	   be undefined if yyoverflow is a macro.  */
-	yyoverflow (YYI18N ("parser stack overflow"),
+	yyoverflow (YY_("parser stack overflow"),
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
 ]b4_location_if([		    &yyls1, yysize * sizeof (*yylsp),])[
@@ -951,14 +951,14 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
       yyvsp = yyvs + yysize - 1;
 ]b4_location_if([      yylsp = yyls + yysize - 1;])[
 
-      YYDPRINTF ((stderr, YYI18N ("Stack size increased to %lu\n"),
+      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
 	YYABORT;
     }
 
-  YYDPRINTF ((stderr, YYI18N ("Entering state %d\n"), yystate));
+  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 
   goto yybackup;
 
@@ -982,19 +982,19 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, YYI18N ("Reading a token: ")));
+      YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPRINTF ((stderr, YYI18N ("Now at end of input.\n")));
+      YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
       yytoken = YYTRANSLATE (yychar);
-      YY_SYMBOL_PRINT (YYI18N ("Next token is"), yytoken, &yylval, &yylloc);
+      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -1015,7 +1015,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the look-ahead token.  */
-  YY_SYMBOL_PRINT (YYI18N ("Shifting"), yytoken, &yylval, &yylloc);
+  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the token being shifted unless it is eof.  */
   if (yychar != YYEOF)
@@ -1123,11 +1123,11 @@ yyerrlab:
 #if 0
 	  /* This is so xgettext sees the translatable formats that are
 	     constructed on the fly.  */
-	  YYI18N ("syntax error, unexpected %s");
-	  YYI18N ("syntax error, unexpected %s, expecting %s");
-	  YYI18N ("syntax error, unexpected %s, expecting %s or %s");
-	  YYI18N ("syntax error, unexpected %s, expecting %s or %s or %s");
-	  YYI18N ("syntax error, unexpected %s, expecting %s or %s or %s or %s");
+	  YY_("syntax error, unexpected %s");
+	  YY_("syntax error, unexpected %s, expecting %s");
+	  YY_("syntax error, unexpected %s, expecting %s or %s");
+	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
+	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
 #endif
 	  char *yyfmt;
 	  char const *yyf;
@@ -1170,7 +1170,7 @@ yyerrlab:
 		yyprefix = yyor;
 	      }
 
-	  yyf = YYI18N (yyformat);
+	  yyf = YY_(yyformat);
 	  yysize1 = yysize + yystrlen (yyf);
 	  yysize_overflow |= yysize1 < yysize;
 	  yysize = yysize1;
@@ -1201,11 +1201,11 @@ yyerrlab:
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_yyerror_args[YYI18N ("syntax error; also memory exhausted"));
+	    yyerror (]b4_yyerror_args[YY_("syntax error; also memory exhausted"));
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror (]b4_yyerror_args[YYI18N ("syntax error"));
+	yyerror (]b4_yyerror_args[YY_("syntax error"));
     }
 
 ]b4_location_if([[  yyerror_range[0] = yylloc;]])[
@@ -1224,7 +1224,7 @@ yyerrlab:
         }
       else
 	{
-	  yydestruct (YYI18N ("Error: discarding"), yytoken, &yylval]b4_location_if([, &yylloc])[);
+	  yydestruct ("Error: discarding", yytoken, &yylval]b4_location_if([, &yylloc])[);
 	  yychar = YYEMPTY;
 	}
     }
@@ -1278,7 +1278,7 @@ yyerrlab1:
 	YYABORT;
 
 ]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
-      yydestruct (YYI18N ("Error: popping"), yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
+      yydestruct ("Error: popping", yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1296,7 +1296,7 @@ yyerrlab1:
   *++yylsp = yyloc;]])[
 
   /* Shift the error token. */
-  YY_SYMBOL_PRINT (YYI18N ("Shifting"), yystos[yyn], yyvsp, yylsp);
+  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
 
   yystate = yyn;
   goto yynewstate;
@@ -1321,14 +1321,14 @@ yyabortlab:
 | yyoverflowlab -- parser overflow comes here.  |
 `----------------------------------------------*/
 yyoverflowlab:
-  yyerror (]b4_yyerror_args[YYI18N ("parser stack overflow"));
+  yyerror (]b4_yyerror_args[YY_("parser stack overflow"));
   yyresult = 2;
   /* Fall through.  */
 #endif
 
 yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
-     yydestruct (YYI18N ("Error: discarding lookahead"),
+     yydestruct ("Error: discarding lookahead",
 		 yytoken, &yylval]b4_location_if([, &yylloc])[);
   if (yyssp != yyss)
     for (;;)
@@ -1337,7 +1337,7 @@ yyreturn:
 	YYPOPSTACK;
 	if (yyssp == yyss)
 	  break;
-	yydestruct (YYI18N ("Error: popping"),
+	yydestruct ("Error: popping",
 		    yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
       }
 #ifndef yyoverflow
