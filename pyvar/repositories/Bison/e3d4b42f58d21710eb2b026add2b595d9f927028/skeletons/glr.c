@@ -651,6 +651,13 @@ yysymbol_name (yysymbol_kind_t yysymbol)
 }]])[
 #endif
 
+/** Left-hand-side symbol for rule #YYRULE.  */
+static inline yysymbol_kind_t
+yylhsNonterm (yyRuleNum yyrule)
+{
+  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
+}
+
 #if ]b4_api_PREFIX[DEBUG
 
 # ifndef YYFPRINTF
@@ -690,6 +697,16 @@ yysymbol_name (yysymbol_kind_t yysymbol)
       }                                                                 \
   } while (0)
 
+static inline void
+yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
+                 yyRuleNum yyrule]b4_user_formals[);
+
+# define YY_REDUCE_PRINT(Args)          \
+  do {                                  \
+    if (yydebug)                        \
+      yy_reduce_print Args;             \
+  } while (0)
+
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
@@ -703,6 +720,7 @@ static void yypdumpstack (yyGLRStack* yystackp)
 
 # define YY_DPRINTF(Args) do {} while (yyfalse)
 # define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
+# define YY_REDUCE_PRINT(Args)
 
 #endif /* !]b4_api_PREFIX[DEBUG */
 
@@ -887,7 +905,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
-  int yylow;
+  int yylow = 1;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
 [  YYUSE (yyrhslen);
 # undef yyerrok
@@ -909,7 +927,6 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   return yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")),     \
          yyerrok, yyerr
 
-  yylow = 1;
   if (yyrhslen == 0)
     *yyvalp = yyval_default;
   else
@@ -1006,13 +1023,6 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
     }
 }
 
-/** Left-hand-side symbol for rule #YYRULE.  */
-static inline yysymbol_kind_t
-yylhsNonterm (yyRuleNum yyrule)
-{
-  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
-}
-
 #define yypact_value_is_default(Yyn) \
   ]b4_table_value_equals([[pact]], [[Yyn]], [b4_pact_ninf], [YYPACT_NINF])[
 
@@ -1382,14 +1392,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
   yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
 }
 
-#if !]b4_api_PREFIX[DEBUG
-# define YY_REDUCE_PRINT(Args)
-#else
-# define YY_REDUCE_PRINT(Args)          \
-  do {                                  \
-    if (yydebug)                        \
-      yy_reduce_print Args;             \
-  } while (0)
+#if ]b4_api_PREFIX[DEBUG
 
 /*----------------------------------------------------------------------.
 | Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
@@ -1692,8 +1695,8 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
   return 0;
 }
 
-static YYRESULTTAG yyresolveValue (yyGLRState* yys,
-                                   yyGLRStack* yystackp]b4_user_formals[);
+static YYRESULTTAG
+yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[);
 
 
 /** Resolve the previous YYN states starting at and including state YYS
