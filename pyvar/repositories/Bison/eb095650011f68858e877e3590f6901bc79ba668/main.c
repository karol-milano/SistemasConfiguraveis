@@ -26,6 +26,7 @@
 #include <bitset_stats.h>
 #include <bitset.h>
 #include <configmake.h>
+#include <quotearg.h>
 #include <timevar.h>
 
 #include "LR0.h"
@@ -43,6 +44,7 @@
 #include "print_graph.h"
 #include "reader.h"
 #include "reduce.h"
+#include "scan-code.h"
 #include "scan-gram.h"
 #include "symtab.h"
 #include "tables.h"
@@ -168,12 +170,15 @@ main (int argc, char *argv[])
   reduce_free ();
   conflicts_free ();
   grammar_free ();
+  output_file_names_free ();
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
   gram_scanner_free ();
   muscle_free ();
   uniqstrs_free ();
+  code_scanner_free ();
+  quotearg_free ();
   timevar_pop (TV_FREE);
 
   if (trace_flag & trace_bitsets)
