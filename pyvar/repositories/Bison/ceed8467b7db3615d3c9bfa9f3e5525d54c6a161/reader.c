@@ -27,14 +27,13 @@
 
    The entry point is reader ().  */
 
-#include <stdio.h>
 #include "system.h"
+#include "getargs.h"
 #include "files.h"
 #include "alloc.h"
 #include "symtab.h"
 #include "lex.h"
 #include "gram.h"
-#include "machine.h"
 #include "complain.h"
 
 #define	LTYPESTR	"\
@@ -62,10 +61,6 @@ typedef\n\
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 static int rline_allocated;
 
-extern int definesflag;
-extern int nolinesflag;
-extern int noparserflag;
-extern int rawtoknumflag;
 extern bucket *symval;
 extern int numval;
 extern int expected_conflicts;
