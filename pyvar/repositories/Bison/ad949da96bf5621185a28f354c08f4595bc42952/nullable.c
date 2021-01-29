@@ -25,7 +25,7 @@
 
 #include "system.h"
 #include "getargs.h"
-#include "reader.h"
+#include "symtab.h"
 #include "types.h"
 #include "gram.h"
 #include "reduce.h"
@@ -39,7 +39,7 @@ nullable_print (FILE *out)
   int i;
   fputs ("NULLABLE\n", out);
   for (i = ntokens; i < nsyms; i++)
-    fprintf (out, "\t%s: %s\n", tags[i], nullable[i] ? "yes" : "no");
+    fprintf (out, "\t%s: %s\n", symbols[i]->tag, nullable[i] ? "yes" : "no");
   fputs ("\n\n", out);
 }
 
