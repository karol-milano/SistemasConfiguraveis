@@ -75,19 +75,6 @@
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].list_density[(I)]++
 
 
-typedef struct bitset_stats_struct
-{
-  bitset bset;
-} *bitset_stats;
-
-
-struct bitset_struct
-{
-  struct bbitset_struct b;
-  struct bitset_stats_struct s;
-};
-
-
 struct bitset_type_info_struct
 {
   unsigned int allocs;
@@ -121,6 +108,29 @@ static void bitset_stats_reset PARAMS ((bitset, bitset_bindex));
 static int bitset_stats_toggle PARAMS ((bitset, bitset_bindex));
 static int bitset_stats_test PARAMS ((bitset, bitset_bindex));
 static bitset_bindex bitset_stats_size PARAMS ((bitset));
+static bitset_bindex bitset_stats_count PARAMS ((bitset));
+static int bitset_stats_empty_p PARAMS ((bitset));
+static void bitset_stats_ones PARAMS ((bitset));
+static void bitset_stats_zero PARAMS ((bitset));
+static void bitset_stats_copy PARAMS ((bitset, bitset));
+static int bitset_stats_disjoint_p PARAMS ((bitset, bitset));
+static int bitset_stats_equal_p PARAMS ((bitset, bitset));
+static void bitset_stats_not PARAMS ((bitset, bitset));
+static int bitset_stats_subset_p PARAMS ((bitset, bitset));
+static void bitset_stats_and PARAMS ((bitset, bitset, bitset));
+static int bitset_stats_and_cmp PARAMS ((bitset, bitset, bitset));
+static void bitset_stats_andn PARAMS ((bitset, bitset, bitset));
+static int bitset_stats_andn_cmp PARAMS ((bitset, bitset, bitset));
+static void bitset_stats_or PARAMS ((bitset, bitset, bitset));
+static int bitset_stats_or_cmp PARAMS ((bitset, bitset, bitset));
+static void bitset_stats_xor PARAMS ((bitset, bitset, bitset));
+static int bitset_stats_xor_cmp PARAMS ((bitset, bitset, bitset));
+static void bitset_stats_and_or PARAMS ((bitset, bitset, bitset, bitset));
+static int bitset_stats_and_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
+static void bitset_stats_andn_or PARAMS ((bitset, bitset, bitset, bitset));
+static int bitset_stats_andn_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
+static void bitset_stats_or_and PARAMS ((bitset, bitset, bitset, bitset));
+static int bitset_stats_or_and_cmp PARAMS ((bitset, bitset, bitset, bitset));
 static bitset_bindex bitset_stats_list PARAMS ((bitset, bitset_bindex *,
 						bitset_bindex,
 						bitset_bindex *));
@@ -799,7 +809,7 @@ bitset_stats_type_get (bset)
 size_t
 bitset_stats_bytes (void)
 {
-  return sizeof (struct bitset_struct);
+  return sizeof (struct bitset_stats_struct);
 }
 
 
@@ -807,7 +817,7 @@ bitset
 bitset_stats_init (bset, n_bits, type)
      bitset bset;
      bitset_bindex n_bits;
-     enum bitset_type type;
+     enum_bitset_type type;
 {
   size_t bytes;
   bitset sbset;
