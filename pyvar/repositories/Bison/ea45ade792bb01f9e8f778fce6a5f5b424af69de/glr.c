@@ -471,6 +471,12 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
    multiple parsers can coexist.  */
 int yydebug;
 
+struct yyGLRStack;
+static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
+  __attribute__ ((__unused__));
+static void yypdumpstack (struct yyGLRStack* yystackp)
+  __attribute__ ((__unused__));
+
 #else /* !]b4_api_PREFIX[DEBUG */
 
 # define YYDPRINTF(Args)
@@ -2482,10 +2488,6 @@ b4_dollar_popdef])[]dnl
 
 /* DEBUGGING ONLY */
 #if ]b4_api_PREFIX[DEBUG
-static void yypstack (yyGLRStack* yystackp, size_t yyk)
-  __attribute__ ((__unused__));
-static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));
-
 static void
 yy_yypstack (yyGLRState* yys)
 {
