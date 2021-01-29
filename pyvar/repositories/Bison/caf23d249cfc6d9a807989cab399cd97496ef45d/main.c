@@ -39,24 +39,38 @@
 #include "conflicts.h"
 #include "print_graph.h"
 #include "muscle_tab.h"
-#include <malloc.h>
-#include <sys/times.h>
 
 /* The name this program was run with, for messages.  */
 char *program_name;
 
+
+/*--------------------------.
+| Tracking space and time.  |
+`--------------------------*/
+
+#if HAVE_MALLOC_H & HAVE_SYS_TIMES_H
+# include <malloc.h>
+# include <sys/times.h>
+#endif
+
 static void
 stage (const char *title)
 {
-  struct mallinfo minfo = mallinfo ();
-  struct tms tinfo;
-  times (&tinfo);
-  fprintf (stderr, "STAGE: %30s: %9d (%9d): %ldu %lds\n",
-	   title,
-	   minfo.uordblks, minfo.arena,
-	   tinfo.tms_utime, tinfo.tms_stime);
+#if HAVE_MALLOC_H & HAVE_SYS_TIMES_H
+  if (trace_flag)
+    {
+      struct mallinfo minfo = mallinfo ();
+      struct tms tinfo;
+      times (&tinfo);
+      fprintf (stderr, "STAGE: %30s: %9d (%9d): %ldu %lds\n",
+	       title,
+	       minfo.uordblks, minfo.arena,
+	       tinfo.tms_utime, tinfo.tms_stime);
+    }
+#endif
 }
 
+
 int
 main (int argc, char *argv[])
 {
