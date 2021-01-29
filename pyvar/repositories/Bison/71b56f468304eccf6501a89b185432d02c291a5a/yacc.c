@@ -366,10 +366,8 @@ typedef unsigned char yytype_uint8;
 
 #ifdef YYTYPE_INT8
 typedef YYTYPE_INT8 yytype_int8;
-#elif ]b4_c_modern[
-typedef signed char yytype_int8;
 #else
-typedef short int yytype_int8;
+typedef signed char yytype_int8;
 #endif
 
 #ifdef YYTYPE_UINT16
@@ -389,7 +387,7 @@ typedef short int yytype_int16;
 #  define YYSIZE_T __SIZE_TYPE__
 # elif defined size_t
 #  define YYSIZE_T size_t
-# elif ! defined YYSIZE_T && ]b4_c_modern[
+# elif ! defined YYSIZE_T
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -446,7 +444,7 @@ b4_push_if([], [b4_lac_if([], [[
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && ]b4_c_modern[
+#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
       /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
 #     ifndef EXIT_SUCCESS
@@ -483,13 +481,13 @@ b4_push_if([], [b4_lac_if([], [[
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if ! defined malloc && ! defined EXIT_SUCCESS && ]b4_c_modern[
+#   if ! defined malloc && ! defined EXIT_SUCCESS
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if ! defined free && ! defined EXIT_SUCCESS && ]b4_c_modern[
+#   if ! defined free && ! defined EXIT_SUCCESS
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
