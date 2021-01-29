@@ -151,7 +151,7 @@ bitset_alloc (bitset_bindex n_bits, enum bitset_type type)
 /* Create a bitset of N_BITS of type TYPE.  */
 bitset
 bitset_obstack_alloc (struct obstack *bobstack,
-		      bitset_bindex n_bits, enum bitset_type type)
+                      bitset_bindex n_bits, enum bitset_type type)
 {
   size_t bytes;
   bitset bset;
@@ -296,15 +296,15 @@ bitset_print (FILE *file, bitset bset, bool verbose)
 
   if (verbose)
     fprintf (file, "n_bits = %lu, set = {",
-	     (unsigned long int) bitset_size (bset));
+             (unsigned long int) bitset_size (bset));
 
   pos = 30;
   BITSET_FOR_EACH (iter, bset, i, 0)
   {
     if (pos > 70)
       {
-	fprintf (file, "\n");
-	pos = 0;
+        fprintf (file, "\n");
+        pos = 0;
       }
 
     fprintf (file, "%lu ", (unsigned long int) i);
@@ -407,7 +407,7 @@ bitset_copy_ (bitset dst, bitset src)
    four operand operations.  */
 static inline bool
 bitset_op4_cmp (bitset dst, bitset src1, bitset src2, bitset src3,
-		enum bitset_ops op)
+                enum bitset_ops op)
 {
   bool changed = false;
   bool stats_enabled_save;
