@@ -18,14 +18,12 @@
 
 /* Written by Paul Eggert.  */
 
-#ifdef HAVE_CONFIG_H
-# include <config.h>
-#endif
-
-#include <errno.h>
+#include <config.h>
 
 #include "get-errno.h"
 
+#include <errno.h>
+
 /* Get and set errno.  A source file that needs to set or get errno,
    but doesn't need to test for specific errno values, can use these
    functions to avoid namespace pollution.  For example, a file that
