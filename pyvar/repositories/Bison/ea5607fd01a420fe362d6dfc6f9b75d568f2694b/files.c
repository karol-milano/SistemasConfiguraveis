@@ -28,19 +28,19 @@
 
 FILE *finput = NULL;
 FILE *foutput = NULL;
-FILE *fguard = NULL;
 
 struct obstack action_obstack;
 struct obstack attrs_obstack;
 struct obstack table_obstack;
 struct obstack defines_obstack;
+struct obstack guard_obstack;
 
-/* File name specified with -o for the output file, or 0 if no -o.  */
-char *spec_outfile;
+char *spec_outfile;	/* for -o. */
+char *spec_file_prefix; /* for -b. */
+char *spec_name_prefix; /* for -p. */
 
 char *infile;
 char *attrsfile;
-char *guardfile;
 
 static char *base_name;
 static char *short_base_name;
@@ -255,13 +255,13 @@ open_files (void)
     foutput = xfopen (stringappend (base_name, EXT_OUTPUT), "w");
 
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
-  guardfile = stringappend (short_base_name, EXT_GUARD_C);
 
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
   obstack_init (&attrs_obstack);
   obstack_init (&table_obstack);
   obstack_init (&defines_obstack);
+  obstack_init (&guard_obstack);
 }
 
 
@@ -273,7 +273,6 @@ open_files (void)
 void
 output_files (void)
 {
-  xfclose (fguard);
   xfclose (finput);
   xfclose (foutput);
 
@@ -294,5 +293,9 @@ output_files (void)
   /* If we produced a semantic parser ATTRS_OBSTACK must be dumped
      into its own file, ATTTRSFILE.  */
   if (semantic_parser)
-    obstack_save (&attrs_obstack, attrsfile);
+    {
+      obstack_save (&attrs_obstack, attrsfile);
+      obstack_save (&guard_obstack,
+		    stringappend (short_base_name, EXT_GUARD_C));
+    }
 }
