@@ -29,16 +29,12 @@
 #include <xstrndup.h>
 
 #include "complain.h"
+#include "dirname.h"
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
 #include "stdio-safer.h"
 
-/* From basename.c.  Almost a lie, as it returns a char *. */
-const char *base_name (char const *name);
-
-FILE *finput = NULL;
-
 struct obstack pre_prologue_obstack;
 struct obstack post_prologue_obstack;
 
@@ -49,21 +45,36 @@ struct obstack post_prologue_obstack;
    NULL), then the %directive is ignored.  As a result, %name-prefix,
    for instance, will not be honored.  */
 
-char *spec_outfile = NULL;	/* for -o. */
-char *spec_file_prefix = NULL;	/* for -b. */
-const char *spec_name_prefix = NULL;	/* for -p. */
-char *spec_verbose_file = NULL;   /* for --verbose. */
-char *spec_graph_file = NULL;   /* for -g. */
-char *spec_defines_file = NULL; /* for --defines. */
-char *parser_file_name = NULL;
+char const *spec_outfile = NULL;       /* for -o. */
+char const *spec_file_prefix = NULL;   /* for -b. */
+char const *spec_name_prefix = NULL;   /* for -p. */
+char const *spec_verbose_file = NULL;  /* for --verbose. */
+char const *spec_graph_file = NULL;    /* for -g. */
+char const *spec_defines_file = NULL;  /* for --defines. */
+char const *parser_file_name;
 
 uniqstr grammar_file = NULL;
 uniqstr current_file = NULL;
 
-static char *full_base_name = NULL;
+/* If --output=dir/foo.c was specified,
+   DIR_PREFIX is `dir/' and ALL_BUT_EXT and ALL_BUT_TAB_EXT are `dir/foo'.
+
+   If --output=dir/foo.tab.c was specified, DIR_PREFIX is `dir/',
+   ALL_BUT_EXT is `dir/foo.tab', and ALL_BUT_TAB_EXT is `dir/foo'.
+
+   If --output was not specified but --file-prefix=dir/foo was specified,
+   ALL_BUT_EXT = `foo.tab' and ALL_BUT_TAB_EXT = `foo'.
+
+   If neither --output nor --file was specified but the input grammar
+   is name dir/foo.y, ALL_BUT_EXT and ALL_BUT_TAB_EXT are `foo'.
+
+   If neither --output nor --file was specified, DIR_PREFIX is the
+   empty string (meaning the current directory); otherwise it is
+   `dir/'.  */
 
-/* Prefix used to generate output file names.  */
-char *short_base_name = NULL;
+static char const *all_but_ext;
+static char const *all_but_tab_ext;
+char const *dir_prefix;
 
 /* C source file extension (the parser source).  */
 static char const *src_extension = NULL;
@@ -121,9 +132,9 @@ xfclose (FILE *ptr)
 }
 
 
-/*---------------------------------------------------------------------.
-| Compute FULL_BASE_NAME, SHORT_BASE_NAME and output files extensions. |
-`---------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Compute ALL_BUT_EXT, ALL_BUT_TAB_EXT and output files extensions. |
+`------------------------------------------------------------------*/
 
 /* Replace all characters FROM by TO in the string IN.
    and returns a new allocated string.  */
@@ -218,29 +229,27 @@ file_name_split (const char *file_name,
 
 
 static void
-compute_base_names (void)
+compute_file_name_parts (void)
 {
   const char *base, *tab, *ext;
 
-  /* If --output=foo.c was specified (SPEC_OUTFILE == foo.c),
-     FULL_BASE_NAME and SHORT_BASE_NAME are `foo'.
-
-     If --output=foo.tab.c was specified, FULL_BASE_NAME is `foo.tab'
-     and SHORT_BASE_NAME is `foo'.
+  /* Compute ALL_BUT_EXT and ALL_BUT_TAB_EXT from SPEC_OUTFILE
+     or GRAMMAR_FILE.
 
      The precise -o name will be used for FTABLE.  For other output
      files, remove the ".c" or ".tab.c" suffix.  */
   if (spec_outfile)
     {
       file_name_split (spec_outfile, &base, &tab, &ext);
+      dir_prefix = xstrndup (spec_outfile, base - spec_outfile);
 
-      /* The full base name goes up the EXT, excluding it. */
-      full_base_name =
+      /* ALL_BUT_EXT goes up the EXT, excluding it. */
+      all_but_ext =
 	xstrndup (spec_outfile,
 		  (strlen (spec_outfile) - (ext ? strlen (ext) : 0)));
 
-      /* The short base name goes up to TAB, excluding it.  */
-      short_base_name =
+      /* ALL_BUT_TAB_EXT goes up to TAB, excluding it.  */
+      all_but_tab_ext =
 	xstrndup (spec_outfile,
 		  (strlen (spec_outfile)
 		   - (tab ? strlen (tab) : (ext ? strlen (ext) : 0))));
@@ -248,40 +257,36 @@ compute_base_names (void)
       if (ext)
 	compute_exts_from_src (ext);
     }
-
-  /* If --file-prefix=foo was specified, FULL_BASE_NAME = `foo.tab'
-     and SHORT_BASE_NAME = `foo'.
-
-     Construct names from it.  */
   else
     {
+      file_name_split (grammar_file, &base, &tab, &ext);
+
       if (spec_file_prefix)
 	{
-	  /* If --file-prefix=foo was specified, SHORT_BASE_NAME =
+         /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT =
 	     `foo'.  */
-	  short_base_name = xstrdup (spec_file_prefix);
+         dir_prefix = xstrndup (grammar_file, base - grammar_file);
+         all_but_tab_ext = xstrdup (spec_file_prefix);
 	}
       else if (yacc_flag)
 	{
 	  /* If --yacc, then the output is `y.tab.c'. */
-	  short_base_name = xstrdup ("y");
+         dir_prefix = "";
+         all_but_tab_ext = "y";
 	}
       else
 	{
-	  /* Otherwise, the short base name is computed from the input
+         /* Otherwise, ALL_BUT_TAB_EXT is computed from the input
 	     grammar: `foo/bar.yy' => `bar'.  */
-	  file_name_split (grammar_file, &base, &tab, &ext);
-	  short_base_name =
+         dir_prefix = "";
+         all_but_tab_ext =
 	    xstrndup (base,
 		      (strlen (base) - (ext ? strlen (ext) : 0)));
 	}
 
-      full_base_name = xmalloc (strlen (short_base_name)
-				+ strlen (TAB_EXT) + 1);
-      stpcpy (stpcpy (full_base_name, short_base_name), TAB_EXT);
+      all_but_ext = concat2 (all_but_tab_ext, TAB_EXT);
 
       /* Compute the extensions from the grammar file name.  */
-      file_name_split (grammar_file, &base, &tab, &ext);
       if (ext && !yacc_flag)
 	compute_exts_from_gf (ext);
     }
@@ -299,7 +304,7 @@ compute_output_file_names (void)
   int j;
   int names = 0;
 
-  compute_base_names ();
+  compute_file_name_parts ();
 
   /* If not yet done. */
   if (!src_extension)
@@ -308,25 +313,25 @@ compute_output_file_names (void)
     header_extension = ".h";
 
   name[names++] = parser_file_name =
-    spec_outfile ? spec_outfile : concat2 (full_base_name, src_extension);
+    spec_outfile ? spec_outfile : concat2 (all_but_ext, src_extension);
 
   if (defines_flag)
     {
       if (! spec_defines_file)
-	spec_defines_file = concat2 (full_base_name, header_extension);
+       spec_defines_file = concat2 (all_but_ext, header_extension);
       name[names++] = spec_defines_file;
     }
 
   if (graph_flag)
     {
       if (! spec_graph_file)
-	spec_graph_file = concat2 (short_base_name, ".vcg");
+       spec_graph_file = concat2 (all_but_tab_ext, ".vcg");
       name[names++] = spec_graph_file;
     }
 
   if (report_flag)
     {
-      spec_verbose_file = concat2 (short_base_name, OUTPUT_EXT);
+      spec_verbose_file = concat2 (all_but_tab_ext, OUTPUT_EXT);
       name[names++] = spec_verbose_file;
     }
 
