@@ -1,6 +1,6 @@
 /* Open and close files for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -140,7 +140,7 @@ tr (const char *in, char from, char to)
   return (temp);
 }
 
-/* Computes extensions from the grammar file extension. */
+/* Compute extensions from the grammar file extension.  */
 static void
 compute_exts_from_gf (const char *ext)
 {
@@ -150,7 +150,7 @@ compute_exts_from_gf (const char *ext)
   header_extension = tr (header_extension, 'Y', 'H');
 }
 
-/* Computes extensions from the given c source file extension. */
+/* Compute extensions from the given c source file extension.  */
 static void
 compute_exts_from_src (const char *ext)
 {
@@ -280,7 +280,7 @@ compute_base_names (void)
 				+ strlen (TAB_EXT) + 1);
       stpcpy (stpcpy (full_base_name, short_base_name), TAB_EXT);
 
-      /* Computes the extensions from the grammar file name.  */
+      /* Compute the extensions from the grammar file name.  */
       filename_split (grammar_file, &base, &tab, &ext);
       if (ext && !yacc_flag)
 	compute_exts_from_gf (ext);
