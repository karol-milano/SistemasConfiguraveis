@@ -897,19 +897,24 @@ output_parser (const char *skel_filename, FILE *out)
 {
   int c;
   FILE *fskel;
-  size_t line;
+  size_t output_line;
+  size_t skeleton_line;
 
   fskel = xfopen (skel_filename, "r");
 
   /* New output code.  */
-  line = 1;
+  output_line = 1;
+  skeleton_line = 1;
   c = getc (fskel);
   while (c != EOF)
     {
       if (c != '%')
 	{
 	  if (c == '\n')
-	    ++line;
+	    {
+	      ++output_line;
+	      ++skeleton_line;
+	    }
 	  putc (c, out);
 	  c = getc (fskel);
 	}
@@ -927,13 +932,15 @@ output_parser (const char *skel_filename, FILE *out)
 	  muscle_key = obstack_finish (&muscle_obstack);
 	  muscle_value = muscle_find (muscle_key);
 	  if (!strcmp (muscle_key, "actions"))
-	    actions_output (out, &line);
+	    actions_output (out, &output_line);
 	  else if (!strcmp (muscle_key, "line"))
-	    fprintf (out, "%d", line);
+	    fprintf (out, "%d", output_line);
+	  else if (!strcmp (muscle_key, "skeleton-line"))
+	    fprintf (out, "%d", skeleton_line);
 	  else if (muscle_value)
 	    {
 	      fputs (muscle_value, out);
-	      line += get_lines_number (muscle_value);
+	      output_line += get_lines_number (muscle_value);
 	    }	  
 	  else
 	    {
