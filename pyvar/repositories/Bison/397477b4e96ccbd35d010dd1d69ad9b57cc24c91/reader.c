@@ -22,7 +22,6 @@
 
 #include "system.h"
 #include "quotearg.h"
-#include "quote.h"
 #include "getargs.h"
 #include "files.h"
 #include "symtab.h"
@@ -138,8 +137,8 @@ get_merge_function (const char* name, const char* type,
       merge_functions = head.next;
     }
   else if (strcmp (type, syms->next->type) != 0)
-    warn_at (loc, _("result type clash on merge function %s: `%s' vs. `%s'"),
-	     name, type, syms->next->type);
+    warn_at (loc, _("result type clash (`%s' `%s') on merge function %s"),
+	     type, syms->next->type, name);
   return n;
 }
 
