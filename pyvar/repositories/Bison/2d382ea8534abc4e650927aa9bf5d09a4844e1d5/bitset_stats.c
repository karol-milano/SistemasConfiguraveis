@@ -120,10 +120,11 @@ static void bitset_stats_set PARAMS ((bitset, bitset_bindex));
 static void bitset_stats_reset PARAMS ((bitset, bitset_bindex));
 static int bitset_stats_toggle PARAMS ((bitset, bitset_bindex));
 static int bitset_stats_test PARAMS ((bitset, bitset_bindex));
-static int bitset_stats_size PARAMS ((bitset));
-static int bitset_stats_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
-				      bitset_bindex *));
-static int bitset_stats_list_reverse
+static bitset_bindex bitset_stats_size PARAMS ((bitset));
+static bitset_bindex bitset_stats_list PARAMS ((bitset, bitset_bindex *,
+						bitset_bindex,
+						bitset_bindex *));
+static bitset_bindex bitset_stats_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 static void bitset_stats_free PARAMS ((bitset));
 static void bitset_percent_histogram_print PARAMS ((FILE *, const char *,
@@ -160,7 +161,7 @@ bitset_percent_histogram_print (file, name, msg, n_bins, bins)
 
   fprintf (file, "%s %s", name, msg);
   for (i = 0; i < n_bins; i++)
-    fprintf (file, "%.0f-%.0f%%\t%8d (%5.1f%%)\n",
+    fprintf (file, "%.0f-%.0f%%\t%8u (%5.1f%%)\n",
 	     i * 100.0 / n_bins,
 	     (i + 1) * 100.0 / n_bins, bins[i],
 	     (100.0 * bins[i]) / total);
@@ -197,13 +198,15 @@ bitset_log_histogram_print (file, name, msg, n_bins, bins)
 
   fprintf (file, "%s %s", name, msg);
   for (i = 0; i < 2; i++)
-    fprintf (file, "%*d\t%8d (%5.1f%%)\n",
+    fprintf (file, "%*d\t%8u (%5.1f%%)\n",
 	     max_width, i, bins[i], 100.0 * bins[i] / total);
 
   for (; i < n_bins; i++)
-    fprintf (file, "%*d-%d\t%8d (%5.1f%%)\n",
+    fprintf (file, "%*lu-%lu\t%8u (%5.1f%%)\n",
 	     max_width - ((unsigned int) (0.30103 * (i) + 0.9999) + 1),
-	     1 << (i - 1), (1 << i) - 1, bins[i],
+	     (unsigned long) 1 << (i - 1),
+	     ((unsigned long) 1 << i) - 1,
+	     bins[i],
 	     (100.0 * bins[i]) / total);
 }
 
@@ -219,20 +222,20 @@ bitset_stats_print_1 (file, name, stats)
     return;
   
   fprintf (file, "%s:\n", name);
-  fprintf (file, _("%d bitset_allocs, %d freed (%.2f%%).\n"),
+  fprintf (file, _("%u bitset_allocs, %u freed (%.2f%%).\n"),
 	   stats->allocs, stats->frees,
 	   stats->allocs ? 100.0 * stats->frees / stats->allocs : 0);
-  fprintf (file, _("%d bitset_sets, %d cached (%.2f%%)\n"),
+  fprintf (file, _("%u bitset_sets, %u cached (%.2f%%)\n"),
 	   stats->sets, stats->cache_sets,
 	   stats->sets ? 100.0 * stats->cache_sets / stats->sets : 0);
-  fprintf (file, _("%d bitset_resets, %d cached (%.2f%%)\n"),
+  fprintf (file, _("%u bitset_resets, %u cached (%.2f%%)\n"),
 	   stats->resets, stats->cache_resets,
 	   stats->resets ? 100.0 * stats->cache_resets / stats->resets : 0);
-  fprintf (file, _("%d bitset_tests, %d cached (%.2f%%)\n"),
+  fprintf (file, _("%u bitset_tests, %u cached (%.2f%%)\n"),
 	   stats->tests, stats->cache_tests,
 	   stats->tests ? 100.0 * stats->cache_tests / stats->tests : 0);
 
-  fprintf (file, _("%d bitset_lists\n"), stats->lists);
+  fprintf (file, _("%u bitset_lists\n"), stats->lists);
 
   bitset_log_histogram_print (file, name, _("count log histogram\n"),
 			      BITSET_LOG_COUNT_BINS, stats->list_counts);
@@ -259,7 +262,7 @@ bitset_stats_print (file, verbose)
   fprintf (file, _("Bitset statistics:\n\n"));
 
   if (bitset_stats_info->runs > 1)
-    fprintf (file, _("Accumulated runs = %d\n"), bitset_stats_info->runs);
+    fprintf (file, _("Accumulated runs = %u\n"), bitset_stats_info->runs);
 
   for (i = 0; i < BITSET_TYPE_NUM; i++)
     bitset_stats_print_1 (file, bitset_type_names[i], 
@@ -430,7 +433,7 @@ bitset_stats_test (src, bitno)
 }
 
 
-static int
+static bitset_bindex
 bitset_stats_size (src)
      bitset src;
 {
@@ -438,7 +441,7 @@ bitset_stats_size (src)
 }
 
 
-static int
+static bitset_bindex
 bitset_stats_count (src)
      bitset src;
 {
@@ -686,7 +689,7 @@ bitset_stats_or_and_cmp (dst, src1, src2, src3)
 }
 
 
-static int
+static bitset_bindex
 bitset_stats_list (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
@@ -728,7 +731,7 @@ bitset_stats_list (bset, list, num, next)
 }
 
 
-static int
+static bitset_bindex
 bitset_stats_list_reverse (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
@@ -793,7 +796,8 @@ bitset_stats_type_get (bset)
 }
 
 
-int bitset_stats_bytes (void)
+size_t
+bitset_stats_bytes (void)
 {
   return sizeof (struct bitset_struct);
 }
@@ -805,7 +809,7 @@ bitset_stats_init (bset, n_bits, type)
      bitset_bindex n_bits;
      enum bitset_type type;
 {
-  unsigned int bytes;
+  size_t bytes;
   bitset sbset;
 
   bset->b.vtable = &bitset_stats_vtable;
