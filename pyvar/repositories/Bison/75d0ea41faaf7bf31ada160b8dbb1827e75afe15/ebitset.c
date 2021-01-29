@@ -121,9 +121,7 @@ static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
 
 
 static bitset_bindex
-ebitset_resize (src, n_bits)
-     bitset src;
-     bitset_bindex n_bits;
+ebitset_resize (bitset src, bitset_bindex n_bits)
 {
   bitset_windex oldsize;
   bitset_windex newsize;
@@ -838,8 +836,7 @@ ebitset_list (bitset bset, bitset_bindex *list,
 
 /* Ensure that any unused bits within the last element are clear.  */
 static inline void
-ebitset_unused_clear (dst)
-     bitset dst;
+ebitset_unused_clear (bitset dst)
 {
   unsigned int last_bit;
   bitset_bindex n_bits;
