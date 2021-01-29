@@ -657,7 +657,6 @@ union yyGLRStackItem {
 };
 
 struct yyGLRStack {
-  int yyerrflag;
   int yyerrState;
 ]b4_location_if([[  /* To compute the location of the error token.  */
   yyGLRStackItem yyerror_range[3];]])[
@@ -681,7 +680,6 @@ static void yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[);
 static void
 yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
 {
-  yystack->yyerrflag = 1;
   if (yymsg != NULL)
     yyerror (]b4_yyerror_args[yymsg);
   longjmp (yystack->yyexception_buffer, 1);
@@ -690,7 +688,7 @@ yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
 static void
 yyStackOverflow (yyGLRStack* yystack]b4_pure_formals[)
 {
-  yyFail (yystack]b4_pure_args[, "parser stack overflow");
+  longjmp (yystack->yyexception_buffer, 2);
 }
 
 #if YYDEBUG || YYERROR_VERBOSE
@@ -957,7 +955,6 @@ static void yyfreeStateSet (yyGLRStateSet* yyset)
 static yybool
 yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
 {
-  yystack->yyerrflag = 0;
   yystack->yyerrState = 0;
   yynerrs = 0;
   yystack->yyspaceLeft = yysize;
@@ -1933,11 +1930,9 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
     default:								     \
       break;								     \
     case yyabort:							     \
-      yystack.yyerrflag = 1;						     \
-      goto yyDone;							     \
+      goto yyabortlab;							     \
     case yyaccept:							     \
-      yystack.yyerrflag = 0;						     \
-      goto yyDone;							     \
+      goto yyacceptlab;							     \
     case yyerr:								     \
       goto yyuser_error;						     \
     }									     \
@@ -1950,6 +1945,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 
 ]b4_c_ansi_function_def([yyparse], [int], b4_parse_param)[
 {
+  int yyresult;
   yySymbol yytoken;
   yyGLRStack yystack;
   size_t yyposn;
@@ -1984,10 +1980,13 @@ m4_popdef([b4_at_dollar])dnl
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])])dnl
 [
-  if (setjmp (yystack.yyexception_buffer) != 0)
-    goto yyDone;
   if (! yyinitGLRStack (&yystack, YYINITDEPTH))
-    yyStackOverflow (&yystack]b4_lpure_args[);
+    goto yyoverflowlab;
+  switch (setjmp (yystack.yyexception_buffer))
+    {
+    case 1: goto yyabortlab;
+    case 2: goto yyoverflowlab;
+    }
   yystack.yytokenp = &yytoken;
   yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc]b4_user_args[);
   yyposn = 0;
@@ -2007,7 +2006,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
           YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 	  if (yystate == YYFINAL)
-	    goto yyDone;
+	    goto yyacceptlab;
 	  if (yyisDefaultedState (yystate))
 	    {
 	      yyrule = yydefaultAction (yystate);
@@ -2089,14 +2088,27 @@ b4_syncline([@oline@], [@ofile@])])dnl
       yyrecoverSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
       yyposn = yystack.yytops.yystates[0]->yyposn;
     }
- yyDone:
-  /* On YYABORT, free the lookahead. */
-  if (yystack.yyerrflag == 1 && yytoken != YYEMPTY)
+
+ yyacceptlab:
+  yyresult = 0;
+  goto yyreturn;
+
+ yyabortlab:
+  yyresult = 1;
+  goto yyreturn;
+
+ yyoverflowlab:
+  yyerror (]b4_lyyerror_args["parser stack overflow");
+  yyresult = 2;
+  /* Fall through.  */
+
+ yyreturn:
+  if (yytoken != YYEOF && yytoken != YYEMPTY)
     yydestruct ("Error: discarding lookahead",
                 yytoken, yylvalp]b4_location_if([, yyllocp])[);
 
   yyfreeGLRStack (&yystack);
-  return yystack.yyerrflag;
+  return yyresult;
 }
 
 /* DEBUGGING ONLY */
