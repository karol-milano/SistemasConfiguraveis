@@ -24,6 +24,7 @@
 #include <bitset_stats.h>
 #include <bitset.h>
 #include <configmake.h>
+#include <progname.h>
 #include <quotearg.h>
 #include <timevar.h>
 
@@ -57,7 +58,7 @@
 int
 main (int argc, char *argv[])
 {
-  program_name = argv[0];
+  set_program_name (argv[0]);
   setlocale (LC_ALL, "");
   (void) bindtextdomain (PACKAGE, LOCALEDIR);
   (void) bindtextdomain ("bison-runtime", LOCALEDIR);
