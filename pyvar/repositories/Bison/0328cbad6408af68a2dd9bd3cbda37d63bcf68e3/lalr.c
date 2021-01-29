@@ -40,7 +40,6 @@
 #include "relation.h"
 #include "symtab.h"
 
-/* goto_map[nterm - NTOKENS] -> number of gotos.  */
 goto_number *goto_map = NULL;
 goto_number ngotos = 0;
 state_number *from_state = NULL;
@@ -99,6 +98,8 @@ void
 set_goto_map (void)
 {
   /* Count the number of gotos (ngotos) per nterm (goto_map). */
+  if (trace_flag & trace_automaton)
+    fprintf (stderr, "nnterms: %d\n", nnterms);
   goto_map = xcalloc (nnterms + 1, sizeof *goto_map);
   ngotos = 0;
   for (state_number s = 0; s < nstates; ++s)
@@ -146,11 +147,17 @@ set_goto_map (void)
   free (temp_map);
 
   if (trace_flag & trace_automaton)
-    for (int i = 0; i < ngotos; ++i)
-      {
-        goto_print (i, stderr);
-        fputc ('\n', stderr);
-      }
+    {
+      for (int i = 0; i < nnterms; ++i)
+        fprintf (stderr, "goto_map[%d (%s)] = %ld .. %ld\n",
+                 i, symbols[ntokens + i]->tag,
+                 goto_map[i], goto_map[i+1] - 1);
+      for (int i = 0; i < ngotos; ++i)
+        {
+          goto_print (i, stderr);
+          fputc ('\n', stderr);
+        }
+    }
 }
 
 
@@ -158,6 +165,7 @@ goto_number
 map_goto (state_number src, symbol_number sym)
 {
   goto_number low = goto_map[sym - ntokens];
+  assert (goto_map[sym - ntokens] != goto_map[sym - ntokens + 1]);
   goto_number high = goto_map[sym - ntokens + 1] - 1;
 
   for (;;)
