@@ -630,6 +630,9 @@ static const yytype_int16 yyrline[] =
 };
 #endif
 
+/** Accessing symbol of state STATE.  */
+#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_type_t, yystos[State])
+
 #if 1
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
@@ -1032,7 +1035,7 @@ do {                                                                      \
 
 static void
 yy_symbol_value_print (FILE *yyo,
-                       int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+                       yysymbol_type_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   FILE *yyoutput = yyo;
   YYUSE (yyoutput);
@@ -1243,7 +1246,7 @@ troff (yyo);
 
 static void
 yy_symbol_print (FILE *yyo,
-                 int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+                 yysymbol_type_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   YYFPRINTF (yyo, "%s %s (",
              yytype < YYNTOKENS ? "token" : "nterm", yysymbol_name (yytype));
@@ -1296,7 +1299,7 @@ yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
-                       yystos[+yyssp[yyi + 1 - yynrhs]],
+                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                        &yyvsp[(yyi + 1) - (yynrhs)]
                        , &(yylsp[(yyi + 1) - (yynrhs)])                       );
       YYFPRINTF (stderr, "\n");
@@ -1660,7 +1663,7 @@ yyreport_syntax_error (const yyparse_context_t *yyctx);
 
 static void
 yydestruct (const char *yymsg,
-            int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
+            yysymbol_type_t yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 {
   YYUSE (yyvaluep);
   YYUSE (yylocationp);
@@ -2592,7 +2595,7 @@ yyreduce:
      case of YYERROR or YYBACKUP, subsequent parser actions might lead
      to an incorrect destructor call or verbose syntax error message
      before the lookahead is translated.  */
-  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
+  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_type_t, yyr1[yyn]), &yyval, &yyloc);
 
   YYPOPSTACK (yylen);
   yylen = 0;
@@ -2706,7 +2709,7 @@ yyerrlab1:
 
       yyerror_range[1] = *yylsp;
       yydestruct ("Error: popping",
-                  yystos[yystate], yyvsp, yylsp);
+                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -2727,7 +2730,7 @@ yyerrlab1:
   *++yylsp = yyloc;
 
   /* Shift the error token.  */
-  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
+  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);
 
   yystate = yyn;
   goto yynewstate;
@@ -2779,7 +2782,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-                  yystos[+*yyssp], yyvsp, yylsp);
+                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
