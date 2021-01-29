@@ -18,15 +18,11 @@
    Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
    02111-1307, USA.  */
 
-
 #include "system.h"
 #include "alloc.h"
 #include "gram.h"
 #include "closure.h"
-
-extern short **derives;
-
-extern void RTC PARAMS ((unsigned *, int));
+#include "derives.h"
 
 short *itemset;
 short *itemsetend;
