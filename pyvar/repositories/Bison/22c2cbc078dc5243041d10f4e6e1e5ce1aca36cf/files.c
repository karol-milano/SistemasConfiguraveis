@@ -1,5 +1,5 @@
 /* Open and close files for bison,
-   Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -34,6 +34,7 @@ struct obstack table_obstack;
 struct obstack defines_obstack;
 struct obstack guard_obstack;
 struct obstack output_obstack;
+struct obstack graph_obstack;
 
 char *spec_outfile = NULL;	/* for -o. */
 char *spec_file_prefix = NULL; /* for -b. */
@@ -213,7 +214,7 @@ compute_exts_from_gf(const char *ext)
     {
       src_extension = tr(ext, 'y', 'c');
       src_extension = tr(src_extension, 'Y', 'C');
-    } 
+    }
   if (!header_extension)
     {
       header_extension = tr(ext, 'y', 'h');
@@ -228,7 +229,7 @@ compute_exts_from_src(const char *ext)
   if (!src_extension)
     src_extension = xstrdup(ext);
   if (!header_extension)
-    {     
+    {
       header_extension = tr(ext, 'c', 'h');
       header_extension = tr(header_extension, 'C', 'H');
     }
