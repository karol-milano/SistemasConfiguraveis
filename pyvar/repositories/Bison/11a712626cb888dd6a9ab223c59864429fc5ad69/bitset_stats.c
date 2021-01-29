@@ -261,7 +261,8 @@ bitset_stats_read (const char *filename)
 	  else
 	    fprintf (stderr, _("Bad stats file size.\n"));
 	}
-      fclose (file);
+      if (fclose (file) != 0)
+	perror (_("Could not read stats file."));
     }
   bitset_stats_info_data.runs++;
 }
@@ -285,7 +286,8 @@ bitset_stats_write (const char *filename)
       if (fwrite (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
 		  1, file) != 1)
 	perror (_("Could not write stats file."));
-      fclose (file);
+      if (fclose (file) != 0)
+	perror (_("Could not write stats file."));
     }
   else
     perror (_("Could not open stats file for writing."));
