@@ -1967,14 +1967,6 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   yytoken = YYEMPTY;
-
-  if (setjmp (yystack.yyexception_buffer) != 0)
-    goto yyDone;
-
-  if (! yyinitGLRStack (&yystack, YYINITDEPTH))
-    goto yyDone;
-  yystack.yytokenp = &yytoken;
-
   yylval = yyval_default;
 ]b4_location_if([
 #if YYLTYPE_IS_TRIVIAL
@@ -1992,6 +1984,11 @@ m4_popdef([b4_at_dollar])dnl
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])])dnl
 [
+  if (setjmp (yystack.yyexception_buffer) != 0)
+    goto yyDone;
+  if (! yyinitGLRStack (&yystack, YYINITDEPTH))
+    yyStackOverflow (&yystack]b4_lpure_args[);
+  yystack.yytokenp = &yytoken;
   yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc]b4_user_args[);
   yyposn = 0;
 
