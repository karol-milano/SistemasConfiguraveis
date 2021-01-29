@@ -60,10 +60,10 @@ closure_print (char const *title, item_index const *array, size_t size)
   for (size_t i = 0; i < size; ++i)
     {
       fprintf (stderr, "  %2d: .", array[i]);
-      item_index *rp;
-      for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
+      item_number *rp;
+      for (rp = &ritem[array[i]]; 0 <= *rp; ++rp)
         fprintf (stderr, " %s", symbols[*rp]->tag);
-      fprintf (stderr, "  (rule %d)\n", -*rp - 1);
+      fprintf (stderr, "  (rule %d)\n", item_number_as_rule_number (*rp));
     }
   fputs ("\n\n", stderr);
 }
