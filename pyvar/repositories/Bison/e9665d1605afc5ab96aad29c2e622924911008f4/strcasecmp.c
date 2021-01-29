@@ -29,7 +29,7 @@
 # define LENGTH_LIMIT_EXPR(Expr) 0
 #endif
 
-#include <sys/types.h>
+#include <stddef.h>
 #include <ctype.h>
 
 #define TOLOWER(Ch) (isupper (Ch) ? tolower (Ch) : (Ch))
