@@ -37,8 +37,8 @@ struct obstack output_obstack;
 struct obstack graph_obstack;
 
 char *spec_outfile = NULL;	/* for -o. */
-char *spec_file_prefix = NULL; /* for -b. */
-char *spec_name_prefix = NULL; /* for -p. */
+char *spec_file_prefix = NULL;	/* for -b. */
+char *spec_name_prefix = NULL;	/* for -p. */
 
 char *infile = NULL;
 char *attrsfile = NULL;
@@ -46,12 +46,12 @@ char *attrsfile = NULL;
 static char *base_name = NULL;
 static char *short_base_name = NULL;
 
-/* C source file extension (the parser source). */
+/* C source file extension (the parser source).  */
 const char *src_extension = NULL;
-/* Header file extension (if option ``-d'' is specified). */
+/* Header file extension (if option ``-d'' is specified).  */
 const char *header_extension = NULL;
-
 
+
 /*--------------------------.
 | Is SUFFIX ending STRING?  |
 `--------------------------*/
@@ -160,16 +160,16 @@ skeleton_find (const char *envvar, const char *skeleton_name)
 
   return res;
 }
-
 
+
 /*----------------------------------------------------------------.
 | Compute BASE_NAME, SHORT_BASE_NAME and output files extensions. |
 `----------------------------------------------------------------*/
 
 /* Replace all characters FROM by TO in the string IN.
-   and returns a new allocated string. */
+   and returns a new allocated string.  */
 static char *
-tr(const char *in, char from, char to)
+tr (const char *in, char from, char to)
 {
   char *temp;
   char *out;
@@ -185,12 +185,12 @@ tr(const char *in, char from, char to)
   return (temp);
 }
 
-/*  Gets the extension index in FILENAME. Returns 0 if fails to
-    find an extension. */
+/* Gets the extension index in FILENAME. Returns 0 if fails to
+   find an extension.  */
 static int
-get_extension_index(const char *filename)
+get_extension_index (const char *filename)
 {
-  int  len;
+  int len;
 
   len = strlen (filename);
 
@@ -208,34 +208,34 @@ get_extension_index(const char *filename)
 
 /* Computes extensions from the grammar file extension. */
 static void
-compute_exts_from_gf(const char *ext)
+compute_exts_from_gf (const char *ext)
 {
-  /* Checks if SRC_EXTENSION is NULL. In the other case, %source_extension 
+  /* Checks if SRC_EXTENSION is NULL. In the other case, %source_extension
      was specified in the grammar file.  */
   if (src_extension == NULL)
     {
-      src_extension = tr(ext, 'y', 'c');
-      src_extension = tr(src_extension, 'Y', 'C');
+      src_extension = tr (ext, 'y', 'c');
+      src_extension = tr (src_extension, 'Y', 'C');
     }
-  /* Checks if HEADER_EXTENSION is NULL. In the other case, 
+  /* Checks if HEADER_EXTENSION is NULL. In the other case,
      %header_extension was specified in the grammar file.  */
   if (header_extension == NULL)
     {
-      header_extension = tr(ext, 'y', 'h');
-      header_extension = tr(header_extension, 'Y', 'H');
+      header_extension = tr (ext, 'y', 'h');
+      header_extension = tr (header_extension, 'Y', 'H');
     }
 }
 
 /* Computes extensions from the given c source file extension. */
 static void
-compute_exts_from_src(const char *ext)
+compute_exts_from_src (const char *ext)
 {
   /* We use this function when the user specifies `-o' or `--output',
      so the extenions must be computed unconditionally from the file name
      given by this option.  */
-  src_extension = xstrdup(ext);
-  header_extension = tr(ext, 'c', 'h');
-  header_extension = tr(header_extension, 'C', 'H');
+  src_extension = xstrdup (ext);
+  header_extension = tr (ext, 'c', 'h');
+  header_extension = tr (header_extension, 'C', 'H');
 }
 
 /* FIXME: Should use xstrndup. */
@@ -264,10 +264,11 @@ compute_base_names (void)
       base_length = strlen (spec_outfile);
 
       ext_index = get_extension_index (spec_outfile);
-      /* if the initial segment of extension contains 'c' or a 'C', I assume
-	 that it is a C or C++ source file */
+      /* If the initial segment of extension contains 'c' or a 'C', I assume
+         that it is a C or C++ source file.  */
       if (ext_index)
-	ext_index = (strspn (spec_outfile + ext_index + 1, "cC")) ? ext_index : 0;
+	ext_index =
+	  (strspn (spec_outfile + ext_index + 1, "cC")) ? ext_index : 0;
       if (ext_index)
 	{
 	  base_length -= strlen (spec_outfile + ext_index);
@@ -300,13 +301,13 @@ compute_base_names (void)
 
       /* Computes the extensions from the garmmar file name.  */
       ext_index = get_extension_index (infile);
-      /* if the initial segment of extension contains a 'y' or a 'Y', I assume
-	 that it is a yacc or bison grammar file */
+      /* If the initial segment of extension contains a 'y' or a 'Y', I assume
+         that it is a yacc or bison grammar file.  */
       if (ext_index)
 	ext_index = (strspn (infile + ext_index + 1, "yY")) ? ext_index : 0;
       if (ext_index)
 	compute_exts_from_gf (infile + ext_index);
-      
+
       return;
     }
 
@@ -323,8 +324,8 @@ compute_base_names (void)
     base_length = strlen (name_base);
 
     ext_index = get_extension_index (name_base);
-    /* if the initial segment of extension contains a 'y' or a 'Y', I assume
-       that it is a yacc or bison grammar file */
+    /* If the initial segment of extension contains a 'y' or a 'Y', I assume
+       that it is a yacc or bison grammar file.  */
     if (ext_index)
       ext_index = (strspn (name_base + ext_index + 1, "yY")) ? ext_index : 0;
     if (ext_index)
@@ -392,11 +393,12 @@ output_files (void)
   if (spec_outfile)
     obstack_save (&table_obstack, spec_outfile);
   else
-    obstack_save (&table_obstack,  stringappend (base_name, src_extension));
+    obstack_save (&table_obstack, stringappend (base_name, src_extension));
 
   /* Output the header file if wanted. */
   if (defines_flag)
-    obstack_save (&defines_obstack, stringappend (base_name, header_extension));
+    obstack_save (&defines_obstack,
+		  stringappend (base_name, header_extension));
 
   /* If we output only the table, dump the actions in ACTFILE. */
   if (no_parser_flag)
@@ -419,7 +421,8 @@ output_files (void)
   if (verbose_flag)
     /* We used to use just .out if spec_name_prefix (-p) was used, but
        that conflicts with Posix.  */
-    obstack_save (&output_obstack, stringappend (short_base_name, EXT_OUTPUT));
+    obstack_save (&output_obstack,
+		  stringappend (short_base_name, EXT_OUTPUT));
 
   if (graph_flag)
     obstack_save (&graph_obstack, stringappend (short_base_name, ".vcg"));
