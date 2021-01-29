@@ -21,19 +21,19 @@
 
 #include "fixits.h"
 
-#include "system.h"
+#include <error.h>
+#include <get-errno.h>
+#include <gl_array_list.h>
+#include <gl_xlist.h>
+#include <progname.h>
+#include <quote.h>
+#include <quotearg.h>
+#include <vasnprintf.h>
 
-#include "error.h"
-#include "get-errno.h"
-#include "getargs.h"
-#include "gl_array_list.h"
-#include "gl_xlist.h"
-#include "progname.h"
-#include "quote.h"
-#include "quotearg.h"
-#include "vasnprintf.h"
+#include "system.h"
 
 #include "files.h"
+#include "getargs.h"
 
 typedef struct
 {
