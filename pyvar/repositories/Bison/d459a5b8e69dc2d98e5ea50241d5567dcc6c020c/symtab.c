@@ -23,6 +23,7 @@
 
 #include "system.h"
 
+#include <assure.h>
 #include <hash.h>
 
 #include "complain.h"
@@ -865,9 +866,9 @@ dummy_symbol_get (location loc)
 {
   /* Incremented for each generated symbol.  */
   static int dummy_count = 0;
-  static char buf[256];
-
-  sprintf (buf, "$@%d", ++dummy_count);
+  char buf[32];
+  int len = snprintf (buf, sizeof buf, "$@%d", ++dummy_count);
+  assure (len < sizeof buf);
   symbol *sym = symbol_get (buf, loc);
   sym->content->class = nterm_sym;
   sym->content->number = nvars++;
