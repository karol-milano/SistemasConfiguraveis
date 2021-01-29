@@ -21,12 +21,10 @@
 #include <config.h>
 #include "system.h"
 
-#include <configmake.h>
 #include <filename.h> /* IS_PATH_WITH_DIR */
 #include <get-errno.h>
 #include <path-join.h>
 #include <quotearg.h>
-#include <relocatable.h> /* relocate2 */
 #include <spawn-pipe.h>
 #include <timevar.h>
 #include <wait-process.h>
@@ -46,9 +44,6 @@
 
 static struct obstack format_obstack;
 
-/* Memory allocated by relocate2, to free.  */
-static char *relocate_buffer = NULL;
-
 
 /*-------------------------------------------------------------------.
 | Create a function NAME which associates to the muscle NAME the     |
@@ -736,17 +731,4 @@ output (void)
     unlink_generated_sources ();
 
   obstack_free (&format_obstack, NULL);
-  free (relocate_buffer);
-}
-
-char const *
-pkgdatadir (void)
-{
-  if (relocate_buffer)
-    return relocate_buffer;
-  else
-    {
-      char const *cp = getenv ("BISON_PKGDATADIR");
-      return cp ? cp : relocate2 (PKGDATADIR, &relocate_buffer);
-    }
 }
