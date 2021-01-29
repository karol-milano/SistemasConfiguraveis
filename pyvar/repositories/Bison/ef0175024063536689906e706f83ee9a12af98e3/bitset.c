@@ -2,19 +2,19 @@
    Copyright (C) 2002 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
-This program is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2 of the License, or
-(at your option) any later version.
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2 of the License, or
+   (at your option) any later version.
 
-This program is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with this program; if not, write to the Free Software
-Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #ifdef HAVE_CONFIG_H
 #include "config.h"
@@ -22,28 +22,13 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #include <stdlib.h>
 #include "bitset.h"
+#include "sbitset.h"
+#include "lbitset.h"
+#include "ebitset.h"
 #include "obstack.h"
 
 static void bitset_print PARAMS ((FILE *, bitset, int));
 
-#if BITSET_CHECK
-#define BITSET__CHECK2(DST, SRC) \
-if ((DST)->OPS != (SRC)->OPS) abort ();
-
-#define BITSET__CHECK3(DST, SRC1, SRC2) \
-if ((DST)->OPS != (SRC1)->OPS || (DST)->OPS != (SRC2)->OPS) abort ();
-
-#define BITSET__CHECK4(DST, SRC1, SRC2) \
-if ((DST)->OPS != (SRC1)->OPS || (DST)->OPS != (SRC2)->OPS \
-    || (DST)->OPS != (SRC3)->OPS) abort ();
-#else
-#define BITSET__CHECK2(DST, SRC)
-
-#define BITSET__CHECK3(DST, SRC1, SRC2)
-
-#define BITSET__CHECK4(DST, SRC1, SRC2, SRC3)
-#endif
-
 #if BITSET_STATS
 #define BITSET_STATS_FILE "bitset.dat"
 
@@ -65,8 +50,8 @@ struct bitset_type_stats_struct
 
 struct bitset_stats_struct
 {
-    unsigned int runs;
-    struct bitset_type_stats_struct types[BITSET_TYPE_NUM];
+  unsigned int runs;
+  struct bitset_type_stats_struct types[BITSET_TYPE_NUM];
 };
 
 struct bitset_stats_struct bitset_stats_data;
@@ -78,9 +63,10 @@ static void bitset_percent_histogram_print PARAMS ((FILE *, const char *,
 						    unsigned int *));
 static void bitset_log_histogram_print PARAMS ((FILE *, const char *,
 						const char *,
-						unsigned int, unsigned int *));
-static void bitset_stats_print_1 PARAMS ((FILE *, const char *,
-					  struct bitset_type_stats_struct *));
+						unsigned int,
+						unsigned int *));
+static void bitset_stats_print_1
+PARAMS ((FILE *, const char *, struct bitset_type_stats_struct *));
 static void bitset_stats_print PARAMS ((FILE *, int));
 static void bitset_stats_read PARAMS ((void));
 static void bitset_stats_write PARAMS ((void));
@@ -91,31 +77,31 @@ static void bitset_stats_write PARAMS ((void));
 
 #define BITSET_STATS_XFREES_INC(BSET) 			\
   if (bitset_stats)					\
-    bitset_stats->types[(BSET)->ops->type].xfrees++
+    bitset_stats->types[BITSET_TYPE_ (BSET)].xfrees++
 
 #define BITSET_STATS_OBALLOCS_INC(TYPE) 		\
   if (bitset_stats)					\
     bitset_stats->types[(TYPE)].oballocs++
 
-#define BITSET_STATS_OBFREES_INC(BSET) 		\
+#define BITSET_STATS_OBFREES_INC(BSET)	 		\
   if (bitset_stats)					\
-    bitset_stats->types[(BSET)->ops->type].obfrees++
+    bitset_stats->types[BITSET_TYPE_ (BSET)].obfrees++
 
 #define BITSET_STATS_LISTS_INC(BSET) 			\
   if (bitset_stats)					\
-    bitset_stats->types[(BSET)->ops->type].lists++
+    bitset_stats->types[BITSET_TYPE_ (BSET)].lists++
 
 #define BITSET_STATS_LIST_COUNTS_INC(BSET, I) 		\
   if (bitset_stats)					\
-    bitset_stats->types[(BSET)->ops->type].list_counts[(I)]++
+    bitset_stats->types[BITSET_TYPE_ (BSET)].list_counts[(I)]++
 
 #define BITSET_STATS_LIST_SIZES_INC(BSET, I) 		\
   if (bitset_stats)					\
-    bitset_stats->types[(BSET)->ops->type].list_sizes[(I)]++
+    bitset_stats->types[BITSET_TYPE_ (BSET)].list_sizes[(I)]++
 
 #define BITSET_STATS_LIST_DENSITY_INC(BSET, I) 		\
   if (bitset_stats)					\
-    bitset_stats->types[(BSET)->ops->type].list_density[(I)]++
+    bitset_stats->types[BITSET_TYPE_ (BSET)].list_density[(I)]++
 
 #else
 #define BITSET_STATS_XMALLOCS_INC(TYPE)
@@ -136,7 +122,6 @@ static void bitset_stats_write PARAMS ((void));
 #endif /* BITSET_STATS  */
 
 
-
 /* Return number of bytes required to create a N_BIT bitset
    of TYPE.  The bitset may grow to require more bytes than this.  */
 int
@@ -202,7 +187,7 @@ bitset_type_choose (n_bits, attr)
 {
   enum bitset_type type;
 
-#ifdef ENABLE_CHECKING
+#if BITSET_CHECK
   /* Check attributes.  */
   if (attr & BITSET_FIXED && attr & BITSET_VARIABLE)
     abort ();
@@ -241,7 +226,11 @@ bitset_alloc (n_bits, type)
 
   bytes = bitset_bytes (type, n_bits);
 
-  bset = (bitset) xmalloc (bytes);
+  bset = (bitset) xcalloc (1, bytes);
+
+  /* The cache is disabled until some elements are allocated.  If we
+     have variable length arrays, then we may need to allocate dummy
+     element.  */
 
   return bitset_init (bset, n_bits, type);
 }
@@ -250,17 +239,21 @@ bitset_alloc (n_bits, type)
 /* Create a bitset of N_BITS of type TYPE.  */
 bitset
 bitset_obstack_alloc (bobstack, n_bits, type)
-    struct obstack *bobstack;
-    bitset_bindex n_bits;
-    enum bitset_type type;
+     struct obstack *bobstack;
+     bitset_bindex n_bits;
+     enum bitset_type type;
 {
   unsigned int bytes;
+  bitset bset;
 
   BITSET_STATS_OBALLOCS_INC (type);
 
   bytes = bitset_bytes (type, n_bits);
 
-  return bitset_init (obstack_alloc (bobstack, bytes), n_bits, type);
+  bset = obstack_alloc (bobstack, bytes);
+  memset (bset, 0, bytes);
+
+  return bitset_init (bset, n_bits, type);
 }
 
 
@@ -286,10 +279,7 @@ bitset_free (bset)
 {
   BITSET_STATS_XFREES_INC (bset);
 
-  if (bset->ops->free)
-    BITSET__FREE (bset);
-
-  bset->ops = NULL;
+  BITSET_FREE_ (bset);
   free (bset);
 }
 
@@ -301,9 +291,7 @@ bitset_obstack_free (bset)
 {
   BITSET_STATS_OBFREES_INC (bset);
 
-  if (bset->ops->free)
-    BITSET__FREE (bset);
-  bset->ops = NULL;
+  BITSET_FREE_ (bset);
 }
 
 
@@ -357,6 +345,7 @@ bitset_last (src)
 }
 
 
+/* Print contents of bitset BSET to FILE.   */
 static void
 bitset_print (file, bset, verbose)
      FILE *file;
@@ -386,153 +375,225 @@ bitset_print (file, bset, verbose)
 }
 
 
+/* DST = SRC.  Return non-zero if DST != SRC.  */
 int
 bitset_copy (dst, src)
-    bitset dst;
-    bitset src;
+     bitset dst;
+     bitset src;
 {
-    unsigned int i;
+  unsigned int i;
 
-    if (dst->ops == src->ops)
-	return BITSET__COPY (dst, src);
+  if (BITSET_COMPATIBLE_ (dst, src))
+    return BITSET_COPY_ (dst, src);
 
-    /* Convert bitset types.  We assume that the DST bitset
-       is large enough to hold the SRC bitset.  */
-    bitset_zero (dst);
-    BITSET_EXECUTE (src, 0, i,
-     {
-       bitset_set (dst, i);
-     });
+  /* Convert bitset types.  We assume that the DST bitset
+     is large enough to hold the SRC bitset.  */
+  bitset_zero (dst);
+  BITSET_EXECUTE (src, 0, i,
+  {
+     bitset_set (dst, i);
+  });
 
-    return 1;
+  return 1;
 }
 
 
 /* Return size in bits of bitset SRC.  */
 int
 bitset_size (src)
-    bitset src;
+     bitset src;
+{
+  return BITSET_SIZE_ (src);
+}
+
+
+/* Return number of bits set in bitset SRC.  */
+int
+bitset_count (src)
+     bitset src;
 {
-    return BITSET__SIZE (src);
+  bitset_bindex list[BITSET_LIST_SIZE];
+  bitset_bindex next;
+  int num;
+  int count;
+  
+  next = 0;
+  for (count = 0; (num = bitset_list (src, list, BITSET_LIST_SIZE, &next));
+       count += num)
+    continue;
+  
+  return count;
 }
 
 
 /* DST = 0.  */
 int
 bitset_zero (dst)
-    bitset dst;
+     bitset dst;
 {
-    return BITSET__OP1 (dst, BITSET_ZERO);
+  return BITSET_ZERO_ (dst);
 }
 
 
 /* DST = ~0.  */
 int
 bitset_ones (dst)
-    bitset dst;
+     bitset dst;
 {
-    return BITSET__OP1 (dst, BITSET_ONES);
+  return BITSET_ONES_ (dst);
 }
 
 
-/* Return non-zero if all bits in bitset SRC are reset.  */
+/* Return SRC == 0.  */
 int
 bitset_empty_p (src)
-    bitset src;
+     bitset src;
 {
-    return BITSET__OP1 (src, BITSET_EMPTY_P);
+  return BITSET_EMPTY_P_ (src);
 }
 
 
 /* Return DST == DST | SRC.  */
 int
 bitset_subset_p (dst, src)
-    bitset dst;
-    bitset src;
+     bitset dst;
+     bitset src;
 {
-    return BITSET__OP2 (dst, src, BITSET_SUBSET_P);
+  BITSET_CHECK2_ (dst, src);
+  return BITSET_SUBSET_P_ (dst, src);
 }
 
 
 /* Return DST == SRC.  */
 int
 bitset_equal_p (dst, src)
-    bitset dst;
-    bitset src;
+     bitset dst;
+     bitset src;
 {
-    BITSET__CHECK2 (dst, src);
-    return BITSET__OP2 (dst, src, BITSET_EQUAL_P);
+  BITSET_CHECK2_ (dst, src);
+  return BITSET_EQUAL_P_ (dst, src);
+}
+
+
+/* Return DST & SRC == 0.  */
+int
+bitset_disjoint_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  BITSET_CHECK2_ (dst, src);
+  return BITSET_DISJOINT_P_ (dst, src);
 }
 
 
 /* DST = ~SRC.  */
 int
 bitset_not (dst, src)
-    bitset dst;
-    bitset src;
+     bitset dst;
+     bitset src;
 {
-    BITSET__CHECK2 (dst, src);
-    return BITSET__OP2 (dst, src, BITSET_NOT);
+  BITSET_CHECK2_ (dst, src);
+  return BITSET_NOT_ (dst, src);
 }
 
 
 /* DST = SRC1 | SRC2.  Return non-zero if DST != SRC1 | SRC2.  */
 int
 bitset_or (dst, src1, src2)
-    bitset dst;
-    bitset src1;
-    bitset src2;
+     bitset dst;
+     bitset src1;
+     bitset src2;
 {
-    BITSET__CHECK3 (dst, src1, src2);
-    return BITSET__OP3 (dst, src1, src2, BITSET_OR);
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_OR_ (dst, src1, src2);
 }
 
 
 /* DST = SRC1 & SRC2.  Return non-zero if DST != SRC1 & SRC2.  */
 int
 bitset_and (dst, src1, src2)
-    bitset dst;
-    bitset src1;
-    bitset src2;
+     bitset dst;
+     bitset src1;
+     bitset src2;
 {
-    BITSET__CHECK3 (dst, src1, src2);
-    return BITSET__OP3 (dst, src1, src2, BITSET_AND);
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_AND_ (dst, src1, src2);
 }
 
 
 /* DST = SRC1 ^ SRC2.  Return non-zero if DST != SRC1 ^ SRC2.  */
 int
 bitset_xor (dst, src1, src2)
-    bitset dst;
-    bitset src1;
-    bitset src2;
+     bitset dst;
+     bitset src1;
+     bitset src2;
 {
-    BITSET__CHECK3 (dst, src1, src2);
-    return BITSET__OP3 (dst, src1, src2, BITSET_XOR);
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_XOR_ (dst, src1, src2);
 }
 
 
 /* DST = SRC1 & ~SRC2.  Return non-zero if DST != SRC1 & ~SRC2.  */
 int
 bitset_andn (dst, src1, src2)
-    bitset dst;
-    bitset src1;
-    bitset src2;
+     bitset dst;
+     bitset src1;
+     bitset src2;
 {
-    BITSET__CHECK3 (dst, src1, src2);
-    return BITSET__OP3 (dst, src1, src2, BITSET_ANDN);
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_ANDN_ (dst, src1, src2);
 }
 
 
 /* DST = SRC1 | ~SRC2.  Return non-zero if DST != SRC1 | ~SRC2.  */
 int
 bitset_orn (dst, src1, src2)
-    bitset dst;
-    bitset src1;
-    bitset src2;
+     bitset dst;
+     bitset src1;
+     bitset src2;
 {
-    BITSET__CHECK3 (dst, src1, src2);
-    return BITSET__OP3 (dst, src1, src2, BITSET_ORN);
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_ORN_ (dst, src1, src2);
+}
+
+
+int
+bitset_op4 (dst, src1, src2, src3, op)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+     enum bitset_ops op;
+{
+  int changed = 0;
+  bitset tmp;
+
+  /* Create temporary bitset.  */
+  tmp = bitset_alloc (BITSET_TYPE_ (dst), 0);
+
+  switch (op)
+    {
+    case BITSET_OP_OR_AND:
+      BITSET_OR_ (tmp, src1, src2);
+      changed = BITSET_AND_ (dst, src3, tmp);
+      break;
+
+    case BITSET_OP_AND_OR:
+      BITSET_AND_ (tmp, src1, src2);
+      changed = BITSET_OR_ (dst, src3, tmp);
+      break;
+
+    case BITSET_OP_ANDN_OR:
+      BITSET_ANDN_ (tmp, src1, src2);
+      changed = BITSET_OR_ (dst, src3, tmp);
+      break;
+
+    default:
+      abort ();
+    }
+
+  bitset_free (tmp);
+  return changed;
 }
 
 
@@ -540,13 +601,13 @@ bitset_orn (dst, src1, src2)
    DST != (SRC1 | SRC2) & SRC3.  */
 int
 bitset_or_and (dst, src1, src2, src3)
-    bitset dst;
-    bitset src1;
-    bitset src2;
-    bitset src3;
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
 {
-    BITSET__CHECK4 (dst, src1, src2, src3);
-    return BITSET__OP4 (dst, src1, src2, src3, BITSET_OR_AND);
+  BITSET_CHECK4_ (dst, src1, src2, src3);
+  return BITSET_OR_AND_ (dst, src1, src2, src3);
 }
 
 
@@ -554,13 +615,27 @@ bitset_or_and (dst, src1, src2, src3)
    DST != (SRC1 & SRC2) | SRC3.  */
 int
 bitset_and_or (dst, src1, src2, src3)
-    bitset dst;
-    bitset src1;
-    bitset src2;
-    bitset src3;
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  BITSET_CHECK4_ (dst, src1, src2, src3);
+  return BITSET_AND_OR_ (dst, src1, src2, src3);
+}
+
+
+/* DST = (SRC1 & ~SRC2) | SRC3.  Return non-zero if
+   DST != (SRC1 & ~SRC2) | SRC3.  */
+int
+bitset_andn_or (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
 {
-    BITSET__CHECK4 (dst, src1, src2, src3);
-    return BITSET__OP4 (dst, src1, src2, src3, BITSET_AND_OR);
+  BITSET_CHECK4_ (dst, src1, src2, src3);
+  return BITSET_ANDN_OR_ (dst, src1, src2, src3);
 }
 
 
@@ -579,7 +654,8 @@ void
 debug_bitset (bset)
      bitset bset;
 {
-  bitset_print (stderr, bset, 1);
+  if (bset)
+    bitset_print (stderr, bset, 1);
 }
 
 
@@ -595,47 +671,47 @@ bitset_release_memory ()
 #if BITSET_STATS
 int
 bitset_list (bset, list, num, next)
-    bitset bset;
-    bitset_bindex *list;
-    bitset_bindex num;
-    bitset_bindex *next;
+     bitset bset;
+     bitset_bindex *list;
+     bitset_bindex num;
+     bitset_bindex *next;
 {
-    bitset_bindex count;
+  bitset_bindex count;
 
-    count = BITSET__LIST (bset, list, num, next);
+  count = BITSET_LIST_ (bset, list, num, next);
 
-    if (bitset_stats)
-      {
-	bitset_bindex tmp;
-	bitset_bindex size;
-	bitset_bindex i;
-	enum bitset_type type;
-
-	type = bset->ops->type;
-	BITSET_STATS_LISTS_INC (bset);
-
-	/* Log histogram of number of set bits.  */
-	for (i = 0, tmp = count; tmp; tmp >>= 1, i++)
-	  continue;
-	if (i >= BITSET_LOG_COUNT_BINS)
-	  i = BITSET_LOG_COUNT_BINS - 1;
-	BITSET_STATS_LIST_COUNTS_INC (bset, i);
-
-	/* Log histogram of number of bits in set.  */
-	size = bitset_size (bset);
-	for (i = 0, tmp = size; tmp; tmp >>= 1, i++)
-	  continue;
-	if (i >= BITSET_LOG_SIZE_BINS)
-	  i = BITSET_LOG_SIZE_BINS - 1;
-	BITSET_STATS_LIST_SIZES_INC (bset, i);
-
-	/* Histogram of fraction of bits set.  */
-	i = size ? (count * BITSET_DENSITY_BINS) / size : 0;
-	if (i >= BITSET_DENSITY_BINS)
-	  i = BITSET_DENSITY_BINS - 1;
-	BITSET_STATS_LIST_DENSITY_INC (bset, i);
-      }
-    return count;
+  if (bitset_stats)
+    {
+      bitset_bindex tmp;
+      bitset_bindex size;
+      bitset_bindex i;
+      enum bitset_type type;
+
+      type = BITSET_TYPE_ (bset);
+      BITSET_STATS_LISTS_INC (bset);
+
+      /* Log histogram of number of set bits.  */
+      for (i = 0, tmp = count; tmp; tmp >>= 1, i++)
+	continue;
+      if (i >= BITSET_LOG_COUNT_BINS)
+	i = BITSET_LOG_COUNT_BINS - 1;
+      BITSET_STATS_LIST_COUNTS_INC (bset, i);
+
+      /* Log histogram of number of bits in set.  */
+      size = bitset_size (bset);
+      for (i = 0, tmp = size; tmp; tmp >>= 1, i++)
+	continue;
+      if (i >= BITSET_LOG_SIZE_BINS)
+	i = BITSET_LOG_SIZE_BINS - 1;
+      BITSET_STATS_LIST_SIZES_INC (bset, i);
+
+      /* Histogram of fraction of bits set.  */
+      i = size ? (count * BITSET_DENSITY_BINS) / size : 0;
+      if (i >= BITSET_DENSITY_BINS)
+	i = BITSET_DENSITY_BINS - 1;
+      BITSET_STATS_LIST_DENSITY_INC (bset, i);
+    }
+  return count;
 }
 
 
@@ -656,14 +732,14 @@ bitset_percent_histogram_print (file, name, msg, n_bins, bins)
     total += bins[i];
 
   if (!total)
-      return;
+    return;
 
   fprintf (file, "%s %s", name, msg);
   for (i = 0; i < n_bins; i++)
     fprintf (file, "%.0f-%.0f%%\t%8d (%5.1f%%)\n",
 	     i * 100.0 / n_bins,
-	     (i + 1) * 100.0 / n_bins,
-	     bins[i], (100.0 * bins[i]) / total);
+	     (i + 1) * 100.0 / n_bins, bins[i],
+	     (100.0 * bins[i]) / total);
 }
 
 
@@ -685,10 +761,10 @@ bitset_log_histogram_print (file, name, msg, n_bins, bins)
     total += bins[i];
 
   if (!total)
-      return;
+    return;
 
   /* 2 * ceil (log10(2) * (N - 1)) + 1  */
-  max_width = 2 * (unsigned int)(0.30103 * (n_bins - 1) + 0.9999) + 1;
+  max_width = 2 * (unsigned int) (0.30103 * (n_bins - 1) + 0.9999) + 1;
 
   fprintf (file, "%s %s", name, msg);
   for (i = 0; i < 2; i++)
@@ -699,7 +775,8 @@ bitset_log_histogram_print (file, name, msg, n_bins, bins)
   for (; i < n_bins; i++)
     fprintf (file, "%*d-%d\t%8d (%5.1f%%)\n",
 	     max_width - ((unsigned int) (0.30103 * (i) + 0.9999) + 1),
-	     1 << (i - 1), (1 << i) - 1, bins[i], (100.0 * bins[i]) / total);
+	     1 << (i - 1), (1 << i) - 1, bins[i],
+	     (100.0 * bins[i]) / total);
 }
 
 
@@ -721,10 +798,10 @@ bitset_stats_print_1 (file, name, stats)
   fprintf (file, "%d bitset_lists\n", stats->lists);
 
   bitset_log_histogram_print (file, name, "count log histogram\n",
-	   BITSET_LOG_COUNT_BINS, stats->list_counts);
+			      BITSET_LOG_COUNT_BINS, stats->list_counts);
 
   bitset_log_histogram_print (file, name, "size log histogram\n",
-	   BITSET_LOG_SIZE_BINS, stats->list_sizes);
+			      BITSET_LOG_SIZE_BINS, stats->list_sizes);
 
   bitset_percent_histogram_print (file, name, "density histogram\n",
 				  BITSET_DENSITY_BINS, stats->list_density);
@@ -738,7 +815,7 @@ bitset_stats_print (file, verbose)
      int verbose ATTRIBUTE_UNUSED;
 {
   int i;
-  static const char *names[] = BITSET__TYPE_NAMES;
+  static const char *names[] = BITSET_TYPE_NAMES;
 
   if (!bitset_stats)
     return;
@@ -749,7 +826,7 @@ bitset_stats_print (file, verbose)
     fprintf (file, "Accumulated runs = %d\n", bitset_stats->runs);
 
   for (i = 0; i < BITSET_TYPE_NUM; i++)
-      bitset_stats_print_1 (file, names[i], &bitset_stats->types[i]);
+    bitset_stats_print_1 (file, names[i], &bitset_stats->types[i]);
 }
 #endif /* BITSET_STATS  */
 
@@ -759,9 +836,9 @@ void
 bitset_stats_init ()
 {
 #if BITSET_STATS
-    bitset_stats = &bitset_stats_data;
-    bitset_stats_read ();
-#endif  /* BITSET_STATS  */
+  bitset_stats = &bitset_stats_data;
+  bitset_stats_read ();
+#endif /* BITSET_STATS  */
 }
 
 
@@ -769,25 +846,25 @@ bitset_stats_init ()
 static void
 bitset_stats_read ()
 {
-    FILE *file;
+  FILE *file;
 
-    if (!bitset_stats)
-      return;
+  if (!bitset_stats)
+    return;
 
-    file = fopen (BITSET_STATS_FILE, "r");
-    if (file)
-      {
-	if (fread (&bitset_stats_data, sizeof (bitset_stats_data),
-		   1, file) != 1)
-	  {
-	    if (ferror (file))
-	      perror ("Could not read stats file");
-	    else
-	      fprintf (stderr, "Bad stats file size\n");
-	  }
-	fclose (file);
-      }
-    bitset_stats_data.runs++;
+  file = fopen (BITSET_STATS_FILE, "r");
+  if (file)
+    {
+      if (fread (&bitset_stats_data, sizeof (bitset_stats_data),
+		 1, file) != 1)
+	{
+	  if (ferror (file))
+	    perror ("Could not read stats file.");
+	  else
+	    fprintf (stderr, "Bad stats file size.\n");
+	}
+      fclose (file);
+    }
+  bitset_stats_data.runs++;
 }
 
 
@@ -795,21 +872,21 @@ bitset_stats_read ()
 static void
 bitset_stats_write ()
 {
-    FILE *file;
+  FILE *file;
 
-    if (!bitset_stats)
-      return;
+  if (!bitset_stats)
+    return;
 
-    file = fopen (BITSET_STATS_FILE, "w");
-    if (file)
-      {
-	if (fwrite (&bitset_stats_data, sizeof (bitset_stats_data),
-		    1, file) != 1)
-	  perror ("Could not write stats file");
-	fclose (file);
-      }
-    else
-      perror ("Could not open stats file for writing");
+  file = fopen (BITSET_STATS_FILE, "w");
+  if (file)
+    {
+      if (fwrite (&bitset_stats_data, sizeof (bitset_stats_data),
+		  1, file) != 1)
+	perror ("Could not write stats file.");
+      fclose (file);
+    }
+  else
+    perror ("Could not open stats file for writing.");
 }
 
 
