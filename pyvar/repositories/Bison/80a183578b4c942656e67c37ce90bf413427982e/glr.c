@@ -704,7 +704,9 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  yyerr for YYERROR, yyabort for YYABORT. */
 static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
-	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack
+	      YYSTYPE* yyvalp,
+	      YYLTYPE* yylocp]b4_location_if(, [ ATTRIBUTE_UNUSED])[,
+	      yyGLRStack* yystack
               ]b4_user_formals[)
 {
   yybool yynormal ATTRIBUTE_UNUSED = (yystack->yysplitPoint == NULL);
@@ -1702,7 +1704,9 @@ yyreportSyntaxError (yyGLRStack* yystack,
    value, and location of the look-ahead.  */
 static void
 yyrecoverSyntaxError (yyGLRStack* yystack,
-		      YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
+		      YYSTYPE* yylvalp,
+		      YYLTYPE* yyllocp]b4_location_if(, [ ATTRIBUTE_UNUSED])[
+		      ]b4_user_formals[)
 {
   yySymbol* const yytokenp = yystack->yytokenp;
   size_t yyk;
@@ -1923,7 +1927,6 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-		  yyGLRState *yys = yystack.yytops.yystates[0];
 ]b4_location_if([[		  yystack.yyerror_range[0] = *yyllocp;]])[
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
