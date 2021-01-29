@@ -22,27 +22,37 @@
 #endif
 
 #include "abitset.h"
+#include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
 
 /* This file implements fixed size bitsets stored as an array
    of words.  Any unused bits in the last word must be zero.  */
 
-typedef struct abitset_struct
-{
-  bitset_bindex n_bits;	/* Number of bits.  */
-  bitset_word words[1];	/* The array of bits.  */
-}
-*abitset;
-
-
-struct bitset_struct
-{
-  struct bbitset_struct b;
-  struct abitset_struct a;
-};
-
 static void abitset_unused_clear PARAMS ((bitset));
+static void abitset_ones PARAMS ((bitset));
+static void abitset_zero PARAMS ((bitset));
+static int abitset_empty_p PARAMS ((bitset));
+static void abitset_copy1 PARAMS ((bitset, bitset));
+static void abitset_not PARAMS ((bitset, bitset));
+static int abitset_equal_p PARAMS ((bitset, bitset));
+static int abitset_subset_p PARAMS ((bitset, bitset));
+static int abitset_disjoint_p PARAMS ((bitset, bitset));
+static void abitset_and PARAMS ((bitset, bitset, bitset));
+static int abitset_and_cmp PARAMS ((bitset, bitset, bitset));
+static void abitset_andn PARAMS ((bitset, bitset, bitset));
+static int abitset_andn_cmp PARAMS ((bitset, bitset, bitset));
+static void abitset_or PARAMS ((bitset, bitset, bitset));
+static int abitset_or_cmp PARAMS ((bitset, bitset, bitset));
+static void abitset_xor PARAMS ((bitset, bitset, bitset));
+static int abitset_xor_cmp PARAMS ((bitset, bitset, bitset));
+static void abitset_and_or PARAMS ((bitset, bitset, bitset, bitset));
+static int abitset_and_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
+static void abitset_andn_or PARAMS ((bitset, bitset, bitset, bitset));
+static int abitset_andn_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
+static void abitset_or_and PARAMS ((bitset, bitset, bitset, bitset));
+static int abitset_or_and_cmp PARAMS ((bitset, bitset, bitset, bitset));
+static void abitset_copy PARAMS ((bitset, bitset));
 
 static bitset_bindex abitset_small_list PARAMS ((bitset, bitset_bindex *,
 						 bitset_bindex,
@@ -799,7 +809,7 @@ abitset_or_and_cmp (dst, src1, src2, src3)
 }
 
 
-void
+static void
 abitset_copy (dst, src)
      bitset dst;
      bitset src;
@@ -891,10 +901,22 @@ abitset_bytes (n_bits)
 {
   bitset_windex size;
   size_t bytes;
+  size_t header_size = offsetof (union bitset_union, a.words);
+  struct bitset_align_struct { char a; union bitset_union b; };
+  size_t bitset_alignment = offsetof (struct bitset_align_struct, b);
 
   size = ABITSET_N_WORDS (n_bits);
-  bytes = size * sizeof (bitset_word);
-  return sizeof (struct bitset_struct) + bytes - sizeof (bitset_word);
+  bytes = header_size + size * sizeof (bitset_word);
+
+  /* Align the size properly for a vector of abitset objects.  */
+  if (header_size % bitset_alignment != 0
+      || sizeof (bitset_word) % bitset_alignment != 0)
+    {
+      bytes += bitset_alignment - 1;
+      bytes -= bytes % bitset_alignment;
+    }
+
+  return bytes;
 }
 
 
