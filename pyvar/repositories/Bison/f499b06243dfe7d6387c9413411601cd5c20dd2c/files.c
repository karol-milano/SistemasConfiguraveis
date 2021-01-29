@@ -164,18 +164,6 @@ xfclose (FILE *ptr)
   return result;
 }
 
-/*--------------------------------------------------.
-| Save the content of the obstack OBS in FILENAME.  |
-`--------------------------------------------------*/
-
-static void
-obstack_save (struct obstack *obs, const char *filename)
-{
-  FILE *out = xfopen (filename, "w");
-  size_t size = obstack_object_size (obs);
-  fwrite (obstack_finish (obs), 1, size, out);
-  xfclose (out);
-}
 
 /*------------------------------------------------------------------.
 | Return the path to the skeleton which locaction might be given in |
@@ -436,38 +424,3 @@ compute_output_file_names (void)
   attrsfile = stringappend (attrsfile, header_extension);
 #endif /* MSDOS */
 }
-
-
-/*---------------------------.
-| Produce the output files.  |
-`---------------------------*/
-
-void
-output_files (void)
-{
-#if 0
-  /* Seems to be invalid now --akim. */
-
-  /* If we output only the table, dump the actions in ACTFILE. */
-  if (no_parser_flag)
-    obstack_save (&action_obstack, stringappend (short_base_name, ".act"));
-  obstack_free (&action_obstack, NULL);
-#endif
-
-  /* If we produced a semantic parser ATTRS_OBSTACK must be dumped
-     into its own file, ATTTRSFILE.  */
-  if (semantic_parser)
-    {
-      char *temp_name;
-
-      obstack_save (&attrs_obstack, attrsfile);
-      temp_name = stringappend (short_base_name, EXT_GUARD_C);
-#ifndef MSDOS
-      temp_name = stringappend (temp_name, src_extension);
-#endif /* MSDOS */
-      obstack_save (&guard_obstack, temp_name);
-    }
-
-  obstack_free (&guard_obstack, NULL);
-  obstack_free (&attrs_obstack, NULL);
-}
