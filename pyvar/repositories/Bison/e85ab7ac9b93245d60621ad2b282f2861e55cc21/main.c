@@ -25,6 +25,7 @@
 #include <bitset/stats.h>
 #include <configmake.h>
 #include <progname.h>
+#include <quote.h>
 #include <quotearg.h>
 #include <relocatable.h> /* relocate2 */
 #include <timevar.h>
@@ -38,15 +39,14 @@
 #include "fixits.h"
 #include "getargs.h"
 #include "gram.h"
-#include "lalr.h"
 #include "ielr.h"
+#include "lalr.h"
 #include "muscle-tab.h"
 #include "nullable.h"
 #include "output.h"
+#include "print-xml.h"
 #include "print.h"
 #include "print_graph.h"
-#include "print-xml.h"
-#include <quote.h>
 #include "reader.h"
 #include "reduce.h"
 #include "scan-code.h"
