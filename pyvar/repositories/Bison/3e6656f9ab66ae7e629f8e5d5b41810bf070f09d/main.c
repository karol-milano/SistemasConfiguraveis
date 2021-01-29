@@ -24,6 +24,7 @@
 #include "bitset_stats.h"
 #include "bitset.h"
 #include "getargs.h"
+#include "struniq.h"
 #include "symtab.h"
 #include "gram.h"
 #include "files.h"
@@ -63,6 +64,7 @@ main (int argc, char *argv[])
   if (trace_flag & trace_bitsets)
     bitset_stats_enable ();
 
+  struniqs_new ();
   muscle_init ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
@@ -165,6 +167,7 @@ main (int argc, char *argv[])
      contains things such as user actions, prologue, epilogue etc.  */
   scanner_free ();
   muscle_free ();
+  struniqs_free ();
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
 #if C_ALLOCA
