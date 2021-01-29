@@ -45,6 +45,7 @@
 #include "muscle-tab.h"
 #include "nullable.h"
 #include "output.h"
+#include "parse-gram.h"
 #include "print-graph.h"
 #include "print-xml.h"
 #include "print.h"
@@ -223,9 +224,12 @@ main (int argc, char *argv[])
   counterexample_free ();
   output_file_names_free ();
 
-  /* The scanner memory cannot be released right after parsing, as it
-     contains things such as user actions, prologue, epilogue etc.  */
+  /* The scanner and parser memory cannot be released right after
+     parsing, as it contains things such as user actions, prologue,
+     epilogue etc.  */
   gram_scanner_free ();
+  parser_free ();
+
   muscle_free ();
   code_scanner_free ();
   skel_scanner_free ();
