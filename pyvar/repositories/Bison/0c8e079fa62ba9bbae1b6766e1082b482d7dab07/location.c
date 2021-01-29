@@ -21,8 +21,10 @@
 #include <config.h>
 #include "system.h"
 
+#include <mbswidth.h>
 #include <quotearg.h>
 
+#include "complain.h"
 #include "location.h"
 
 location const empty_location;
