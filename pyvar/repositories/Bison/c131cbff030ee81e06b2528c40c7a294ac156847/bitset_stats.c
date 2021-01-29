@@ -38,6 +38,8 @@
 #include <string.h>
 #include <stdio.h>
 
+#include "gettext.h"
+#define _(Msgid)  gettext (Msgid)
 
 /* Configuration macros.  */
 #define BITSET_STATS_FILE "bitset.dat"
@@ -221,28 +223,28 @@ bitset_stats_print_1 (file, name, stats)
     return;
   
   fprintf (file, "%s:\n", name);
-  fprintf (file, "%d bitset_allocs, %d freed (%.2f%%).\n",
+  fprintf (file, _("%d bitset_allocs, %d freed (%.2f%%).\n"),
 	   stats->allocs, stats->frees,
 	   stats->allocs ? 100.0 * stats->frees / stats->allocs : 0);
-  fprintf (file, "%d bitset_sets, %d cached (%.2f%%)\n",
+  fprintf (file, _("%d bitset_sets, %d cached (%.2f%%)\n"),
 	   stats->sets, stats->cache_sets,
 	   stats->sets ? 100.0 * stats->cache_sets / stats->sets : 0);
-  fprintf (file, "%d bitset_resets, %d cached (%.2f%%)\n",
+  fprintf (file, _("%d bitset_resets, %d cached (%.2f%%)\n"),
 	   stats->resets, stats->cache_resets,
 	   stats->resets ? 100.0 * stats->cache_resets / stats->resets : 0);
-  fprintf (file, "%d bitset_tests, %d cached (%.2f%%)\n",
+  fprintf (file, _("%d bitset_tests, %d cached (%.2f%%)\n"),
 	   stats->tests, stats->cache_tests,
 	   stats->tests ? 100.0 * stats->cache_tests / stats->tests : 0);
 
-  fprintf (file, "%d bitset_lists\n", stats->lists);
+  fprintf (file, _("%d bitset_lists\n"), stats->lists);
 
-  bitset_log_histogram_print (file, name, "count log histogram\n",
+  bitset_log_histogram_print (file, name, _("count log histogram\n"),
 			      BITSET_LOG_COUNT_BINS, stats->list_counts);
 
-  bitset_log_histogram_print (file, name, "size log histogram\n",
+  bitset_log_histogram_print (file, name, _("size log histogram\n"),
 			      BITSET_LOG_SIZE_BINS, stats->list_sizes);
 
-  bitset_percent_histogram_print (file, name, "density histogram\n",
+  bitset_percent_histogram_print (file, name, _("density histogram\n"),
 				  BITSET_DENSITY_BINS, stats->list_density);
 }
 
@@ -259,10 +261,10 @@ bitset_stats_print (file, verbose)
   if (!bitset_stats_info)
     return;
 
-  fprintf (file, "Bitset statistics:\n\n");
+  fprintf (file, _("Bitset statistics:\n\n"));
 
   if (bitset_stats_info->runs > 1)
-    fprintf (file, "Accumulated runs = %d\n", bitset_stats_info->runs);
+    fprintf (file, _("Accumulated runs = %d\n"), bitset_stats_info->runs);
 
   for (i = 0; i < BITSET_TYPE_NUM; i++)
     bitset_stats_print_1 (file, names[i], &bitset_stats_info->types[i]);
@@ -306,9 +308,9 @@ bitset_stats_read (filename)
 		 1, file) != 1)
 	{
 	  if (ferror (file))
-	    perror ("Could not read stats file.");
+	    perror (_("Could not read stats file."));
 	  else
-	    fprintf (stderr, "Bad stats file size.\n");
+	    fprintf (stderr, _("Bad stats file size.\n"));
 	}
       fclose (file);
     }
@@ -334,11 +336,11 @@ bitset_stats_write (filename)
     {
       if (fwrite (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
 		  1, file) != 1)
-	perror ("Could not write stats file.");
+	perror (_("Could not write stats file."));
       fclose (file);
     }
   else
-    perror ("Could not open stats file for writing.");
+    perror (_("Could not open stats file for writing."));
 }
 
 
@@ -365,14 +367,14 @@ bitset_stats_set (dst, bitno)
      bitset_bindex bitno;
 {
   bitset bset = dst->s.bset;
-  bitset_windex index = bitno / BITSET_WORD_BITS;
-  bitset_windex offset = index - bset->b.cindex;
+  bitset_windex wordno = bitno / BITSET_WORD_BITS;
+  bitset_windex offset = wordno - bset->b.cindex;
   
   BITSET_STATS_SETS_INC (bset);
 
   if (offset < bset->b.csize)
     {
-      bset->b.cdata[offset] |= (1 << (bitno % BITSET_WORD_BITS));
+      bset->b.cdata[offset] |= (bitset_word) 1 << (bitno % BITSET_WORD_BITS);
       BITSET_STATS_CACHE_SETS_INC (bset);
     }
   else
@@ -386,14 +388,15 @@ bitset_stats_reset (dst, bitno)
      bitset_bindex bitno;
 {
   bitset bset = dst->s.bset;
-  bitset_windex index = bitno / BITSET_WORD_BITS;
-  bitset_windex offset = index - bset->b.cindex;
+  bitset_windex wordno = bitno / BITSET_WORD_BITS;
+  bitset_windex offset = wordno - bset->b.cindex;
   
   BITSET_STATS_RESETS_INC (bset);
 
   if (offset < bset->b.csize)
     {
-      bset->b.cdata[offset] &= ~(1 << (bitno % BITSET_WORD_BITS));
+      bset->b.cdata[offset] &=
+	~((bitset_word) 1 << (bitno % BITSET_WORD_BITS));
       BITSET_STATS_CACHE_RESETS_INC (bset);
     }
   else
@@ -407,8 +410,8 @@ bitset_stats_test (src, bitno)
      bitset_bindex bitno;
 {
   bitset bset = src->s.bset;
-  bitset_windex index = bitno / BITSET_WORD_BITS;
-  bitset_windex offset = index - bset->b.cindex;
+  bitset_windex wordno = bitno / BITSET_WORD_BITS;
+  bitset_windex offset = wordno - bset->b.cindex;
 
   BITSET_STATS_TESTS_INC (bset);
   
