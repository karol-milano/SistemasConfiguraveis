@@ -1,5 +1,6 @@
 /* Open and close files for bison,
-   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000, 2001, 2002
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -54,15 +55,18 @@ char *infile = NULL;
 char *attrsfile = NULL;
 
 static char *full_base_name = NULL;
+
+/* Prefix used to generate output file names.  */
 char *short_base_name = NULL;
 
+/* Infix used to generate output file names (i.e., `.tab', or `_tab',
+   or `').  */
+char *output_infix = NULL;
+
 /* C source file extension (the parser source).  */
 const char *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified).  */
 const char *header_extension = NULL;
-
-/* Should we insert '.tab' in yacc-compatible parsers?  */
-int tab_extension = 0;
 
 
 /*--------------------------.
@@ -347,14 +351,16 @@ compute_base_names (void)
       full_base_name =
 	xstrndup (spec_outfile,
 		  (strlen (spec_outfile) - (ext ? strlen (ext) : 0)));
+
       /* The short base name goes up to TAB, excluding it.  */
       short_base_name =
 	xstrndup (spec_outfile,
 		  (strlen (spec_outfile)
 		   - (tab ? strlen (tab) : (ext ? strlen (ext) : 0))));
 
-      /* Do we have a tab part? */
-      tab_extension = !!tab;
+      if (tab)
+	output_infix = xstrndup (tab,
+				 (strlen (tab) - (ext ? strlen (ext) : 0)));
 
       if (ext)
 	compute_exts_from_src (ext);
@@ -388,7 +394,8 @@ compute_base_names (void)
 	}
 
       /* In these cases, always append `.tab'. */
-      tab_extension = 1;
+      output_infix = xstrdup (EXT_TAB);
+
       full_base_name = XMALLOC (char,
 				strlen (short_base_name)
 				+ strlen (EXT_TAB) + 1);
