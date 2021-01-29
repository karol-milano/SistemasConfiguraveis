@@ -264,11 +264,11 @@ compute_base_names (void)
       /* if the initial segment of extension contains 'c' or a 'C', I assume
 	 that it is a C or C++ source file */
       if (ext_index)
-	ext_index = (strspn(spec_outfile + ext_index + 1, "cC")) ? ext_index : 0;
+	ext_index = (strspn (spec_outfile + ext_index + 1, "cC")) ? ext_index : 0;
       if (ext_index)
 	{
 	  base_length -= strlen (spec_outfile + ext_index);
-	  compute_exts_from_src(spec_outfile + ext_index);
+	  compute_exts_from_src (spec_outfile + ext_index);
 	}
 
       base_name = strndup (spec_outfile, base_length);
@@ -295,6 +295,15 @@ compute_base_names (void)
 			   strlen (short_base_name) + strlen (EXT_TAB) + 1);
       stpcpy (stpcpy (base_name, short_base_name), EXT_TAB);
 
+      /* Computes the extensions from the garmmar file name.  */
+      ext_index = get_extension_index (infile);
+      /* if the initial segment of extension contains a 'y' or a 'Y', I assume
+	 that it is a yacc or bison grammar file */
+      if (ext_index)
+	ext_index = (strspn (infile + ext_index + 1, "yY")) ? ext_index : 0;
+      if (ext_index)
+	compute_exts_from_gf (infile + ext_index);
+      
       return;
     }
 
@@ -314,11 +323,11 @@ compute_base_names (void)
     /* if the initial segment of extension contains a 'y' or a 'Y', I assume
        that it is a yacc or bison grammar file */
     if (ext_index)
-      ext_index = (strspn(name_base + ext_index + 1, "yY")) ? ext_index : 0;
+      ext_index = (strspn (name_base + ext_index + 1, "yY")) ? ext_index : 0;
     if (ext_index)
       {
 	base_length -= strlen (name_base + ext_index);
-	compute_exts_from_gf(name_base + ext_index);
+	compute_exts_from_gf (name_base + ext_index);
       }
 
     short_base_length = base_length;
