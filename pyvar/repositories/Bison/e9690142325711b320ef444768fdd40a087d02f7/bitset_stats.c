@@ -48,29 +48,29 @@
 
 
 /* Accessor macros.  */
-#define BITSET_STATS_ALLOCS_INC(TYPE)			\
+#define BITSET_STATS_ALLOCS_INC(TYPE)                   \
     bitset_stats_info->types[(TYPE)].allocs++
-#define BITSET_STATS_FREES_INC(BSET)			\
+#define BITSET_STATS_FREES_INC(BSET)                    \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].frees++
-#define BITSET_STATS_SETS_INC(BSET)			\
+#define BITSET_STATS_SETS_INC(BSET)                     \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].sets++
-#define BITSET_STATS_CACHE_SETS_INC(BSET)		\
+#define BITSET_STATS_CACHE_SETS_INC(BSET)               \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].cache_sets++
-#define BITSET_STATS_RESETS_INC(BSET)			\
+#define BITSET_STATS_RESETS_INC(BSET)                   \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].resets++
-#define BITSET_STATS_CACHE_RESETS_INC(BSET)		\
+#define BITSET_STATS_CACHE_RESETS_INC(BSET)             \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].cache_resets++
-#define BITSET_STATS_TESTS_INC(BSET)			\
+#define BITSET_STATS_TESTS_INC(BSET)                    \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].tests++
-#define BITSET_STATS_CACHE_TESTS_INC(BSET)		\
+#define BITSET_STATS_CACHE_TESTS_INC(BSET)              \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].cache_tests++
-#define BITSET_STATS_LISTS_INC(BSET)			\
+#define BITSET_STATS_LISTS_INC(BSET)                    \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].lists++
-#define BITSET_STATS_LIST_COUNTS_INC(BSET, I)		\
+#define BITSET_STATS_LIST_COUNTS_INC(BSET, I)           \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].list_counts[(I)]++
-#define BITSET_STATS_LIST_SIZES_INC(BSET, I)		\
+#define BITSET_STATS_LIST_SIZES_INC(BSET, I)            \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].list_sizes[(I)]++
-#define BITSET_STATS_LIST_DENSITY_INC(BSET, I)		\
+#define BITSET_STATS_LIST_DENSITY_INC(BSET, I)          \
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].list_density[(I)]++
 
 
@@ -105,7 +105,7 @@ bool bitset_stats_enabled = false;
 /* Print a percentage histogram with message MSG to FILE.  */
 static void
 bitset_percent_histogram_print (FILE *file, const char *name, const char *msg,
-				unsigned int n_bins, unsigned int *bins)
+                                unsigned int n_bins, unsigned int *bins)
 {
   unsigned int i;
   unsigned int total;
@@ -120,16 +120,16 @@ bitset_percent_histogram_print (FILE *file, const char *name, const char *msg,
   fprintf (file, "%s %s", name, msg);
   for (i = 0; i < n_bins; i++)
     fprintf (file, "%.0f-%.0f%%\t%8u (%5.1f%%)\n",
-	     i * 100.0 / n_bins,
-	     (i + 1) * 100.0 / n_bins, bins[i],
-	     (100.0 * bins[i]) / total);
+             i * 100.0 / n_bins,
+             (i + 1) * 100.0 / n_bins, bins[i],
+             (100.0 * bins[i]) / total);
 }
 
 
 /* Print a log histogram with message MSG to FILE.  */
 static void
 bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
-			    unsigned int n_bins, unsigned int *bins)
+                            unsigned int n_bins, unsigned int *bins)
 {
   unsigned int i;
   unsigned int total;
@@ -153,50 +153,50 @@ bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
   fprintf (file, "%s %s", name, msg);
   for (i = 0; i < 2; i++)
     fprintf (file, "%*d\t%8u (%5.1f%%)\n",
-	     max_width, i, bins[i], 100.0 * bins[i] / total);
+             max_width, i, bins[i], 100.0 * bins[i] / total);
 
   for (; i < n_bins; i++)
     fprintf (file, "%*lu-%lu\t%8u (%5.1f%%)\n",
-	     max_width - ((unsigned int) (0.30103 * (i) + 0.9999) + 1),
-	     1UL << (i - 1),
-	     (1UL << i) - 1,
-	     bins[i],
-	     (100.0 * bins[i]) / total);
+             max_width - ((unsigned int) (0.30103 * (i) + 0.9999) + 1),
+             1UL << (i - 1),
+             (1UL << i) - 1,
+             bins[i],
+             (100.0 * bins[i]) / total);
 }
 
 
 /* Print bitset statistics to FILE.  */
 static void
 bitset_stats_print_1 (FILE *file, const char *name,
-		      struct bitset_type_info_struct *stats)
+                      struct bitset_type_info_struct *stats)
 {
   if (!stats)
     return;
 
   fprintf (file, "%s:\n", name);
   fprintf (file, _("%u bitset_allocs, %u freed (%.2f%%).\n"),
-	   stats->allocs, stats->frees,
-	   stats->allocs ? 100.0 * stats->frees / stats->allocs : 0);
+           stats->allocs, stats->frees,
+           stats->allocs ? 100.0 * stats->frees / stats->allocs : 0);
   fprintf (file, _("%u bitset_sets, %u cached (%.2f%%)\n"),
-	   stats->sets, stats->cache_sets,
-	   stats->sets ? 100.0 * stats->cache_sets / stats->sets : 0);
+           stats->sets, stats->cache_sets,
+           stats->sets ? 100.0 * stats->cache_sets / stats->sets : 0);
   fprintf (file, _("%u bitset_resets, %u cached (%.2f%%)\n"),
-	   stats->resets, stats->cache_resets,
-	   stats->resets ? 100.0 * stats->cache_resets / stats->resets : 0);
+           stats->resets, stats->cache_resets,
+           stats->resets ? 100.0 * stats->cache_resets / stats->resets : 0);
   fprintf (file, _("%u bitset_tests, %u cached (%.2f%%)\n"),
-	   stats->tests, stats->cache_tests,
-	   stats->tests ? 100.0 * stats->cache_tests / stats->tests : 0);
+           stats->tests, stats->cache_tests,
+           stats->tests ? 100.0 * stats->cache_tests / stats->tests : 0);
 
   fprintf (file, _("%u bitset_lists\n"), stats->lists);
 
   bitset_log_histogram_print (file, name, _("count log histogram\n"),
-			      BITSET_LOG_COUNT_BINS, stats->list_counts);
+                              BITSET_LOG_COUNT_BINS, stats->list_counts);
 
   bitset_log_histogram_print (file, name, _("size log histogram\n"),
-			      BITSET_LOG_SIZE_BINS, stats->list_sizes);
+                              BITSET_LOG_SIZE_BINS, stats->list_sizes);
 
   bitset_percent_histogram_print (file, name, _("density histogram\n"),
-				  BITSET_DENSITY_BINS, stats->list_density);
+                                  BITSET_DENSITY_BINS, stats->list_density);
 }
 
 
@@ -216,7 +216,7 @@ bitset_stats_print (FILE *file, bool verbose ATTRIBUTE_UNUSED)
 
   for (i = 0; i < BITSET_TYPE_NUM; i++)
     bitset_stats_print_1 (file, bitset_type_names[i],
-			  &bitset_stats_info->types[i]);
+                          &bitset_stats_info->types[i]);
 }
 
 
@@ -253,15 +253,15 @@ bitset_stats_read (const char *file_name)
   if (file)
     {
       if (fread (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
-		 1, file) != 1)
-	{
-	  if (ferror (file))
-	    perror (_("Could not read stats file."));
-	  else
-	    fprintf (stderr, _("Bad stats file size.\n"));
-	}
+                 1, file) != 1)
+        {
+          if (ferror (file))
+            perror (_("Could not read stats file."));
+          else
+            fprintf (stderr, _("Bad stats file size.\n"));
+        }
       if (fclose (file) != 0)
-	perror (_("Could not read stats file."));
+        perror (_("Could not read stats file."));
     }
   bitset_stats_info_data.runs++;
 }
@@ -283,10 +283,10 @@ bitset_stats_write (const char *file_name)
   if (file)
     {
       if (fwrite (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
-		  1, file) != 1)
-	perror (_("Could not write stats file."));
+                  1, file) != 1)
+        perror (_("Could not write stats file."));
       if (fclose (file) != 0)
-	perror (_("Could not write stats file."));
+        perror (_("Could not write stats file."));
     }
   else
     perror (_("Could not open stats file for writing."));
@@ -340,7 +340,7 @@ bitset_stats_reset (bitset dst, bitset_bindex bitno)
   if (offset < bset->b.csize)
     {
       bset->b.cdata[offset] &=
-	~((bitset_word) 1 << (bitno % BITSET_WORD_BITS));
+        ~((bitset_word) 1 << (bitno % BITSET_WORD_BITS));
       BITSET_STATS_CACHE_RESETS_INC (bset);
     }
   else
@@ -570,7 +570,7 @@ bitset_stats_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 
 static bitset_bindex
 bitset_stats_list (bitset bset, bitset_bindex *list,
-		   bitset_bindex num, bitset_bindex *next)
+                   bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex count;
   bitset_bindex tmp;
@@ -609,7 +609,7 @@ bitset_stats_list (bitset bset, bitset_bindex *list,
 
 static bitset_bindex
 bitset_stats_list_reverse (bitset bset, bitset_bindex *list,
-			   bitset_bindex num, bitset_bindex *next)
+                           bitset_bindex num, bitset_bindex *next)
 {
   return BITSET_LIST_REVERSE_ (bset->s.bset, list, num, next);
 }
