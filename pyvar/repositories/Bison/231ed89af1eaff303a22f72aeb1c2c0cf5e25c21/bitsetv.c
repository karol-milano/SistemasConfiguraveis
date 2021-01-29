@@ -15,13 +15,12 @@
    along with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
 
-#ifdef HAVE_CONFIG_H
-# include <config.h>
-#endif
+#include <config.h>
 
-#include <stdlib.h>
 #include "bitsetv.h"
 
+#include <stdlib.h>
+
 
 /* Create a vector of N_VECS bitsets, each of N_BITS, and of
    type TYPE.  */
