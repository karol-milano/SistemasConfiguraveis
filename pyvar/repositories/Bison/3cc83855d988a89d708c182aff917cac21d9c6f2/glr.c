@@ -445,9 +445,9 @@ int yydebug;
 
 struct yyGLRStack;
 static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
-  __attribute__ ((__unused__));
+  YY_ATTRIBUTE_UNUSED;
 static void yypdumpstack (struct yyGLRStack* yystackp)
-  __attribute__ ((__unused__));
+  YY_ATTRIBUTE_UNUSED;
 
 #else /* !]b4_api_PREFIX[DEBUG */
 
@@ -669,9 +669,7 @@ struct yyGLRStack {
 static void yyexpandGLRStack (yyGLRStack* yystackp);
 #endif
 
-static void yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
-  __attribute__ ((__noreturn__));
-static void
+static _Noreturn void
 yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
 {
   if (yymsg != YY_NULL)
@@ -679,9 +677,7 @@ yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
   YYLONGJMP (yystackp->yyexception_buffer, 1);
 }
 
-static void yyMemoryExhausted (yyGLRStack* yystackp)
-  __attribute__ ((__noreturn__));
-static void
+static _Noreturn void
 yyMemoryExhausted (yyGLRStack* yystackp)
 {
   YYLONGJMP (yystackp->yyexception_buffer, 2);
@@ -702,7 +698,7 @@ yytokenName (yySymbol yytoken)
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
  *  containing the pointer to the next state in the chain.  */
-static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
+static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
 static void
 yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 {
@@ -729,7 +725,7 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
  * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
  * For convenience, always return YYLOW1.  */
 static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
-     __attribute__ ((__unused__));
+     YY_ATTRIBUTE_UNUSED;
 static inline int
 yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
 {
@@ -751,8 +747,7 @@ yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
-  yybool yynormal __attribute__ ((__unused__)) =
-    (yystackp->yysplitPoint == YY_NULL);
+  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULL);
   int yylow;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
 [  YYUSE (yyrhslen);
