@@ -45,6 +45,11 @@ char *attrsfile;
 static char *base_name;
 static char *short_base_name;
 
+/* C source file extension (the parser source). */
+static char *src_extension;	
+/* Header file extension (if option ``-d'' is specified). */
+static char *header_extension;
+
 
 /*--------------------------.
 | Is SUFFIX ending STRING?  |
@@ -156,9 +161,68 @@ skeleton_find (const char *envvar, const char *skeleton)
 }
 
 
-/*----------------------------------------.
-| Compute BASE_NAME and SHORT_BASE_NAME.  |
-`----------------------------------------*/
+/*----------------------------------------------------------------.
+| Compute BASE_NAME, SHORT_BASE_NAME and output files extensions. |
+`----------------------------------------------------------------*/
+
+/* Replace all characters FROM by TO in the string IN. 
+   and returns a new allocated string. */  
+static char *
+tr(const char *in, char from, char to)
+{
+  char *temp;
+  char *out;
+  
+  out = XMALLOC (char, strlen (in) + 1);
+
+  for (temp = out; *in; in++, out++)
+    if (*in == from)
+      *out = to;
+    else
+      *out = *in;
+  *out = 0;
+  return (temp);
+}
+
+/*  Gets the extension index in FILENAME. Returns 0 if fails to 
+    find an extension. */
+static int 
+get_extension_index(const char *filename)
+{
+  int  len;
+
+  len = strlen (filename);
+  
+  if (filename[len-- - 1] == '.')
+    return (0);
+
+  while ((len > 0) && (filename[len - 1] != '.'))
+    if (filename[len - 1] == '/')
+      return (0);
+    else
+      len--;
+
+  return (len - 1);
+}
+
+/* Computes extensions from the grammar file extension. */
+static void
+compute_exts_from_gf(const char *ext)
+{
+  src_extension = tr(ext, 'y', 'c');
+  src_extension = tr(src_extension, 'Y', 'C');
+  header_extension = tr(ext, 'y', 'h');
+  header_extension = tr(header_extension, 'Y', 'H');
+}
+
+/* Computes extensions from the given c source file extension. */
+static void
+compute_exts_from_src(const char *ext)
+{
+  src_extension = xstrdup(ext);
+  header_extension = tr(ext, 'c', 'h');
+  header_extension = tr(header_extension, 'C', 'H');
+}
 
 /* FIXME: Should use xstrndup. */
 
@@ -167,6 +231,11 @@ compute_base_names (void)
 {
   size_t base_length;
   size_t short_base_length;
+  size_t ext_index;
+  
+  /* Set default extensions */
+  src_extension = ".c";
+  header_extension = ".h";
 
   /* If --output=foo.c was specified (SPEC_OUTFILE == foo.c),
      BASE_NAME and SHORT_BASE_NAME are `foo'.
@@ -183,8 +252,18 @@ compute_base_names (void)
 #endif /* MSDOS */
       /* BASE_LENGTH includes ".tab" but not ".c".  */
       base_length = strlen (spec_outfile);
-      if (strsuffix (spec_outfile, ".c"))
-	base_length -= 2;
+      
+      ext_index = get_extension_index (spec_outfile);
+      /* if the initial segment of extension contains 'c' or a 'C', I assume 
+	 that it is a C or C++ source file */
+      if (ext_index)
+	ext_index = (strspn(spec_outfile + ext_index + 1, "cC")) ? ext_index : 0;
+      if (ext_index)
+	{
+	  base_length -= strlen (spec_outfile + ext_index);
+	  compute_exts_from_src(spec_outfile + ext_index);
+	}
+      
       base_name = strndup (spec_outfile, base_length);
       /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
       short_base_length = base_length;
@@ -205,7 +284,6 @@ compute_base_names (void)
       strlwr (spec_file_prefix);
 #endif /* MSDOS */
       short_base_name = xstrdup (spec_file_prefix);
-
       base_name = XMALLOC (char,
 			   strlen (short_base_name) + strlen (EXT_TAB) + 1);
       stpcpy (stpcpy (base_name, short_base_name), EXT_TAB);
@@ -224,8 +302,18 @@ compute_base_names (void)
     /* BASE_LENGTH gets length of BASE_NAME, sans ".y" suffix if any.  */
 
     base_length = strlen (name_base);
-    if (strsuffix (name_base, ".y"))
-      base_length -= 2;
+    
+    ext_index = get_extension_index (name_base);
+    /* if the initial segment of extension contains a 'y' or a 'Y', I assume 
+       that it is a yacc or bison grammar file */
+    if (ext_index)
+      ext_index = (strspn(name_base + ext_index + 1, "yY")) ? ext_index : 0;
+    if (ext_index)
+      {
+	base_length -= strlen (name_base + ext_index);
+	compute_exts_from_gf(name_base + ext_index);
+      }
+
     short_base_length = base_length;
     short_base_name = strndup (name_base, short_base_length);
 
@@ -268,17 +356,21 @@ output_files (void)
   xfclose (finput);
 
   compute_base_names ();
+
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
+#ifndef MSDOS
+  stringappend (attrsfile, header_extension);
+#endif /* MSDOS */  
 
   /* Output the main file.  */
   if (spec_outfile)
     obstack_save (&table_obstack, spec_outfile);
   else
-    obstack_save (&table_obstack,  stringappend (base_name, ".c"));
+    obstack_save (&table_obstack,  stringappend (base_name, src_extension));
 
   /* Output the header file if wanted. */
   if (defines_flag)
-    obstack_save (&defines_obstack, stringappend (base_name, ".h"));
+    obstack_save (&defines_obstack, stringappend (base_name, header_extension));
 
   /* If we output only the table, dump the actions in ACTFILE. */
   if (no_parser_flag)
@@ -288,9 +380,14 @@ output_files (void)
      into its own file, ATTTRSFILE.  */
   if (semantic_parser)
     {
+      char *temp_name;
+
       obstack_save (&attrs_obstack, attrsfile);
-      obstack_save (&guard_obstack,
-		    stringappend (short_base_name, EXT_GUARD_C));
+      temp_name = stringappend (short_base_name, EXT_GUARD_C);
+#ifndef MSDOS
+      temp_name = stringappend (temp_name, src_extension);
+#endif /* MSDOS */
+      obstack_save (&guard_obstack, temp_name);
     }
 
   if (verbose_flag)
