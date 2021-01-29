@@ -648,74 +648,6 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
 #endif /* YYDEBUG. */
 
 
-/*----------------------------------------------------------.
-| yyreport_parse_error -- report a parse error in YYSTATE.  |
-`----------------------------------------------------------*/
-
-b4_c_function([yyreport_parse_error],
-	      [static void],
-	      [[int],     [yystate]],
-	      [[int],     [yychar]],
-	      [[YYSTYPE], [yyvalue]]b4_location_if([,
-	      [[YYLTYPE], [yylloc]]]))
-[{
-#if YYERROR_VERBOSE
-  int yyn = yypact[yystate];
-
-  if (YYPACT_NINF < yyn && yyn < YYLAST)
-    {
-      YYSIZE_T yysize = 0;
-      int yytype = YYTRANSLATE (yychar);
-      char *yymsg;
-      int yyx, yycount;
-
-      yycount = 0;
-      /* Start YYX at -YYN if negative to avoid negative indexes in
-	 YYCHECK.  */
-      for (yyx = yyn < 0 ? -yyn : 0;
-	   yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-	  yysize += yystrlen (yytname[yyx]) + 15, yycount++;
-      yysize += yystrlen ("parse error, unexpected ") + 1;
-      yysize += yystrlen (yytname[yytype]);
-      yymsg = (char *) YYSTACK_ALLOC (yysize);
-      if (yymsg != 0)
-	{
-	  char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
-	  yyp = yystpcpy (yyp, yytname[yytype]);
-
-	  if (yycount < 5)
-	    {
-	      yycount = 0;
-	      for (yyx = yyn < 0 ? -yyn : 0;
-		   yyx < (int) (sizeof (yytname) / sizeof (char *));
-		   yyx++)
-		if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-		  {
-		    const char *yyq = ! yycount ? ", expecting " : " or ";
-		    yyp = yystpcpy (yyp, yyq);
-		    yyp = yystpcpy (yyp, yytname[yyx]);
-		    yycount++;
-		  }
-	    }
-	  yyerror (yymsg);
-	  YYSTACK_FREE (yymsg);
-	}
-      else
-	yyerror ("parse error; also virtual memory exhausted");
-    }
-  else
-#endif /* YYERROR_VERBOSE */
-    yyerror ("parse error");
-
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yystate;
-  (void) yychar;
-  (void) yyvalue;
-  ]b4_location_if([(void) yylloc;])[
-}]
-
-
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
@@ -1127,7 +1059,54 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-      yyreport_parse_error (yystate, yychar, yylval]b4_location_if([, yylloc])[);
+#if YYERROR_VERBOSE
+      yyn = yypact[yystate];
+
+      if (YYPACT_NINF < yyn && yyn < YYLAST)
+	{
+	  YYSIZE_T yysize = 0;
+	  int yytype = YYTRANSLATE (yychar);
+	  char *yymsg;
+	  int yyx, yycount;
+
+	  yycount = 0;
+	  /* Start YYX at -YYN if negative to avoid negative indexes in
+	     YYCHECK.  */
+	  for (yyx = yyn < 0 ? -yyn : 0;
+	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
+	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
+	  yysize += yystrlen ("parse error, unexpected ") + 1;
+	  yysize += yystrlen (yytname[yytype]);
+	  yymsg = (char *) YYSTACK_ALLOC (yysize);
+	  if (yymsg != 0)
+	    {
+	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
+	      yyp = yystpcpy (yyp, yytname[yytype]);
+
+	      if (yycount < 5)
+		{
+		  yycount = 0;
+		  for (yyx = yyn < 0 ? -yyn : 0;
+		       yyx < (int) (sizeof (yytname) / sizeof (char *));
+		       yyx++)
+		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+		      {
+			const char *yyq = ! yycount ? ", expecting " : " or ";
+			yyp = yystpcpy (yyp, yyq);
+			yyp = yystpcpy (yyp, yytname[yyx]);
+			yycount++;
+		      }
+		}
+	      yyerror (yymsg);
+	      YYSTACK_FREE (yymsg);
+	    }
+	  else
+	    yyerror ("parse error; also virtual memory exhausted");
+	}
+      else
+#endif /* YYERROR_VERBOSE */
+	yyerror ("parse error");
     }
   goto yyerrlab1;
 
