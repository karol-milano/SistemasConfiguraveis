@@ -241,7 +241,7 @@ closure (item_number *core, int n)
 void
 free_closure (void)
 {
-  XFREE (itemset);
+  free (itemset);
   bitset_free (ruleset);
   bitsetv_free (fderives);
 }
