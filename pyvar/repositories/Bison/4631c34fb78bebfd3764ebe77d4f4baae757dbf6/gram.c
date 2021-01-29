@@ -23,11 +23,12 @@
 
 #include <quotearg.h>
 
+#include "complain.h"
 #include "gram.h"
+#include "print-xml.h"
 #include "reader.h"
 #include "reduce.h"
 #include "symtab.h"
-#include "print-xml.h"
 
 /* Comments for these variables are in gram.h.  */
 
@@ -308,9 +309,9 @@ grammar_rules_useless_report (const char *message)
   for (r = 0; r < nrules ; ++r)
     if (!rules[r].useful)
       {
-	location_print (stderr, rules[r].location);
-	fprintf (stderr, ": %s: %s: ", _("warning"), message);
-	rule_print (&rules[r], stderr);
+        warn_at (rules[r].location, "%s: ", message);
+        rule_print (&rules[r], stderr);
+        fflush (stderr);
       }
 }
 
