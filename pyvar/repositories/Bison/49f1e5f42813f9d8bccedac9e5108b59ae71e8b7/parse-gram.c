@@ -627,6 +627,7 @@ union yyalloc
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  167
 
+/* YYMAXUTOK -- Last valid token kind.  */
 #define YYMAXUTOK   315
 
 
@@ -1752,7 +1753,7 @@ yydestruct (const char *yymsg,
 int
 yyparse (void)
 {
-/* The lookahead symbol.  */
+/* Lookahead token kind.  */
 int yychar;
 
 
@@ -1807,7 +1808,7 @@ YYLTYPE yylloc = yyloc_default;
   int yyn;
   /* The return value of yyparse.  */
   int yyresult;
-  /* Lookahead token as an internal (translated) token number.  */
+  /* Lookahead symbol kind.  */
   yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
   /* The variables used to return semantic value and location from the
      action routines.  */
