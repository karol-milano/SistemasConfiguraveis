@@ -1456,15 +1456,15 @@ yyparse ()
 #endif
 #endif
 {
-  /* The look-ahead symbol.  */
+  /* The lookahead symbol.  */
 int yychar;
 
-/* The semantic value of the look-ahead symbol.  */
+/* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 int yynerrs;
-/* Location data for the look-ahead symbol.  */
+/* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;
 
   int yystate;
@@ -1472,7 +1472,7 @@ YYLTYPE yylloc;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
-  /* Look-ahead token as an internal (translated) token number.  */
+  /* Lookahead token as an internal (translated) token number.  */
   int yytoken = 0;
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
@@ -1640,16 +1640,16 @@ YYLTYPE yylloc;
 yybackup:
 
   /* Do appropriate processing given the current state.  Read a
-     look-ahead token if we need one and don't already have one.  */
+     lookahead token if we need one and don't already have one.  */
 
-  /* First try to decide what to do without reference to look-ahead token.  */
+  /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
 
-  /* Not known => get a look-ahead token if don't already have one.  */
+  /* Not known => get a lookahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1689,7 +1689,7 @@ yybackup:
   if (yyerrstatus)
     yyerrstatus--;
 
-  /* Shift the look-ahead token.  */
+  /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the shifted token unless it is eof.  */
@@ -2216,7 +2216,7 @@ yyerrlab:
 
   if (yyerrstatus == 3)
     {
-      /* If just tried and failed to reuse look-ahead token after an
+      /* If just tried and failed to reuse lookahead token after an
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
@@ -2233,7 +2233,7 @@ yyerrlab:
 	}
     }
 
-  /* Else will try to reuse look-ahead token after shifting the error
+  /* Else will try to reuse lookahead token after shifting the error
      token.  */
   goto yyerrlab1;
 
@@ -2298,7 +2298,7 @@ yyerrlab1:
 
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the look-ahead.  YYLOC is available though.  */
+     the lookahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;
 
