@@ -24,6 +24,7 @@
 
 #include "complain.h"
 #include "files.h"
+#include "fixits.h"
 #include "getargs.h"
 #include "muscle-tab.h"
 #include "quote.h"
@@ -532,6 +533,7 @@ muscle_percent_define_insert (char const *var, location variable_loc,
       i += SUB_INDENT;
       location loc = muscle_percent_define_get_loc (variable);
       complain_indent (&loc, complaint, &i, _("previous definition"));
+      fixits_register (&variable_loc, "");
       warned = true;
     }
 
