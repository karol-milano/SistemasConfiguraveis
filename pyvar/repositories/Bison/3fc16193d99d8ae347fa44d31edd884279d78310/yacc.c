@@ -501,11 +501,12 @@ do								\
     }								\
 while (0)
 
+
 #define YYTERROR	1
 #define YYERRCODE	256
 
-/* YYLLOC_DEFAULT -- Compute the default location (before the actions
-   are run).  */
+
+/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].  */
 
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(Current, Rhs, N)		\
@@ -513,8 +514,22 @@ while (0)
     (Current).first_column = (Rhs)[1].first_column,	\
     (Current).last_line    = (Rhs)[N].last_line,	\
     (Current).last_column  = (Rhs)[N].last_column)
+
+/* YY_LOCATION_PRINT -- Print the location on the stream.
+   This macro was not mandated originally: define only if we know
+   we won't break user code: when these are the locations we know.  */
+
+# define YY_LOCATION_PRINT(File, Loc)			\
+    fprintf (File, "%d.%d-%d.%d",			\
+             (Loc).first_line, (Loc).first_column,	\
+             (Loc).last_line,  (Loc).last_column)
+#endif
+
+#ifndef YY_LOCATION_PRINT
+# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 #endif
 
+
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
 #ifdef YYLEX_PARAM
@@ -770,7 +785,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
   YYLTYPE *yylsp;
-  YYLTYPE *yylerrsp;]])[
+  /* The locations where the error started and ended. */
+  YYLTYPE yyerror_range[2];]])[
 
 #define YYPOPSTACK   (yyvsp--, yyssp--]b4_location_if([, yylsp--])[)
 
@@ -1097,7 +1113,7 @@ yyerrlab:
 	yyerror (]b4_yyerror_args["syntax error");
     }
 
-]b4_location_if([  yylerrsp = yylsp;])[
+]b4_location_if([[  yyerror_range[0] = yylloc;]])[
 
   if (yyerrstatus == 3)
     {
@@ -1111,6 +1127,7 @@ yyerrlab:
 	  if (yychar == YYEOF)
 	     for (;;)
 	       {
+]b4_location_if([[                 yyerror_range[0] = *yylsp;]])[
 		 YYPOPSTACK;
 		 if (yyssp == yyss)
 		   YYABORT;
@@ -1122,7 +1139,6 @@ yyerrlab:
 	{
 	  yydestruct ("Error: discarding", yytoken, &yylval]b4_location_if([, &yylloc])[);
 	  yychar = YYEMPTY;
-]b4_location_if([	  *++yylerrsp = yylloc;])[
 	}
     }
 
@@ -1143,13 +1159,12 @@ yyerrorlab:
      goto yyerrorlab;
 #endif
 
-  yyvsp -= yylen;
+]b4_location_if([[  yyerror_range[0] = yylsp[1-yylen];
+  yylsp -= yylen;
+  ]])[yyvsp -= yylen;
   yyssp -= yylen;
   yystate = *yyssp;
-  ]b4_location_if([yylerrsp = yylsp;
-  *++yylerrsp = yyloc;
-  yylsp -= yylen;
-  ])[goto yyerrlab1;
+  goto yyerrlab1;
 
 
 /*-------------------------------------------------------------.
@@ -1176,6 +1191,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
+]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
       yydestruct ("Error: popping", yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       YYPOPSTACK;
       yystate = *yyssp;
@@ -1186,8 +1202,12 @@ yyerrlab1:
     YYACCEPT;
 
   *++yyvsp = yylval;
-]b4_location_if([  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
-  *++yylsp = yyloc;])[
+]b4_location_if([[
+  yyerror_range[1] = yylloc;
+  /* Using YYLLOC is tempting, but would change the location of
+     the look-ahead.  YYLOC is available though. */
+  YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
+  *++yylsp = yyloc;]])[
 
   /* Shift the error token. */
   YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
