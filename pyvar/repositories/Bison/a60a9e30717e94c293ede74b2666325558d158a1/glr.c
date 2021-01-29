@@ -305,8 +305,12 @@ b4_percent_code_get[]dnl
 # include <setjmp.h>
 # define YYJMP_BUF jmp_buf
 # define YYSETJMP(Env) setjmp (Env)
-/* Pacify clang.  */
-# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
+/* Pacify Clang and ICC.  */
+# define YYLONGJMP(Env, Val)                    \
+ do {                                           \
+   longjmp (Env, Val);                          \
+   YYASSERT (0);                                \
+ } while (yyfalse)
 #endif
 
 ]b4_attribute_define[
