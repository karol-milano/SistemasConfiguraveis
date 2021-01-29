@@ -22,13 +22,16 @@
 #include "system.h"
 
 #include <configmake.h> /* PKGDATADIR */
-#include <error.h>
 #include <dirname.h>
+#include <error.h>
 #include <get-errno.h>
 #include <quote.h>
 #include <quotearg.h>
 #include <relocatable.h> /* relocate2 */
 #include <stdio-safer.h>
+#include <sys/stat.h>
+#include <sys/types.h>
+#include <unistd.h>
 #include <xstrndup.h>
 
 #include "complain.h"
@@ -421,6 +424,23 @@ pkgdatadir (void)
     }
 }
 
+char const *
+m4path (void)
+{
+  char const *m4 = getenv ("M4");
+  if (m4)
+    return m4;
+
+  /* We don't use relocate2() to store the temporary buffer and re-use
+     it, because m4path() is only called once.  */
+  char const *m4_relocated = relocate (M4);
+  struct stat buf;
+  if (stat (m4_relocated, &buf) == 0)
+    return m4_relocated;
+
+  return M4;
+}
+
 void
 output_file_names_free (void)
 {
