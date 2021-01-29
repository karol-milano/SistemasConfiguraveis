@@ -30,29 +30,32 @@ Software Foundation, 59 Temple Place - Suite 330, Boston, MA
    type TYPE.  */
 bitset *
 bitsetv_alloc (n_vecs, n_bits, type)
-    unsigned int n_vecs;
-    unsigned int n_bits;
-    enum bitset_type type;
+     unsigned int n_vecs;
+     unsigned int n_bits;
+     enum bitset_type type;
 {
-    unsigned int vector_bytes;
-    unsigned int bytes;
-    bitset *bsetv;
-    unsigned int i;
-
-    /* Determine number of bytes for each set.  */
-    bytes = bitset_bytes (type, n_bits);
-
-    /* Allocate vector table at head of bitset array.  */
-    vector_bytes = n_vecs * sizeof (bitset);
-    bsetv = (bitset *) xmalloc (vector_bytes + bytes * n_vecs);
-
-    for (i = 0; i < n_vecs; i++)
+  unsigned int vector_bytes;
+  unsigned int bytes;
+  bitset *bsetv;
+  unsigned int i;
+  
+  /* Determine number of bytes for each set.  */
+  bytes = bitset_bytes (type, n_bits);
+  
+  /* Allocate vector table at head of bitset array.  */
+  vector_bytes = (n_vecs + 1) * sizeof (bitset);
+  bsetv = (bitset *) xcalloc (1, vector_bytes + bytes * n_vecs);
+  
+  for (i = 0; i < n_vecs; i++)
     {
-      bsetv[i] = (bitset)((char *)bsetv + vector_bytes + i * bytes);
+      bsetv[i] = (bitset) ((char *) bsetv + vector_bytes + i * bytes);
 
       bitset_init (bsetv[i], n_bits, type);
     }
-    return bsetv;
+  
+  /* Null terminate table.  */
+  bsetv[i] = 0;
+  return bsetv;
 }
 
 
@@ -60,48 +63,50 @@ bitsetv_alloc (n_vecs, n_bits, type)
    attribute hints specified by ATTR.  */
 bitset *
 bitsetv_create (n_vecs, n_bits, attr)
-    unsigned int n_vecs;
-    unsigned int n_bits;
-    unsigned int attr;
+     unsigned int n_vecs;
+     unsigned int n_bits;
+     unsigned int attr;
 {
-    enum bitset_type type;
-
-    type = bitset_type_choose (n_bits, attr);
-    return bitsetv_alloc (n_vecs, n_bits, type);
+  enum bitset_type type;
+  
+  type = bitset_type_choose (n_bits, attr);
+  return bitsetv_alloc (n_vecs, n_bits, type);
 }
 
 
 /* Free bitset vector BSETV.  */
 void
 bitsetv_free (bsetv)
-    bitset *bsetv;
+     bitset *bsetv;
 {
-    free (bsetv);
+  unsigned int i;
+
+  for (i = 0; bsetv[i]; i++)
+      BITSET_FREE_ (bsetv[i]);
+  free (bsetv);
 }
 
 
-/* Zero a vector of N_VECS bitsets.  */
+/* Zero a vector of bitsets.  */
 void
-bitsetv_zero (bsetv, n_vecs)
+bitsetv_zero (bsetv)
      struct bitset_struct **bsetv;
-     unsigned int n_vecs;
 {
   unsigned int i;
-
-  for (i = 0; i < n_vecs; i++)
-      bitset_zero (bsetv[i]);
+  
+  for (i = 0; bsetv[i]; i++)
+    bitset_zero (bsetv[i]);
 }
 
 
-/* Set a vector of N_VECS bitsets to ones.  */
+/* Set a vector of bitsets to ones.  */
 void
-bitsetv_ones (bsetv, n_vecs)
+bitsetv_ones (bsetv)
      bitset *bsetv;
-     unsigned int n_vecs;
 {
   unsigned int i;
-
-  for (i = 0; i < n_vecs; i++)
+  
+  for (i = 0; bsetv[i]; i++)
     bitset_ones (bsetv[i]);
 }
 
@@ -109,20 +114,35 @@ bitsetv_ones (bsetv, n_vecs)
 /* Dump the contents of a bitset vector BSETV with N_VECS elements to
    FILE.  */
 void
-bitsetv_dump (file, title, subtitle, bsetv, n_vecs)
+bitsetv_dump (file, title, subtitle, bsetv)
      FILE *file;
      const char *title, *subtitle;
      bitset *bsetv;
-     unsigned int n_vecs;
 {
   unsigned int i;
-
+  
   fprintf (file, "%s\n", title);
-  for (i = 0; i < n_vecs; i++)
+  for (i = 0; bsetv[i]; i++)
     {
       fprintf (file, "%s %d\n", subtitle, i);
       bitset_dump (file, bsetv[i]);
     }
-
+  
   fprintf (file, "\n");
 }
+
+
+void
+debug_bitsetv (bsetv)
+     bitset *bsetv;
+{
+  unsigned int i;
+  
+  for (i = 0; bsetv[i]; i++)
+    {
+      fprintf (stderr, "%d: ", i);
+      debug_bitset (bsetv[i]);
+    }
+  
+  fprintf (stderr, "\n");
+}
