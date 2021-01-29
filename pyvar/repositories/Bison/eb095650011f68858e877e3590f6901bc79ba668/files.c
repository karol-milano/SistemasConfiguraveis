@@ -48,10 +48,10 @@ struct obstack post_prologue_obstack;
 char const *spec_outfile = NULL;       /* for -o. */
 char const *spec_file_prefix = NULL;   /* for -b. */
 char const *spec_name_prefix = NULL;   /* for -p. */
-char const *spec_verbose_file = NULL;  /* for --verbose. */
-char const *spec_graph_file = NULL;    /* for -g. */
-char const *spec_defines_file = NULL;  /* for --defines. */
-char const *parser_file_name;
+char *spec_verbose_file = NULL;  /* for --verbose. */
+char *spec_graph_file = NULL;    /* for -g. */
+char *spec_defines_file = NULL;  /* for --defines. */
+char *parser_file_name;
 
 uniqstr grammar_file = NULL;
 uniqstr current_file = NULL;
@@ -72,14 +72,14 @@ uniqstr current_file = NULL;
    empty string (meaning the current directory); otherwise it is
    `dir/'.  */
 
-static char const *all_but_ext;
-static char const *all_but_tab_ext;
-char const *dir_prefix;
+static char *all_but_ext;
+static char *all_but_tab_ext;
+char *dir_prefix;
 
 /* C source file extension (the parser source).  */
-static char const *src_extension = NULL;
+static char *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified).  */
-static char const *header_extension = NULL;
+static char *header_extension = NULL;
 
 /*-----------------------------------------------------------------.
 | Return a newly allocated string composed of the concatenation of |
@@ -136,31 +136,25 @@ xfclose (FILE *ptr)
 | Compute ALL_BUT_EXT, ALL_BUT_TAB_EXT and output files extensions. |
 `------------------------------------------------------------------*/
 
-/* Replace all characters FROM by TO in the string IN.
-   and returns a new allocated string.  */
+/* In the string S, replace all characters FROM by TO.  */
 static char *
-tr (const char *in, char from, char to)
+tr (char *s, char from, char to)
 {
-  char *temp;
-  char *out = xmalloc (strlen (in) + 1);
-
-  for (temp = out; *in; in++, out++)
-    if (*in == from)
-      *out = to;
-    else
-      *out = *in;
-  *out = 0;
-  return (temp);
+  for (; *s; s++)
+    if (*s == from)
+      *s = to;
 }
 
 /* Compute extensions from the grammar file extension.  */
 static void
 compute_exts_from_gf (const char *ext)
 {
-  src_extension = tr (ext, 'y', 'c');
-  src_extension = tr (src_extension, 'Y', 'C');
-  header_extension = tr (ext, 'y', 'h');
-  header_extension = tr (header_extension, 'Y', 'H');
+  src_extension = xstrdup (ext);
+  header_extension = xstrdup (ext);
+  tr (src_extension, 'y', 'c');
+  tr (src_extension, 'Y', 'C');
+  tr (header_extension, 'y', 'h');
+  tr (header_extension, 'Y', 'H');
 }
 
 /* Compute extensions from the given c source file extension.  */
@@ -171,8 +165,9 @@ compute_exts_from_src (const char *ext)
      so the extenions must be computed unconditionally from the file name
      given by this option.  */
   src_extension = xstrdup (ext);
-  header_extension = tr (ext, 'c', 'h');
-  header_extension = tr (header_extension, 'C', 'H');
+  header_extension = xstrdup (ext);
+  tr (header_extension, 'c', 'h');
+  tr (header_extension, 'C', 'H');
 }
 
 
@@ -270,14 +265,14 @@ compute_file_name_parts (void)
       else if (yacc_flag)
 	{
 	  /* If --yacc, then the output is `y.tab.c'.  */
-	  dir_prefix = "";
-	  all_but_tab_ext = "y";
+	  dir_prefix = xstrdup ("");
+	  all_but_tab_ext = xstrdup ("y");
 	}
       else
 	{
 	  /* Otherwise, ALL_BUT_TAB_EXT is computed from the input
 	     grammar: `foo/bar.yy' => `bar'.  */
-	  dir_prefix = "";
+	  dir_prefix = xstrdup ("");
 	  all_but_tab_ext =
 	    xstrndup (base, (strlen (base) - (ext ? strlen (ext) : 0)));
 	}
@@ -306,12 +301,14 @@ compute_output_file_names (void)
 
   /* If not yet done. */
   if (!src_extension)
-    src_extension = ".c";
+    src_extension = xstrdup (".c");
   if (!header_extension)
-    header_extension = ".h";
+    header_extension = xstrdup (".h");
 
   name[names++] = parser_file_name =
-    spec_outfile ? spec_outfile : concat2 (all_but_ext, src_extension);
+    (spec_outfile
+     ? xstrdup (spec_outfile)
+     : concat2 (all_but_ext, src_extension));
 
   if (defines_flag)
     {
@@ -337,4 +334,19 @@ compute_output_file_names (void)
     for (i = 0; i < j; i++)
       if (strcmp (name[i], name[j]) == 0)
 	warn (_("conflicting outputs to file %s"), quote (name[i]));
+
+  free (all_but_ext);
+  free (all_but_tab_ext);
+  free (src_extension);
+  free (header_extension);
+}
+
+void
+output_file_names_free (void)
+{
+  free (spec_verbose_file);
+  free (spec_graph_file);
+  free (spec_defines_file);
+  free (parser_file_name);
+  free (dir_prefix);
 }
