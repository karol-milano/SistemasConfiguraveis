@@ -30,7 +30,6 @@ FILE *finput = NULL;
 
 struct obstack action_obstack;
 struct obstack attrs_obstack;
-struct obstack defines_obstack;
 struct obstack guard_obstack;
 struct obstack output_obstack;
 
@@ -94,7 +93,7 @@ stringappend (const char *string1, const char *string2)
 | alphanumerical + underscore).                                    |
 `-----------------------------------------------------------------*/
 
-static char *
+char *
 compute_header_macro (void)
 {
   const char *prefix = "BISON_";
@@ -178,26 +177,6 @@ obstack_save (struct obstack *obs, const char *filename)
   xfclose (out);
 }
 
-/*---------------------------------------------------------------------.
-| Output double inclusion protection macros and saves defines_obstack  |
-`---------------------------------------------------------------------*/
-
-static void
-defines_obstack_save (const char *filename)
-{
-  FILE *out = xfopen (filename, "w");
-  size_t size = obstack_object_size (&defines_obstack);
-  char *macro_name = compute_header_macro ();
-
-  fprintf (out, "#ifndef %s\n", macro_name);
-  fprintf (out, "# define %s\n\n", macro_name);
-  fwrite (obstack_finish (&defines_obstack), 1, size, out);
-  fprintf (out, "\n#endif /* not %s */\n", macro_name);
-
-  free (macro_name);
-  xfclose (out);
-}
-
 /*------------------------------------------------------------------.
 | Return the path to the skeleton which locaction might be given in |
 | ENVVAR, otherwise return SKELETON_NAME.                           |
@@ -471,7 +450,6 @@ open_files (void)
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
   obstack_init (&attrs_obstack);
-  obstack_init (&defines_obstack);
   obstack_init (&guard_obstack);
   obstack_init (&output_obstack);
 }
@@ -495,11 +473,6 @@ close_files (void)
 void
 output_files (void)
 {
-  /* Output the header file if wanted. */
-  if (defines_flag)
-    defines_obstack_save (spec_defines_file);
-  obstack_free (&defines_obstack, NULL);
-
 #if 0
   /* Seems to be invalid now --akim. */
 
