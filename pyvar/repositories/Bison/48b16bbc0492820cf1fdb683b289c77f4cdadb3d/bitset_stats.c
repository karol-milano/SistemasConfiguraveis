@@ -241,17 +241,17 @@ bitset_stats_disable (void)
 
 /* Read bitset statistics file.  */
 void
-bitset_stats_read (const char *filename)
+bitset_stats_read (const char *file_name)
 {
   FILE *file;
 
   if (!bitset_stats_info)
     return;
 
-  if (!filename)
-    filename = BITSET_STATS_FILE;
+  if (!file_name)
+    file_name = BITSET_STATS_FILE;
 
-  file = fopen (filename, "r");
+  file = fopen (file_name, "r");
   if (file)
     {
       if (fread (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
@@ -271,17 +271,17 @@ bitset_stats_read (const char *filename)
 
 /* Write bitset statistics file.  */
 void
-bitset_stats_write (const char *filename)
+bitset_stats_write (const char *file_name)
 {
   FILE *file;
 
   if (!bitset_stats_info)
     return;
 
-  if (!filename)
-    filename = BITSET_STATS_FILE;
+  if (!file_name)
+    file_name = BITSET_STATS_FILE;
 
-  file = fopen (filename, "w");
+  file = fopen (file_name, "w");
   if (file)
     {
       if (fwrite (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
