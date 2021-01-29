@@ -21,11 +21,13 @@
 #include <config.h>
 #include "system.h"
 
+#include <configmake.h> /* PKGDATADIR */
 #include <error.h>
 #include <dirname.h>
 #include <get-errno.h>
 #include <quote.h>
 #include <quotearg.h>
+#include <relocatable.h> /* relocate2 */
 #include <stdio-safer.h>
 #include <xstrndup.h>
 
@@ -404,6 +406,21 @@ unlink_generated_sources (void)
       unlink (generated_files[i].name);
 }
 
+/* Memory allocated by relocate2, to free.  */
+static char *relocate_buffer = NULL;
+
+char const *
+pkgdatadir (void)
+{
+  if (relocate_buffer)
+    return relocate_buffer;
+  else
+    {
+      char const *cp = getenv ("BISON_PKGDATADIR");
+      return cp ? cp : relocate2 (PKGDATADIR, &relocate_buffer);
+    }
+}
+
 void
 output_file_names_free (void)
 {
@@ -417,4 +434,5 @@ output_file_names_free (void)
   for (int i = 0; i < generated_files_size; i++)
     free (generated_files[i].name);
   free (generated_files);
+  free (relocate_buffer);
 }
