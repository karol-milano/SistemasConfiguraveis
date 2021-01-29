@@ -1,4 +1,4 @@
-/* Lookahead sensative state item searches for counterexample generation
+/* Lookahead sensitive state item searches for counterexample generation
 
    Copyright (C) 2020 Free Software Foundation, Inc.
 
@@ -19,16 +19,16 @@
 
 #include <config.h>
 
-#include <stdlib.h>
+#include "lssi.h"
 
 #include <gl_linked_list.h>
 #include <gl_xlist.h>
+#include <stdlib.h>
 
 #include "getargs.h"
-#include "lssi.h"
 #include "nullable.h"
 
-// lookahead sensative state item
+// Lookahead sensitive state item.
 typedef struct lssi
 {
   state_item_number si;
