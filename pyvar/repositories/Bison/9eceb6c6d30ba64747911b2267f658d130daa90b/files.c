@@ -19,6 +19,8 @@ the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */
 
 
+#include "system.h"
+
 #if defined (VMS) & !defined (__VMS_POSIX)
 #include <ssdef.h>
 #define unlink delete
@@ -40,7 +42,6 @@ Boston, MA 02111-1307, USA.  */
 #endif
 
 #include <stdio.h>
-#include "system.h"
 #include "files.h"
 #include "alloc.h"
 #include "gram.h"
