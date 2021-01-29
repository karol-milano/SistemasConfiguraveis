@@ -2045,13 +2045,13 @@ yyabortlab:
 yyexhaustedlab:
   yyerror (]b4_yyerror_args[YY_("memory exhausted"));
   yyresult = 2;
-  /* Fall through.  */
+  goto yyreturn;
 #endif
 
 
-/*-----------------------------------------------------.
-| yyreturn -- parsing is finished, return the result.  |
-`-----------------------------------------------------*/
+/*-------------------------------------------------------.
+| yyreturn -- parsing is finished, clean up and return.  |
+`-------------------------------------------------------*/
 yyreturn:
   if (yychar != ]b4_symbol(-2, id)[)
     {
@@ -2079,11 +2079,12 @@ yyreturn:
     YYSTACK_FREE (yyes);]])b4_push_if([[
   yypstate_clear (yyps);
   yyps->yynew = 1;
+  goto yypushreturn;
 
 
-/*-----------------------------------------.
-| yypushreturn -- ask for the next token.  |
-`-----------------------------------------*/
+/*-------------------------.
+| yypushreturn -- return.  |
+`-------------------------*/
 yypushreturn:]])[
 ]b4_parse_error_bmatch([detailed\|verbose],
 [[  if (yymsg != yymsgbuf)
