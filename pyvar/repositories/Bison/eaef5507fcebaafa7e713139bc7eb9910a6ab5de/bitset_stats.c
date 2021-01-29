@@ -1,5 +1,5 @@
 /* Bitset statistics.
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -33,13 +33,18 @@
 #include "abitset.h"
 #include "ebitset.h"
 #include "lbitset.h"
+#include "vbitset.h"
 #include "bitset_stats.h"
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 
+#ifdef HAVE_GETTEXT_H
 #include "gettext.h"
 #define _(Msgid)  gettext (Msgid)
+#else
+#define _(Msgid)  Msgid
+#endif
 
 /* Configuration macros.  */
 #define BITSET_STATS_FILE "bitset.dat"
@@ -375,6 +380,13 @@ bitset_stats_test (bitset src, bitset_bindex bitno)
 }
 
 
+static bitset_bindex
+bitset_stats_resize (bitset src, bitset_bindex size)
+{
+    return BITSET_RESIZE_ (src->s.bset, size);
+}
+
+
 static bitset_bindex
 bitset_stats_size (bitset src)
 {
@@ -518,7 +530,6 @@ static void
 bitset_stats_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
-
   BITSET_AND_OR_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
@@ -527,7 +538,6 @@ static bool
 bitset_stats_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
-
   return BITSET_AND_OR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
@@ -536,7 +546,6 @@ static void
 bitset_stats_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
-
   BITSET_ANDN_OR_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
@@ -545,7 +554,6 @@ static bool
 bitset_stats_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
-
   return BITSET_ANDN_OR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
@@ -554,7 +562,6 @@ static void
 bitset_stats_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
-
   BITSET_OR_AND_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
@@ -563,7 +570,6 @@ static bool
 bitset_stats_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
-
   return BITSET_OR_AND_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
@@ -576,9 +582,11 @@ bitset_stats_list (bitset bset, bitset_bindex *list,
   bitset_bindex tmp;
   bitset_bindex size;
   bitset_bindex i;
+  enum bitset_type type;
 
   count = BITSET_LIST_ (bset->s.bset, list, num, next);
 
+  type = BITSET_TYPE_ (bset->s.bset);
   BITSET_STATS_LISTS_INC (bset->s.bset);
 
   /* Log histogram of number of set bits.  */
@@ -626,6 +634,7 @@ struct bitset_vtable bitset_stats_vtable = {
   bitset_stats_reset,
   bitset_stats_toggle,
   bitset_stats_test,
+  bitset_stats_resize,
   bitset_stats_size,
   bitset_stats_count,
   bitset_stats_empty_p,
@@ -685,6 +694,8 @@ bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
   bset->b.csize = 0;
   bset->b.cdata = 0;
 
+  BITSET_NBITS_ (bset) = n_bits;
+
   /* Set up the actual bitset implementation that
      we are a wrapper over.  */
   switch (type)
@@ -707,6 +718,12 @@ bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
       ebitset_init (sbset, n_bits);
       break;
 
+    case BITSET_VARRAY:
+      bytes = vbitset_bytes (n_bits);
+      sbset = (bitset) xcalloc (1, bytes);
+      vbitset_init (sbset, n_bits);
+      break;
+
     default:
       abort ();
     }
