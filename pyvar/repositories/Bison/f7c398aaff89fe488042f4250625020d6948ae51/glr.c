@@ -216,11 +216,13 @@ static YYLTYPE yyloc_default;
 ]/* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])
 [
-#if ! defined (__cplusplus)
-   typedef char bool;
-#  define yytrue 1
-#  define yyfalse 0
+#ifdef __cplusplus
+   typedef bool yybool;
+#else
+   typedef unsigned char yybool;
 #endif
+#define yytrue 1
+#define yyfalse 0
 
 /*-----------------.
 | GCC extensions.  |
@@ -536,8 +538,8 @@ typedef struct yyGLRStack yyGLRStack;
 typedef struct yyGLRStateSet yyGLRStateSet;
 
 struct yyGLRState {
-  bool yyisState;
-  bool yyresolved;
+  yybool yyisState;
+  yybool yyresolved;
   yyStateNum yylrState;
   yyGLRState* yypred;
   size_t yyposn;
@@ -554,7 +556,7 @@ struct yyGLRStateSet {
 };
 
 struct yySemanticOption {
-  bool yyisState;
+  yybool yyisState;
   yyRuleNum yyrule;
   yyGLRState* yystate;
   yySemanticOption* yynext;
@@ -713,7 +715,7 @@ yylhsNonterm (yyRuleNum yyrule)
 
 /** True iff LR state STATE has only a default reduction (regardless
  *  of token). */
-static inline bool
+static inline yybool
 yyisDefaultedState (yyStateNum yystate)
 {
   return yyis_pact_ninf (yypact[yystate]);
@@ -772,13 +774,13 @@ yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
     return yydefgoto[yylhs - YYNTOKENS];
 }
 
-static inline bool
+static inline yybool
 yyisShiftAction (int yyaction)
 {
   return 0 < yyaction;
 }
 
-static inline bool
+static inline yybool
 yyisErrorAction (int yyaction)
 {
   return yyaction == 0;
@@ -864,7 +866,7 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
        yyn -= 1, yyp0 += 1, yyp1 += 1)
     {
       *yyp1 = *yyp0;
-      if (*(bool*) yyp0)
+      if (*(yybool *) yyp0)
 	{
 	  yyGLRState* yys0 = &yyp0->yystate;
 	  yyGLRState* yys1 = &yyp1->yystate;
@@ -1123,7 +1125,7 @@ yy_reduce_print (size_t yyk, yyRuleNum yyrule)
  */
 static inline YYRESULTTAG
 yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
-             bool yyforceEval]b4_pure_formals[)
+             yybool yyforceEval]b4_pure_formals[)
 {
   size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;
 
@@ -1209,7 +1211,7 @@ yysplitStack (yyGLRStack* yystack, int yyk)
 /** True iff Y0 and Y1 represent identical options at the top level.
  *  That is, they represent the same rule applied to RHS symbols
  *  that produce the same terminal symbols. */
-static bool
+static yybool
 yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
 {
   if (yyy0->yyrule == yyy1->yyrule)
@@ -1918,7 +1920,7 @@ yypdumpstack (yyGLRStack* yystack)
   for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1)
     {
       fprintf (stderr, "%3lu. ", (unsigned long) (yyp - yystack->yyitems));
-      if (*(bool*) yyp)
+      if (*(yybool *) yyp)
 	{
 	  fprintf (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
 		   yyp->yystate.yyresolved, yyp->yystate.yylrState,
