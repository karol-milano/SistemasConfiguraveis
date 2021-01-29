@@ -620,42 +620,8 @@ yystpcpy (yydest, yysrc)
 
 
 #if YYDEBUG
-/*-----------------------------.
-| Print this symbol on YYOUT.  |
-`-----------------------------*/
-
-b4_c_function_def([yysymprint],
-  	          [static void],
-	          [[FILE *yyout],        [yyout]],
-	          [[int yytype],         [yytype]],
-	          [[YYSTYPE yyvalue],    [yyvalue]]b4_location_if([,
-	          [[YYLTYPE yylocation], [yylocation]]]))
-{
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yyvalue;
-b4_location_if([  (void) yylocation;
-])dnl
-
-  if (yytype < YYNTOKENS)
-    {
-      YYFPRINTF (yyout, "token %s (", yytname[[yytype]]);
-# ifdef YYPRINT
-      YYPRINT (yyout, yytoknum[[yytype]], yyvalue);
-# endif
-    }
-  else
-    YYFPRINTF (yyout, "nterm %s (", yytname[[yytype]]);
-
-  switch (yytype)
-    {
-m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
-      default:
-        break;
-    }
-  YYFPRINTF (yyout, ")");
-}
+b4_yysymprint_generate([b4_c_function_def])
 #endif /* YYDEBUG. */
-
 b4_yydestruct_generate([b4_c_function_def])
 
 
@@ -888,7 +854,7 @@ yybackup:
       /* We have to keep this `#if YYDEBUG', since we use variables
 	 which are defined only if `YYDEBUG' is set.  */
       YYDPRINTF ((stderr, "Next token is "));
-      YYDSYMPRINT ((stderr, yytoken, yylval]b4_location_if([, yyloc])[));
+      YYDSYMPRINT ((stderr, yytoken, &yylval]b4_location_if([, &yyloc])[));
       YYDPRINTF ((stderr, "\n"));
     }
 
@@ -1097,9 +1063,9 @@ yyerrlab1:
 	      YYDPRINTF ((stderr, "Error: popping "));
 	      YYDSYMPRINT ((stderr,
 			    yystos[*yyssp],
-			    *yyvsp]b4_location_if([, *yylsp])[));
+			    yyvsp]b4_location_if([, yylsp])[));
 	      YYDPRINTF ((stderr, "\n"));
-	      yydestruct (yystos[*yyssp], *yyvsp]b4_location_if([, *yylsp])[);
+	      yydestruct (yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
 	      YYPOPSTACK;
 	    }
 	  YYABORT;
@@ -1107,7 +1073,7 @@ yyerrlab1:
 
       YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
 		  yytoken, yytname[yytoken]));
-      yydestruct (yytoken, yylval]b4_location_if([, yylloc])[);
+      yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
       yytoken = YYEMPTY;
     }
 
@@ -1136,10 +1102,10 @@ yyerrlab1:
 
       YYDPRINTF ((stderr, "Error: popping "));
       YYDSYMPRINT ((stderr,
-		    yystos[*yyssp], *yyvsp]b4_location_if([, *yylsp])[));
+		    yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[));
       YYDPRINTF ((stderr, "\n"));
 
-      yydestruct (yystos[yystate], *yyvsp]b4_location_if([, *yylsp])[);
+      yydestruct (yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       yyvsp--;
       yystate = *--yyssp;
 ]b4_location_if([      yylsp--;])[
