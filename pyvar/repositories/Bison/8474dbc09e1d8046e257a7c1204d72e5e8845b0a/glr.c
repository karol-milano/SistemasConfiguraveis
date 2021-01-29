@@ -708,7 +708,7 @@ struct yyGLRStack {
 static void yyexpandGLRStack (yyGLRStack* yystackp);
 #endif
 
-static _Noreturn void
+_Noreturn static void
 yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
 {
   if (yymsg != YY_NULLPTR)
@@ -716,7 +716,7 @@ yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
   YYLONGJMP (yystackp->yyexception_buffer, 1);
 }
 
-static _Noreturn void
+_Noreturn static void
 yyMemoryExhausted (yyGLRStack* yystackp)
 {
   YYLONGJMP (yystackp->yyexception_buffer, 2);
