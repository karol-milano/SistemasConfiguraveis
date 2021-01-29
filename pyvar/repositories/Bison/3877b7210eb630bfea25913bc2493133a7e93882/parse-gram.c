@@ -898,8 +898,7 @@ static const yytype_int8 yyr2[] =
 enum { YYENOMEM = -2 };
 
 #define yyerrok         (yyerrstatus = 0)
-#define yyclearin       (yychar = YYEMPTY)
-#define YYEMPTY         (-2)
+#define yyclearin       (yychar = GRAM_EMPTY)
 
 #define YYACCEPT        goto yyacceptlab
 #define YYABORT         goto yyabortlab
@@ -910,7 +909,7 @@ enum { YYENOMEM = -2 };
 
 #define YYBACKUP(Token, Value)                                    \
   do                                                              \
-    if (yychar == YYEMPTY)                                        \
+    if (yychar == GRAM_EMPTY)                                        \
       {                                                           \
         yychar = (Token);                                         \
         yylval = (Value);                                         \
@@ -1819,7 +1818,7 @@ YYLTYPE yylloc = yyloc_default;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
-  yychar = YYEMPTY; /* Cause a token to be read.  */
+  yychar = GRAM_EMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
 {
@@ -1943,7 +1942,7 @@ yybackup:
   /* Not known => get a lookahead token if don't already have one.  */
 
   /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
-  if (yychar == YYEMPTY)
+  if (yychar == GRAM_EMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token\n"));
       yychar = yylex (&yylval, &yylloc);
@@ -1993,7 +1992,7 @@ yybackup:
   *++yylsp = yylloc;
 
   /* Discard the shifted token.  */
-  yychar = YYEMPTY;
+  yychar = GRAM_EMPTY;
   YY_LAC_DISCARD ("shift");
   goto yynewstate;
 
@@ -2619,7 +2618,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yytoken = yychar == GRAM_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
 
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
@@ -2628,7 +2627,7 @@ yyerrlab:
       {
         yypcontext_t yyctx
           = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
-        if (yychar != YYEMPTY)
+        if (yychar != GRAM_EMPTY)
           YY_LAC_ESTABLISH;
         if (yyreport_syntax_error (&yyctx) == 2)
           goto yyexhaustedlab;
@@ -2652,7 +2651,7 @@ yyerrlab:
         {
           yydestruct ("Error: discarding",
                       yytoken, &yylval, &yylloc);
-          yychar = YYEMPTY;
+          yychar = GRAM_EMPTY;
         }
     }
 
@@ -2763,7 +2762,7 @@ yyexhaustedlab:
 | yyreturn -- parsing is finished, return the result.  |
 `-----------------------------------------------------*/
 yyreturn:
-  if (yychar != YYEMPTY)
+  if (yychar != GRAM_EMPTY)
     {
       /* Make sure we have latest lookahead translation.  See comments at
          user semantic actions for why this is necessary.  */
