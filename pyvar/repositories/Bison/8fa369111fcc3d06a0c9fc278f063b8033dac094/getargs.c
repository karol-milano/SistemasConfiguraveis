@@ -20,7 +20,6 @@
 
 #include <config.h>
 #include "system.h"
-#include "revision.h"
 #include "output.h"
 
 #include <argmatch.h>
@@ -338,7 +337,6 @@ version (void)
      continue.  */
   printf (_("bison (GNU Bison) %s"), VERSION);
   putc ('\n', stdout);
-  printf ("%s", revision);
   fputs (_("Written by Robert Corbett and Richard Stallman.\n"), stdout);
   putc ('\n', stdout);
 
