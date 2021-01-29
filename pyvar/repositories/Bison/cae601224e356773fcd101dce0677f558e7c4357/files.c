@@ -253,27 +253,6 @@ tr (const char *in, char from, char to)
   return (temp);
 }
 
-/* Gets the extension index in FILENAME. Returns 0 if fails to
-   find an extension.  */
-static int
-get_extension_index (const char *filename)
-{
-  int len;
-
-  len = strlen (filename);
-
-  if (filename[len-- - 1] == '.')
-    return (0);
-
-  while ((len > 0) && (filename[len - 1] != '.'))
-    if (filename[len - 1] == '/')
-      return (0);
-    else
-      len--;
-
-  return (len - 1);
-}
-
 /* Computes extensions from the grammar file extension. */
 static void
 compute_exts_from_gf (const char *ext)
@@ -338,7 +317,7 @@ filename_split (const char *filename,
   /* If there is an exentension, check if there is a `.tab' part right
      before.  */
   if (*ext
-      && (*ext - *base) > strlen (".tab")
+      && (*ext - *base) > (int) strlen (".tab")
       && (!strncmp (*ext - strlen (".tab"), ".tab", strlen (".tab"))
 	  || !strncmp (*ext - strlen ("_tab"), "_tab", strlen ("_tab"))))
     *tab = *ext - strlen (".tab");
@@ -351,9 +330,6 @@ static void
 compute_base_names (void)
 {
   const char *base, *tab, *ext;
-  size_t base_length;
-  size_t short_base_length;
-  size_t ext_index;
 
   /* If --output=foo.c was specified (SPEC_OUTFILE == foo.c),
      BASE_NAME and SHORT_BASE_NAME are `foo'.
@@ -365,7 +341,6 @@ compute_base_names (void)
      files, remove the ".c" or ".tab.c" suffix.  */
   if (spec_outfile)
     {
-      const char *cp;
       filename_split (spec_outfile, &base, &tab, &ext);
 
       /* The full base name goes up the EXT, excluding it. */
