@@ -136,9 +136,26 @@ xfclose (FILE *ptr)
 
   return result;
 }
+
+/*--------------------------------------------------.
+| Save the content of the obstack OBS in FILENAME.  |
+`--------------------------------------------------*/
+
+void
+obstack_save (struct obstack *obs, const char *filename)
+{
+  FILE *out = xfopen (filename, "w");
+  size_t size = obstack_object_size (obs);
+  fwrite (obstack_finish (obs), 1, size, out);
+  xfclose (out);
+}
+
 
-/* JF this has been hacked to death.  Nowaday it sets up the file names for
-   the output files, and opens the tmp files and the parser */
+/*-----------------------------------------------------------------.
+| Open the input file.  Look for the skeletons.  Find the names of |
+| the output files.  Prepare the obstacks.                         |
+`-----------------------------------------------------------------*/
+
 void
 open_files (void)
 {
@@ -358,53 +375,33 @@ open_extra_files (void)
   fguard = xfopen (guardfile, "w");
 }
 
+
+/*-----------------------------------------------------.
+| Close the open files, produce all the output files.  |
+`-----------------------------------------------------*/
+
 void
-done (void)
+output_files (void)
 {
   xfclose (fguard);
   xfclose (finput);
   xfclose (fparser);
   xfclose (foutput);
 
-  /* JF write out the output file */
-  if (!complain_message_count)
-    {
-      /* Output the main file.  */
-      FILE *ftab = xfopen (tabfile, "w");
-      size_t size = obstack_object_size (&table_obstack);
-      fwrite (obstack_finish (&table_obstack), 1, size, ftab);
-      xfclose (ftab);
-
-      /* Output the header file is wanted. */
-      if (defines_flag)
-	{
-	  FILE *fdefs = xfopen (defsfile, "w");
-	  size_t size = obstack_object_size (&defines_obstack);
-	  fwrite (obstack_finish (&defines_obstack), 1, size, fdefs);
-	  xfclose (fdefs);
-	}
-    }
+  /* Output the main file.  */
+  obstack_save (&table_obstack, tabfile);
+
+  /* Output the header file if wanted. */
+  if (defines_flag)
+    obstack_save (&defines_obstack, defsfile);
 
-  /* If we output only the table, dump the actions in ACTION_OBSTACK.
+  /* If we output only the table, dump the actions in ACTFILE.
      */
   if (no_parser_flag)
-    {
-      FILE *faction = xfopen (actfile, "w");
-      size_t size = obstack_object_size (&action_obstack);
-      fwrite (obstack_finish (&action_obstack), 1, size, faction);
-      xfclose (faction);
-    }
+    obstack_save (&action_obstack, actfile);
 
   /* If we produced a semantic parser ATTRS_OBSTACK must be dumped
      into its own file, ATTTRSFILE.  */
   if (semantic_parser)
-    {
-      FILE *fattrs = xfopen (attrsfile, "w");
-      size_t size = obstack_object_size (&attrs_obstack);
-      fwrite (obstack_finish (&attrs_obstack), 1, size, fattrs);
-      xfclose (fattrs);
-    }
-
-/* Don't call exit again, we're in atexit ().
-  exit (complain_message_count ? 1 : 0); */
+    obstack_save (&attrs_obstack, attrsfile);
 }
