@@ -20,6 +20,7 @@
 
 #include "system.h"
 #include "hash.h"
+#include "quotearg.h"
 #include "files.h"
 #include "muscle_tab.h"
 #include "getargs.h"
@@ -64,7 +65,7 @@ muscle_init (void)
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
-  MUSCLE_INSERT_STRING ("filename", infile);
+  MUSCLE_INSERT_C_STRING ("filename", infile);
 }
 
 
