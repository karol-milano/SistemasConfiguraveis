@@ -23,6 +23,8 @@
 #include "system.h"
 #include "bitset.h"
 #include "getargs.h"
+#include "symtab.h"
+#include "gram.h"
 #include "files.h"
 #include "complain.h"
 #include "derives.h"
@@ -36,7 +38,6 @@
 #include "conflicts.h"
 #include "print_graph.h"
 #include "muscle_tab.h"
-#include "symtab.h"
 #include "lex.h"
 
 /* The name this program was run with, for messages.  */
