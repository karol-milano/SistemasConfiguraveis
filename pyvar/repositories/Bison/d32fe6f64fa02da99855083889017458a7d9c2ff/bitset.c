@@ -35,12 +35,12 @@ static void bitset_print PARAMS ((FILE *, bitset, int));
 
 /* Return number of bytes required to create a N_BIT bitset
    of TYPE.  The bitset may grow to require more bytes than this.  */
-int
+size_t
 bitset_bytes (type, n_bits)
      enum bitset_type type;
      bitset_bindex n_bits;
 {
-  unsigned int bytes;
+  size_t bytes;
 
   if (bitset_stats_enabled)
     return bitset_stats_bytes ();
@@ -132,7 +132,7 @@ bitset_alloc (n_bits, type)
      bitset_bindex n_bits;
      enum bitset_type type;
 {
-  unsigned int bytes;
+  size_t bytes;
   bitset bset;
 
   bytes = bitset_bytes (type, n_bits);
@@ -154,7 +154,7 @@ bitset_obstack_alloc (bobstack, n_bits, type)
      bitset_bindex n_bits;
      enum bitset_type type;
 {
-  unsigned int bytes;
+  size_t bytes;
   bitset bset;
 
   bytes = bitset_bytes (type, n_bits);
@@ -229,8 +229,8 @@ bitset_type_name_get (bset)
 
 
 /* Find next bit set in SRC starting from and including BITNO.
-   Return -1 if SRC empty.  */
-int
+   Return BITSET_BINDEX_MAX if SRC empty.  */
+bitset_bindex
 bitset_next (src, bitno)
      bitset src;
      bitset_bindex bitno;
@@ -239,14 +239,14 @@ bitset_next (src, bitno)
   bitset_bindex next = bitno;
 
   if (!bitset_list (src, &val, 1, &next))
-    return -1;
+    return BITSET_BINDEX_MAX;
   return val;
 }
 
 
 /* Find previous bit set in SRC starting from and including BITNO.
-   Return -1 if SRC empty.  */
-int
+   Return BITSET_BINDEX_MAX if SRC empty.  */
+bitset_bindex
 bitset_prev (src, bitno)
      bitset src;
      bitset_bindex bitno;
@@ -255,13 +255,13 @@ bitset_prev (src, bitno)
   bitset_bindex next = bitno;
 
   if (!bitset_list_reverse (src, &val, 1, &next))
-    return -1;
+    return BITSET_BINDEX_MAX;
   return val;
 }
 
 
 /* Find first set bit.   */
-int
+bitset_bindex
 bitset_first (src)
      bitset src;
 {
@@ -270,7 +270,7 @@ bitset_first (src)
 
 
 /* Find last set bit.   */
-int
+bitset_bindex
 bitset_last (src)
      bitset src;
 {
@@ -305,7 +305,8 @@ bitset_print (file, bset, verbose)
   bitset_iterator iter;
 
   if (verbose)
-    fprintf (file, "n_bits = %d, set = {", bitset_size (bset));
+    fprintf (file, "n_bits = %lu, set = {",
+	     (unsigned long) bitset_size (bset));
 
   pos = 30;
   BITSET_FOR_EACH (iter, bset, i, 0)
@@ -368,14 +369,14 @@ bitset_toggle_ (bset, bitno)
 
 
 /* Return number of bits set in bitset SRC.  */
-int
+bitset_bindex
 bitset_count_ (src)
      bitset src;
 {
   bitset_bindex list[BITSET_LIST_SIZE];
   bitset_bindex next;
-  int num;
-  int count;
+  bitset_bindex num;
+  bitset_bindex count;
   
   /* This could be greatly sped up by adding a count method for each
      bitset implementation that uses a direct technique (based on
