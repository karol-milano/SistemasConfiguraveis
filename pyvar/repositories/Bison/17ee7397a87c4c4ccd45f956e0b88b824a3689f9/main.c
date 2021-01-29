@@ -21,26 +21,29 @@
 
 
 #include "system.h"
-#include "bitset_stats.h"
-#include "bitset.h"
-#include "getargs.h"
-#include "struniq.h"
-#include "symtab.h"
-#include "gram.h"
-#include "files.h"
+
+#include <bitset_stats.h>
+#include <bitset.h>
+#include <timevar.h>
+
+#include "LR0.h"
 #include "complain.h"
+#include "conflicts.h"
 #include "derives.h"
-#include "tables.h"
-#include "output.h"
-#include "reader.h"
+#include "files.h"
+#include "getargs.h"
+#include "gram.h"
 #include "lalr.h"
-#include "reduce.h"
+#include "muscle_tab.h"
 #include "nullable.h"
+#include "output.h"
 #include "print.h"
-#include "LR0.h"
-#include "conflicts.h"
 #include "print_graph.h"
-#include "muscle_tab.h"
+#include "reader.h"
+#include "reduce.h"
+#include "symtab.h"
+#include "tables.h"
+#include "uniqstr.h"
 
 /* The name this program was run with, for messages.  */
 char *program_name;
@@ -55,11 +58,11 @@ main (int argc, char *argv[])
   (void) bindtextdomain (PACKAGE, LOCALEDIR);
   (void) textdomain (PACKAGE);
 
-  struniqs_new ();
+  uniqstrs_new ();
 
   getargs (argc, argv);
 
-  time_report = trace_flag & trace_time;
+  timevar_report = trace_flag & trace_time;
   init_timevar ();
   timevar_start (TV_TOTAL);
 
@@ -166,7 +169,7 @@ main (int argc, char *argv[])
      contains things such as user actions, prologue, epilogue etc.  */
   scanner_free ();
   muscle_free ();
-  struniqs_free ();
+  uniqstrs_free ();
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
 #if C_ALLOCA
