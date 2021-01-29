@@ -263,7 +263,8 @@ b4_syncline([@oline@], [@ofile@])[
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__cplusplus))
+#    if (! defined (alloca) && ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) \
+	 && (defined (__STDC__) || defined (__cplusplus)))
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #     ifndef _STDLIB_H
 #      define _STDLIB_H 1
