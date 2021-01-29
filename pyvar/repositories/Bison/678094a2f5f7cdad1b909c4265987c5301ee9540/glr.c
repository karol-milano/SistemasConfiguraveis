@@ -2089,9 +2089,11 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 /*ARGSUSED*/ static void
 yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
-  if (yystackp->yyerrState == 0)
-    {
-#if YYERROR_VERBOSE
+  if (yystackp->yyerrState != 0)
+    return;
+#if ! YYERROR_VERBOSE
+  yyerror (]b4_lyyerror_args[YY_("syntax error"));
+#else
       int yyn;
       yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
 if (YYPACT_NINF < yyn && yyn <= YYLAST)
@@ -2188,11 +2190,10 @@ if (YYPACT_NINF < yyn && yyn <= YYLAST)
     }
   }
 else
-#endif /* YYERROR_VERBOSE */
   yyerror (]b4_lyyerror_args[YY_("syntax error"));
+#endif /* YYERROR_VERBOSE */
   yynerrs += 1;
 }
-}
 
 /* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
    yylval, and yylloc are the syntactic category, semantic value, and location
