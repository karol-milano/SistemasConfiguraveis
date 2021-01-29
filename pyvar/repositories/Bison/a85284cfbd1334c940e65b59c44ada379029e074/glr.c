@@ -909,10 +909,12 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
   YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
 ]b4_location_if([[  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
-]])
+]])[
   switch (yyn)
     {
-      b4_actions
+      ]b4_actions
+/* Line __line__ of glr.c.  */
+b4_syncline([@oline@], [@ofile@])[
       default: break;
     }
 
@@ -924,8 +926,6 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYBACKUP
 # undef yyclearin
 # undef YYRECOVERING
-/* Line __line__ of glr.c.  */
-b4_syncline([@oline@], [@ofile@])
 }
 
 
@@ -937,11 +937,11 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 
   switch (yyn)
     {
-      b4_mergers
+      ]b4_mergers[
       default: break;
     }
 }
-[
+
 			      /* Bison grammar-table manipulation.  */
 
 ]b4_yydestruct_generate([b4_c_ansi_function_def])[
@@ -2324,7 +2324,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
  yybuglab:
   YYASSERT (yyfalse);
-  /* Fall through.  */
+  goto yyabortlab;
 
  yyabortlab:
   yyresult = 1;
@@ -2333,7 +2333,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
  yyexhaustedlab:
   yyerror (]b4_lyyerror_args[YY_("memory exhausted"));
   yyresult = 2;
-  /* Fall through.  */
+  goto yyreturn;
 
  yyreturn:
   if (yytoken != YYEOF && yytoken != YYEMPTY)
