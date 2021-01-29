@@ -25,6 +25,7 @@
 #include "hash.h"
 #include "files.h"
 #include "muscle_tab.h"
+#include "getargs.h"
 
 struct hash_table muscle_table;
 
@@ -55,6 +56,9 @@ muscle_init (void)
   muscle_insert ("version", VERSION);
   muscle_insert ("filename", infile);
 
+  /* Skeleton use.  */
+  muscle_insert ("skeleton", skeleton);
+
   /* Types.  */
   muscle_insert ("stype", "int");
   muscle_insert ("ltype", "yyltype");
