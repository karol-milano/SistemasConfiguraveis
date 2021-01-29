@@ -31,24 +31,7 @@
 # include <stdlib.h>
 #endif
 
-#if HAVE_STDBOOL_H
-# include <stdbool.h>
-#else
-# ifndef __bool_true_false_are_defined
-#  if ! HAVE__BOOL
-#   ifdef __cplusplus
-typedef bool _Bool;
-#   else
-typedef unsigned char _Bool;
-#   endif
-#  endif
-#  define bool _Bool
-#  define false 0
-#  define true 1
-#  define __bool_true_false_are_defined 1
-# endif
-#endif
-
+#include <stdbool.h>
 #include <stdio.h>
 
 #ifndef HAVE_DECL_FREE
