@@ -19,6 +19,8 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
+#include "getargs.h"
+
 #include "system.h"
 
 #include <argmatch.h>
@@ -31,7 +33,6 @@
 
 #include "complain.h"
 #include "files.h"
-#include "getargs.h"
 #include "muscle-tab.h"
 #include "output.h"
 #include "uniqstr.h"
@@ -290,7 +291,7 @@ Operation modes:\n\
   -u, --update               apply fixes to the source grammar file and exit\n\
   -y, --yacc                 emulate POSIX Yacc\n\
   -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
-  -f, --feature[=FEATURE]    activate miscellaneous features\n\
+  -f, --feature[=FEATURES]   activate miscellaneous features\n\
 \n\
 "), stdout);
 
@@ -356,10 +357,15 @@ THINGS is a list of comma separated words that can include:\n\
       putc ('\n', stdout);
 
       fputs (_("\
-FEATURE is a list of comma separated words that can include:\n\
-  'caret'        show errors with carets\n\
-  'all'          all of the above\n\
-  'none'         disable all of the above\n\
+FEATURES is a list of comma separated words that can include:\n\
+  'caret', 'diagnostics-show-caret'\n\
+    show errors with carets\n\
+  'fixit', 'diagnostics-parseable-fixits'\n\
+    show machine-readable fixes\n\
+  'all'\n\
+    all of the above\n\
+  'none'\n\
+    disable all of the above\n\
   "), stdout);
 
       putc ('\n', stdout);
