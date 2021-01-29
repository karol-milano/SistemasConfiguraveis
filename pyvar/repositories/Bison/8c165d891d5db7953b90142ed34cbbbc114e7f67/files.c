@@ -384,11 +384,11 @@ compute_base_names (void)
       else
 	{
 	  /* Otherwise, the short base name is computed from the input
-	     grammar: `foo.yy' => `foo'.  */
+	     grammar: `foo/bar.yy' => `bar'.  */
 	  filename_split (infile, &base, &tab, &ext);
 	  short_base_name =
-	    xstrndup (infile,
-		      (strlen (infile) - (ext ? strlen (ext) : 0)));
+	    xstrndup (base,
+		      (strlen (base) - (ext ? strlen (ext) : 0)));
 	}
 
       /* In these cases, always append `.tab'. */
