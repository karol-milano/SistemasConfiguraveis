@@ -221,7 +221,6 @@ b4_syncline([@oline@], [@ofile@])
 #include <stdlib.h>
 #include <string.h>
 #include <stdarg.h>
-#include <setjmp.h>
 
 #ifndef YY_
 # if YYENABLE_NLS
@@ -255,6 +254,13 @@ b4_syncline([@oline@], [@ofile@])
 #define yytrue 1
 #define yyfalse 0
 
+#ifndef YYSETJMP
+# include <setjmp.h>
+# define YYJMP_BUF jmp_buf
+# define YYSETJMP(env) setjmp (env)
+# define YYLONGJMP(env, val) longjmp (env, val)
+#endif
+
 /*-----------------.
 | GCC extensions.  |
 `-----------------*/
@@ -728,7 +734,7 @@ struct yyGLRStack {
   int yyrawchar;
 ])[
   yySymbol* yytokenp;
-  jmp_buf yyexception_buffer;
+  YYJMP_BUF yyexception_buffer;
   yyGLRStackItem* yyitems;
   yyGLRStackItem* yynextFree;
   size_t yyspaceLeft;
@@ -746,7 +752,7 @@ yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
 {
   if (yymsg != NULL)
     yyerror (]b4_yyerror_args[yymsg);
-  longjmp (yystack->yyexception_buffer, 1);
+  YYLONGJMP (yystack->yyexception_buffer, 1);
 }
 
 static void yyMemoryExhausted (yyGLRStack* yystack)
@@ -754,7 +760,7 @@ static void yyMemoryExhausted (yyGLRStack* yystack)
 static void
 yyMemoryExhausted (yyGLRStack* yystack)
 {
-  longjmp (yystack->yyexception_buffer, 2);
+  YYLONGJMP (yystack->yyexception_buffer, 2);
 }
 
 #if YYDEBUG || YYERROR_VERBOSE
@@ -2081,10 +2087,12 @@ b4_syncline([@oline@], [@ofile@])])dnl
 [
   if (! yyinitGLRStack (&yystack, YYINITDEPTH))
     goto yyexhaustedlab;
-  switch (setjmp (yystack.yyexception_buffer))
+  switch (YYSETJMP (yystack.yyexception_buffer))
     {
+    case 0: break;
     case 1: goto yyabortlab;
     case 2: goto yyexhaustedlab;
+    default: goto yybuglab;
     }
   yystack.yytokenp = &yytoken;
   yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc);
