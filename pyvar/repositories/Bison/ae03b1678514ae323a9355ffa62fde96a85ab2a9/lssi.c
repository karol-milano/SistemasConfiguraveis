@@ -38,7 +38,7 @@ typedef struct lssi
   bool free_lookahead;
 } lssi;
 
-lssi *
+static lssi *
 new_lssi (state_item_number si, lssi *p, bitset l, bool free_l)
 {
   lssi *res = xmalloc (sizeof *res);
@@ -49,7 +49,7 @@ new_lssi (state_item_number si, lssi *p, bitset l, bool free_l)
   return res;
 }
 
-void
+static void
 lssi_free (lssi *sn)
 {
   if (sn == NULL)
@@ -117,7 +117,7 @@ lssi_print (lssi *l)
  * Compute the set of state-items that can reach the given conflict item via
  * a combination of transitions or production steps.
  */
-bitset
+static bitset
 eligible_state_items (state_item *target)
 {
   bitset result = bitset_create (nstate_items, BITSET_FIXED);
