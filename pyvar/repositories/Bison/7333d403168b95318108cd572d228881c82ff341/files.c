@@ -46,9 +46,9 @@ static char *base_name = NULL;
 static char *short_base_name = NULL;
 
 /* C source file extension (the parser source). */
-static const char *src_extension = NULL;
+const char *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified). */
-static const char *header_extension = NULL;
+const char *header_extension = NULL;
 
 
 /*--------------------------.
@@ -209,19 +209,29 @@ get_extension_index(const char *filename)
 static void
 compute_exts_from_gf(const char *ext)
 {
-  src_extension = tr(ext, 'y', 'c');
-  src_extension = tr(src_extension, 'Y', 'C');
-  header_extension = tr(ext, 'y', 'h');
-  header_extension = tr(header_extension, 'Y', 'H');
+  if (!src_extension)
+    {
+      src_extension = tr(ext, 'y', 'c');
+      src_extension = tr(src_extension, 'Y', 'C');
+    } 
+  if (!header_extension)
+    {
+      header_extension = tr(ext, 'y', 'h');
+      header_extension = tr(header_extension, 'Y', 'H');
+    }
 }
 
 /* Computes extensions from the given c source file extension. */
 static void
 compute_exts_from_src(const char *ext)
 {
-  src_extension = xstrdup(ext);
-  header_extension = tr(ext, 'c', 'h');
-  header_extension = tr(header_extension, 'C', 'H');
+  if (!src_extension)
+    src_extension = xstrdup(ext);
+  if (!header_extension)
+    {     
+      header_extension = tr(ext, 'c', 'h');
+      header_extension = tr(header_extension, 'C', 'H');
+    }
 }
 
 /* FIXME: Should use xstrndup. */
@@ -233,10 +243,6 @@ compute_base_names (void)
   size_t short_base_length;
   size_t ext_index;
 
-  /* Set default extensions */
-  src_extension = ".c";
-  header_extension = ".h";
-
   /* If --output=foo.c was specified (SPEC_OUTFILE == foo.c),
      BASE_NAME and SHORT_BASE_NAME are `foo'.
 
@@ -357,6 +363,12 @@ output_files (void)
 
   compute_base_names ();
 
+  /* Set default extensions */
+  if (!src_extension)
+    src_extension = ".c";
+  if (!header_extension)
+    header_extension = ".h";
+
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
 #ifndef MSDOS
   stringappend (attrsfile, header_extension);
