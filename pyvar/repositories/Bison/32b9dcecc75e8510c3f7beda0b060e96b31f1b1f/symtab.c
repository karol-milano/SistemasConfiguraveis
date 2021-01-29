@@ -19,13 +19,14 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+#include "symtab.h"
+
 #include "system.h"
 
 #include <hash.h>
 
 #include "complain.h"
 #include "gram.h"
-#include "symtab.h"
 
 /*-------------------------------------------------------------------.
 | Symbols sorted by tag.  Allocated by the first invocation of       |
