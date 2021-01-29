@@ -1,5 +1,5 @@
 /* Variable array bitsets.
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -33,17 +33,15 @@
    has the same size.
 */
 
-static void vbitset_unused_clear PARAMS ((bitset));
-
-static void vbitset_set PARAMS ((bitset, bitset_bindex));
-static void vbitset_reset PARAMS ((bitset, bitset_bindex));
-static bool vbitset_test PARAMS ((bitset, bitset_bindex));
-static bitset_bindex vbitset_list PARAMS ((bitset, bitset_bindex *, 
-					   bitset_bindex,
-					   bitset_bindex *));
-static bitset_bindex vbitset_list_reverse PARAMS ((bitset, bitset_bindex *,
-						   bitset_bindex,
-						   bitset_bindex *));
+static void vbitset_unused_clear (bitset);
+
+static void vbitset_set (bitset, bitset_bindex);
+static void vbitset_reset (bitset, bitset_bindex);
+static bool vbitset_test (bitset, bitset_bindex);
+static bitset_bindex vbitset_list (bitset, bitset_bindex *, 
+				   bitset_bindex, bitset_bindex *);
+static bitset_bindex vbitset_list_reverse (bitset, bitset_bindex *,
+					   bitset_bindex, bitset_bindex *);
 
 #define VBITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
 #define VBITSET_WORDS(X) ((X)->b.cdata)
