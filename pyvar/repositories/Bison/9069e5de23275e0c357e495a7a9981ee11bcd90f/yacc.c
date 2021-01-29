@@ -254,11 +254,11 @@ b4_syncline([@oline@], [@ofile@])[
 #  if YYSTACK_USE_ALLOCA
 #   ifdef __GNUC__
 #    define YYSTACK_ALLOC __builtin_alloca
-#   elif defined __BUILTIN_VA_ARG_INCR
+#   elif defined (__BUILTIN_VA_ARG_INCR)
 #    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
-#   elif defined _AIX
+#   elif defined (_AIX)
 #    define YYSTACK_ALLOC __alloca
-#   elif defined _MSC_VER
+#   elif defined (_MSC_VER)
 #    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
 #    define alloca _alloca
 #   else
