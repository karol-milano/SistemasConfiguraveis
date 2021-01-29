@@ -28,6 +28,7 @@
 #include <timevar.h>
 
 #include "LR0.h"
+#include "closeout.h"
 #include "complain.h"
 #include "conflicts.h"
 #include "derives.h"
@@ -62,6 +63,8 @@ main (int argc, char *argv[])
   (void) bindtextdomain ("bison-runtime", LOCALEDIR);
   (void) textdomain (PACKAGE);
 
+  atexit (close_stdout);
+
   uniqstrs_new ();
   muscle_init ();
 
