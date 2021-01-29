@@ -404,24 +404,24 @@ typedef short int yytype_int16;
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
 ]b4_c_function_def([YYID], [static int], [[int yyi], [yyi]])[
 {
@@ -680,11 +680,11 @@ static const ]b4_int_type_for([b4_table])[ yytable[] =
   ]b4_table[
 };
 
-#define yypact_value_is_default(yystate) \
-  ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
+#define yypact_value_is_default(Yystate) \
+  ]b4_table_value_equals([[pact]], [[Yystate]], [b4_pact_ninf])[
 
-#define yytable_value_is_error(yytable_value) \
-  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
+#define yytable_value_is_error(Yytable_value) \
+  ]b4_table_value_equals([[table]], [[Yytable_value]], [b4_table_ninf])[
 
 static const ]b4_int_type_for([b4_check])[ yycheck[] =
 {
