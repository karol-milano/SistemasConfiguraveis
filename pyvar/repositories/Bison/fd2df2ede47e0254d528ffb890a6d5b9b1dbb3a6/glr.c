@@ -678,37 +678,11 @@ struct yyGLRStack {
 static void yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[);
 
 static void
-yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yyformat, ...)
+yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
 {
   yystack->yyerrflag = 1;
-  if (yyformat != NULL)
-    {
-      char yysmallbuf[1024];
-      char const *yymsg = yysmallbuf;
-      char *yybigbuf = NULL;
-      int yymsglen;
-      va_list yyap;
-
-      va_start (yyap, yyformat);
-      yymsglen = vsnprintf (yysmallbuf, sizeof yysmallbuf, yyformat, yyap);
-      va_end (yyap);
-
-      if (yymsglen < 0)
-	yymsg = "message is too long to be printed";
-      else if (sizeof yysmallbuf <= yymsglen && yymsglen < YYSIZEMAX)
-	{
-	  size_t yybigsize = yymsglen;
-	  yybigsize++;
-	  yymsg = yybigbuf = YYMALLOC (yybigsize);
-
-	  va_start (yyap, yyformat);
-	  vsnprintf (yybigbuf, yybigsize, yyformat, yyap);
-	  va_end (yyap);
-	}
-
-      yyerror (]b4_yyerror_args[yymsg);
-      YYFREE (yybigbuf);
-    }
+  if (yymsg != NULL)
+    yyerror (]b4_yyerror_args[yymsg);
   longjmp (yystack->yyexception_buffer, 1);
 }
 
@@ -1973,7 +1947,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 
 ]b4_c_ansi_function_def([yyparse], [int], b4_parse_param)[
 {
-  yySymbol yytoken = YYEMPTY;
+  yySymbol yytoken;
   yyGLRStack yystack;
   size_t yyposn;
 ]b4_pure_if(
@@ -1989,6 +1963,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
+  yytoken = YYEMPTY;
+
   if (setjmp (yystack.yyexception_buffer) != 0)
     goto yyDone;
 
