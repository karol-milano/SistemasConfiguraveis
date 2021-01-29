@@ -68,17 +68,6 @@ ebitset_elt;
 
 typedef ebitset_elt *ebitset_elts;
 
-/* Head of ebitset linked list.  */
-typedef struct ebitset_struct
-{
-  bitset_windex size;		/* Number of elements.  */
-  ebitset_elts *elts;		/* Expanding array of pointers to elements.  */
-}
-*ebitset;
-
-
-typedef void(*PFV)();
-
 
 /* Number of elements to initially allocate.  */
 
@@ -92,14 +81,9 @@ typedef void(*PFV)();
 #define EBITSET_GROW_SIZE 4
 #endif
 
-struct bitset_struct
-{
-  struct bbitset_struct b;
-  struct ebitset_struct e;
-};
-
 enum ebitset_find_mode
   { EBITSET_FIND, EBITSET_CREATE, EBITSET_SUBST };
+typedef int enum_ebitset_find_mode;
 
 static ebitset_elt ebitset_zero_elts[1]; /* Elements of all zero bits.  */
 
@@ -115,7 +99,7 @@ static void ebitset_elt_add PARAMS ((bitset, ebitset_elt *, bitset_windex));
 static void ebitset_elt_remove PARAMS ((bitset, bitset_windex));
 static void ebitset_elt_free PARAMS ((ebitset_elt *));
 static ebitset_elt *ebitset_elt_find PARAMS ((bitset, bitset_windex,
-					      enum ebitset_find_mode));
+					      enum_ebitset_find_mode));
 static ebitset_elt *ebitset_elt_last PARAMS ((bitset));
 static int ebitset_elt_zero_p PARAMS ((ebitset_elt *));
 
@@ -131,15 +115,22 @@ static int ebitset_disjoint_p PARAMS ((bitset, bitset));
 static int ebitset_equal_p PARAMS ((bitset, bitset));
 static void ebitset_not PARAMS ((bitset, bitset));
 static int ebitset_subset_p PARAMS ((bitset, bitset));
-static int ebitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int ebitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum_bitset_ops));
+static void ebitset_and PARAMS ((bitset, bitset, bitset));
 static int ebitset_and_cmp PARAMS ((bitset, bitset, bitset));
+static void ebitset_andn PARAMS ((bitset, bitset, bitset));
 static int ebitset_andn_cmp PARAMS ((bitset, bitset, bitset));
+static void ebitset_or PARAMS ((bitset, bitset, bitset));
 static int ebitset_or_cmp PARAMS ((bitset, bitset, bitset));
+static void ebitset_xor PARAMS ((bitset, bitset, bitset));
 static int ebitset_xor_cmp PARAMS ((bitset, bitset, bitset));
+static void ebitset_copy PARAMS ((bitset, bitset));
 static bitset_bindex ebitset_list PARAMS ((bitset, bitset_bindex *,
 					   bitset_bindex, bitset_bindex *));
 static bitset_bindex ebitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
+static void ebitset_ones PARAMS ((bitset));
+static int ebitset_empty_p PARAMS ((bitset));
 static void ebitset_free PARAMS ((bitset));
 
 #define EBITSET_ELTS(BSET) ((BSET)->e.elts)
@@ -320,7 +311,7 @@ static ebitset_elt *
 ebitset_elt_find (bset, windex, mode)
      bitset bset;
      bitset_windex windex;
-     enum ebitset_find_mode mode;
+     enum_ebitset_find_mode mode;
 {
   ebitset_elt *elt;
   bitset_windex size;
@@ -1016,7 +1007,7 @@ ebitset_op3_cmp (dst, src1, src2, op)
      bitset dst;
      bitset src1;
      bitset src2;
-     enum bitset_ops op;
+     enum_bitset_ops op;
 {
   bitset_windex ssize1;
   bitset_windex ssize2;
@@ -1164,6 +1155,16 @@ ebitset_op3_cmp (dst, src1, src2, op)
 }
 
 
+static void
+ebitset_and (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  ebitset_and_cmp (dst, src1, src2);
+}
+
+
 static int
 ebitset_and_cmp (dst, src1, src2)
      bitset dst;
@@ -1190,6 +1191,16 @@ ebitset_and_cmp (dst, src1, src2)
 }
 
 
+static void
+ebitset_andn (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  ebitset_andn_cmp (dst, src1, src2);
+}
+
+
 static int
 ebitset_andn_cmp (dst, src1, src2)
      bitset dst;
@@ -1213,6 +1224,16 @@ ebitset_andn_cmp (dst, src1, src2)
 }
 
 
+static void
+ebitset_or (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  ebitset_or_cmp (dst, src1, src2);
+}
+
+
 static int
 ebitset_or_cmp (dst, src1, src2)
      bitset dst;
@@ -1231,6 +1252,16 @@ ebitset_or_cmp (dst, src1, src2)
 }
 
 
+static void
+ebitset_xor (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  ebitset_xor_cmp (dst, src1, src2);
+}
+
+
 static int
 ebitset_xor_cmp (dst, src1, src2)
      bitset dst;
@@ -1277,19 +1308,19 @@ struct bitset_vtable ebitset_vtable = {
   ebitset_equal_p,
   ebitset_not,
   ebitset_subset_p,
-  (PFV) ebitset_and_cmp,
+  ebitset_and,
   ebitset_and_cmp,
-  (PFV) ebitset_andn_cmp,
+  ebitset_andn,
   ebitset_andn_cmp,
-  (PFV) ebitset_or_cmp,
+  ebitset_or,
   ebitset_or_cmp,
-  (PFV) ebitset_xor_cmp,
+  ebitset_xor,
   ebitset_xor_cmp,
-  (PFV) bitset_and_or_cmp_,
+  bitset_and_or_,
   bitset_and_or_cmp_,
-  (PFV) bitset_andn_or_cmp_,
+  bitset_andn_or_,
   bitset_andn_or_cmp_,
-  (PFV) bitset_or_and_cmp_,
+  bitset_or_and_,
   bitset_or_and_cmp_,
   ebitset_list,
   ebitset_list_reverse,
@@ -1303,7 +1334,7 @@ size_t
 ebitset_bytes (n_bits)
      bitset_bindex n_bits ATTRIBUTE_UNUSED;
 {
-  return sizeof (struct bitset_struct);
+  return sizeof (struct ebitset_struct);
 }
 
 
