@@ -125,7 +125,7 @@ static struct obstack format_obstack;
 int error_verbose = 0;
 
 /* Returns the number of lines of S.  */
-static size_t
+size_t
 get_lines_number (const char *s)
 {
   size_t lines = 0;
@@ -503,7 +503,7 @@ token_actions (void)
 | Output the actions to OOUT.  |
 `-----------------------------*/
 
-static void
+void
 actions_output (FILE *out, size_t *line)
 {
   int rule;
@@ -539,7 +539,7 @@ actions_output (FILE *out, size_t *line)
 | Output the guards to OOUT.  |
 `----------------------------*/
 
-static void
+void
 guards_output (FILE *out, size_t *line)
 {
   int rule;
@@ -571,7 +571,7 @@ guards_output (FILE *out, size_t *line)
 | Output the tokens definition to OOUT.  |
 `---------------------------------------*/
 
-static void
+void
 token_definitions_output (FILE *out, size_t *line)
 {
   int i;
@@ -1042,6 +1042,11 @@ static void
 output_master_parser (void)
 {
   FILE *parser = xfopen (parser_file_name, "w");
+
+  /* FIXME: Remove the two following lines.  */
+  printf ("Test: %s\n", infile);
+  printf ("Test: %s\n", parser_file_name);
+
   if (!skeleton)
     {
       if (semantic_parser)
@@ -1056,29 +1061,24 @@ output_master_parser (void)
   xfclose (parser);
 }
 
+/* Call the skeleton parser.  */
 
-/* FIXME. */
-
-#define MUSCLE_INSERT_INT(Key, Value)				\
-{								\
-  obstack_fgrow1 (&muscle_obstack, "%d", Value);	       	\
-  obstack_1grow (&muscle_obstack, 0);				\
-  muscle_insert (Key, obstack_finish (&muscle_obstack));	\
-}
-
-#define MUSCLE_INSERT_STRING(Key, Value)			\
-{								\
-  obstack_sgrow (&muscle_obstack, Value);			\
-  obstack_1grow (&muscle_obstack, 0);				\
-  muscle_insert (Key, obstack_finish (&muscle_obstack));	\
-}
+static 
+void
+output_skeleton ()
+{
+  /* Find the right skeleton file.  */
+  if (!skeleton)
+    {
+      if (semantic_parser)
+	skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
+      else
+	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
+    }
 
-#define MUSCLE_INSERT_PREFIX(Key, Value)	       			\
-{									\
-  obstack_fgrow2 (&muscle_obstack, "%s%s", 				\
-		  spec_name_prefix ? spec_name_prefix : "yy", Value);	\
-  obstack_1grow (&muscle_obstack, 0);					\
-  muscle_insert (Key, obstack_finish (&muscle_obstack));	       	\
+  /* Parse the skeleton file and output the needed parsers.  */
+  muscle_insert ("skeleton", skeleton);
+  process_skeleton (infile, skeleton);
 }
 
 static void
@@ -1102,7 +1102,6 @@ prepare (void)
   MUSCLE_INSERT_INT ("locations-flag", locations_flag);
 }
 
-
 /*-------------------------.
 | Output the header file.  |
 `-------------------------*/
@@ -1188,8 +1187,13 @@ output (void)
   obstack_1grow (&attrs_obstack, 0);
   muscle_insert ("prologue", obstack_finish (&attrs_obstack));
 
+  /* Process the selected skeleton file.  */
+  output_skeleton ();
+
   /* Output the parser. */
+#if 0
   output_master_parser ();
+#endif
   /* Output the header if needed. */
   if (defines_flag)
     header_output ();
