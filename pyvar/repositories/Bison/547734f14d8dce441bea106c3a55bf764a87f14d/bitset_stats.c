@@ -576,11 +576,9 @@ bitset_stats_list (bitset bset, bitset_bindex *list,
   bitset_bindex tmp;
   bitset_bindex size;
   bitset_bindex i;
-  enum bitset_type type;
 
   count = BITSET_LIST_ (bset->s.bset, list, num, next);
 
-  type = BITSET_TYPE_ (bset->s.bset);
   BITSET_STATS_LISTS_INC (bset->s.bset);
 
   /* Log histogram of number of set bits.  */
