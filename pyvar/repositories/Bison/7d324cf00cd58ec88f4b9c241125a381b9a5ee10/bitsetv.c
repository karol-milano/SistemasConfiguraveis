@@ -29,23 +29,19 @@ bitset *
 bitsetv_alloc (bitset_bindex n_vecs, bitset_bindex n_bits,
                enum bitset_type type)
 {
-  size_t vector_bytes;
-  size_t bytes;
-  bitset *bsetv;
-  bitset_bindex i;
-
   /* Determine number of bytes for each set.  */
-  bytes = bitset_bytes (type, n_bits);
+  size_t bytes = bitset_bytes (type, n_bits);
 
   /* If size calculation overflows, memory is exhausted.  */
   if (BITSET_SIZE_MAX / (sizeof (bitset) + bytes) <= n_vecs)
     xalloc_die ();
 
   /* Allocate vector table at head of bitset array.  */
-  vector_bytes = (n_vecs + 1) * sizeof (bitset) + bytes - 1;
+  size_t vector_bytes = (n_vecs + 1) * sizeof (bitset) + bytes - 1;
   vector_bytes -= vector_bytes % bytes;
-  bsetv = xcalloc (1, vector_bytes + bytes * n_vecs);
+  bitset *bsetv = xcalloc (1, vector_bytes + bytes * n_vecs);
 
+  bitset_bindex i = 0;
   for (i = 0; i < n_vecs; i++)
     {
       bsetv[i] = (bitset) (void *) ((char *) bsetv + vector_bytes + i * bytes);
@@ -64,9 +60,7 @@ bitsetv_alloc (bitset_bindex n_vecs, bitset_bindex n_bits,
 bitset *
 bitsetv_create (bitset_bindex n_vecs, bitset_bindex n_bits, unsigned attr)
 {
-  enum bitset_type type;
-
-  type = bitset_type_choose (n_bits, attr);
+  enum bitset_type type = bitset_type_choose (n_bits, attr);
   return bitsetv_alloc (n_vecs, n_bits, type);
 }
 
@@ -75,10 +69,8 @@ bitsetv_create (bitset_bindex n_vecs, bitset_bindex n_bits, unsigned attr)
 void
 bitsetv_free (bitsetv bsetv)
 {
-  bitset_bindex i;
-
-  for (i = 0; bsetv[i]; i++)
-      BITSET_FREE_ (bsetv[i]);
+  for (bitset_bindex i = 0; bsetv[i]; i++)
+    BITSET_FREE_ (bsetv[i]);
   free (bsetv);
 }
 
@@ -87,9 +79,7 @@ bitsetv_free (bitsetv bsetv)
 void
 bitsetv_zero (bitsetv bsetv)
 {
-  bitset_bindex i;
-
-  for (i = 0; bsetv[i]; i++)
+  for (bitset_bindex i = 0; bsetv[i]; i++)
     bitset_zero (bsetv[i]);
 }
 
@@ -98,9 +88,7 @@ bitsetv_zero (bitsetv bsetv)
 void
 bitsetv_ones (bitsetv bsetv)
 {
-  bitset_bindex i;
-
-  for (i = 0; bsetv[i]; i++)
+  for (bitset_bindex i = 0; bsetv[i]; i++)
     bitset_ones (bsetv[i]);
 }
 
@@ -110,11 +98,8 @@ bitsetv_ones (bitsetv bsetv)
 void
 bitsetv_transitive_closure (bitsetv bsetv)
 {
-  bitset_bindex i;
-  bitset_bindex j;
-
-  for (i = 0; bsetv[i]; i++)
-    for (j = 0; bsetv[j]; j++)
+  for (bitset_bindex i = 0; bsetv[i]; i++)
+    for (bitset_bindex j = 0; bsetv[j]; j++)
       if (bitset_test (bsetv[j], i))
         bitset_or (bsetv[j], bsetv[j], bsetv[i]);
 }
@@ -127,10 +112,8 @@ bitsetv_transitive_closure (bitsetv bsetv)
 void
 bitsetv_reflexive_transitive_closure (bitsetv bsetv)
 {
-  bitset_bindex i;
-
   bitsetv_transitive_closure (bsetv);
-  for (i = 0; bsetv[i]; i++)
+  for (bitset_bindex i = 0; bsetv[i]; i++)
     bitset_set (bsetv[i], i);
 }
 
@@ -141,10 +124,8 @@ void
 bitsetv_dump (FILE *file, char const *title, char const *subtitle,
               bitsetv bsetv)
 {
-  bitset_windex i;
-
   fprintf (file, "%s\n", title);
-  for (i = 0; bsetv[i]; i++)
+  for (bitset_windex i = 0; bsetv[i]; i++)
     {
       fprintf (file, "%s %lu\n", subtitle, (unsigned long) i);
       bitset_dump (file, bsetv[i]);
@@ -157,9 +138,7 @@ bitsetv_dump (FILE *file, char const *title, char const *subtitle,
 void
 debug_bitsetv (bitsetv bsetv)
 {
-  bitset_windex i;
-
-  for (i = 0; bsetv[i]; i++)
+  for (bitset_windex i = 0; bsetv[i]; i++)
     {
       fprintf (stderr, "%lu: ", (unsigned long) i);
       debug_bitset (bsetv[i]);
