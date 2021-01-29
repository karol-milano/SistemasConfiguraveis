@@ -36,12 +36,10 @@
 #include "muscle_tab.h"
 #include "output.h"
 #include "reader.h"
+#include "scan-skel.h"
 #include "symtab.h"
 #include "tables.h"
 
-/* From src/scan-skel.l. */
-void scan_skel (FILE *);
-
 
 static struct obstack format_obstack;
 
@@ -559,7 +557,8 @@ output_skeleton (void)
 
   out = fdopen (filter_fd[0], "w");
   if (! out)
-    error (EXIT_FAILURE, get_errno (), "fdopen");
+    error (EXIT_FAILURE, get_errno (),
+	   "fdopen");
 
   /* Output the definitions of all the muscles.  */
   fputs ("m4_init()\n", out);
@@ -580,7 +579,8 @@ output_skeleton (void)
   timevar_push (TV_M4);
   in = fdopen (filter_fd[1], "r");
   if (! in)
-    error (EXIT_FAILURE, get_errno (), "fdopen");
+    error (EXIT_FAILURE, get_errno (),
+	   "fdopen");
   scan_skel (in);
   xfclose (in);
   reap_subpipe (pid, m4);
