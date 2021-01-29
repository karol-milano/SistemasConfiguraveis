@@ -26,6 +26,7 @@
 #include <configmake.h>
 #include <progname.h>
 #include <quotearg.h>
+#include <relocatable.h> /* relocate2 */
 #include <timevar.h>
 
 #include "LR0.h"
@@ -58,10 +59,16 @@
 int
 main (int argc, char *argv[])
 {
+#define DEPENDS_ON_LIBINTL 1
   set_program_name (argv[0]);
   setlocale (LC_ALL, "");
-  (void) bindtextdomain (PACKAGE, LOCALEDIR);
-  (void) bindtextdomain ("bison-runtime", LOCALEDIR);
+  {
+    char *cp = NULL;
+    char const *localedir = relocate2 (LOCALEDIR, &cp);
+    (void) bindtextdomain (PACKAGE, localedir);
+    (void) bindtextdomain ("bison-runtime", localedir);
+    free (cp);
+  }
   (void) textdomain (PACKAGE);
 
   {
