@@ -108,18 +108,15 @@ static void
 bitset_percent_histogram_print (FILE *file, const char *name, const char *msg,
                                 unsigned n_bins, unsigned *bins)
 {
-  unsigned i;
-  unsigned total;
-
-  total = 0;
-  for (i = 0; i < n_bins; i++)
+  unsigned total = 0;
+  for (unsigned i = 0; i < n_bins; i++)
     total += bins[i];
 
   if (!total)
     return;
 
   fprintf (file, "%s %s", name, msg);
-  for (i = 0; i < n_bins; i++)
+  for (unsigned i = 0; i < n_bins; i++)
     fprintf (file, "%.0f-%.0f%%\t%8u (%5.1f%%)\n",
              i * 100.0 / n_bins,
              (i + 1) * 100.0 / n_bins, bins[i],
@@ -132,37 +129,39 @@ static void
 bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
                             unsigned n_bins, unsigned *bins)
 {
-  unsigned i;
-  unsigned total;
-  unsigned max_width;
-
-  total = 0;
-  for (i = 0; i < n_bins; i++)
+  unsigned total = 0;
+  for (unsigned i = 0; i < n_bins; i++)
     total += bins[i];
 
   if (!total)
     return;
 
   /* Determine number of useful bins.  */
-  for (i = n_bins; i > 3 && ! bins[i - 1]; i--)
-     continue;
-  n_bins = i;
+  {
+    unsigned i;
+    for (i = n_bins; i > 3 && ! bins[i - 1]; i--)
+      continue;
+    n_bins = i;
+  }
 
   /* 2 * ceil (log10 (2) * (N - 1)) + 1.  */
-  max_width = 2 * (unsigned) (0.30103 * (n_bins - 1) + 0.9999) + 1;
+  unsigned max_width = 2 * (unsigned) (0.30103 * (n_bins - 1) + 0.9999) + 1;
 
   fprintf (file, "%s %s", name, msg);
-  for (i = 0; i < 2; i++)
-    fprintf (file, "%*d\t%8u (%5.1f%%)\n",
-             max_width, i, bins[i], 100.0 * bins[i] / total);
-
-  for (; i < n_bins; i++)
-    fprintf (file, "%*lu-%lu\t%8u (%5.1f%%)\n",
-             max_width - ((unsigned) (0.30103 * (i) + 0.9999) + 1),
-             1UL << (i - 1),
-             (1UL << i) - 1,
-             bins[i],
-             (100.0 * bins[i]) / total);
+  {
+    unsigned i;
+    for (i = 0; i < 2; i++)
+      fprintf (file, "%*d\t%8u (%5.1f%%)\n",
+               max_width, i, bins[i], 100.0 * bins[i] / total);
+
+    for (; i < n_bins; i++)
+      fprintf (file, "%*lu-%lu\t%8u (%5.1f%%)\n",
+               max_width - ((unsigned) (0.30103 * (i) + 0.9999) + 1),
+               1UL << (i - 1),
+               (1UL << i) - 1,
+               bins[i],
+               (100.0 * bins[i]) / total);
+  }
 }
 
 
@@ -205,8 +204,6 @@ bitset_stats_print_1 (FILE *file, const char *name,
 static void
 bitset_stats_print (FILE *file, bool verbose ATTRIBUTE_UNUSED)
 {
-  int i;
-
   if (!bitset_stats_info)
     return;
 
@@ -215,7 +212,7 @@ bitset_stats_print (FILE *file, bool verbose ATTRIBUTE_UNUSED)
   if (bitset_stats_info->runs > 1)
     fprintf (file, _("Accumulated runs = %u\n"), bitset_stats_info->runs);
 
-  for (i = 0; i < BITSET_TYPE_NUM; i++)
+  for (int i = 0; i < BITSET_TYPE_NUM; i++)
     bitset_stats_print_1 (file, bitset_type_names[i],
                           &bitset_stats_info->types[i]);
 }
@@ -242,15 +239,13 @@ bitset_stats_disable (void)
 void
 bitset_stats_read (const char *file_name)
 {
-  FILE *file;
-
   if (!bitset_stats_info)
     return;
 
   if (!file_name)
     file_name = BITSET_STATS_FILE;
 
-  file = fopen (file_name, "r");
+  FILE *file = fopen (file_name, "r");
   if (file)
     {
       if (fread (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
@@ -272,15 +267,13 @@ bitset_stats_read (const char *file_name)
 void
 bitset_stats_write (const char *file_name)
 {
-  FILE *file;
-
   if (!bitset_stats_info)
     return;
 
   if (!file_name)
     file_name = BITSET_STATS_FILE;
 
-  file = fopen (file_name, "w");
+  FILE *file = fopen (file_name, "w");
   if (file)
     {
       if (fwrite (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
@@ -352,7 +345,7 @@ bitset_stats_reset (bitset dst, bitset_bindex bitno)
 static bool
 bitset_stats_toggle (bitset src, bitset_bindex bitno)
 {
-    return BITSET_TOGGLE_ (src->s.bset, bitno);
+  return BITSET_TOGGLE_ (src->s.bset, bitno);
 }
 
 
@@ -573,15 +566,14 @@ static bitset_bindex
 bitset_stats_list (bitset bset, bitset_bindex *list,
                    bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex count;
+  bitset_bindex count = BITSET_LIST_ (bset->s.bset, list, num, next);
+
+  BITSET_STATS_LISTS_INC (bset->s.bset);
+
   bitset_bindex tmp;
   bitset_bindex size;
   bitset_bindex i;
 
-  count = BITSET_LIST_ (bset->s.bset, list, num, next);
-
-  BITSET_STATS_LISTS_INC (bset->s.bset);
-
   /* Log histogram of number of set bits.  */
   for (i = 0, tmp = count; tmp; tmp >>= 1, i++)
      continue;
@@ -663,7 +655,7 @@ struct bitset_vtable bitset_stats_vtable = {
 enum bitset_type
 bitset_stats_type_get (bitset bset)
 {
-   return BITSET_TYPE_ (bset->s.bset);
+  return BITSET_TYPE_ (bset->s.bset);
 }
 
 
@@ -677,9 +669,6 @@ bitset_stats_bytes (void)
 bitset
 bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 {
-  size_t bytes;
-  bitset sbset;
-
   bset->b.vtable = &bitset_stats_vtable;
 
   /* Disable cache.  */
@@ -691,6 +680,8 @@ bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 
   /* Set up the actual bitset implementation that
      we are a wrapper over.  */
+  size_t bytes;
+  bitset sbset;
   switch (type)
     {
     default:
