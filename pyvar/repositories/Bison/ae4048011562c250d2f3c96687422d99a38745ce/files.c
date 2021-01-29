@@ -26,6 +26,9 @@
 #include "error.h"
 #include "complain.h"
 
+/* From basename.c.  Almost a lie, as it returns a char *. */
+const char *base_name PARAMS ((char const *name));
+
 FILE *finput = NULL;
 
 struct obstack action_obstack;
@@ -50,7 +53,7 @@ char *parser_file_name = NULL;
 char *infile = NULL;
 char *attrsfile = NULL;
 
-static char *base_name = NULL;
+static char *full_base_name = NULL;
 char *short_base_name = NULL;
 
 /* C source file extension (the parser source).  */
@@ -120,10 +123,10 @@ compute_header_macro (void)
     {
       macro_name = XMALLOC (char,
 			    strlen (prefix) +
-			    strlen (base_name) +
+			    strlen (full_base_name) +
 			    strlen (header_extension) + 1);
       cp = stpcpy (macro_name, prefix);
-      cp = stpcpy (cp, base_name);
+      cp = stpcpy (cp, full_base_name);
       cp = stpcpy (cp, header_extension);
     }
 
@@ -293,11 +296,61 @@ compute_exts_from_src (const char *ext)
   header_extension = tr (header_extension, 'C', 'H');
 }
 
+
+/* Decompose FILENAME in four parts: *BASE, *TAB, and *EXT, the fourth
+   part, (the directory) is ranging from FILENAME to the char before
+   *BASE, so we don't need an additional parameter.
+
+   *EXT points to the last period in the basename, or NULL if none.
+
+   If there is no *EXT, *TAB is NULL.  Otherwise, *TAB points to
+   `.tab' or `_tab' if present right before *EXT, or is NULL. *TAB
+   cannot be equal to *BASE.
+
+   None are allocated, they are simply pointers to parts of FILENAME.
+   Examples:
+
+   '/tmp/foo.tab.c' -> *BASE = 'foo.tab.c', *TAB = '.tab.c', *EXT =
+   '.c'
+
+   'foo.c' -> *BASE = 'foo.c', *TAB = NULL, *EXT = '.c'
+
+   'tab.c' -> *BASE = 'tab.c', *TAB = NULL, *EXT = '.c'
+
+   '.tab.c' -> *BASE = '.tab.c', *TAB = NULL, *EXT = '.c'
+
+   'foo.tab' -> *BASE = 'foo.tab', *TAB = NULL, *EXT = '.tab'
+
+   'foo_tab' -> *BASE = 'foo_tab', *TAB = NULL, *EXT = NULL
+
+   'foo' -> *BASE = 'foo', *TAB = NULL, *EXT = NULL.  */
+
+static void
+filename_split (const char *filename,
+		const char **base, const char **tab, const char **ext)
+{
+  *base = base_name (filename);
+
+  /* Look for the extension, i.e., look for the last dot. */
+  *ext = strrchr (*base, '.');
+  *tab = NULL;
+
+  /* If there is an exentension, check if there is a `.tab' part right
+     before.  */
+  if (*ext
+      && (*ext - *base) > strlen (".tab")
+      && (!strncmp (*ext - strlen (".tab"), ".tab", strlen (".tab"))
+	  || !strncmp (*ext - strlen ("_tab"), "_tab", strlen ("_tab"))))
+    *tab = *ext - strlen (".tab");
+}
+
+
 /* FIXME: Should use xstrndup. */
 
 static void
 compute_base_names (void)
 {
+  const char *base, *tab, *ext;
   size_t base_length;
   size_t short_base_length;
   size_t ext_index;
@@ -312,104 +365,65 @@ compute_base_names (void)
      files, remove the ".c" or ".tab.c" suffix.  */
   if (spec_outfile)
     {
-#ifdef MSDOS
-      strlwr (spec_outfile);
-#endif /* MSDOS */
-      /* BASE_LENGTH includes ".tab" but not ".c".  */
-      base_length = strlen (spec_outfile);
-
-      ext_index = get_extension_index (spec_outfile);
-      /* If the initial segment of extension contains 'c' or a 'C', I assume
-         that it is a C or C++ source file.  */
-      if (ext_index)
-	ext_index =
-	  (strspn (spec_outfile + ext_index + 1, "cC")) ? ext_index : 0;
-      if (ext_index)
-	{
-	  base_length -= strlen (spec_outfile + ext_index);
-	  compute_exts_from_src (spec_outfile + ext_index);
-	}
-
-      base_name = strndup (spec_outfile, base_length);
-      /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
-      short_base_length = base_length;
-      if (strsuffix (base_name, ".tab") || strsuffix (base_name, "_tab"))
-	short_base_length -= 4;
-      short_base_name = strndup (spec_outfile, short_base_length);
-
-      /* FIXME: This is a quick and dirty way for me to find out if we
-	 should .tab or not, using the computations above.  */
-      if (strcmp (base_name, short_base_name))
-	tab_extension = 1;
-
-      return;
+      const char *cp;
+      filename_split (spec_outfile, &base, &tab, &ext);
+
+      /* The full base name goes up the EXT, excluding it. */
+      full_base_name =
+	xstrndup (spec_outfile,
+		  (strlen (spec_outfile) - (ext ? strlen (ext) : 0)));
+      /* The short base name goes up to TAB, excluding it.  */
+      short_base_name =
+	xstrndup (spec_outfile,
+		  (strlen (spec_outfile)
+		   - (tab ? strlen (tab) : (ext ? strlen (ext) : 0))));
+
+      /* Do we have a tab part? */
+      tab_extension = !!tab;
+
+      if (ext)
+	compute_exts_from_src (ext);
     }
 
-  /* If --file-prefix=foo was specified, BASE_NAME and SHORT_BASE_NAME
-     are `foo'.
+  /* If --file-prefix=foo was specified, FULL_BASE_NAME = `foo.tab'
+     and SHORT_BASE_NAME = `foo'.
 
      Construct names from it.  */
-  if (spec_file_prefix)
+  else
     {
-#ifdef MSDOS
-      strlwr (spec_file_prefix);
-#endif /* MSDOS */
-      short_base_name = xstrdup (spec_file_prefix);
-      base_name = XMALLOC (char,
-			   strlen (short_base_name) + strlen (EXT_TAB) + 1);
-      stpcpy (stpcpy (base_name, short_base_name), EXT_TAB);
-
-      /* Computes the extensions from the garmmar file name.  */
-      ext_index = get_extension_index (infile);
-      /* If the initial segment of extension contains a 'y' or a 'Y', I assume
-         that it is a yacc or bison grammar file.  */
-      if (ext_index)
-	ext_index = (strspn (infile + ext_index + 1, "yY")) ? ext_index : 0;
-      if (ext_index)
-	compute_exts_from_gf (infile + ext_index);
-
-      /* It seems that when only a prefix is given, '.tab' should always be
-	 used.  */
-      tab_extension = 1;
+      if (spec_file_prefix)
+	{
+	  /* If --file-prefix=foo was specified, SHORT_BASE_NAME =
+	     `foo'.  */
+	  short_base_name = xstrdup (spec_file_prefix);
+	}
+      else if (yacc_flag)
+	{
+	  /* If --yacc, then the output is `y.tab.c'. */
+	  short_base_name = xstrdup ("y");
+	}
+      else
+	{
+	  /* Otherwise, the short base name is computed from the input
+	     grammar: `foo.yy' => `foo'.  */
+	  filename_split (infile, &base, &tab, &ext);
+	  short_base_name =
+	    xstrndup (infile,
+		      (strlen (infile) - (ext ? strlen (ext) : 0)));
+	}
 
-      return;
+      /* In these cases, always append `.tab'. */
+      tab_extension = 1;
+      full_base_name = XMALLOC (char,
+				strlen (short_base_name)
+				+ strlen (EXT_TAB) + 1);
+      stpcpy (stpcpy (full_base_name, short_base_name), EXT_TAB);
+
+      /* Computes the extensions from the grammar file name.  */
+      filename_split (infile, &base, &tab, &ext);
+      if (ext)
+	compute_exts_from_gf (ext);
     }
-
-  /* If neither -o nor --file-prefix were specified, and the input
-     file is foo.y, BASE_NAME is `foo.tab', and SHORT_BASE_NAME is
-     `foo'.
-
-     If --yacc is used, do as if the input file was `y.y'.  */
-  {
-    const char *name_base = yacc_flag ? "y.y" : infile;
-
-    /* BASE_LENGTH gets length of BASE_NAME, sans ".y" suffix if any.  */
-
-    base_length = strlen (name_base);
-
-    ext_index = get_extension_index (name_base);
-    /* If the initial segment of extension contains a 'y' or a 'Y', I assume
-       that it is a yacc or bison grammar file.  */
-    if (ext_index)
-      ext_index = (strspn (name_base + ext_index + 1, "yY")) ? ext_index : 0;
-    if (ext_index)
-      {
-	base_length -= strlen (name_base + ext_index);
-	compute_exts_from_gf (name_base + ext_index);
-      }
-
-    short_base_length = base_length;
-    short_base_name = strndup (name_base, short_base_length);
-
-    base_name = XMALLOC (char,
-			 strlen (short_base_name) + strlen (EXT_TAB) + 1);
-    stpcpy (stpcpy (base_name, short_base_name), EXT_TAB);
-
-    /* By default, Bison should insert '.tab' were needed.  */
-    tab_extension = 1;
-
-    return;
-  }
 }
 
 /*-------------------------------------------------------.
@@ -422,7 +436,7 @@ compute_output_file_names (void)
   compute_base_names ();
 
   parser_file_name =
-    spec_outfile ? spec_outfile : stringappend (base_name, src_extension);
+    spec_outfile ? spec_outfile : stringappend (full_base_name, src_extension);
 
   /* If not yet done. */
   if (!src_extension)
@@ -432,7 +446,7 @@ compute_output_file_names (void)
 
   /* It the defines filename if not given, we create it.  */
   if (!spec_defines_file)
-    spec_defines_file = stringappend (base_name, header_extension);
+    spec_defines_file = stringappend (full_base_name, header_extension);
 
   /* It the graph filename if not given, we create it.  */
   if (!spec_graph_file)
@@ -441,7 +455,4 @@ compute_output_file_names (void)
   spec_verbose_file = stringappend (short_base_name, EXT_OUTPUT);
 
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
-#ifndef MSDOS
-  attrsfile = stringappend (attrsfile, header_extension);
-#endif /* MSDOS */
 }
