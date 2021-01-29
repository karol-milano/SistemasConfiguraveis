@@ -185,11 +185,11 @@ compute_base_names (void)
       base_length = strlen (spec_outfile);
       if (strsuffix (spec_outfile, ".c"))
 	base_length -= 2;
+      base_name = strndup (spec_outfile, base_length);
       /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
       short_base_length = base_length;
-      if (strsuffix (spec_outfile, ".tab") || strsuffix (spec_outfile, "_tab"))
+      if (strsuffix (base_name, ".tab") || strsuffix (base_name, "_tab"))
 	short_base_length -= 4;
-      base_name = strndup (spec_outfile, base_length);
       short_base_name = strndup (spec_outfile, short_base_length);
 
       return;
