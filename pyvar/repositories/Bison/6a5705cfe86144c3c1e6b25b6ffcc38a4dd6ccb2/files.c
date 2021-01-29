@@ -29,6 +29,15 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 #endif
 #endif
 
+#if defined (_MSC_VER)
+#ifndef XPFILE
+#define XPFILE "c:/usr/local/lib/bison.simple"
+#endif
+#ifndef XPFILE1
+#define XPFILE1 "c:/usr/local/lib/bison.hairy"
+#endif
+#endif
+
 #include <stdio.h>
 #include "system.h"
 #include "files.h"
