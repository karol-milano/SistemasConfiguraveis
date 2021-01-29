@@ -285,7 +285,7 @@ compute_file_name_parts (void)
                       last_component (spec_file_prefix) - spec_file_prefix);
           all_but_tab_ext = xstrdup (spec_file_prefix);
         }
-      else if (yacc_flag)
+      else if (! location_empty (yacc_loc))
         {
           /* If --yacc, then the output is 'y.tab.c'.  */
           dir_prefix = xstrdup ("");
@@ -306,7 +306,7 @@ compute_file_name_parts (void)
         all_but_ext = xstrdup (all_but_tab_ext);
 
       /* Compute the extensions from the grammar file name.  */
-      if (ext && !yacc_flag)
+      if (ext && location_empty (yacc_loc))
         compute_exts_from_gf (ext);
     }
 }
