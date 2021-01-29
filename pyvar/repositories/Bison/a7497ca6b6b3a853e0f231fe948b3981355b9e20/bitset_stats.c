@@ -284,7 +284,7 @@ bitset_stats_write (const char *file_name)
     {
       if (fwrite (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
                   1, file) != 1)
-        perror (_("cannot not write stats file"));
+        perror (_("cannot write stats file"));
       if (fclose (file) != 0)
         perror (_("cannot write stats file"));
     }
