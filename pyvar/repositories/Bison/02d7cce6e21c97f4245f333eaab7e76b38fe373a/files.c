@@ -263,25 +263,23 @@ compute_file_name_parts (void)
 
       if (spec_file_prefix)
 	{
-         /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT =
-	     `foo'.  */
-         dir_prefix = xstrndup (grammar_file, base - grammar_file);
-         all_but_tab_ext = xstrdup (spec_file_prefix);
+	  /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT = `foo'.  */
+	  dir_prefix = xstrndup (grammar_file, base - grammar_file);
+	  all_but_tab_ext = xstrdup (spec_file_prefix);
 	}
       else if (yacc_flag)
 	{
-	  /* If --yacc, then the output is `y.tab.c'. */
-         dir_prefix = "";
-         all_but_tab_ext = "y";
+	  /* If --yacc, then the output is `y.tab.c'.  */
+	  dir_prefix = "";
+	  all_but_tab_ext = "y";
 	}
       else
 	{
-         /* Otherwise, ALL_BUT_TAB_EXT is computed from the input
+	  /* Otherwise, ALL_BUT_TAB_EXT is computed from the input
 	     grammar: `foo/bar.yy' => `bar'.  */
-         dir_prefix = "";
-         all_but_tab_ext =
-	    xstrndup (base,
-		      (strlen (base) - (ext ? strlen (ext) : 0)));
+	  dir_prefix = "";
+	  all_but_tab_ext =
+	    xstrndup (base, (strlen (base) - (ext ? strlen (ext) : 0)));
 	}
 
       all_but_ext = concat2 (all_but_tab_ext, TAB_EXT);
@@ -318,14 +316,14 @@ compute_output_file_names (void)
   if (defines_flag)
     {
       if (! spec_defines_file)
-       spec_defines_file = concat2 (all_but_ext, header_extension);
+	spec_defines_file = concat2 (all_but_ext, header_extension);
       name[names++] = spec_defines_file;
     }
 
   if (graph_flag)
     {
       if (! spec_graph_file)
-       spec_graph_file = concat2 (all_but_tab_ext, ".vcg");
+	spec_graph_file = concat2 (all_but_tab_ext, ".vcg");
       name[names++] = spec_graph_file;
     }
 
