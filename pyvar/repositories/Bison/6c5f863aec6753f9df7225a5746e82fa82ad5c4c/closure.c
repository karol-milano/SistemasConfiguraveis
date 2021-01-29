@@ -241,7 +241,7 @@ closure (item_number *core, int n)
 void
 free_closure (void)
 {
-  free (itemset);
+  XFREE (itemset);
   bitset_free (ruleset);
   bitsetv_free (fderives);
 }
