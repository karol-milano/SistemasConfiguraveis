@@ -515,6 +515,11 @@ static const char *const yytname[] =
 };
 #endif
 
+/* INFRINGES ON USER NAME SPACE */
+#ifndef _
+# define _(msgid) msgid
+#endif
+
 # ifdef YYPRINT
 /* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
@@ -715,7 +720,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror ("syntax error: cannot back up");\
+      yyerror (_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
 while (0)
@@ -815,7 +820,7 @@ yy_stack_print (bottom, top)
     short int *top;
 #endif
 {
-  YYFPRINTF (stderr, "Stack now");
+  YYFPRINTF (stderr, _("Stack now"));
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
   YYFPRINTF (stderr, "\n");
@@ -843,7 +848,7 @@ yy_reduce_print (yyrule)
 {
   int yyi;
   unsigned int yylno = yyrline[yyrule];
-  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
+  YYFPRINTF (stderr, _("Reducing stack by rule %d (line %u), "),
              yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
@@ -1147,8 +1152,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 843 of yacc.c.  */
-#line 1152 "parse-gram.c"
+/* Line 848 of yacc.c.  */
+#line 1157 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1184,7 +1189,7 @@ YYLTYPE yylloc;
 	   data in use in that stack, in bytes.  This used to be a
 	   conditional around just the two extra args, but that might
 	   be undefined if yyoverflow is a macro.  */
-	yyoverflow ("parser stack overflow",
+	yyoverflow (_("parser stack overflow"),
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
 		    &yyls1, yysize * sizeof (*yylsp),
@@ -1224,14 +1229,14 @@ YYLTYPE yylloc;
       yyvsp = yyvs + yysize - 1;
       yylsp = yyls + yysize - 1;
 
-      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
+      YYDPRINTF ((stderr, _("Stack size increased to %lu\n"),
 		  (unsigned long int) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
 	YYABORT;
     }
 
-  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
+  YYDPRINTF ((stderr, _("Entering state %d\n"), yystate));
 
   goto yybackup;
 
@@ -1255,19 +1260,19 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, "Reading a token: "));
+      YYDPRINTF ((stderr, _("Reading a token: ")));
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPRINTF ((stderr, "Now at end of input.\n"));
+      YYDPRINTF ((stderr, _("Now at end of input.\n")));
     }
   else
     {
       yytoken = YYTRANSLATE (yychar);
-      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+      YY_SYMBOL_PRINT (_("Next token is"), yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -1288,7 +1293,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the look-ahead token.  */
-  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
+  YY_SYMBOL_PRINT (_("Shifting"), yytoken, &yylval, &yylloc);
 
   /* Discard the token being shifted unless it is eof.  */
   if (yychar != YYEOF)
@@ -1735,8 +1740,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1039 of yacc.c.  */
-#line 1740 "parse-gram.c"
+/* Line 1044 of yacc.c.  */
+#line 1745 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1790,7 +1795,7 @@ yyerrlab:
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
 	  int yycount = 0;
 
-	  yyprefix = ", expecting ";
+	  yyprefix = _(", expecting ");
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      {
@@ -1802,34 +1807,34 @@ yyerrlab:
 		    break;
 		  }
 	      }
-	  yysize += (sizeof ("syntax error, unexpected ")
-		     + yystrlen (yytname[yytype]));
+	  yysize += (strlen (_("syntax error, unexpected "))
+		     + yystrlen (yytname[yytype]) + 1);
 	  yymsg = (char *) YYSTACK_ALLOC (yysize);
 	  if (yymsg != 0)
 	    {
-	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
+	      char *yyp = yystpcpy (yymsg, _("syntax error, unexpected "));
 	      yyp = yystpcpy (yyp, yytname[yytype]);
 
 	      if (yycount < 5)
 		{
-		  yyprefix = ", expecting ";
+		  yyprefix = _(", expecting ");
 		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 		      {
 			yyp = yystpcpy (yyp, yyprefix);
 			yyp = yystpcpy (yyp, yytname[yyx]);
-			yyprefix = " or ";
+			yyprefix = _(" or ");
 		      }
 		}
 	      yyerror (yymsg);
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror ("syntax error; also virtual memory exhausted");
+	    yyerror (_("syntax error; also virtual memory exhausted"));
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror ("syntax error");
+	yyerror (_("syntax error"));
     }
 
   yyerror_range[0] = yylloc;
@@ -1850,13 +1855,13 @@ yyerrlab:
 		 YYPOPSTACK;
 		 if (yyssp == yyss)
 		   YYABORT;
-		 yydestruct ("Error: popping",
+		 yydestruct (_("Error: popping"),
                              yystos[*yyssp], yyvsp, yylsp);
 	       }
         }
       else
 	{
-	  yydestruct ("Error: discarding", yytoken, &yylval, &yylloc);
+	  yydestruct (_("Error: discarding"), yytoken, &yylval, &yylloc);
 	  yychar = YYEMPTY;
 	}
     }
@@ -1910,7 +1915,7 @@ yyerrlab1:
 	YYABORT;
 
       yyerror_range[0] = *yylsp;
-      yydestruct ("Error: popping", yystos[yystate], yyvsp, yylsp);
+      yydestruct (_("Error: popping"), yystos[yystate], yyvsp, yylsp);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1928,7 +1933,7 @@ yyerrlab1:
   *++yylsp = yyloc;
 
   /* Shift the error token. */
-  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
+  YY_SYMBOL_PRINT (_("Shifting"), yystos[yyn], yyvsp, yylsp);
 
   yystate = yyn;
   goto yynewstate;
@@ -1945,7 +1950,7 @@ yyacceptlab:
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
 yyabortlab:
-  yydestruct ("Error: discarding lookahead",
+  yydestruct (_("Error: discarding lookahead"),
               yytoken, &yylval, &yylloc);
   yychar = YYEMPTY;
   yyresult = 1;
@@ -1956,7 +1961,7 @@ yyabortlab:
 | yyoverflowlab -- parser overflow comes here.  |
 `----------------------------------------------*/
 yyoverflowlab:
-  yyerror ("parser stack overflow");
+  yyerror (_("parser stack overflow"));
   yyresult = 2;
   /* Fall through.  */
 #endif
