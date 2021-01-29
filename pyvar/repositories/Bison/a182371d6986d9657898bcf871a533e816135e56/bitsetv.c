@@ -29,35 +29,33 @@ Software Foundation, 59 Temple Place - Suite 330, Boston, MA
 /* Create a vector of N_VECS bitsets, each of N_BITS, and of
    type TYPE.  */
 bitset *
-bitsetv_alloc (n_vecs, n_bits, type)
-     bitset_bindex n_vecs;
-     bitset_bindex n_bits;
-     enum_bitset_type type;
+bitsetv_alloc (bitset_bindex n_vecs, bitset_bindex n_bits,
+	       enum bitset_type type)
 {
   size_t vector_bytes;
   size_t bytes;
   bitset *bsetv;
   bitset_bindex i;
-  
+
   /* Determine number of bytes for each set.  */
   bytes = bitset_bytes (type, n_bits);
 
   /* If size calculation overflows, memory is exhausted.  */
   if (BITSET_SIZE_MAX / (sizeof (bitset) + bytes) <= n_vecs)
     xalloc_die ();
-  
+
   /* Allocate vector table at head of bitset array.  */
   vector_bytes = (n_vecs + 1) * sizeof (bitset) + bytes - 1;
   vector_bytes -= vector_bytes % bytes;
   bsetv = (bitset *) xcalloc (1, vector_bytes + bytes * n_vecs);
-  
+
   for (i = 0; i < n_vecs; i++)
     {
       bsetv[i] = (bitset) (void *) ((char *) bsetv + vector_bytes + i * bytes);
-      
+
       bitset_init (bsetv[i], n_bits, type);
     }
-  
+
   /* Null terminate table.  */
   bsetv[i] = 0;
   return bsetv;
@@ -67,13 +65,10 @@ bitsetv_alloc (n_vecs, n_bits, type)
 /* Create a vector of N_VECS bitsets, each of N_BITS, and with
    attribute hints specified by ATTR.  */
 bitset *
-bitsetv_create (n_vecs, n_bits, attr)
-     bitset_bindex n_vecs;
-     bitset_bindex n_bits;
-     unsigned int attr;
+bitsetv_create (bitset_bindex n_vecs, bitset_bindex n_bits, unsigned int attr)
 {
   enum bitset_type type;
-  
+
   type = bitset_type_choose (n_bits, attr);
   return bitsetv_alloc (n_vecs, n_bits, type);
 }
@@ -81,8 +76,7 @@ bitsetv_create (n_vecs, n_bits, attr)
 
 /* Free bitset vector BSETV.  */
 void
-bitsetv_free (bsetv)
-     bitset *bsetv;
+bitsetv_free (bitsetv bsetv)
 {
   bitset_bindex i;
 
@@ -94,11 +88,10 @@ bitsetv_free (bsetv)
 
 /* Zero a vector of bitsets.  */
 void
-bitsetv_zero (bsetv)
-     bitsetv bsetv;
+bitsetv_zero (bitsetv bsetv)
 {
   bitset_bindex i;
-  
+
   for (i = 0; bsetv[i]; i++)
     bitset_zero (bsetv[i]);
 }
@@ -106,11 +99,10 @@ bitsetv_zero (bsetv)
 
 /* Set a vector of bitsets to ones.  */
 void
-bitsetv_ones (bsetv)
-     bitset *bsetv;
+bitsetv_ones (bitsetv bsetv)
 {
   bitset_bindex i;
-  
+
   for (i = 0; bsetv[i]; i++)
     bitset_ones (bsetv[i]);
 }
@@ -119,8 +111,7 @@ bitsetv_ones (bsetv)
 /* Given a vector BSETV of N bitsets of size N, modify its contents to
    be the transitive closure of what was given.  */
 void
-bitsetv_transitive_closure (bsetv)
-     bitset *bsetv;
+bitsetv_transitive_closure (bitsetv bsetv)
 {
   bitset_bindex i;
   bitset_bindex j;
@@ -128,12 +119,12 @@ bitsetv_transitive_closure (bsetv)
   for (i = 0; bsetv[i]; i++)
     for (j = 0; bsetv[j]; j++)
       if (bitset_test (bsetv[j], i))
-        bitset_or (bsetv[j], bsetv[j], bsetv[i]);
+	bitset_or (bsetv[j], bsetv[j], bsetv[i]);
 }
 
 
 /* Given a vector BSETV of N bitsets of size N, modify its contents to
-   be the reflexive transitive closure of what was given.  This is 
+   be the reflexive transitive closure of what was given.  This is
    the same as transitive closure but with all bits on the diagonal
    of the bit matrix set.  */
 void
@@ -150,35 +141,32 @@ bitsetv_reflexive_transitive_closure (bitsetv bsetv)
 /* Dump the contents of a bitset vector BSETV with N_VECS elements to
    FILE.  */
 void
-bitsetv_dump (file, title, subtitle, bsetv)
-     FILE *file;
-     const char *title, *subtitle;
-     bitset *bsetv;
+bitsetv_dump (FILE *file, char const *title, char const *subtitle,
+	      bitsetv bsetv)
 {
   bitset_windex i;
-  
+
   fprintf (file, "%s\n", title);
   for (i = 0; bsetv[i]; i++)
     {
       fprintf (file, "%s %lu\n", subtitle, (unsigned long) i);
       bitset_dump (file, bsetv[i]);
     }
-  
+
   fprintf (file, "\n");
 }
 
 
 void
-debug_bitsetv (bsetv)
-     bitset *bsetv;
+debug_bitsetv (bitsetv bsetv)
 {
   bitset_windex i;
-  
+
   for (i = 0; bsetv[i]; i++)
     {
       fprintf (stderr, "%lu: ", (unsigned long) i);
       debug_bitset (bsetv[i]);
     }
-  
+
   fprintf (stderr, "\n");
 }
