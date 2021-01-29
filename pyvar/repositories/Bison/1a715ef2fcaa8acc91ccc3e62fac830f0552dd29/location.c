@@ -18,7 +18,7 @@
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.  */
 
-
+#include "system.h"
 #include "location.h"
 
-location_t empty_location = { 0, 0, 0, 0 };
+location_t empty_location = { NULL, 0, 0, 0, 0 };
