@@ -23,16 +23,15 @@
    operations get vectored through here and we then call the appropriate
    routines.  */
 
-#ifdef HAVE_CONFIG_H
-# include <config.h>
-#endif
+#include <config.h>
+
+#include "bitset_stats.h"
 
 #include "bbitset.h"
 #include "abitset.h"
 #include "ebitset.h"
 #include "lbitset.h"
 #include "vbitset.h"
-#include "bitset_stats.h"
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
