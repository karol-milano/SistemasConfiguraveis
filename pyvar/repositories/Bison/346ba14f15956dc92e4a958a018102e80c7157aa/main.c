@@ -38,6 +38,7 @@
 #include "files.h"
 #include "fixits.h"
 #include "getargs.h"
+#include "glyphs.h"
 #include "gram.h"
 #include "ielr.h"
 #include "lalr.h"
@@ -85,6 +86,7 @@ main (int argc, char *argv[])
 
   atexit (close_stdout);
 
+  glyphs_init ();
   uniqstrs_new ();
   muscle_init ();
   complain_init ();
