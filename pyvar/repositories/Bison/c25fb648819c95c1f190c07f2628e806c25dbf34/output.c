@@ -959,10 +959,6 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	    obstack_sgrow (oout, muscle_value);
 	  else if (!strcmp (muscle_key, "line"))
 	    obstack_fgrow1 (oout, "%d", line + 1);
-	  /* How can lineno be correct after having finished reading
-	     input file ? --Marc.  */
-	  else if (!strcmp (muscle_key, "input-line"))
-	    obstack_fgrow1 (oout, "%d", lineno);
 	  else
 	    {
 	      obstack_sgrow (oout, "%%");
