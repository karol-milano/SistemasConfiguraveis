@@ -101,7 +101,7 @@
 #include "symtab.h"
 #include "conflicts.h"
 #include "muscle_tab.h"
-
+#include "skeleton.h"
 
 static int nvectors;
 static int nentries;
@@ -961,111 +961,12 @@ output_actions (void)
 }
 
 
-/*------------------------------------------------------------.
-| Copy the parser code from SKEL_FILENAME into OOUT obstack.  |
-| and do the muscle substitution.                             |
-`------------------------------------------------------------*/
+/*---------------------------.
+| Call the skeleton parser.  |
+`---------------------------*/
 
 static void
-output_parser (const char *skel_filename, FILE *out)
-{
-  int c;
-  FILE *fskel;
-  size_t output_line;
-  size_t skeleton_line;
-
-  fskel = xfopen (skel_filename, "r");
-
-  /* New output code.  */
-  output_line = 1;
-  skeleton_line = 1;
-  c = getc (fskel);
-  while (c != EOF)
-    {
-      if (c != '%')
-	{
-	  if (c == '\n')
-	    {
-	      ++output_line;
-	      ++skeleton_line;
-	    }
-	  putc (c, out);
-	  c = getc (fskel);
-	}
-      else if ((c = getc (fskel)) == '%')
-	{
-	  /* Read the muscle.  */
-	  const char *muscle_key = 0;
-	  const char *muscle_value = 0;
-
-	  while (isalnum (c = getc (fskel)) || c == '-')
-	    obstack_1grow (&muscle_obstack, c);
-	  obstack_1grow (&muscle_obstack, 0);
-
-	  /* Output the right value, or see if it's something special.  */
-	  muscle_key = obstack_finish (&muscle_obstack);
-	  muscle_value = muscle_find (muscle_key);
-	  if (!strcmp (muscle_key, "actions"))
-	    actions_output (out, &output_line);
-	  else if (!strcmp (muscle_key, "guards"))
-	    guards_output (out, &output_line);
-	  else if (!strcmp (muscle_key, "line"))
-	    fprintf (out, "%d", output_line);
-	  else if (!strcmp (muscle_key, "tokendef"))
-	    token_definitions_output (out, &output_line);
-	  else if (!strcmp (muscle_key, "skeleton-line"))
-	    fprintf (out, "%d", skeleton_line);
-	  else if (muscle_value)
-	    {
-	      fputs (muscle_value, out);
-	      output_line += get_lines_number (muscle_value);
-	    }
-	  else
-	    {
-	      fputs ("%%", out);
-	      fputs (muscle_key, out);
-	    }
-	}
-      else
-	putc ('%', out);
-    }
-
-  /* End.  */
-  xfclose (fskel);
-}
-
-/*----------------------------------------.
-| Prepare the master parser to be output  |
-`----------------------------------------*/
-
-static void
-output_master_parser (void)
-{
-  FILE *parser = xfopen (parser_file_name, "w");
-
-  /* FIXME: Remove the two following lines.  */
-  printf ("Test: %s\n", infile);
-  printf ("Test: %s\n", parser_file_name);
-
-  if (!skeleton)
-    {
-      if (semantic_parser)
-	skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
-      else
-	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
-    }
-  muscle_insert ("skeleton", skeleton);
-  muscle_insert ("parser-file-name", parser_file_name);
-
-  output_parser (skeleton, parser);
-  xfclose (parser);
-}
-
-/* Call the skeleton parser.  */
-
-static 
-void
-output_skeleton ()
+output_skeleton (void)
 {
   /* Find the right skeleton file.  */
   if (!skeleton)
@@ -1078,7 +979,7 @@ output_skeleton ()
 
   /* Parse the skeleton file and output the needed parsers.  */
   muscle_insert ("skeleton", skeleton);
-  process_skeleton (infile, skeleton);
+  process_skeleton (skeleton);
 }
 
 static void
@@ -1190,10 +1091,6 @@ output (void)
   /* Process the selected skeleton file.  */
   output_skeleton ();
 
-  /* Output the parser. */
-#if 0
-  output_master_parser ();
-#endif
   /* Output the header if needed. */
   if (defines_flag)
     header_output ();
