@@ -19,10 +19,10 @@ the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */
 
 
-/* set up nullable, a vector saying which nonterminals can expand into the null string.
-   nullable[i - ntokens] is nonzero if symbol i can do so.  */
+/* set up nullable, a vector saying which nonterminals can expand into
+   the null string.  nullable[i - ntokens] is nonzero if symbol i can
+   do so.  */
 
-#include <stdio.h>
 #include "system.h"
 #include "types.h"
 #include "gram.h"
