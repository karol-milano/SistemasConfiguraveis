@@ -22,6 +22,7 @@
 
 #include <config.h>
 #include "system.h"
+#include "revision.h"
 
 #include <argmatch.h>
 #include <error.h>
@@ -272,6 +273,7 @@ version (void)
      continue.  */
   printf (_("bison (GNU Bison) %s"), VERSION);
   putc ('\n', stdout);
+  printf ("%s", revision);
   fputs (_("Written by Robert Corbett and Richard Stallman.\n"), stdout);
   putc ('\n', stdout);
 
