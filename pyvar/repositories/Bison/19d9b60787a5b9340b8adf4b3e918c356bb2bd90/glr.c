@@ -290,7 +290,8 @@ b4_percent_code_get[]dnl
 # include <setjmp.h>
 # define YYJMP_BUF jmp_buf
 # define YYSETJMP(Env) setjmp (Env)
-# define YYLONGJMP(Env, Val) longjmp (Env, Val)
+// Pacify clang.
+# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
 #endif
 
 /*-----------------.
