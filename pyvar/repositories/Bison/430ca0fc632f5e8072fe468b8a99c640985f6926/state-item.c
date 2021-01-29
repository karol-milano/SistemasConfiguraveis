@@ -492,27 +492,26 @@ state_item_rule (const state_item *si)
  * Report the state_item graph
  */
 static void
-state_items_report (void)
+state_items_report (FILE *out)
 {
-  printf ("# state items: %zu\n", nstate_items);
+  fprintf (out, "# state items: %zu\n", nstate_items);
   for (state_number i = 0; i < nstates; ++i)
     {
-      printf ("State %d:\n", i);
+      fprintf (out, "State %d:\n", i);
       for (state_item_number j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
           state_item *si = &state_items[j];
-          item_print (si->item, NULL, stdout);
+          item_print (si->item, NULL, out);
           if (SI_DISABLED (j))
             {
-              item_print (si->item, NULL, stdout);
-              puts (" DISABLED");
+              item_print (si->item, NULL, out);
+              fputs (" DISABLED", out);
               continue;
             }
-          puts ("");
           if (si->trans >= 0)
             {
-              fputs ("    -> ", stdout);
-              state_item_print (&state_items[si->trans], stdout, "");
+              fputs ("    -> ", out);
+              state_item_print (&state_items[si->trans], out, "");
             }
 
           bitset sets[2] = { si->prods, si->revs };
@@ -526,24 +525,23 @@ state_items_report (void)
                   state_item_number sin;
                   BITSET_FOR_EACH (biter, b, sin, 0)
                     {
-                      fputs (txt[seti], stdout);
-                      state_item_print (&state_items[sin], stdout, "");
+                      fputs (txt[seti], out);
+                      state_item_print (&state_items[sin], out, "");
                     }
                 }
             }
-          puts ("");
         }
     }
-  printf ("FIRSTS\n");
+  fprintf (out, "FIRSTS\n");
   for (symbol_number i = ntokens; i < nsyms; ++i)
     {
-      printf ("  %s firsts\n", symbols[i]->tag);
+      fprintf (out, "  %s firsts\n", symbols[i]->tag);
       bitset_iterator iter;
       symbol_number j;
       BITSET_FOR_EACH (iter, FIRSTS (i), j, 0)
-        printf ("    %s\n", symbols[j]->tag);
+        fprintf (out, "    %s\n", symbols[j]->tag);
     }
-  puts ("\n");
+  fputc ('\n', out);
 }
 
 void
@@ -558,8 +556,8 @@ state_items_init (void)
   prune_disabled_paths ();
   if (trace_flag & trace_cex)
     {
-      printf ("init: %f\n", difftime (time (NULL), start));
-      state_items_report ();
+      fprintf (stderr, "init: %f\n", difftime (time (NULL), start));
+      state_items_report (stderr);
     }
 }
 
