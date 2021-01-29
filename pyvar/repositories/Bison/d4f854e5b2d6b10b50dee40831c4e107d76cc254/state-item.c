@@ -477,9 +477,9 @@ prune_disabled_paths (void)
 }
 
 void
-print_state_item (const state_item *si, FILE *out)
+print_state_item (const state_item *si, FILE *out, const char *prefix)
 {
-  fprintf (out, "%d:", si->state->number);
+  fputs (prefix, out);
   item_print (si->item, NULL, out);
   putc ('\n', out);
 }
@@ -508,7 +508,7 @@ state_items_report (void)
           if (si->trans >= 0)
             {
               fputs ("    -> ", stdout);
-              print_state_item (state_items + si->trans, stdout);
+              print_state_item (state_items + si->trans, stdout, "");
             }
 
           bitset sets[2] = { si->prods, si->revs };
@@ -523,7 +523,7 @@ state_items_report (void)
                   BITSET_FOR_EACH (biter, b, sin, 0)
                     {
                       fputs (txt[seti], stdout);
-                      print_state_item (state_items + sin, stdout);
+                      print_state_item (state_items + sin, stdout, "");
                     }
                 }
             }
