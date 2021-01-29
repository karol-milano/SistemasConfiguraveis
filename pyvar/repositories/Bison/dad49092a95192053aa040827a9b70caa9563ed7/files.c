@@ -42,6 +42,11 @@ Boston, MA 02111-1307, USA.  */
 #endif
 
 #include <stdio.h>
+
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #include "files.h"
 #include "alloc.h"
 #include "gram.h"
