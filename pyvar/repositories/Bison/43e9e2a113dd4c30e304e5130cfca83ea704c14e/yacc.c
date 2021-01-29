@@ -437,6 +437,7 @@ b4_push_if([], [b4_lac_if([], [[
 #    define YYSTACK_ALLOC alloca
 #    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && ]b4_c_modern[
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
+      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
 #     ifndef EXIT_SUCCESS
 #      define EXIT_SUCCESS 0
 #     endif
