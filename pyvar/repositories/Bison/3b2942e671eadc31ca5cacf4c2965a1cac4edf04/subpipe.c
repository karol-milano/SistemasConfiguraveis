@@ -34,9 +34,7 @@
 
 #include <stdlib.h>
 
-#if HAVE_UNISTD_H
-# include <unistd.h>
-#endif
+#include <unistd.h>
 #ifndef STDIN_FILENO
 # define STDIN_FILENO 0
 #endif
