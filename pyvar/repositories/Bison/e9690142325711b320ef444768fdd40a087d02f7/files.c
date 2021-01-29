@@ -200,7 +200,7 @@ compute_exts_from_src (const char *ext)
 
 static void
 file_name_split (const char *file_name,
-		 const char **base, const char **tab, const char **ext)
+                 const char **base, const char **tab, const char **ext)
 {
   *base = last_component (file_name);
 
@@ -215,9 +215,9 @@ file_name_split (const char *file_name,
       size_t baselen = *ext - *base;
       size_t dottablen = 4;
       if (dottablen < baselen
-	  && (strncmp (*ext - dottablen, ".tab", dottablen) == 0
-	      || strncmp (*ext - dottablen, "_tab", dottablen) == 0))
-	*tab = *ext - dottablen;
+          && (strncmp (*ext - dottablen, ".tab", dottablen) == 0
+              || strncmp (*ext - dottablen, "_tab", dottablen) == 0))
+        *tab = *ext - dottablen;
     }
 }
 
@@ -239,44 +239,44 @@ compute_file_name_parts (void)
 
       /* ALL_BUT_EXT goes up the EXT, excluding it. */
       all_but_ext =
-	xstrndup (spec_outfile,
-		  (strlen (spec_outfile) - (ext ? strlen (ext) : 0)));
+        xstrndup (spec_outfile,
+                  (strlen (spec_outfile) - (ext ? strlen (ext) : 0)));
 
       /* ALL_BUT_TAB_EXT goes up to TAB, excluding it.  */
       all_but_tab_ext =
-	xstrndup (spec_outfile,
-		  (strlen (spec_outfile)
-		   - (tab ? strlen (tab) : (ext ? strlen (ext) : 0))));
+        xstrndup (spec_outfile,
+                  (strlen (spec_outfile)
+                   - (tab ? strlen (tab) : (ext ? strlen (ext) : 0))));
 
       if (ext)
-	compute_exts_from_src (ext);
+        compute_exts_from_src (ext);
     }
   else
     {
       file_name_split (grammar_file, &base, &tab, &ext);
 
       if (spec_file_prefix)
-	{
-	  /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT = `foo'.  */
-	  dir_prefix =
+        {
+          /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT = `foo'.  */
+          dir_prefix =
             xstrndup (spec_file_prefix,
                       last_component (spec_file_prefix) - spec_file_prefix);
-	  all_but_tab_ext = xstrdup (spec_file_prefix);
-	}
+          all_but_tab_ext = xstrdup (spec_file_prefix);
+        }
       else if (yacc_flag)
-	{
-	  /* If --yacc, then the output is `y.tab.c'.  */
-	  dir_prefix = xstrdup ("");
-	  all_but_tab_ext = xstrdup ("y");
-	}
+        {
+          /* If --yacc, then the output is `y.tab.c'.  */
+          dir_prefix = xstrdup ("");
+          all_but_tab_ext = xstrdup ("y");
+        }
       else
-	{
-	  /* Otherwise, ALL_BUT_TAB_EXT is computed from the input
-	     grammar: `foo/bar.yy' => `bar'.  */
-	  dir_prefix = xstrdup ("");
-	  all_but_tab_ext =
-	    xstrndup (base, (strlen (base) - (ext ? strlen (ext) : 0)));
-	}
+        {
+          /* Otherwise, ALL_BUT_TAB_EXT is computed from the input
+             grammar: `foo/bar.yy' => `bar'.  */
+          dir_prefix = xstrdup ("");
+          all_but_tab_ext =
+            xstrndup (base, (strlen (base) - (ext ? strlen (ext) : 0)));
+        }
 
       if (language->add_tab)
         all_but_ext = concat2 (all_but_tab_ext, TAB_EXT);
@@ -285,7 +285,7 @@ compute_file_name_parts (void)
 
       /* Compute the extensions from the grammar file name.  */
       if (ext && !yacc_flag)
-	compute_exts_from_gf (ext);
+        compute_exts_from_gf (ext);
     }
 }
 
@@ -312,20 +312,20 @@ compute_output_file_names (void)
   if (defines_flag)
     {
       if (! spec_defines_file)
-	spec_defines_file = concat2 (all_but_ext, header_extension);
+        spec_defines_file = concat2 (all_but_ext, header_extension);
     }
 
   if (graph_flag)
     {
       if (! spec_graph_file)
-	spec_graph_file = concat2 (all_but_tab_ext, ".dot");
+        spec_graph_file = concat2 (all_but_tab_ext, ".dot");
       output_file_name_check (&spec_graph_file);
     }
 
   if (xml_flag)
     {
       if (! spec_xml_file)
-	spec_xml_file = concat2 (all_but_tab_ext, ".xml");
+        spec_xml_file = concat2 (all_but_tab_ext, ".xml");
       output_file_name_check (&spec_xml_file);
     }
 
