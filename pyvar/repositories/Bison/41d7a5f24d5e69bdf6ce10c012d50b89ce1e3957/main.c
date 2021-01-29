@@ -40,6 +40,7 @@
 #include "output.h"
 #include "print.h"
 #include "print_graph.h"
+#include "print-xml.h"
 #include "reader.h"
 #include "reduce.h"
 #include "scan-code.h"
@@ -151,6 +152,14 @@ main (int argc, char *argv[])
       timevar_pop (TV_GRAPH);
     }
 
+  /* Output xml.  */
+  if (xml_flag)
+    {
+      timevar_push (TV_XML);
+      print_xml ();
+      timevar_pop (TV_XML);
+    }
+
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
   if (complaint_issued)
