@@ -19,13 +19,15 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+#include "state.h"
+
 #include "system.h"
 
 #include <hash.h>
 
+#include "closure.h"
 #include "complain.h"
 #include "gram.h"
-#include "state.h"
 #include "print-xml.h"
 
 
@@ -443,6 +445,7 @@ state **states = NULL;
 void
 states_free (void)
 {
+  closure_free ();
   for (state_number i = 0; i < nstates; ++i)
     state_free (states[i]);
   free (states);
