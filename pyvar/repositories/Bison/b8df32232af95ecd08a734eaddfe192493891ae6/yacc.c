@@ -631,14 +631,154 @@ int yyparse (void);
 # endif
 #endif
 
+
+#if YYDEBUG
+/*-----------------------------.
+| Print this symbol on YYOUT.  |
+`-----------------------------*/
+
+static void
 #if defined (__STDC__) || defined (__cplusplus)
-static void yydestruct (int yytype,
-			YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]));
-# if YYDEBUG
-static void yysymprint (FILE* out, int yytype,
-			YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]));
+yysymprint (FILE* yyout, int yytype,
+	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
+#else
+yysymprint (yyout, yytype,
+	    yyvalue[]b4_location_if([, yylocation]))
+  FILE* yyout;
+  int yytype;
+  YYSTYPE yyvalue;
+  b4_location_if([YYLTYPE yylocation;])
+#endif
+{
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+b4_location_if([  (void) yylocation;
+])dnl
+
+  if (yytype < YYNTOKENS)
+    {
+      YYFPRINTF (yyout, "token %s (", yytname[[yytype]]);
+# ifdef YYPRINT
+      YYPRINT (yyout, yytoknum[[yytype]], yyvalue);
 # endif
+    }
+  else
+    YYFPRINTF (yyout, "nterm %s (", yytname[[yytype]]);
+
+  switch (yytype)
+    {
+m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
+      default:
+        break;
+    }
+  YYFPRINTF (yyout, ")");
+}
+#endif /* YYDEBUG. */
+
+
+/*----------------------------------------------------------.
+| yyreport_parse_error -- report a parse error in YYSTATE.  |
+`----------------------------------------------------------*/
+
+static void
+#if defined (__STDC__) || defined (__cplusplus)
+yyreport_parse_error (int yystate, int yychar,
+		      YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
+#else
+yyreport_parse_error (yystate, yychar,
+		      yyvalue[]b4_location_if([, yylocation]))
+  int yystate;
+  int yychar;
+  YYSTYPE yyvalue;
+  b4_location_if([YYLTYPE yylocation;])
 #endif
+[{
+#if YYERROR_VERBOSE
+  int yyn = yypact[yystate];
+
+  if (YYPACT_NINF < yyn && yyn < YYLAST)
+    {
+      YYSIZE_T yysize = 0;
+      int yytype = YYTRANSLATE (yychar);
+      char *yymsg;
+      int yyx, yycount;
+
+      yycount = 0;
+      /* Start YYX at -YYN if negative to avoid negative indexes in
+	 YYCHECK.  */
+      for (yyx = yyn < 0 ? -yyn : 0;
+	   yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
+	if (yycheck[yyx + yyn] == yyx)
+	  yysize += yystrlen (yytname[yyx]) + 15, yycount++;
+      yysize += yystrlen ("parse error, unexpected ") + 1;
+      yysize += yystrlen (yytname[yytype]);
+      yymsg = (char *) YYSTACK_ALLOC (yysize);
+      if (yymsg != 0)
+	{
+	  char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
+	  yyp = yystpcpy (yyp, yytname[yytype]);
+
+	  if (yycount < 5)
+	    {
+	      yycount = 0;
+	      for (yyx = yyn < 0 ? -yyn : 0;
+		   yyx < (int) (sizeof (yytname) / sizeof (char *));
+		   yyx++)
+		if (yycheck[yyx + yyn] == yyx)
+		  {
+		    const char *yyq = ! yycount ? ", expecting " : " or ";
+		    yyp = yystpcpy (yyp, yyq);
+		    yyp = yystpcpy (yyp, yytname[yyx]);
+		    yycount++;
+		  }
+	    }
+	  yyerror (yymsg);
+	  YYSTACK_FREE (yymsg);
+	}
+      else
+	yyerror ("parse error; also virtual memory exhausted");
+    }
+  else
+#endif /* YYERROR_VERBOSE */
+    yyerror ("parse error");
+
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yystate;
+  (void) yychar;
+  (void) yyvalue;
+  ]b4_location_if([(void) yylocation;])[
+}]
+
+
+/*-----------------------------------------------.
+| Release the memory associated to this symbol.  |
+`-----------------------------------------------*/
+
+static void
+#if defined (__STDC__) || defined (__cplusplus)
+yydestruct (int yytype,
+	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
+#else
+yydestruct (yytype,
+	    yyvalue[]b4_location_if([, yylocation]))
+  int yytype;
+  YYSTYPE yyvalue;
+  b4_location_if([YYLTYPE yylocation;])
+#endif
+{
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+b4_location_if([  (void) yylocation;
+])dnl
+
+  switch (yytype)
+    {
+m4_map([b4_symbol_actions], m4_defn([b4_symbol_destructors]))dnl
+      default:
+        break;
+    }
+}
+
 
 m4_divert_push([KILL])# ======================== M4 code.
 # b4_declare_parser_variables
@@ -998,54 +1138,7 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-
-#if YYERROR_VERBOSE
-      yyn = yypact[yystate];
-
-      if (YYPACT_NINF < yyn && yyn < YYLAST)
-	{
-	  YYSIZE_T yysize = 0;
-	  char *yymsg;
-	  int yyx, yycount;
-
-	  yycount = 0;
-	  /* Start YYX at -YYN if negative to avoid negative indexes in
-	     YYCHECK.  */
-	  for (yyx = yyn < 0 ? -yyn : 0;
-	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
-	    if (yycheck[yyx + yyn] == yyx)
-	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
-	  yysize += yystrlen ("parse error, unexpected ") + 1;
-	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
-	  yymsg = (char *) YYSTACK_ALLOC (yysize);
-	  if (yymsg != 0)
-	    {
-	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
-	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);
-
-	      if (yycount < 5)
-		{
-		  yycount = 0;
-		  for (yyx = yyn < 0 ? -yyn : 0;
-		       yyx < (int) (sizeof (yytname) / sizeof (char *));
-		       yyx++)
-		    if (yycheck[yyx + yyn] == yyx)
-		      {
-			const char *yyq = ! yycount ? ", expecting " : " or ";
-			yyp = yystpcpy (yyp, yyq);
-			yyp = yystpcpy (yyp, yytname[yyx]);
-			yycount++;
-		      }
-		}
-	      yyerror (yymsg);
-	      YYSTACK_FREE (yymsg);
-  	    }
-  	  else
-  	    yyerror ("parse error; also virtual memory exhausted");
-        }
-      else
-#endif /* YYERROR_VERBOSE */
-        yyerror ("parse error");
+      yyreport_parse_error (yystate, yychar, yylval]b4_location_if([, yylloc])[);
     }
   goto yyerrlab1;
 
@@ -1174,62 +1267,6 @@ yyreturn:
 ]}
 
 
-/*-----------------------------------------------.
-| Release the memory associated to this symbol.  |
-`-----------------------------------------------*/
-
-static void
-yydestruct (int yytype,
-	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
-{
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yyvalue;
-b4_location_if([  (void) yylocation;
-])dnl
-
-  switch (yytype)
-    {
-m4_map([b4_symbol_actions], m4_defn([b4_symbol_destructors]))dnl
-      default:
-        break;
-    }
-}
-
-
-#if YYDEBUG
-/*-----------------------------.
-| Print this symbol on YYOUT.  |
-`-----------------------------*/
-
-static void
-yysymprint (FILE* yyout, int yytype,
-	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
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
-#endif /* YYDEBUG. */
-
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [#output "b4_output_header_name"
