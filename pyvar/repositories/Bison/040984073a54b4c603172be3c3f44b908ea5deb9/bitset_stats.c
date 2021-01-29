@@ -50,29 +50,29 @@
 
 
 /* Accessor macros.  */
-#define BITSET_STATS_ALLOCS_INC(TYPE)	 		\
+#define BITSET_STATS_ALLOCS_INC(TYPE)			\
     bitset_stats_info->types[(TYPE)].allocs++
-#define BITSET_STATS_FREES_INC(BSET) 			\
+#define BITSET_STATS_FREES_INC(BSET)			\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].frees++
-#define BITSET_STATS_SETS_INC(BSET) 			\
+#define BITSET_STATS_SETS_INC(BSET)			\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].sets++
-#define BITSET_STATS_CACHE_SETS_INC(BSET) 		\
+#define BITSET_STATS_CACHE_SETS_INC(BSET)		\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].cache_sets++
-#define BITSET_STATS_RESETS_INC(BSET) 			\
+#define BITSET_STATS_RESETS_INC(BSET)			\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].resets++
-#define BITSET_STATS_CACHE_RESETS_INC(BSET) 		\
+#define BITSET_STATS_CACHE_RESETS_INC(BSET)		\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].cache_resets++
-#define BITSET_STATS_TESTS_INC(BSET) 			\
+#define BITSET_STATS_TESTS_INC(BSET)			\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].tests++
-#define BITSET_STATS_CACHE_TESTS_INC(BSET) 		\
+#define BITSET_STATS_CACHE_TESTS_INC(BSET)		\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].cache_tests++
-#define BITSET_STATS_LISTS_INC(BSET) 			\
+#define BITSET_STATS_LISTS_INC(BSET)			\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].lists++
-#define BITSET_STATS_LIST_COUNTS_INC(BSET, I) 		\
+#define BITSET_STATS_LIST_COUNTS_INC(BSET, I)		\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].list_counts[(I)]++
-#define BITSET_STATS_LIST_SIZES_INC(BSET, I) 		\
+#define BITSET_STATS_LIST_SIZES_INC(BSET, I)		\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].list_sizes[(I)]++
-#define BITSET_STATS_LIST_DENSITY_INC(BSET, I) 		\
+#define BITSET_STATS_LIST_DENSITY_INC(BSET, I)		\
     bitset_stats_info->types[BITSET_TYPE_ (BSET)].list_density[(I)]++
 
 
