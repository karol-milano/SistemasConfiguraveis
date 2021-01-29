@@ -594,12 +594,12 @@ static void yyfreeGLRStack (yyGLRStack* yystack);
 static void
 yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yyformat, ...)
 {
+  yystack->yyerrflag = 1;
   if (yyformat != NULL)
     {
       char yymsg[256];
       va_list yyap;
       va_start (yyap, yyformat);
-      yystack->yyerrflag = 1;
       vsprintf (yymsg, yyformat, yyap);
       yyerror (]b4_yyerror_args[yymsg);
     }
