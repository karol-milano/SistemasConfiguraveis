@@ -57,10 +57,6 @@ static char *full_base_name = NULL;
 /* Prefix used to generate output file names.  */
 char *short_base_name = NULL;
 
-/* Infix used to generate output file names (i.e., `.tab', or `_tab',
-   or `').  */
-char *output_infix = NULL;
-
 /* C source file extension (the parser source).  */
 const char *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified).  */
@@ -258,10 +254,6 @@ compute_base_names (void)
 		  (strlen (spec_outfile)
 		   - (tab ? strlen (tab) : (ext ? strlen (ext) : 0))));
 
-      if (tab)
-	output_infix = xstrndup (tab,
-				 (strlen (tab) - (ext ? strlen (ext) : 0)));
-
       if (ext)
 	compute_exts_from_src (ext);
     }
@@ -293,9 +285,6 @@ compute_base_names (void)
 		      (strlen (base) - (ext ? strlen (ext) : 0)));
 	}
 
-      /* In these cases, always append `.tab'. */
-      output_infix = xstrdup (EXT_TAB);
-
       full_base_name = XMALLOC (char,
 				strlen (short_base_name)
 				+ strlen (EXT_TAB) + 1);
