@@ -883,8 +883,7 @@ lbitset_empty_p (bitset dst)
 
 /* Ensure that any unused bits within the last element are clear.  */
 static inline void
-lbitset_unused_clear (dst)
-     bitset dst;
+lbitset_unused_clear (bitset dst)
 {
   unsigned int last_bit;
   bitset_bindex n_bits;
