@@ -536,6 +536,38 @@ actions_output (FILE *out, size_t *line)
 }
 
 
+/*----------------------------.
+| Output the guards to OOUT.  |
+`----------------------------*/
+
+static void
+guards_output (FILE *out, size_t *line)
+{
+  int rule;
+  for (rule = 1; rule < nrules + 1; ++rule)
+    if (rule_table[rule].action)
+      {
+	fprintf (out, "  case %d:\n", rule);
+
+	if (!no_lines_flag)
+	  fprintf (out, muscle_find ("linef"),
+		   rule_table[rule].guard_line,
+		   quotearg_style (c_quoting_style,
+				   muscle_find ("filename")));
+	fprintf (out, "{ %s; }\n    break;\n\n",
+		 rule_table[rule].guard);
+
+	/* We always output 4 '\n' per action.  */
+	*line += 4;
+	/* Plus one if !no_lines_flag.  */
+	if (!no_lines_flag)
+	  ++*line;
+	/* Get the number of lines written by the user.  */
+	*line += get_lines_number (rule_table[rule].guard);
+      }
+}
+
+
 static void
 save_column (int symbol, int default_state)
 {
@@ -928,6 +960,8 @@ output_parser (const char *skel_filename, FILE *out)
 	  muscle_value = muscle_find (muscle_key);
 	  if (!strcmp (muscle_key, "actions"))
 	    actions_output (out, &output_line);
+	  else if (!strcmp (muscle_key, "guards"))
+	    guards_output (out, &output_line);
 	  else if (!strcmp (muscle_key, "line"))
 	    fprintf (out, "%d", output_line);
 	  else if (!strcmp (muscle_key, "skeleton-line"))
@@ -1091,7 +1125,9 @@ output (void)
     header_output ();
 
   free (rule_table + 1);
-  obstack_free (&muscle_obstack, 0);
-  obstack_free (&format_obstack, 0);
-  obstack_free (&action_obstack, 0);
+  obstack_free (&muscle_obstack, NULL);
+  obstack_free (&format_obstack, NULL);
+  obstack_free (&action_obstack, NULL);
+  obstack_free (&guard_obstack, NULL);
+  obstack_free (&attrs_obstack, NULL);
 }
