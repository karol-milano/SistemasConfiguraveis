@@ -39,11 +39,10 @@ const char * const bitset_type_names[] = BITSET_TYPE_NAMES;
 size_t
 bitset_bytes (enum bitset_type type, bitset_bindex n_bits)
 {
-  size_t bytes;
-
   if (bitset_stats_enabled)
     return bitset_stats_bytes ();
 
+  size_t bytes;
   switch (type)
     {
     default:
@@ -134,12 +133,9 @@ bitset_type_choose (bitset_bindex n_bits ATTRIBUTE_UNUSED, unsigned attr)
 bitset
 bitset_alloc (bitset_bindex n_bits, enum bitset_type type)
 {
-  size_t bytes;
-  bitset bset;
+  size_t bytes = bitset_bytes (type, n_bits);
 
-  bytes = bitset_bytes (type, n_bits);
-
-  bset = xcalloc (1, bytes);
+  bitset bset = xcalloc (1, bytes);
 
   /* The cache is disabled until some elements are allocated.  If we
      have variable length arrays, then we may need to allocate a dummy
@@ -154,12 +150,9 @@ bitset
 bitset_obstack_alloc (struct obstack *bobstack,
                       bitset_bindex n_bits, enum bitset_type type)
 {
-  size_t bytes;
-  bitset bset;
+  size_t bytes = bitset_bytes (type, n_bits);
 
-  bytes = bitset_bytes (type, n_bits);
-
-  bset = obstack_alloc (bobstack, bytes);
+  bitset bset = obstack_alloc (bobstack, bytes);
   memset (bset, 0, bytes);
 
   return bitset_init (bset, n_bits, type);
@@ -171,9 +164,7 @@ bitset_obstack_alloc (struct obstack *bobstack,
 bitset
 bitset_create (bitset_bindex n_bits, unsigned attr)
 {
-  enum bitset_type type;
-
-  type = bitset_type_choose (n_bits, attr);
+  enum bitset_type type = bitset_type_choose (n_bits, attr);
 
   return bitset_alloc (n_bits, type);
 }
@@ -200,9 +191,7 @@ bitset_obstack_free (bitset bset)
 enum bitset_type
 bitset_type_get (bitset bset)
 {
-   enum bitset_type type;
-
-   type = BITSET_TYPE_ (bset);
+   enum bitset_type type = BITSET_TYPE_ (bset);
    if (type != BITSET_STATS)
       return type;
 
@@ -214,9 +203,7 @@ bitset_type_get (bitset bset)
 const char *
 bitset_type_name_get (bitset bset)
 {
-  enum bitset_type type;
-
-  type = bitset_type_get (bset);
+  enum bitset_type type = bitset_type_get (bset);
 
   return bitset_type_names[type];
 }
@@ -240,7 +227,7 @@ bitset_next (bitset src, bitset_bindex bitno)
 extern bool
 bitset_compatible_p (bitset bset1, bitset bset2)
 {
-    return BITSET_COMPATIBLE_ (bset1, bset2);
+  return BITSET_COMPATIBLE_ (bset1, bset2);
 }
 
 
@@ -291,15 +278,13 @@ bitset_only_set_p (bitset src, bitset_bindex bitno)
 static void
 bitset_print (FILE *file, bitset bset, bool verbose)
 {
-  unsigned pos;
-  bitset_bindex i;
-  bitset_iterator iter;
-
   if (verbose)
     fprintf (file, "n_bits = %lu, set = {",
              (unsigned long) bitset_size (bset));
 
-  pos = 30;
+  unsigned pos = 30;
+  bitset_bindex i;
+  bitset_iterator iter;
   BITSET_FOR_EACH (iter, bset, i, 0)
   {
     if (pos > 70)
@@ -357,7 +342,7 @@ bitset_toggle_ (bitset bset, bitset_bindex bitno)
 bitset_bindex
 bitset_size_ (bitset src)
 {
-    return BITSET_NBITS_ (src);
+  return BITSET_NBITS_ (src);
 }
 
 
@@ -366,7 +351,6 @@ bitset_bindex
 bitset_count_ (bitset src)
 {
   bitset_bindex list[BITSET_LIST_SIZE];
-  bitset_bindex next;
   bitset_bindex num;
   bitset_bindex count;
 
@@ -374,7 +358,7 @@ bitset_count_ (bitset src)
      bitset implementation that uses a direct technique (based on
      masks) for counting the number of bits set in a word.  */
 
-  next = 0;
+  bitset_bindex next = 0;
   for (count = 0; (num = bitset_list (src, list, BITSET_LIST_SIZE, &next));
        count += num)
     continue;
@@ -411,13 +395,11 @@ bitset_op4_cmp (bitset dst, bitset src1, bitset src2, bitset src3,
                 enum bitset_ops op)
 {
   bool changed = false;
-  bool stats_enabled_save;
-  bitset tmp;
 
   /* Create temporary bitset.  */
-  stats_enabled_save = bitset_stats_enabled;
+  bool stats_enabled_save = bitset_stats_enabled;
   bitset_stats_enabled = false;
-  tmp = bitset_alloc (0, bitset_type_get (dst));
+  bitset tmp = bitset_alloc (0, bitset_type_get (dst));
   bitset_stats_enabled = stats_enabled_save;
 
   switch (op)
