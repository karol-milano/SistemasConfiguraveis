@@ -21,10 +21,10 @@
 #include <config.h>
 #include "system.h"
 
-#include <concat-filename.h>
 #include <configmake.h>
-#include <filename.h>
+#include <filename.h> /* IS_PATH_WITH_DIR */
 #include <get-errno.h>
+#include <path-join.h>
 #include <quotearg.h>
 #include <spawn-pipe.h>
 #include <timevar.h>
@@ -531,11 +531,11 @@ output_skeleton (void)
   /* Compute the names of the package data dir and skeleton files.  */
   char const *m4 = (m4 = getenv ("M4")) ? m4 : M4;
   char const *datadir = pkgdatadir ();
-  char *m4sugar = xconcatenated_filename (datadir, "m4sugar/m4sugar.m4", NULL);
-  char *m4bison = xconcatenated_filename (datadir, "bison.m4", NULL);
+  char *m4sugar = xpath_join (datadir, "m4sugar/m4sugar.m4");
+  char *m4bison = xpath_join (datadir, "bison.m4");
   char *skel = (IS_PATH_WITH_DIR (skeleton)
                 ? xstrdup (skeleton)
-                : xconcatenated_filename (datadir, skeleton, NULL));
+                : xpath_join (datadir, skeleton));
 
   /* Test whether m4sugar.m4 is readable, to check for proper
      installation.  A faulty installation can cause deadlock, so a
