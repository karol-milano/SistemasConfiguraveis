@@ -1,5 +1,5 @@
 /* Array bitsets.
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -123,14 +123,14 @@ abitset_reset (bitset dst ATTRIBUTE_UNUSED,
 
 
 /* Test bit BITNO in bitset SRC.  */
-static int
+static bool
 abitset_test (bitset src ATTRIBUTE_UNUSED,
 	      bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* This should never occur for abitsets since we should always
      hit the cache.  */
   abort ();
-  return 0;
+  return false;
 }
 
 
@@ -336,7 +336,7 @@ abitset_zero (bitset dst)
 }
 
 
-static int
+static bool
 abitset_empty_p (bitset dst)
 {
   bitset_windex i;
@@ -344,9 +344,9 @@ abitset_empty_p (bitset dst)
 
   for (i = 0; i < dst->b.csize; i++)
     if (dstp[i])
-      return 0;
+      return false;
 
-  return 1;
+  return true;
 }
 
 
@@ -377,7 +377,7 @@ abitset_not (bitset dst, bitset src)
 }
 
 
-static int
+static bool
 abitset_equal_p (bitset dst, bitset src)
 {
   bitset_windex i;
@@ -387,12 +387,12 @@ abitset_equal_p (bitset dst, bitset src)
 
   for (i = 0; i < size; i++)
       if (*srcp++ != *dstp++)
-	  return 0;
-  return 1;
+	  return false;
+  return true;
 }
 
 
-static int
+static bool
 abitset_subset_p (bitset dst, bitset src)
 {
   bitset_windex i;
@@ -402,12 +402,12 @@ abitset_subset_p (bitset dst, bitset src)
 
   for (i = 0; i < size; i++, dstp++, srcp++)
       if (*dstp != (*srcp | *dstp))
-	  return 0;
-  return 1;
+	  return false;
+  return true;
 }
 
 
-static int
+static bool
 abitset_disjoint_p (bitset dst, bitset src)
 {
   bitset_windex i;
@@ -417,9 +417,9 @@ abitset_disjoint_p (bitset dst, bitset src)
 
   for (i = 0; i < size; i++)
       if (*srcp++ & *dstp++)
-	  return 0;
+	  return false;
 
-  return 1;
+  return true;
 }
 
 
@@ -437,11 +437,11 @@ abitset_and (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 abitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
-  int changed = 0;
+  bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -453,7 +453,7 @@ abitset_and_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
 	{
-	  changed = 1;
+	  changed = true;
 	  *dstp = tmp;
 	}
     }
@@ -475,11 +475,11 @@ abitset_andn (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 abitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
-  int changed = 0;
+  bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -491,7 +491,7 @@ abitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
 	{
-	  changed = 1;
+	  changed = true;
 	  *dstp = tmp;
 	}
     }
@@ -513,11 +513,11 @@ abitset_or (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 abitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
-  int changed = 0;
+  bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -529,7 +529,7 @@ abitset_or_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
 	{
-	  changed = 1;
+	  changed = true;
 	  *dstp = tmp;
 	}
     }
@@ -551,11 +551,11 @@ abitset_xor (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 abitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
-  int changed = 0;
+  bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -567,7 +567,7 @@ abitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
 	{
-	  changed = 1;
+	  changed = true;
 	  *dstp = tmp;
 	}
     }
@@ -590,11 +590,11 @@ abitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 }
 
 
-static int
+static bool
 abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
-  int changed = 0;
+  bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
@@ -607,7 +607,7 @@ abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 
       if (*dstp != tmp)
 	{
-	  changed = 1;
+	  changed = true;
 	  *dstp = tmp;
 	}
     }
@@ -630,11 +630,11 @@ abitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 }
 
 
-static int
+static bool
 abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
-  int changed = 0;
+  bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
@@ -647,7 +647,7 @@ abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 
       if (*dstp != tmp)
 	{
-	  changed = 1;
+	  changed = true;
 	  *dstp = tmp;
 	}
     }
@@ -670,11 +670,11 @@ abitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 }
 
 
-static int
+static bool
 abitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
-  int changed = 0;
+  bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
@@ -687,7 +687,7 @@ abitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 
       if (*dstp != tmp)
 	{
-	  changed = 1;
+	  changed = true;
 	  *dstp = tmp;
 	}
     }
