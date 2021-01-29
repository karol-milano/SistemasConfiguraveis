@@ -31,11 +31,7 @@
 #include "reduce.h"
 #include "nullable.h"
 #include "print.h"
-
-#if 0				/* XXX currently unused.  */
-/* Nonzero means failure has been detected; don't write a parser file.  */
-static int failure;
-#endif
+#include "LR0.h"
 
 /* The name this program was run with, for messages.  */
 char *program_name;
@@ -44,13 +40,6 @@ extern void berror PARAMS((const char *));
 
 extern char *printable_version PARAMS ((int));
 
-extern void generate_states PARAMS ((void));
-extern void initialize_conflicts PARAMS ((void));
-extern void finalize_conflicts PARAMS ((void));
-
-
-/* VMS complained about using `int'.  */
-
 int
 main (int argc, char *argv[])
 {
