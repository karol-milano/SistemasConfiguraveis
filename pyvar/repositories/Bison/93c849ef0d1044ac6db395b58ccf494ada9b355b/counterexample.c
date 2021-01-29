@@ -23,7 +23,6 @@
 #include <hash.h>
 #include <stdlib.h>
 #include <gl_linked_list.h>
-#include <gl_xlist.h>
 #include <gl_rbtreehash_list.h>
 
 #include "closure.h"
@@ -82,21 +81,22 @@ new_counterexample (const derivation *d1, const derivation *d2,
 void
 print_counterexample (counterexample *cex)
 {
+  FILE *out = stderr;
   if (cex->unifying)
-    printf ("Example ");
+    fprintf (out, "Example  ");
   else
-    printf ("First  Example");
-  derivation_print_leaves (cex->d1, stdout);
-  printf ("\nFirst  derivation ");
-  derivation_print (cex->d1, stdout);
+    fprintf (out, "First  Example ");
+  derivation_print_leaves (cex->d1, out);
+  fprintf (out, "\nFirst  derivation ");
+  derivation_print (cex->d1, out);
   if (!cex->unifying)
     {
-      printf ("\nSecond Example ");
-      derivation_print_leaves (cex->d2, stdout);
+      fprintf (out, "\nSecond Example ");
+      derivation_print_leaves (cex->d2, out);
     }
-  printf ("\nSecond derivation ");
-  derivation_print (cex->d2, stdout);
-  fputs ("\n\n", stdout);
+  fprintf (out, "\nSecond derivation ");
+  derivation_print (cex->d2, out);
+  fputs ("\n\n", out);
 }
 
 /*
@@ -167,7 +167,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
   gl_list_t queue = gl_list_create (GL_LINKED_LIST, NULL, NULL,
                                     (gl_listelement_dispose_fn) si_bfs_free,
                                     true, 1, (const void **) &init);
-  si_bfs_node *node;
+  si_bfs_node *node = NULL;
   // breadth-first search for a path of productions to the conflict symbol
   while (gl_list_size (queue) > 0)
     {
@@ -463,11 +463,11 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
     }
   if (trace_flag & trace_cex)
     {
-      puts ("SHIFT ITEM PATH:");
+      fputs ("SHIFT ITEM PATH:\n", stderr);
       gl_list_iterator_t it = gl_list_iterator (result);
       state_item *sip;
       while (gl_list_iterator_next (&it, (const void **) &sip, NULL))
-        print_state_item (sip, stdout);
+        print_state_item (sip, stderr);
     }
   return result;
 }
@@ -562,11 +562,11 @@ search_state_free (search_state *ss)
 static void
 search_state_print (search_state *ss)
 {
-  fputs ("CONFLICT 1 ", stdout);
+  fputs ("CONFLICT 1 ", stderr);
   print_parse_state (ss->states[0]);
-  fputs ("CONFLICT 2 ", stdout);
+  fputs ("CONFLICT 2 ", stderr);
   print_parse_state (ss->states[1]);
-  putc ('\n', stdout);
+  putc ('\n', stderr);
 }
 
 /*
@@ -1071,13 +1071,14 @@ unifying_example (state_item_number itm1,
               if (!assurance_printed && time_passed > ASSURANCE_LIMIT
                   && stage3result)
                 {
-                  puts
-                    ("Productions leading up to the conflict state found.  Still finding a possible unifying counterexample...");
+                  fputs ("Productions leading up to the conflict state found.  "
+                         "Still finding a possible unifying counterexample...",
+                         stderr);
                   assurance_printed = true;
                 }
               if (time_passed > TIME_LIMIT)
                 {
-                  printf ("time limit exceeded: %f\n", time_passed);
+                  fprintf (stderr, "time limit exceeded: %f\n", time_passed);
                   goto cex_search_end;
                 }
             }
@@ -1171,10 +1172,11 @@ void
 counterexample_report_shift_reduce (state_item_number itm1, state_item_number itm2,
                                     symbol_number next_sym)
 {
-  puts ("Shift-Reduce Conflict:");
-  print_state_item (&state_items[itm1], stdout);
-  print_state_item (&state_items[itm2], stdout);
-  printf ("On Symbol: %s\n", symbols[next_sym]->tag);
+  FILE *out = stderr;
+  fputs ("Shift-Reduce Conflict:\n", out);
+  print_state_item (&state_items[itm1], out);
+  print_state_item (&state_items[itm2], out);
+  fprintf (out, "On Symbol: %s\n", symbols[next_sym]->tag);
   counterexample_report (itm1, itm2, next_sym, true);
 }
 
@@ -1182,16 +1184,15 @@ void
 counterexample_report_reduce_reduce (state_item_number itm1, state_item_number itm2,
                                      bitset conflict_syms)
 {
-  puts ("Reduce-Reduce Conflict:");
-  print_state_item (&state_items[itm1], stdout);
-  print_state_item (&state_items[itm2], stdout);
-  fputs ("On Symbols: {", stdout);
+  FILE *out = stderr;
+  fputs ("Reduce-Reduce Conflict:\n", out);
+  print_state_item (&state_items[itm1], out);
+  print_state_item (&state_items[itm2], out);
+  fputs ("On Symbols: {", out);
   bitset_iterator biter;
   state_item_number sym;
   BITSET_FOR_EACH (biter, conflict_syms, sym, 0)
-    {
-      printf ("%s,", symbols[sym]->tag);
-    }
-  fputs ("}\n", stdout);
+    fprintf (out, "%s,", symbols[sym]->tag);
+  fputs ("}\n", out);
   counterexample_report (itm1, itm2, bitset_first (conflict_syms), false);
 }
