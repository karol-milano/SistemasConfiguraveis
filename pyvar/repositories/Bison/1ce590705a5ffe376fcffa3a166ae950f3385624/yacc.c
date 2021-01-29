@@ -375,6 +375,11 @@ static const char *const yytname[] =
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
@@ -492,7 +497,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror (]b4_yyerror_args["syntax error: cannot back up");\
+      yyerror (]b4_yyerror_args[_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
 while (0)
@@ -586,7 +591,7 @@ do {								\
                    [[short int *bottom], [bottom]],
                    [[short int *top],    [top]])[
 {
-  YYFPRINTF (stderr, "Stack now");
+  YYFPRINTF (stderr, _("Stack now"));
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
   YYFPRINTF (stderr, "\n");
@@ -608,7 +613,7 @@ do {								\
 {
   int yyi;
   unsigned int yylno = yyrline[yyrule];
-  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
+  YYFPRINTF (stderr, _("Reducing stack by rule %d (line %u), "),
              yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
@@ -877,7 +882,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	   data in use in that stack, in bytes.  This used to be a
 	   conditional around just the two extra args, but that might
 	   be undefined if yyoverflow is a macro.  */
-	yyoverflow ("parser stack overflow",
+	yyoverflow (_("parser stack overflow"),
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
 ]b4_location_if([		    &yyls1, yysize * sizeof (*yylsp),])[
@@ -917,14 +922,14 @@ b4_syncline([@oline@], [@ofile@])])dnl
       yyvsp = yyvs + yysize - 1;
 ]b4_location_if([      yylsp = yyls + yysize - 1;])[
 
-      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
+      YYDPRINTF ((stderr, _("Stack size increased to %lu\n"),
 		  (unsigned long int) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
 	YYABORT;
     }
 
-  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
+  YYDPRINTF ((stderr, _("Entering state %d\n"), yystate));
 
   goto yybackup;
 
@@ -948,19 +953,19 @@ yybackup:
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
@@ -981,7 +986,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the look-ahead token.  */
-  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
+  YY_SYMBOL_PRINT (_("Shifting"), yytoken, &yylval, &yylloc);
 
   /* Discard the token being shifted unless it is eof.  */
   if (yychar != YYEOF)
@@ -1091,7 +1096,7 @@ yyerrlab:
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
 	  int yycount = 0;
 
-	  yyprefix = ", expecting ";
+	  yyprefix = _(", expecting ");
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      {
@@ -1103,34 +1108,34 @@ yyerrlab:
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
 	      yyerror (]b4_yyerror_args[yymsg);
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_yyerror_args["syntax error; also virtual memory exhausted");
+	    yyerror (]b4_yyerror_args[_("syntax error; also virtual memory exhausted"));
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror (]b4_yyerror_args["syntax error");
+	yyerror (]b4_yyerror_args[_("syntax error"));
     }
 
 ]b4_location_if([[  yyerror_range[0] = yylloc;]])[
@@ -1151,13 +1156,13 @@ yyerrlab:
 		 YYPOPSTACK;
 		 if (yyssp == yyss)
 		   YYABORT;
-		 yydestruct ("Error: popping",
+		 yydestruct (_("Error: popping"),
                              yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
 	       }
         }
       else
 	{
-	  yydestruct ("Error: discarding", yytoken, &yylval]b4_location_if([, &yylloc])[);
+	  yydestruct (_("Error: discarding"), yytoken, &yylval]b4_location_if([, &yylloc])[);
 	  yychar = YYEMPTY;
 	}
     }
@@ -1211,7 +1216,7 @@ yyerrlab1:
 	YYABORT;
 
 ]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
-      yydestruct ("Error: popping", yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
+      yydestruct (_("Error: popping"), yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1229,7 +1234,7 @@ yyerrlab1:
   *++yylsp = yyloc;]])[
 
   /* Shift the error token. */
-  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
+  YY_SYMBOL_PRINT (_("Shifting"), yystos[yyn], yyvsp, yylsp);
 
   yystate = yyn;
   goto yynewstate;
@@ -1246,7 +1251,7 @@ yyacceptlab:
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
 yyabortlab:
-  yydestruct ("Error: discarding lookahead",
+  yydestruct (_("Error: discarding lookahead"),
               yytoken, &yylval]b4_location_if([, &yylloc])[);
   yychar = YYEMPTY;
   yyresult = 1;
@@ -1257,7 +1262,7 @@ yyabortlab:
 | yyoverflowlab -- parser overflow comes here.  |
 `----------------------------------------------*/
 yyoverflowlab:
-  yyerror (]b4_yyerror_args["parser stack overflow");
+  yyerror (]b4_yyerror_args[_("parser stack overflow"));
   yyresult = 2;
   /* Fall through.  */
 #endif
