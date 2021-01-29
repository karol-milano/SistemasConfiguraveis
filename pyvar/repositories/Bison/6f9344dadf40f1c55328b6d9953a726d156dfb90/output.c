@@ -991,6 +991,8 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	    obstack_sgrow (oout, muscle_value);
 	  else if (!strcmp (muscle_key, "line"))
 	    obstack_fgrow1 (oout, "%d", line + 1);
+	  else if (!strcmp (muscle_key, "input_line"))
+	    obstack_fgrow1 (oout, "%d", lineno + 1);
 	  else if (!strcmp (muscle_key, "action"))
 	    {
 	      size_t size = obstack_object_size (&action_obstack);
