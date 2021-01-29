@@ -437,34 +437,6 @@ compute_output_file_names (void)
 #endif /* MSDOS */
 }
 
-/*-----------------------------------------------------------------.
-| Open the input file.  Look for the skeletons.  Find the names of |
-| the output files.  Prepare the obstacks.                         |
-`-----------------------------------------------------------------*/
-
-void
-open_files (void)
-{
-  finput = xfopen (infile, "r");
-
-  /* Initialize the obstacks. */
-  obstack_init (&action_obstack);
-  obstack_init (&attrs_obstack);
-  obstack_init (&guard_obstack);
-  obstack_init (&output_obstack);
-}
-
-
-
-/*-----------------------.
-| Close the open file..  |
-`-----------------------*/
-
-void
-close_files (void)
-{
-  xfclose (finput);
-}
 
 /*---------------------------.
 | Produce the output files.  |
