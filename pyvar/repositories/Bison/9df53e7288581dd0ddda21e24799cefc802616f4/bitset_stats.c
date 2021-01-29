@@ -77,23 +77,23 @@
 
 struct bitset_type_info_struct
 {
-  unsigned int allocs;
-  unsigned int frees;
-  unsigned int lists;
-  unsigned int sets;
-  unsigned int cache_sets;
-  unsigned int resets;
-  unsigned int cache_resets;
-  unsigned int tests;
-  unsigned int cache_tests;
-  unsigned int list_counts[BITSET_LOG_COUNT_BINS];
-  unsigned int list_sizes[BITSET_LOG_SIZE_BINS];
-  unsigned int list_density[BITSET_DENSITY_BINS];
+  unsigned allocs;
+  unsigned frees;
+  unsigned lists;
+  unsigned sets;
+  unsigned cache_sets;
+  unsigned resets;
+  unsigned cache_resets;
+  unsigned tests;
+  unsigned cache_tests;
+  unsigned list_counts[BITSET_LOG_COUNT_BINS];
+  unsigned list_sizes[BITSET_LOG_SIZE_BINS];
+  unsigned list_density[BITSET_DENSITY_BINS];
 };
 
 struct bitset_stats_info_struct
 {
-  unsigned int runs;
+  unsigned runs;
   struct bitset_type_info_struct types[BITSET_TYPE_NUM];
 };
 
@@ -106,10 +106,10 @@ bool bitset_stats_enabled = false;
 /* Print a percentage histogram with message MSG to FILE.  */
 static void
 bitset_percent_histogram_print (FILE *file, const char *name, const char *msg,
-                                unsigned int n_bins, unsigned int *bins)
+                                unsigned n_bins, unsigned *bins)
 {
-  unsigned int i;
-  unsigned int total;
+  unsigned i;
+  unsigned total;
 
   total = 0;
   for (i = 0; i < n_bins; i++)
@@ -130,11 +130,11 @@ bitset_percent_histogram_print (FILE *file, const char *name, const char *msg,
 /* Print a log histogram with message MSG to FILE.  */
 static void
 bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
-                            unsigned int n_bins, unsigned int *bins)
+                            unsigned n_bins, unsigned *bins)
 {
-  unsigned int i;
-  unsigned int total;
-  unsigned int max_width;
+  unsigned i;
+  unsigned total;
+  unsigned max_width;
 
   total = 0;
   for (i = 0; i < n_bins; i++)
@@ -149,7 +149,7 @@ bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
   n_bins = i;
 
   /* 2 * ceil (log10 (2) * (N - 1)) + 1.  */
-  max_width = 2 * (unsigned int) (0.30103 * (n_bins - 1) + 0.9999) + 1;
+  max_width = 2 * (unsigned) (0.30103 * (n_bins - 1) + 0.9999) + 1;
 
   fprintf (file, "%s %s", name, msg);
   for (i = 0; i < 2; i++)
@@ -158,7 +158,7 @@ bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
 
   for (; i < n_bins; i++)
     fprintf (file, "%*lu-%lu\t%8u (%5.1f%%)\n",
-             max_width - ((unsigned int) (0.30103 * (i) + 0.9999) + 1),
+             max_width - ((unsigned) (0.30103 * (i) + 0.9999) + 1),
              1UL << (i - 1),
              (1UL << i) - 1,
              bins[i],
