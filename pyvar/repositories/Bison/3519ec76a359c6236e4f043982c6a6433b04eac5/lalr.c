@@ -30,10 +30,9 @@ Boston, MA 02111-1307, USA.  */
 #include "gram.h"
 #include "complain.h"
 #include "lalr.h"
+#include "nullable.h"
 
 extern short **derives;
-extern char *nullable;
-
 
 int tokensetsize;
 short *lookaheads;
