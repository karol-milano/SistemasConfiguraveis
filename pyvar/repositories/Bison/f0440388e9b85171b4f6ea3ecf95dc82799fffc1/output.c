@@ -125,6 +125,23 @@ struct obstack output_obstack;
 
 int error_verbose = 0;
 
+/* Returns the number of lines of S.  */
+static size_t
+get_lines_number (const char *s)
+{
+  size_t lines = 0;
+  
+  size_t i;
+  for (i = 0; s[i]; ++i)
+    {
+      if (s[i] == '\n')
+	++lines;
+    }   
+  
+  return lines;
+}
+
+
 /* FIXME. */
 
 static inline void
@@ -519,7 +536,7 @@ token_actions (void)
 `-----------------------------*/
 
 static void
-actions_output (FILE *out)
+actions_output (FILE *out, size_t *line)
 {
   int rule;
   for (rule = 1; rule < nrules + 1; ++rule)
@@ -538,6 +555,11 @@ actions_output (FILE *out)
 	fprintf (out, "{ %s%s }\n    break;\n\n",
 		 rule_table[rule].action,
 		 yacc_flag ? ";" : "");
+
+	/* We always output 5 '\n' per action.  */
+	*line += 5;
+	/* Get the number of lines written by the user.  */
+	*line += get_lines_number (rule_table[rule].action);
       }
 }
 
@@ -962,11 +984,14 @@ output_parser (const char *skel_filename, FILE *out)
 	  muscle_key = obstack_finish (&muscle_obstack);
 	  muscle_value = muscle_find (muscle_key);
 	  if (!strcmp (muscle_key, "actions"))
-	    actions_output (out);
+	    actions_output (out, &line);
 	  else if (!strcmp (muscle_key, "line"))
-	    fprintf (out, "%d", line + 1);
+	    fprintf (out, "%d", line);
 	  else if (muscle_value)
-	    fputs (muscle_value, out);
+	    {
+	      fputs (muscle_value, out);
+	      line += get_lines_number (muscle_value);
+	    }	  
 	  else
 	    {
 	      fputs ("%%", out);
@@ -997,6 +1022,7 @@ output_master_parser (void)
 	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
     }
   muscle_insert ("skeleton", skeleton);
+  muscle_insert ("parser-file-name", parser_file_name);
 
   output_parser (skeleton, parser);
   xfclose (parser);
