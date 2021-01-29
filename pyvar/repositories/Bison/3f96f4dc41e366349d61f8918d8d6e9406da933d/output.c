@@ -285,8 +285,6 @@ output_rule_data (void)
 		     0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&output_obstack));
   XFREE (short_tab);
-
-  XFREE (rule_table + 1);
 }
 
 /*------------------------------------------------------------------.
@@ -512,6 +510,34 @@ token_actions (void)
 }
 
 
+/*-----------------------------.
+| Output the actions to OOUT.  |
+`-----------------------------*/
+
+static void
+actions_output (struct obstack *oout)
+{
+  int rule;
+  for (rule = 1; rule < nrules + 1; ++rule)
+    if (rule_table[rule].action)
+      {
+	obstack_fgrow1 (oout, "  case %d:\n", rule);
+
+	if (!no_lines_flag)
+	  obstack_fgrow2 (oout, muscle_find ("linef"),
+			  rule_table[rule].action_line,
+			  quotearg_style (c_quoting_style,
+					  muscle_find ("filename")));
+	obstack_1grow (oout, '{');
+	obstack_sgrow (oout, rule_table[rule].action);
+	/* As a Bison extension, add the ending semicolon.  Since some
+	   Yacc don't do that, help people using bison as a Yacc
+	   finding their missing semicolons.  */
+	obstack_fgrow1 (oout, "%s}\n    break;\n\n", yacc_flag ? ";" : "");
+      }
+}
+
+
 static void
 save_column (int symbol, int default_state)
 {
@@ -931,10 +957,12 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	  /* Output the right value, or see if it's something special.  */
 	  muscle_key = obstack_finish (&muscle_obstack);
 	  muscle_value = muscle_find (muscle_key);
-	  if (muscle_value)
-	    obstack_sgrow (oout, muscle_value);
+	  if (!strcmp (muscle_key, "actions"))
+	    actions_output (oout);
 	  else if (!strcmp (muscle_key, "line"))
 	    obstack_fgrow1 (oout, "%d", line + 1);
+	  else if (muscle_value)
+	    obstack_sgrow (oout, muscle_value);
 	  else
 	    {
 	      obstack_sgrow (oout, "%%");
@@ -1011,11 +1039,6 @@ prepare (void)
   MUSCLE_INSERT_INT ("ntokens", ntokens);
 
   MUSCLE_INSERT_INT ("locations-flag", locations_flag);
-
-  /* We need to save the actions in the muscle %%action.  */
-  obstack_1grow (&action_obstack, 0);
-  muscle_insert ("action", obstack_finish (&action_obstack));
-
 }
 
 /*----------------------------------------------------------.
@@ -1044,6 +1067,7 @@ output (void)
 
   output_master_parser ();
 
+  free (rule_table + 1);
   obstack_free (&muscle_obstack, 0);
   obstack_free (&output_obstack, 0);
   obstack_free (&action_obstack, 0);
