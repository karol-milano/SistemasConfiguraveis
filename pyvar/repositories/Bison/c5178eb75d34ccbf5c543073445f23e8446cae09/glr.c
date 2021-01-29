@@ -241,24 +241,24 @@ b4_percent_code_get[]dnl
 # if defined YYENABLE_NLS && YYENABLE_NLS
 #  if ENABLE_NLS
 #   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
-#   define YY_(msgid) dgettext ("bison-runtime", msgid)
+#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
 #  endif
 # endif
 # ifndef YY_
-#  define YY_(msgid) msgid
+#  define YY_(Msgid) Msgid
 # endif
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
 #if ! defined lint || defined __GNUC__
-# define YYUSE(e) ((void) (e))
+# define YYUSE(E) ((void) (E))
 #else
-# define YYUSE(e) /* empty */
+# define YYUSE(E) /* empty */
 #endif
 
 /* Identity function, used to suppress warnings about constant conditions.  */
 #ifndef lint
-# define YYID(n) (n)
+# define YYID(N) (N)
 #else
 ]b4_c_function_def([YYID], [static int], [[int i], [i]])[
 {
@@ -289,8 +289,8 @@ b4_percent_code_get[]dnl
 #ifndef YYSETJMP
 # include <setjmp.h>
 # define YYJMP_BUF jmp_buf
-# define YYSETJMP(env) setjmp (env)
-# define YYLONGJMP(env, val) longjmp (env, val)
+# define YYSETJMP(Env) setjmp (Env)
+# define YYLONGJMP(Env, Val) longjmp (Env, Val)
 #endif
 
 /*-----------------.
@@ -313,7 +313,7 @@ b4_percent_code_get[]dnl
 #endif])[
 
 #ifndef YYASSERT
-# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
+# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
 #endif
 
 /* YYFINAL -- State number of the termination state.  */
@@ -972,8 +972,8 @@ yylhsNonterm (yyRuleNum yyrule)
   return yyr1[yyrule];
 }
 
-#define yypact_value_is_default(yystate) \
-  ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
+#define yypact_value_is_default(Yystate) \
+  ]b4_table_value_equals([[pact]], [[Yystate]], [b4_pact_ninf])[
 
 /** True iff LR state STATE has only a default reduction (regardless
  *  of token).  */
@@ -990,8 +990,8 @@ yydefaultAction (yyStateNum yystate)
   return yydefact[yystate];
 }
 
-#define yytable_value_is_error(yytable_value) \
-  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
+#define yytable_value_is_error(Yytable_value) \
+  ]b4_table_value_equals([[table]], [[Yytable_value]], [b4_table_ninf])[
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
