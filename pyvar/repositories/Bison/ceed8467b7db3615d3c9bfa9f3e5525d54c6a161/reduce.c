@@ -29,17 +29,15 @@ Boston, MA 02111-1307, USA.  */
  * parser.
  */
 
-#include <stdio.h>
 #include "system.h"
+#include "getargs.h"
 #include "files.h"
 #include "gram.h"
-#include "machine.h"
 #include "alloc.h"
 #include "complain.h"
 
 
 extern char   **tags;		/* reader.c */
-extern int      verboseflag;	/* getargs.c */
 static int      statisticsflag;	/* XXXXXXX */
 extern int      fixed_outfiles;
 
