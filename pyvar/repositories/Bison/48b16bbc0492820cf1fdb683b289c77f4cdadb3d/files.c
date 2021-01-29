@@ -165,8 +165,8 @@ compute_exts_from_src (const char *ext)
 }
 
 
-/* Decompose FILENAME in four parts: *BASE, *TAB, and *EXT, the fourth
-   part, (the directory) is ranging from FILENAME to the char before
+/* Decompose FILE_NAME in four parts: *BASE, *TAB, and *EXT, the fourth
+   part, (the directory) is ranging from FILE_NAME to the char before
    *BASE, so we don't need an additional parameter.
 
    *EXT points to the last period in the basename, or NULL if none.
@@ -175,7 +175,7 @@ compute_exts_from_src (const char *ext)
    `.tab' or `_tab' if present right before *EXT, or is NULL. *TAB
    cannot be equal to *BASE.
 
-   None are allocated, they are simply pointers to parts of FILENAME.
+   None are allocated, they are simply pointers to parts of FILE_NAME.
    Examples:
 
    '/tmp/foo.tab.c' -> *BASE = 'foo.tab.c', *TAB = '.tab.c', *EXT =
@@ -194,10 +194,10 @@ compute_exts_from_src (const char *ext)
    'foo' -> *BASE = 'foo', *TAB = NULL, *EXT = NULL.  */
 
 static void
-filename_split (const char *filename,
-		const char **base, const char **tab, const char **ext)
+file_name_split (const char *file_name,
+		 const char **base, const char **tab, const char **ext)
 {
-  *base = base_name (filename);
+  *base = base_name (file_name);
 
   /* Look for the extension, i.e., look for the last dot. */
   *ext = strrchr (*base, '.');
@@ -232,7 +232,7 @@ compute_base_names (void)
      files, remove the ".c" or ".tab.c" suffix.  */
   if (spec_outfile)
     {
-      filename_split (spec_outfile, &base, &tab, &ext);
+      file_name_split (spec_outfile, &base, &tab, &ext);
 
       /* The full base name goes up the EXT, excluding it. */
       full_base_name =
@@ -270,7 +270,7 @@ compute_base_names (void)
 	{
 	  /* Otherwise, the short base name is computed from the input
 	     grammar: `foo/bar.yy' => `bar'.  */
-	  filename_split (grammar_file, &base, &tab, &ext);
+	  file_name_split (grammar_file, &base, &tab, &ext);
 	  short_base_name =
 	    xstrndup (base,
 		      (strlen (base) - (ext ? strlen (ext) : 0)));
@@ -281,7 +281,7 @@ compute_base_names (void)
       stpcpy (stpcpy (full_base_name, short_base_name), TAB_EXT);
 
       /* Compute the extensions from the grammar file name.  */
-      filename_split (grammar_file, &base, &tab, &ext);
+      file_name_split (grammar_file, &base, &tab, &ext);
       if (ext && !yacc_flag)
 	compute_exts_from_gf (ext);
     }
