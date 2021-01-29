@@ -21,6 +21,7 @@ Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
 #include "gram.h"
+#include "reader.h"
 
 void dummy PARAMS((void));
 
@@ -52,10 +53,15 @@ int pure_parser;
 
 int error_token_number;
 
-/* This is to avoid linker problems which occur on VMS when using GCC,
-   when the file in question contains data definitions only.  */
-
 void
-dummy (void)
+ritem_print (FILE *out)
 {
+  int i;
+  fputs ("RITEM\n", out);
+  for (i = 0; ritem[i]; ++i)
+    if (ritem[i] > 0)
+      fprintf (out, "  %s", tags[ritem[i]]);
+    else
+      fprintf (out, "  (rule %d)\n", -ritem[i]);
+  fputs ("\n\n", out);
 }
