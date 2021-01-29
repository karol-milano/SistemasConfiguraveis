@@ -24,6 +24,7 @@
 #include <quotearg.h>
 
 #include "complain.h"
+#include "getargs.h"
 #include "gram.h"
 #include "print-xml.h"
 #include "reader.h"
@@ -310,8 +311,11 @@ grammar_rules_useless_report (const char *message)
     if (!rules[r].useful)
       {
         warn_at (rules[r].location, "%s: ", message);
-        rule_print (&rules[r], stderr);
-        fflush (stderr);
+        if (warnings_flag & warnings_other)
+          {
+            rule_print (&rules[r], stderr);
+            fflush (stderr);
+          }
       }
 }
 
