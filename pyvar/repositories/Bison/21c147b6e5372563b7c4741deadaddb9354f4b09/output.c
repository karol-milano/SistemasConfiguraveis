@@ -42,6 +42,7 @@
 #include "scan-skel.h"
 #include "symtab.h"
 #include "tables.h"
+#include "strversion.h"
 
 static struct obstack format_obstack;
 
@@ -807,6 +808,9 @@ prepare (void)
   char const *cp = getenv ("BISON_USE_PUSH_FOR_PULL");
   bool use_push_for_pull_flag = cp && *cp && strtol (cp, 0, 10);
 
+  /* Versions.  */
+  MUSCLE_INSERT_STRING ("version_string", VERSION);
+  MUSCLE_INSERT_INT ("version", strversion_to_int (VERSION));
   MUSCLE_INSERT_INT ("required_version", required_version);
 
   /* Flags. */
