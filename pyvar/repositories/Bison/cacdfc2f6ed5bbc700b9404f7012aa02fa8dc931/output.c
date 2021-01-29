@@ -38,6 +38,7 @@
 #include "muscle-tab.h"
 #include "output.h"
 #include "reader.h"
+#include "reduce.h"
 #include "scan-code.h"    /* max_left_semantic_context */
 #include "scan-skel.h"
 #include "symtab.h"
@@ -414,6 +415,14 @@ merger_output (FILE *out)
 static void
 prepare_symbol_definitions (void)
 {
+  /* Map "orig NUM" to new numbers.  See data/README.  */
+  for (symbol_number i = ntokens; i < nsyms + nuseless_nonterminals; ++i)
+    {
+      obstack_printf (&format_obstack, "symbol(orig %d, number)", i);
+      const char *key = obstack_finish0 (&format_obstack);
+      MUSCLE_INSERT_INT (key, nterm_map ? nterm_map[i - ntokens] : i);
+    }
+
   for (int i = 0; i < nsyms; ++i)
     {
       symbol *sym = symbols[i];
