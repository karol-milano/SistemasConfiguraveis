@@ -1032,15 +1032,15 @@ yyparse ()
 #endif
 #endif
 {
-  /* The lookahead symbol.  */
+  /* The look-ahead symbol.  */
 int yychar;
 
-/* The semantic value of the lookahead symbol.  */
+/* The semantic value of the look-ahead symbol.  */
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 int yynerrs;
-/* Location data for the lookahead symbol.  */
+/* Location data for the look-ahead symbol.  */
 YYLTYPE yylloc;
 
   register int yystate;
@@ -1048,7 +1048,7 @@ YYLTYPE yylloc;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
-  /* Lookahead token as an internal (translated) token number.  */
+  /* Look-ahead token as an internal (translated) token number.  */
   int yytoken = 0;
 
   /* Three stacks and their tools:
@@ -1204,18 +1204,18 @@ YYLTYPE yylloc;
 yybackup:
 
 /* Do appropriate processing given the current state.  */
-/* Read a lookahead token if we need one and don't already have one.  */
+/* Read a look-ahead token if we need one and don't already have one.  */
 /* yyresume: */
 
-  /* First try to decide what to do without reference to lookahead token.  */
+  /* First try to decide what to do without reference to look-ahead token.  */
 
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
 
-  /* Not known => get a lookahead token if don't already have one.  */
+  /* Not known => get a look-ahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1250,7 +1250,7 @@ yybackup:
   if (yyn == YYFINAL)
     YYACCEPT;
 
-  /* Shift the lookahead token.  */
+  /* Shift the look-ahead token.  */
   YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
 
   /* Discard the token being shifted unless it is eof.  */
@@ -1798,7 +1798,7 @@ yyerrlab:
 
   if (yyerrstatus == 3)
     {
-      /* If just tried and failed to reuse lookahead token after an
+      /* If just tried and failed to reuse look-ahead token after an
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
@@ -1824,7 +1824,7 @@ yyerrlab:
 	}
     }
 
-  /* Else will try to reuse lookahead token after shifting the error
+  /* Else will try to reuse look-ahead token after shifting the error
      token.  */
   goto yyerrlab1;
 
