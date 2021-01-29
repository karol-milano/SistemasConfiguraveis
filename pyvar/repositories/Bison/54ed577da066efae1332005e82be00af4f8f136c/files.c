@@ -45,7 +45,7 @@ char const *spec_outfile = NULL;       /* for -o. */
 char const *spec_file_prefix = NULL;   /* for -b. */
 location spec_file_prefix_loc = EMPTY_LOCATION_INIT;
 char const *spec_name_prefix = NULL;   /* for -p. */
-location spec_name_prefix_loc = EMPTY_LOCATION_INIT;;
+location spec_name_prefix_loc = EMPTY_LOCATION_INIT;
 char *spec_verbose_file = NULL;  /* for --verbose. */
 char *spec_graph_file = NULL;    /* for -g. */
 char *spec_xml_file = NULL;      /* for -x. */
@@ -117,14 +117,12 @@ concat2 (char const *str1, char const *str2)
 FILE *
 xfopen (const char *name, const char *mode)
 {
-  FILE *ptr;
-
-  ptr = fopen_safer (name, mode);
-  if (!ptr)
+  FILE *res = fopen_safer (name, mode);
+  if (!res)
     error (EXIT_FAILURE, get_errno (),
            _("%s: cannot open"), quotearg_colon (name));
 
-  return ptr;
+  return res;
 }
 
 /*-------------------------------------------------------------.
@@ -245,19 +243,18 @@ file_name_split (const char *file_name,
     }
 }
 
+/* Compute ALL_BUT_EXT and ALL_BUT_TAB_EXT from SPEC_OUTFILE or
+   GRAMMAR_FILE.
+
+   The precise -o name will be used for FTABLE.  For other output
+   files, remove the ".c" or ".tab.c" suffix.  */
 
 static void
 compute_file_name_parts (void)
 {
-  const char *base, *tab, *ext;
-
-  /* Compute ALL_BUT_EXT and ALL_BUT_TAB_EXT from SPEC_OUTFILE
-     or GRAMMAR_FILE.
-
-     The precise -o name will be used for FTABLE.  For other output
-     files, remove the ".c" or ".tab.c" suffix.  */
   if (spec_outfile)
     {
+      const char *base, *tab, *ext;
       file_name_split (spec_outfile, &base, &tab, &ext);
       dir_prefix = xstrndup (spec_outfile, base - spec_outfile);
 
@@ -277,6 +274,7 @@ compute_file_name_parts (void)
     }
   else
     {
+      const char *base, *tab, *ext;
       file_name_split (grammar_file, &base, &tab, &ext);
 
       if (spec_file_prefix)
@@ -376,16 +374,13 @@ output_file_name_check (char **file_name, bool source)
       conflict = true;
     }
   else
-    {
-      int i;
-      for (i = 0; i < generated_files_size; i++)
-        if (STREQ (generated_files[i].name, *file_name))
-          {
-            complain (NULL, Wother, _("conflicting outputs to file %s"),
-                      quote (generated_files[i].name));
-            conflict = true;
-          }
-    }
+    for (int i = 0; i < generated_files_size; i++)
+      if (STREQ (generated_files[i].name, *file_name))
+        {
+          complain (NULL, Wother, _("conflicting outputs to file %s"),
+                    quote (generated_files[i].name));
+          conflict = true;
+        }
   if (conflict)
     {
       free (*file_name);
@@ -403,8 +398,7 @@ output_file_name_check (char **file_name, bool source)
 void
 unlink_generated_sources (void)
 {
-  int i;
-  for (i = 0; i < generated_files_size; i++)
+  for (int i = 0; i < generated_files_size; i++)
     if (generated_files[i].is_source)
       /* Ignore errors.  The file might not even exist.  */
       unlink (generated_files[i].name);
@@ -420,10 +414,7 @@ output_file_names_free (void)
   free (spec_defines_file);
   free (parser_file_name);
   free (dir_prefix);
-  {
-    int i;
-    for (i = 0; i < generated_files_size; i++)
-      free (generated_files[i].name);
-  }
+  for (int i = 0; i < generated_files_size; i++)
+    free (generated_files[i].name);
   free (generated_files);
 }
