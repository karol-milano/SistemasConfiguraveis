@@ -101,7 +101,7 @@ bitset_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
    specified by ATTR.  For variable size bitsets, N_BITS is only a
    hint and may be zero.  */
 enum bitset_type
-bitset_type_choose (bitset_bindex n_bits ATTRIBUTE_UNUSED, unsigned int attr)
+bitset_type_choose (bitset_bindex n_bits ATTRIBUTE_UNUSED, unsigned attr)
 {
   /* Check attributes.  */
   if (attr & BITSET_FIXED && attr & BITSET_VARIABLE)
@@ -169,7 +169,7 @@ bitset_obstack_alloc (struct obstack *bobstack,
 /* Create a bitset of N_BITS and with attribute hints specified by
    ATTR.  */
 bitset
-bitset_create (bitset_bindex n_bits, unsigned int attr)
+bitset_create (bitset_bindex n_bits, unsigned attr)
 {
   enum bitset_type type;
 
@@ -291,13 +291,13 @@ bitset_only_set_p (bitset src, bitset_bindex bitno)
 static void
 bitset_print (FILE *file, bitset bset, bool verbose)
 {
-  unsigned int pos;
+  unsigned pos;
   bitset_bindex i;
   bitset_iterator iter;
 
   if (verbose)
     fprintf (file, "n_bits = %lu, set = {",
-             (unsigned long int) bitset_size (bset));
+             (unsigned long) bitset_size (bset));
 
   pos = 30;
   BITSET_FOR_EACH (iter, bset, i, 0)
@@ -308,7 +308,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
         pos = 0;
       }
 
-    fprintf (file, "%lu ", (unsigned long int) i);
+    fprintf (file, "%lu ", (unsigned long) i);
     pos += 1 + (i >= 10) + (i >= 100);
   };
 
