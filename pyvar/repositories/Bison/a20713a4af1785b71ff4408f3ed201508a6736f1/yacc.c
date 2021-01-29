@@ -335,8 +335,7 @@ union yyalloc
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
 #define YYTRANSLATE(YYX) 						\
-  ((YYX <= 0) ? YYEOF :							\
-   (unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
@@ -462,8 +461,8 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 #endif
 
 #define yyerrok		(yyerrstatus = 0)
-#define yyclearin	(yytoken = YYEMPTY)
-#define YYEMPTY		-2
+#define yyclearin	(yychar = YYEMPTY)
+#define YYEMPTY		(-2)
 #define YYEOF		0
 
 #define YYACCEPT	goto yyacceptlab
@@ -480,7 +479,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 
 #define YYBACKUP(Token, Value)					\
 do								\
-  if (yytoken == YYEMPTY && yylen == 1)				\
+  if (yychar == YYEMPTY && yylen == 1)				\
     {								\
       yychar = (Token);						\
       yylval = (Value);						\
@@ -790,7 +789,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   yystate = 0;
   yyerrstatus = 0;
   yynerrs = 0;
-  yychar = yytoken = YYEMPTY;		/* Cause a token to be read.  */
+  yychar = YYEMPTY;		/* Cause a token to be read.  */
 
   /* Initialize stack pointers.
      Waste one element of value and location stack
@@ -900,20 +899,21 @@ yybackup:
 
   /* Not known => get a lookahead token if don't already have one.  */
 
-  /* YYTOKEN is either YYEMPTY or YYEOF or a valid token.  */
-  if (yytoken == YYEMPTY)
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
+  if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
-      yytoken = YYTRANSLATE (yychar);
     }
 
-  if (yytoken == YYEOF)
+  if (yychar <= YYEOF)
     {
+      yychar = yytoken = YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
+      yytoken = YYTRANSLATE (yychar);
       YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
     }
 
@@ -938,8 +938,8 @@ yybackup:
   YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
 
   /* Discard the token being shifted unless it is eof.  */
-  if (yytoken != YYEOF)
-    yytoken = YYEMPTY;
+  if (yychar != YYEOF)
+    yychar = YYEMPTY;
 
   *++yyvsp = yylval;
 ]b4_location_if([  *++yylsp = yylloc;])[
@@ -1080,7 +1080,7 @@ yyerrlab:
 	 error, discard it.  */
 
       /* Return failure if at end of input.  */
-      if (yytoken == YYEOF)
+      if (yychar == YYEOF)
         {
 	  /* Pop the error token.  */
           YYPOPSTACK;
@@ -1096,7 +1096,7 @@ yyerrlab:
 
       YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
       yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
-      yytoken = YYEMPTY;
+      yychar = YYEMPTY;
     }
 
   /* Else will try to reuse lookahead token after shifting the error
