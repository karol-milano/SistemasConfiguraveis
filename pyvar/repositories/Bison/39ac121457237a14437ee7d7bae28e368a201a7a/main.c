@@ -44,6 +44,7 @@
 #include "print.h"
 #include "print_graph.h"
 #include "print-xml.h"
+#include <quote.h>
 #include "reader.h"
 #include "reduce.h"
 #include "scan-code.h"
@@ -54,7 +55,6 @@
 #include "uniqstr.h"
 
 
-
 int
 main (int argc, char *argv[])
 {
@@ -64,6 +64,14 @@ main (int argc, char *argv[])
   (void) bindtextdomain ("bison-runtime", LOCALEDIR);
   (void) textdomain (PACKAGE);
 
+  {
+    char const *cp = getenv ("LC_CTYPE");
+    if (cp && STREQ (cp, "C"))
+      set_custom_quoting (&quote_quoting_options, "'", "'");
+    else
+      set_quoting_style (&quote_quoting_options, locale_quoting_style);
+  }
+
   atexit (close_stdout);
 
   uniqstrs_new ();
