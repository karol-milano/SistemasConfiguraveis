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
+            perror (_("cannot read stats file"));
+          else
+            fprintf (stderr, _("bad stats file size\n"));
+        }
       if (fclose (file) != 0)
-	perror (_("Could not read stats file."));
+        perror (_("cannot read stats file"));
     }
   bitset_stats_info_data.runs++;
 }
@@ -283,13 +283,13 @@ bitset_stats_write (const char *file_name)
   if (file)
     {
       if (fwrite (&bitset_stats_info_data, sizeof (bitset_stats_info_data),
-		  1, file) != 1)
-	perror (_("Could not write stats file."));
+                  1, file) != 1)
+        perror (_("cannot not write stats file"));
       if (fclose (file) != 0)
-	perror (_("Could not write stats file."));
+        perror (_("cannot write stats file"));
     }
   else
-    perror (_("Could not open stats file for writing."));
+    perror (_("cannot open stats file for writing"));
 }
 
 
