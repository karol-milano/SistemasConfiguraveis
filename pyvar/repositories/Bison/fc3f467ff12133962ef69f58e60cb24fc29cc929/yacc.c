@@ -338,8 +338,13 @@ typedef short int yytype_int16;
 #  ifndef YYSTACK_ALLOC_MAXIMUM
 #   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
 #  endif
-#  ifdef __cplusplus
-extern "C" {
+#  if (defined __cplusplus && ! defined _STDLIB_H \
+       && ! ((defined YYMALLOC || defined malloc) \
+	     && (defined YYFREE || defined free)))
+#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
+#   ifndef _STDLIB_H
+#    define _STDLIB_H 1
+#   endif
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
@@ -353,9 +358,6 @@ void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
-#  ifdef __cplusplus
-}
-#  endif
 # endif
 #endif /* ! defined yyoverflow || YYERROR_VERBOSE */
 
