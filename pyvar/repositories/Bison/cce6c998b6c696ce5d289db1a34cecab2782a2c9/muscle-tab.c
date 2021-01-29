@@ -21,13 +21,13 @@
 #include "system.h"
 
 #include <hash.h>
+#include <quote.h>
 
 #include "complain.h"
 #include "files.h"
 #include "fixits.h"
 #include "getargs.h"
 #include "muscle-tab.h"
-#include "quote.h"
 
 muscle_kind
 muscle_kind_new (char const *k)
@@ -626,17 +626,17 @@ muscle_percent_define_check_kind (char const *variable, muscle_kind kind)
         {
         case muscle_code:
           complain (&loc, Wdeprecated,
-                    "%%define variable '%s' requires '{...}' values",
+                    _("%%define variable '%s' requires '{...}' values"),
                     variable);
           break;
         case muscle_keyword:
           complain (&loc, Wdeprecated,
-                    "%%define variable '%s' requires keyword values",
+                    _("%%define variable '%s' requires keyword values"),
                     variable);
           break;
         case muscle_string:
           complain (&loc, Wdeprecated,
-                    "%%define variable '%s' requires '\"...\"' values",
+                    _("%%define variable '%s' requires '\"...\"' values"),
                     variable);
           break;
         }
