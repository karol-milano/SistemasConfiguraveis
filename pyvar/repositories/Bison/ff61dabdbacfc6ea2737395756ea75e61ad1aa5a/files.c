@@ -29,7 +29,6 @@
 FILE *finput = NULL;
 FILE *foutput = NULL;
 FILE *fguard = NULL;
-FILE *fparser = NULL;
 
 struct obstack action_obstack;
 struct obstack attrs_obstack;
@@ -41,11 +40,11 @@ char *spec_outfile;
 
 char *infile;
 char *attrsfile;
+char *guardfile;
 
 static char *outfile;
 static char *defsfile;
 static char *tabfile;
-static char *guardfile;
 static char *actfile;
 
 /*-----------------------------------------------------------------.
@@ -85,7 +84,7 @@ stringappend (const char *string1, int end1, const char *string2)
 | if fails.                                                        |
 `-----------------------------------------------------------------*/
 
-static FILE *
+FILE *
 xfopen (const char *name, const char *mode)
 {
   FILE *ptr;
@@ -101,7 +100,7 @@ xfopen (const char *name, const char *mode)
 | Try to close file PTR, and print an error message if fails.  |
 `-------------------------------------------------------------*/
 
-static int
+int
 xfclose (FILE *ptr)
 {
   int result;
@@ -130,7 +129,12 @@ obstack_save (struct obstack *obs, const char *filename)
 }
 
 
-static const char *
+/*------------------------------------------------------------------.
+| Return the path to the skeleton which locaction might be given in |
+| ENVVAR, otherwise return SKELETON.                                |
+`------------------------------------------------------------------*/
+
+const char *
 skeleton_find (const char *envvar, const char *skeleton)
 {
   const char *res = getenv (envvar);
@@ -221,9 +225,6 @@ open_files (void)
 
   finput = xfopen (infile, "r");
 
-  if (!no_parser_flag)
-    fparser = xfopen (skeleton_find ("BISON_SIMPLE", BISON_SIMPLE), "r");
-
   if (verbose_flag)
     {
       /* We used to use just .out if spec_name_prefix (-p) was used,
@@ -261,22 +262,6 @@ open_files (void)
 
 
 
-/*--------------------------------------------------------------------.
-| Open the output files needed only for the semantic parser.  This    |
-| is done when %semantic_parser is seen in the declarations section.  |
-`--------------------------------------------------------------------*/
-
-void
-open_extra_files (void)
-{
-  xfclose (fparser);
-
-  if (!no_parser_flag)
-    fparser = xfopen (skeleton_find ("BISON_HAIRY", BISON_HAIRY), "r");
-  fguard = xfopen (guardfile, "w");
-}
-
-
 /*-----------------------------------------------------.
 | Close the open files, produce all the output files.  |
 `-----------------------------------------------------*/
@@ -286,7 +271,6 @@ output_files (void)
 {
   xfclose (fguard);
   xfclose (finput);
-  xfclose (fparser);
   xfclose (foutput);
 
   /* Output the main file.  */
