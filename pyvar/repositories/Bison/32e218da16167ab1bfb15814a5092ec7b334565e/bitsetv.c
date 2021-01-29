@@ -30,17 +30,21 @@ Software Foundation, 59 Temple Place - Suite 330, Boston, MA
    type TYPE.  */
 bitset *
 bitsetv_alloc (n_vecs, n_bits, type)
-     unsigned int n_vecs;
-     unsigned int n_bits;
+     bitset_bindex n_vecs;
+     bitset_bindex n_bits;
      enum bitset_type type;
 {
-  unsigned int vector_bytes;
-  unsigned int bytes;
+  size_t vector_bytes;
+  size_t bytes;
   bitset *bsetv;
-  unsigned int i;
+  bitset_bindex i;
   
   /* Determine number of bytes for each set.  */
   bytes = bitset_bytes (type, n_bits);
+
+  /* If size calculation overflows, memory is exhausted.  */
+  if (BITSET_SIZE_MAX / (sizeof (bitset) + bytes) <= n_vecs)
+    xalloc_die ();
   
   /* Allocate vector table at head of bitset array.  */
   vector_bytes = (n_vecs + 1) * sizeof (bitset);
@@ -63,8 +67,8 @@ bitsetv_alloc (n_vecs, n_bits, type)
    attribute hints specified by ATTR.  */
 bitset *
 bitsetv_create (n_vecs, n_bits, attr)
-     unsigned int n_vecs;
-     unsigned int n_bits;
+     bitset_bindex n_vecs;
+     bitset_bindex n_bits;
      unsigned int attr;
 {
   enum bitset_type type;
@@ -79,7 +83,7 @@ void
 bitsetv_free (bsetv)
      bitset *bsetv;
 {
-  unsigned int i;
+  bitset_bindex i;
 
   for (i = 0; bsetv[i]; i++)
       BITSET_FREE_ (bsetv[i]);
@@ -92,7 +96,7 @@ void
 bitsetv_zero (bsetv)
      struct bitset_struct **bsetv;
 {
-  unsigned int i;
+  bitset_bindex i;
   
   for (i = 0; bsetv[i]; i++)
     bitset_zero (bsetv[i]);
@@ -104,7 +108,7 @@ void
 bitsetv_ones (bsetv)
      bitset *bsetv;
 {
-  unsigned int i;
+  bitset_bindex i;
   
   for (i = 0; bsetv[i]; i++)
     bitset_ones (bsetv[i]);
@@ -117,8 +121,8 @@ void
 bitsetv_transitive_closure (bsetv)
      bitset *bsetv;
 {
-  unsigned int i;
-  unsigned int j;
+  bitset_bindex i;
+  bitset_bindex j;
 
   for (i = 0; bsetv[i]; i++)
     for (j = 0; bsetv[j]; j++)
@@ -134,7 +138,7 @@ bitsetv_transitive_closure (bsetv)
 void
 bitsetv_reflexive_transitive_closure (bitsetv bsetv)
 {
-  int i;
+  bitset_bindex i;
 
   bitsetv_transitive_closure (bsetv);
   for (i = 0; bsetv[i]; i++)
@@ -150,12 +154,12 @@ bitsetv_dump (file, title, subtitle, bsetv)
      const char *title, *subtitle;
      bitset *bsetv;
 {
-  unsigned int i;
+  bitset_windex i;
   
   fprintf (file, "%s\n", title);
   for (i = 0; bsetv[i]; i++)
     {
-      fprintf (file, "%s %d\n", subtitle, i);
+      fprintf (file, "%s %lu\n", subtitle, (unsigned long) i);
       bitset_dump (file, bsetv[i]);
     }
   
@@ -167,11 +171,11 @@ void
 debug_bitsetv (bsetv)
      bitset *bsetv;
 {
-  unsigned int i;
+  bitset_windex i;
   
   for (i = 0; bsetv[i]; i++)
     {
-      fprintf (stderr, "%d: ", i);
+      fprintf (stderr, "%lu: ", (unsigned long) i);
       debug_bitset (bsetv[i]);
     }
   
