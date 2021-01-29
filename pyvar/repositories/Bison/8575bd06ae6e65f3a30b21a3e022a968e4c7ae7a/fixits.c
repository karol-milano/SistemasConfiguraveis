@@ -33,6 +33,7 @@
 #include "quotearg.h"
 #include "vasnprintf.h"
 
+#include "complain.h"
 #include "files.h"
 
 typedef struct
@@ -97,6 +98,13 @@ fixits_run (void)
   if (!fixits)
     return;
 
+  if (!update_flag)
+    {
+      complain (NULL, Wother,
+                _("some fixes can be applied.  Rerun with option '--update'."));
+      return;
+    }
+
   /* This is not unlike what is done in location_caret.  */
   uniqstr input = ((fixit *) gl_list_get_at (fixits, 0))->location.start.file;
   /* Backup the file. */
