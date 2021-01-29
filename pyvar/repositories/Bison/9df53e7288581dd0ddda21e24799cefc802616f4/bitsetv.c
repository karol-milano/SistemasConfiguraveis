@@ -62,7 +62,7 @@ bitsetv_alloc (bitset_bindex n_vecs, bitset_bindex n_bits,
 /* Create a vector of N_VECS bitsets, each of N_BITS, and with
    attribute hints specified by ATTR.  */
 bitset *
-bitsetv_create (bitset_bindex n_vecs, bitset_bindex n_bits, unsigned int attr)
+bitsetv_create (bitset_bindex n_vecs, bitset_bindex n_bits, unsigned attr)
 {
   enum bitset_type type;
 
@@ -146,7 +146,7 @@ bitsetv_dump (FILE *file, char const *title, char const *subtitle,
   fprintf (file, "%s\n", title);
   for (i = 0; bsetv[i]; i++)
     {
-      fprintf (file, "%s %lu\n", subtitle, (unsigned long int) i);
+      fprintf (file, "%s %lu\n", subtitle, (unsigned long) i);
       bitset_dump (file, bsetv[i]);
     }
 
@@ -161,7 +161,7 @@ debug_bitsetv (bitsetv bsetv)
 
   for (i = 0; bsetv[i]; i++)
     {
-      fprintf (stderr, "%lu: ", (unsigned long int) i);
+      fprintf (stderr, "%lu: ", (unsigned long) i);
       debug_bitset (bsetv[i]);
     }
 
