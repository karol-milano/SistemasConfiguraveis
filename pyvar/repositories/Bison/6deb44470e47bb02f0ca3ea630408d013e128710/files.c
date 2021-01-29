@@ -245,12 +245,8 @@ compute_base_names (void)
 void
 open_files (void)
 {
-  compute_base_names ();
-
   finput = xfopen (infile, "r");
 
-  attrsfile = stringappend (short_base_name, EXT_STYPE_H);
-
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
   obstack_init (&attrs_obstack);
@@ -271,6 +267,9 @@ output_files (void)
 {
   xfclose (finput);
 
+  compute_base_names ();
+  attrsfile = stringappend (short_base_name, EXT_STYPE_H);
+
   /* Output the main file.  */
   if (spec_outfile)
     obstack_save (&table_obstack, spec_outfile);
