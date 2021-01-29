@@ -210,12 +210,16 @@ get_extension_index(const char *filename)
 static void
 compute_exts_from_gf(const char *ext)
 {
-  if (!src_extension)
+  /* Checks if SRC_EXTENSION is NULL. In the other case, %source_extension 
+     was specified in the grammar file.  */
+  if (src_extension == NULL)
     {
       src_extension = tr(ext, 'y', 'c');
       src_extension = tr(src_extension, 'Y', 'C');
     }
-  if (!header_extension)
+  /* Checks if HEADER_EXTENSION is NULL. In the other case, 
+     %header_extension was specified in the grammar file.  */
+  if (header_extension == NULL)
     {
       header_extension = tr(ext, 'y', 'h');
       header_extension = tr(header_extension, 'Y', 'H');
@@ -226,13 +230,12 @@ compute_exts_from_gf(const char *ext)
 static void
 compute_exts_from_src(const char *ext)
 {
-  if (!src_extension)
-    src_extension = xstrdup(ext);
-  if (!header_extension)
-    {
-      header_extension = tr(ext, 'c', 'h');
-      header_extension = tr(header_extension, 'C', 'H');
-    }
+  /* We use this function when the user specifies `-o' or `--output',
+     so the extenions must be computed unconditionally from the file name
+     given by this option.  */
+  src_extension = xstrdup(ext);
+  header_extension = tr(ext, 'c', 'h');
+  header_extension = tr(header_extension, 'C', 'H');
 }
 
 /* FIXME: Should use xstrndup. */
