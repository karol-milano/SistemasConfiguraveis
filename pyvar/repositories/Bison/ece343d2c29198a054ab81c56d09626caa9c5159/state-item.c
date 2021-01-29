@@ -475,7 +475,7 @@ prune_disabled_paths (void)
 }
 
 void
-print_state_item (const state_item *si, FILE *out, const char *prefix)
+state_item_print (const state_item *si, FILE *out, const char *prefix)
 {
   fputs (prefix, out);
   item_print (si->item, NULL, out);
@@ -506,7 +506,7 @@ state_items_report (void)
           if (si->trans >= 0)
             {
               fputs ("    -> ", stdout);
-              print_state_item (&state_items[si->trans], stdout, "");
+              state_item_print (&state_items[si->trans], stdout, "");
             }
 
           bitset sets[2] = { si->prods, si->revs };
@@ -521,7 +521,7 @@ state_items_report (void)
                   BITSET_FOR_EACH (biter, b, sin, 0)
                     {
                       fputs (txt[seti], stdout);
-                      print_state_item (&state_items[sin], stdout, "");
+                      state_item_print (&state_items[sin], stdout, "");
                     }
                 }
             }
