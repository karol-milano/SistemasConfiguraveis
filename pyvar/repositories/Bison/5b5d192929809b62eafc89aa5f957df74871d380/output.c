@@ -972,7 +972,7 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	  const char *muscle_key = 0;
 	  const char *muscle_value = 0;
 
-	  while (isalnum (c = getc (fskel)) || c == '_')
+	  while (isalnum (c = getc (fskel)) || c == '-')
 	    obstack_1grow (&muscle_obstack, c);
 	  obstack_1grow (&muscle_obstack, 0);
 
@@ -983,7 +983,7 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	    obstack_sgrow (oout, muscle_value);
 	  else if (!strcmp (muscle_key, "line"))
 	    obstack_fgrow1 (oout, "%d", line + 1);
-	  else if (!strcmp (muscle_key, "input_line"))
+	  else if (!strcmp (muscle_key, "input-line"))
 	    obstack_fgrow1 (oout, "%d", lineno);
 	  else
 	    {
@@ -1052,14 +1052,14 @@ prepare (void)
   MUSCLE_INSERT_INT ("final", final_state);
   MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
   MUSCLE_INSERT_INT ("ntbase", ntokens);
-  MUSCLE_INSERT_INT ("error_verbose", error_verbose_flag);
+  MUSCLE_INSERT_INT ("error-verbose", error_verbose_flag);
 
   MUSCLE_INSERT_INT ("nnts", nvars);
   MUSCLE_INSERT_INT ("nrules", nrules);
   MUSCLE_INSERT_INT ("nstates", nstates);
   MUSCLE_INSERT_INT ("ntokens", ntokens);
 
-  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
+  MUSCLE_INSERT_INT ("locations-flag", locations_flag);
 
   /* We need to save the actions in the muscle %%action.  */
   muscle_insert ("action", obstack_finish (&action_obstack));
