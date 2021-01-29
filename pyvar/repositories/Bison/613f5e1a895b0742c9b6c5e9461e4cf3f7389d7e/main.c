@@ -21,6 +21,7 @@
 
 
 #include "system.h"
+#include "bitset_stats.h"
 #include "bitset.h"
 #include "getargs.h"
 #include "symtab.h"
@@ -50,11 +51,12 @@ main (int argc, char *argv[])
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
 
-  bitset_stats_init ();
-
   lineno = 0;
   getargs (argc, argv);
 
+  if (trace_flag)
+    bitset_stats_enable ();
+
   muscle_init ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
@@ -122,5 +124,8 @@ main (int argc, char *argv[])
     alloca (0);
 #endif
 
+    if (trace_flag)
+      bitset_stats_dump (stderr);
+
   return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
 }
