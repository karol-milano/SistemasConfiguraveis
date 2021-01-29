@@ -216,6 +216,13 @@ b4_syncline([@oline@], [@ofile@])[
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
+# ifndef YYFREE
+#  define YYFREE free
+# endif
+# ifndef YYMALLOC
+#  define YYMALLOC malloc
+# endif
+
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
 # ifdef YYSTACK_USE_ALLOCA
@@ -240,8 +247,8 @@ b4_syncline([@oline@], [@ofile@])[
 #   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #   define YYSIZE_T size_t
 #  endif
-#  define YYSTACK_ALLOC malloc
-#  define YYSTACK_FREE free
+#  define YYSTACK_ALLOC YYMALLOC
+#  define YYSTACK_FREE YYFREE
 # endif
 #endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
