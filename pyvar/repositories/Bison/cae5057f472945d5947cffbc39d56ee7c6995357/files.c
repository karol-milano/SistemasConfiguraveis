@@ -267,7 +267,9 @@ compute_file_name_parts (void)
       if (spec_file_prefix)
 	{
 	  /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT = `foo'.  */
-	  dir_prefix = xstrndup (grammar_file, base - grammar_file);
+	  dir_prefix =
+            xstrndup (spec_file_prefix,
+                      last_component (spec_file_prefix) - spec_file_prefix);
 	  all_but_tab_ext = xstrdup (spec_file_prefix);
 	}
       else if (yacc_flag)
