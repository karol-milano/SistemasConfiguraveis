@@ -21,6 +21,7 @@
 #include <config.h>
 #include "system.h"
 
+#include <attribute.h>
 #include <error.h>
 #include <hash.h>
 #include <quotearg.h>
@@ -117,12 +118,11 @@ uniqstr_print (uniqstr ustr)
 }
 
 static bool
-uniqstr_print_processor (void *ustr, void *null ATTRIBUTE_UNUSED)
+uniqstr_print_processor (void *ustr, void *null MAYBE_UNUSED)
 {
   return uniqstr_print (ustr);
 }
 
-
 int
 uniqstr_cmp (uniqstr l, uniqstr r)
 {
