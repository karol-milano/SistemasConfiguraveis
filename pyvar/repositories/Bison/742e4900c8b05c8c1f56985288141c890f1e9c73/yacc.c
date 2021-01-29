@@ -964,15 +964,15 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 # Declare the variables that are global, or local to YYPARSE if
 # pure-parser.
 m4_define([b4_declare_parser_variables],
-[/* The look-ahead symbol.  */
+[/* The lookahead symbol.  */
 int yychar;
 
-/* The semantic value of the look-ahead symbol.  */
+/* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 int yynerrs;b4_locations_if([
-/* Location data for the look-ahead symbol.  */
+/* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;])
 ])
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
@@ -997,7 +997,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
-  /* Look-ahead token as an internal (translated) token number.  */
+  /* Lookahead token as an internal (translated) token number.  */
   int yytoken = 0;
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
@@ -1168,16 +1168,16 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
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
@@ -1217,7 +1217,7 @@ yybackup:
   if (yyerrstatus)
     yyerrstatus--;
 
-  /* Shift the look-ahead token.  */
+  /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the shifted token unless it is eof.  */
@@ -1341,7 +1341,7 @@ yyerrlab:
 
   if (yyerrstatus == 3)
     {
-      /* If just tried and failed to reuse look-ahead token after an
+      /* If just tried and failed to reuse lookahead token after an
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
@@ -1358,7 +1358,7 @@ yyerrlab:
 	}
     }
 
-  /* Else will try to reuse look-ahead token after shifting the error
+  /* Else will try to reuse lookahead token after shifting the error
      token.  */
   goto yyerrlab1;
 
@@ -1423,7 +1423,7 @@ yyerrlab1:
 ]b4_locations_if([[
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the look-ahead.  YYLOC is available though.  */
+     the lookahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;]])[
 
