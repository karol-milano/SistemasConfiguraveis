@@ -23,6 +23,7 @@
 
 #include "lbitset.h"
 #include "obstack.h"
+#include <stddef.h>
 #include <stdlib.h>
 #include <stdio.h>
 
@@ -63,27 +64,9 @@ typedef struct lbitset_elt_struct
 lbitset_elt;
 
 
-/* Head of lbitset linked list.  */
-typedef struct lbitset_struct
-{
-  lbitset_elt *head;		/* First element in linked list.  */
-  lbitset_elt *tail;		/* Last element in linked list.  */
-}
-*lbitset;
-
-
-struct bitset_struct
-{
-  struct bbitset_struct b;
-  struct lbitset_struct l;
-};
-
-
-typedef void(*PFV)();
-
-
 enum lbitset_find_mode
   { LBITSET_FIND, LBITSET_CREATE, LBITSET_SUBST };
+typedef int enum_lbitset_find_mode;
 
 static lbitset_elt lbitset_zero_elts[3]; /* Elements of all zero bits.  */
 
@@ -98,7 +81,7 @@ static void lbitset_elt_link PARAMS ((bitset, lbitset_elt *));
 static void lbitset_elt_unlink PARAMS ((bitset, lbitset_elt *));
 static void lbitset_elt_free PARAMS ((lbitset_elt *));
 static lbitset_elt *lbitset_elt_find PARAMS ((bitset, bitset_windex,
-					      enum lbitset_find_mode));
+					      enum_lbitset_find_mode));
 static int lbitset_elt_zero_p PARAMS ((lbitset_elt *));
 
 static void lbitset_prune PARAMS ((bitset, lbitset_elt *));
@@ -111,15 +94,29 @@ static void lbitset_set PARAMS ((bitset, bitset_bindex));
 static void lbitset_reset PARAMS ((bitset, bitset_bindex));
 static int lbitset_test PARAMS ((bitset, bitset_bindex));
 static bitset_bindex lbitset_size PARAMS ((bitset));
-static int lbitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int lbitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum_bitset_ops));
+static void lbitset_and PARAMS ((bitset, bitset, bitset));
+static int lbitset_and_cmp PARAMS ((bitset, bitset, bitset));
+static void lbitset_andn PARAMS ((bitset, bitset, bitset));
+static int lbitset_andn_cmp PARAMS ((bitset, bitset, bitset));
+static void lbitset_or PARAMS ((bitset, bitset, bitset));
+static int lbitset_or_cmp PARAMS ((bitset, bitset, bitset));
+static void lbitset_xor PARAMS ((bitset, bitset, bitset));
+static int lbitset_xor_cmp PARAMS ((bitset, bitset, bitset));
 static bitset_bindex lbitset_list PARAMS ((bitset, bitset_bindex *,
 					   bitset_bindex, bitset_bindex *));
 static bitset_bindex lbitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
+static int lbitset_empty_p PARAMS ((bitset));
+static void lbitset_ones PARAMS ((bitset));
+static void lbitset_not PARAMS ((bitset, bitset));
+static int lbitset_subset_p PARAMS ((bitset, bitset));
+static int lbitset_disjoint_p PARAMS ((bitset, bitset));
 static void lbitset_free PARAMS ((bitset));
+extern void debug_lbitset PARAMS ((bitset));
 
-
-#define LBITSET_CURRENT1(X) (lbitset_elt *)((char *)(X) + ((char *)&(((lbitset_elt *)(X))->next) - (char *)&(((lbitset_elt *)(X))->words)))
+#define LBITSET_CURRENT1(X) \
+  ((lbitset_elt *) (void *) ((char *) (X) - offsetof (lbitset_elt, words)))
 
 #define LBITSET_CURRENT(X) LBITSET_CURRENT1((X)->b.cdata)
 
@@ -367,7 +364,7 @@ static lbitset_elt *
 lbitset_elt_find (bset, windex, mode)
      bitset bset;
      bitset_windex windex;
-     enum lbitset_find_mode mode;
+     enum_lbitset_find_mode mode;
 {
   lbitset_elt *elt;
   lbitset_elt *current;
@@ -1094,7 +1091,7 @@ lbitset_op3_cmp (dst, src1, src2, op)
      bitset dst;
      bitset src1;
      bitset src2;
-     enum bitset_ops op;
+     enum_bitset_ops op;
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
@@ -1251,6 +1248,16 @@ lbitset_op3_cmp (dst, src1, src2, op)
 }
 
 
+static void
+lbitset_and (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_and_cmp (dst, src1, src2);
+}
+
+
 static int
 lbitset_and_cmp (dst, src1, src2)
      bitset dst;
@@ -1279,6 +1286,16 @@ lbitset_and_cmp (dst, src1, src2)
 }
 
 
+static void
+lbitset_andn (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_andn_cmp (dst, src1, src2);
+}
+
+
 static int
 lbitset_andn_cmp (dst, src1, src2)
      bitset dst;
@@ -1304,6 +1321,16 @@ lbitset_andn_cmp (dst, src1, src2)
 }
 
 
+static void
+lbitset_or (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_or_cmp (dst, src1, src2);
+}
+
+
 static int
 lbitset_or_cmp (dst, src1, src2)
      bitset dst;
@@ -1325,6 +1352,16 @@ lbitset_or_cmp (dst, src1, src2)
 }
 
 
+static void
+lbitset_xor (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_xor_cmp (dst, src1, src2);
+}
+
+
 static int
 lbitset_xor_cmp (dst, src1, src2)
      bitset dst;
@@ -1363,19 +1400,19 @@ struct bitset_vtable lbitset_vtable = {
   lbitset_equal_p,
   lbitset_not,
   lbitset_subset_p,
-  (PFV) lbitset_and_cmp,
+  lbitset_and,
   lbitset_and_cmp,
-  (PFV) lbitset_andn_cmp,
+  lbitset_andn,
   lbitset_andn_cmp,
-  (PFV) lbitset_or_cmp,
+  lbitset_or,
   lbitset_or_cmp,
-  (PFV) lbitset_xor_cmp,
+  lbitset_xor,
   lbitset_xor_cmp,
-  (PFV) bitset_and_or_cmp_,
+  bitset_and_or_,
   bitset_and_or_cmp_,
-  (PFV) bitset_andn_or_cmp_,
+  bitset_andn_or_,
   bitset_andn_or_cmp_,
-  (PFV) bitset_or_and_cmp_,
+  bitset_or_and_,
   bitset_or_and_cmp_,
   lbitset_list,
   lbitset_list_reverse,
@@ -1389,7 +1426,7 @@ size_t
 lbitset_bytes (n_bits)
      bitset_bindex n_bits ATTRIBUTE_UNUSED;
 {
-  return sizeof (struct bitset_struct);
+  return sizeof (struct lbitset_struct);
 }
 
 
