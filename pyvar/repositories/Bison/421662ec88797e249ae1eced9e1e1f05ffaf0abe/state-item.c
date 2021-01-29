@@ -563,7 +563,7 @@ void
 state_items_free (void)
 {
   for (int i = 0; i < nstate_items; ++i)
-    if (!SI_DISABLED(i))
+    if (!SI_DISABLED (i))
       {
         state_item *si = state_items + i;
         if (si->prods)
