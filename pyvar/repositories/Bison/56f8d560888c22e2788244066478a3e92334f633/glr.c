@@ -258,22 +258,12 @@ b4_percent_code_get[]dnl
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#if ! defined lint || defined __GNUC__
+#ifdef __GNUC__
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
 #endif
 
-/* Identity function, used to suppress warnings about constant conditions.  */
-#ifndef lint
-# define YYID(n) (n)
-#else
-]b4_function_define([YYID], [static int], [[int i], [i]])[
-{
-  return i;
-}
-#endif
-
 #ifndef YYFREE
 # define YYFREE free
 #endif
@@ -477,7 +467,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
     YYRESULTTAG yychk_flag = YYE;               \
     if (yychk_flag != yyok)                     \
       return yychk_flag;                        \
-  } while (YYID (0))
+  } while (0)
 
 #if ]b4_api_PREFIX[DEBUG
 
@@ -489,7 +479,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
   do {                                          \
     if (yydebug)                                \
       YYFPRINTF Args;                           \
-  } while (YYID (0))
+  } while (0)
 
 ]b4_yy_symbol_print_define[
 
@@ -501,7 +491,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
         yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
         YYFPRINTF (stderr, "\n");                                       \
       }                                                                 \
-  } while (YYID (0))
+  } while (0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -546,13 +536,13 @@ int yydebug;
   do {                                                  \
     if (Yystack->yyspaceLeft < YYHEADROOM)              \
       yyexpandGLRStack (Yystack);                       \
-  } while (YYID (0))
+  } while (0)
 #else
 # define YY_RESERVE_GLRSTACK(Yystack)                   \
   do {                                                  \
     if (Yystack->yyspaceLeft < YYHEADROOM)              \
       yyMemoryExhausted (Yystack);                      \
-  } while (YYID (0))
+  } while (0)
 #endif
 
 
@@ -804,7 +794,7 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  value ($$), and yylocp points to place for location information
  *  (@@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
  *  yyerr for YYERROR, yyabort for YYABORT.  */
-/*ARGSUSED*/ static YYRESULTTAG
+static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
@@ -855,9 +845,9 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef yyclearin
 # undef YYRECOVERING
 }
-
 
-/*ARGSUSED*/ static void
+
+static void
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
   YYUSE (yy0);
@@ -1277,13 +1267,13 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 do {                                    \
   if (yydebug)                          \
     yy_reduce_print Args;               \
-} while (YYID (0))
+} while (0)
 
 /*----------------------------------------------------------------------.
 | Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
 `----------------------------------------------------------------------*/
 
-/*ARGSUSED*/ static inline void
+static inline void
 yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                  yyRuleNum yyrule]b4_user_formals[)
 {
@@ -1533,7 +1523,7 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
         {
           yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
           yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
-          while (YYID (yytrue))
+          while (yytrue)
             {
               if (yyz1 == *yyz0p || yyz1 == YY_NULL)
                 break;
@@ -1694,7 +1684,7 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 }
 #endif
 
-/*ARGSUSED*/ static YYRESULTTAG
+static YYRESULTTAG
 yyreportAmbiguity (yySemanticOption* yyx0,
                    yySemanticOption* yyx1]b4_pure_formals[)
 {
@@ -2025,7 +2015,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
   return yyok;
 }
 
-/*ARGSUSED*/ static void
+static void
 yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
   if (yystackp->yyerrState != 0)
@@ -2157,7 +2147,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 /* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
    yylval, and yylloc are the syntactic category, semantic value, and location
    of the lookahead.  */
-/*ARGSUSED*/ static void
+static void
 yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
   size_t yyk;
@@ -2166,7 +2156,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   if (yystackp->yyerrState == 3)
     /* We just shifted the error token and (perhaps) took some
        reductions.  Skip tokens until we can proceed.  */
-    while (YYID (yytrue))
+    while (yytrue)
       {
         yySymbol yytoken;
         if (yychar == YYEOF)
@@ -2270,7 +2260,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     default:                                                                 \
       goto yybuglab;                                                         \
     }                                                                        \
-  } while (YYID (0))
+  } while (0)
 
 /*----------.
 | yyparse.  |
@@ -2311,13 +2301,13 @@ b4_dollar_popdef])[]dnl
   yyglrShift (&yystack, 0, 0, 0, &yylval]b4_locations_if([, &yylloc])[);
   yyposn = 0;
 
-  while (YYID (yytrue))
+  while (yytrue)
     {
       /* For efficiency, we have two loops, the first of which is
          specialized to deterministic operation (single stack, no
          potential ambiguity).  */
       /* Standard mode */
-      while (YYID (yytrue))
+      while (yytrue)
         {
           yyRuleNum yyrule;
           int yyaction;
@@ -2381,7 +2371,7 @@ b4_dollar_popdef])[]dnl
             }
         }
 
-      while (YYID (yytrue))
+      while (yytrue)
         {
           yySymbol yytoken_to_shift;
           size_t yys;
@@ -2513,8 +2503,7 @@ b4_dollar_popdef])[]dnl
       yyfreeGLRStack (&yystack);
     }
 
-  /* Make sure YYID is used.  */
-  return YYID (yyresult);
+  return yyresult;
 }
 
 /* DEBUGGING ONLY */
