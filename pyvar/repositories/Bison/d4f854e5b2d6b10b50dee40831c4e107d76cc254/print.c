@@ -19,20 +19,24 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+
+#include "print.h"
+
 #include "system.h"
 
 #include <bitset.h>
 #include <mbswidth.h>
 
 #include "closure.h"
+#include "complain.h"
 #include "conflicts.h"
+#include "counterexample.h"
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
 #include "lr0.h"
 #include "muscle-tab.h"
-#include "print.h"
 #include "reader.h"
 #include "reduce.h"
 #include "state.h"
@@ -352,6 +356,11 @@ print_state (FILE *out, const state *s)
       fputc ('\n', out);
       fputs (s->solved_conflicts, out);
     }
+  if (warning_is_enabled (Wcounterexamples) && has_conflicts (s))
+    {
+      fputc ('\n', out);
+      counterexample_report_state (s, out, "    ");
+    }
 }
 
 /*-----------------------------------------.
