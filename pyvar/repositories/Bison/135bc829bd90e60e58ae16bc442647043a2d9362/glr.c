@@ -269,7 +269,7 @@ b4_syncline([@oline@], [@ofile@])
 #  if defined (__cplusplus)
 #   define YYOPTIONAL_LOC(Name) /* empty */
 #  else
-#   define YYOPTIONAL_LOC(Name) Name ATTRIBUTE_UNUSED
+#   define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
 #  endif])[
 # endif
 #endif
@@ -278,10 +278,6 @@ b4_syncline([@oline@], [@ofile@])
 # define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
 #endif
 
-#ifndef ATTRIBUTE_UNUSED
-# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
-#endif
-
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  ]b4_final_state_number[
 /* YYLAST -- Last index in YYTABLE.  */
@@ -742,6 +738,8 @@ struct yyGLRStack {
 
 static void yyexpandGLRStack (yyGLRStack* yystack);
 
+static void yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
+  __attribute__ ((__noreturn__));
 static void
 yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
 {
@@ -750,6 +748,8 @@ yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
   longjmp (yystack->yyexception_buffer, 1);
 }
 
+static void yyMemoryExhausted (yyGLRStack* yystack)
+  __attribute__ ((__noreturn__));
 static void
 yyMemoryExhausted (yyGLRStack* yystack)
 {
@@ -772,7 +772,7 @@ yytokenName (yySymbol yytoken)
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
  *  containing the pointer to the next state in the chain. Assumes
  *  YYLOW1 < YYLOW0.  */
-static void yyfillin (yyGLRStackItem *, int, int) ATTRIBUTE_UNUSED;
+static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
 static void
 yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 {
@@ -793,7 +793,7 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
    YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
    For convenience, always return YYLOW1.  */
 static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
-     ATTRIBUTE_UNUSED;
+     __attribute__ ((__unused__));
 static inline int
 yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
 {
@@ -817,7 +817,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      yyGLRStack* yystack
               ]b4_user_formals[)
 {
-  yybool yynormal ATTRIBUTE_UNUSED = (yystack->yysplitPoint == NULL);
+  yybool yynormal __attribute__ ((__unused__)) =
+    (yystack->yysplitPoint == NULL);
   int yylow;
 
 # undef yyerrok
@@ -1575,6 +1576,9 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 }
 #endif
 
+static void yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
+			       yyGLRStack* yystack]b4_pure_formals[)
+  __attribute__ ((__noreturn__));
 static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 		   yyGLRStack* yystack]b4_pure_formals[)
@@ -2188,8 +2192,9 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
 /* DEBUGGING ONLY */
 #ifdef YYDEBUG
-static void yypstack (yyGLRStack* yystack, size_t yyk) ATTRIBUTE_UNUSED;
-static void yypdumpstack (yyGLRStack* yystack) ATTRIBUTE_UNUSED;
+static void yypstack (yyGLRStack* yystack, size_t yyk)
+  __attribute__ ((__unused__));
+static void yypdumpstack (yyGLRStack* yystack) __attribute__ ((__unused__));
 
 static void
 yy_yypstack (yyGLRState* yys)
