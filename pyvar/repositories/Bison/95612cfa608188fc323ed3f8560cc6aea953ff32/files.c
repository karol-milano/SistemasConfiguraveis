@@ -50,7 +50,8 @@ char *spec_graph_file = NULL;   /* for -g. */
 char *spec_defines_file = NULL; /* for --defines. */
 char *parser_file_name = NULL;
 
-char *infile = NULL;
+struniq_t grammar_file = NULL;
+struniq_t current_file = NULL;
 
 static char *full_base_name = NULL;
 
@@ -279,7 +280,7 @@ compute_base_names (void)
 	{
 	  /* Otherwise, the short base name is computed from the input
 	     grammar: `foo/bar.yy' => `bar'.  */
-	  filename_split (infile, &base, &tab, &ext);
+	  filename_split (grammar_file, &base, &tab, &ext);
 	  short_base_name =
 	    xstrndup (base,
 		      (strlen (base) - (ext ? strlen (ext) : 0)));
@@ -291,7 +292,7 @@ compute_base_names (void)
       stpcpy (stpcpy (full_base_name, short_base_name), EXT_TAB);
 
       /* Computes the extensions from the grammar file name.  */
-      filename_split (infile, &base, &tab, &ext);
+      filename_split (grammar_file, &base, &tab, &ext);
       if (ext && !yacc_flag)
 	compute_exts_from_gf (ext);
     }
