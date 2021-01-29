@@ -30,7 +30,6 @@ FILE *finput = NULL;
 
 struct obstack action_obstack;
 struct obstack attrs_obstack;
-struct obstack table_obstack;
 struct obstack defines_obstack;
 struct obstack guard_obstack;
 struct obstack output_obstack;
@@ -41,6 +40,7 @@ const char *spec_name_prefix = "yy";	/* for -p. */
 char *spec_verbose_file = NULL;   /* for --verbose. */
 char *spec_graph_file = NULL;   /* for -g. */
 char *spec_defines_file = NULL; /* for --defines. */
+char *parser_file_name = NULL;
 
 char *infile = NULL;
 char *attrsfile = NULL;
@@ -433,6 +433,9 @@ compute_output_file_names (void)
 {
   compute_base_names ();
 
+  parser_file_name =
+    spec_outfile ? spec_outfile : stringappend (base_name, src_extension);
+
   /* If not yet done. */
   if (!src_extension)
     src_extension = ".c";
@@ -453,7 +456,6 @@ compute_output_file_names (void)
 #ifndef MSDOS
   attrsfile = stringappend (attrsfile, header_extension);
 #endif /* MSDOS */
-
 }
 
 /*-----------------------------------------------------------------.
@@ -469,7 +471,6 @@ open_files (void)
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
   obstack_init (&attrs_obstack);
-  obstack_init (&table_obstack);
   obstack_init (&defines_obstack);
   obstack_init (&guard_obstack);
   obstack_init (&output_obstack);
@@ -494,13 +495,6 @@ close_files (void)
 void
 output_files (void)
 {
-  /* Output the main file.  */
-  if (spec_outfile)
-    obstack_save (&table_obstack, spec_outfile);
-  else
-    obstack_save (&table_obstack, stringappend (base_name, src_extension));
-  obstack_free (&table_obstack, NULL);
-
   /* Output the header file if wanted. */
   if (defines_flag)
     defines_obstack_save (spec_defines_file);
